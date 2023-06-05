#include <REGX51.H>
unsigned char a[8]={0xFF, 0x80, 0x77, 0x77, 0x77, 0x77, 0x80, 0xFF};


void display(){
	unsigned int i;
	for(i=0;i<=7;i++){
		P3=0x80>>i;
		P2=a[i];
	}
}

void main(){
	while(1){
		display();
	}
}