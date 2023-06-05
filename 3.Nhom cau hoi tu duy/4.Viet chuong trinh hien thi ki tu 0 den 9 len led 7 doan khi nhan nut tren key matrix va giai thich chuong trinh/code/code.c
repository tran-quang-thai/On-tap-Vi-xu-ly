#include <REGX51.H>

sbit ROW1 = P1^0;
sbit ROW2 = P1^1;
sbit ROW3 = P1^2;
sbit ROW4 = P1^3;
sbit COL1 = P1^4;
sbit COL2 = P1^5;
sbit COL3 = P1^6;
sbit COL4 = P1^7;

unsigned char key=0xFF;
unsigned char s[]={0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09};

void delay(int t){
    unsigned int i;
    for(i=0;i<t;i++){
        TMOD=0x01;
        TH0=0xFC; //delay 1ms
        TL0=0x18;
        TR0=1;
        while(!TF0);
        TF0=0;
        TR0=0;
    }
}

unsigned char Keypad_Read(){
    unsigned char key = 0xFF;
    ROW1=0;
    if(!COL1) key='0'; // Clear
    if(!COL2) key='1';
    if(!COL3) key='2'; // =
    if(!COL4) key='3'; // +
    ROW1=1;
    ROW2=0;
    if(!COL1) key='4';
    if(!COL2) key='5';
    if(!COL3) key='6';
    if(!COL4) key='7'; // -
    ROW2=1;
    ROW3=0;
    if(!COL1) key='8';
    if(!COL2) key='9';
    if(!COL3) key='A';
    if(!COL4) key='B'; // *
    ROW3=1;
    ROW4=0;
    if(!COL1) key='C';
    if(!COL2) key='D';
    if(!COL3) key='E';
    if(!COL4) key='F'; // "/"
    ROW4=1;
    return key;
}

void main(){
	unsigned char key;
	P2=0xFF;
	while(1){
		key=Keypad_Read();
		if(key!=0xFF){
			delay(250);
			P2=s[key-'0'];
		}
	}
}