#include <REGX51.H>

void ngat(void) interrupt 0{
	P1_0=0;
}

void main(){
	EA=1; // cho phep ngat toan cuc
	EX0=1; // cho phep ngat timer 0
	IT0=1; // Cài đặt ngắt ngoài 0 theo cạnh lên. 
	while(1){
	}
}