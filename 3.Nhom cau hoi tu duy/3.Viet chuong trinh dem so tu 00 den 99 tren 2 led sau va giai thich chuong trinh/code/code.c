#include <REGX51.H>
#define D1 P3_7
#define D2 P3_6
unsigned char D[]={0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09};

void delay(unsigned int t){
	unsigned int i;
	TMOD=0x01;
	for(i=0;i<t;i++){
		TH0=0xFC;
		TL0=0x18;
		TR0=1;
		while(!TF0);
		TF0=0;
		TR0=0;
	}
}

void display(){
	unsigned int d1, d2, w, m=48;
	for(d2=0;d2<=9;d2++){
		for(d1=0;d1<=9;d1++){
			for(w=0;w<10;w++){
				D1=1;
				P2=D[d1];
				delay(m);
				D1=0;
				
				D2=1;
				P2=D[d2];
				delay(m);
				D2=0;
			}
	
		}
	}
}

void main(){
	while(1){
		display();
	}
}
	
