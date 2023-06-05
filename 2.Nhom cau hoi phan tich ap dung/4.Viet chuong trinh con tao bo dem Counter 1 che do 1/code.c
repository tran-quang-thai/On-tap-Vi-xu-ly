#include <REGX51.H>

void main() {
	TMOD=0x50;
	while(1){
	TH1=0x00;
	TR1=1;
	P2=TL1;
//	TF1=0;
//	TR1=0;
	}
}
