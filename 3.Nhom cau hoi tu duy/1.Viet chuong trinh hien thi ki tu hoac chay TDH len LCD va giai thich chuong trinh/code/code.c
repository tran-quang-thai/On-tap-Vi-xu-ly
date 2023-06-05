#include <REGX51.H>
#define RS P2_0
#define RW P2_1
#define EN P2_2
#define DATA P3

unsigned char a[16]="            TDH";
unsigned char c[16];

void delay(int t){
	unsigned int j;
	for(j=0;j<t;j++){
		TMOD=0x01; // timer0, mode1
		TH0=0xFC; //delay 1ms
		TL0=0x18;
		TR0=1;
		while(!TF0);
		TF0=0;
		TR0=0;
	}
}

void LCD_Cmd(unsigned char cmd){
	RS=0;
	RW=0;
	DATA=cmd;
	
	EN=1;
	delay(1);
	EN=0;
	delay(5);
}

void LCD_Write(unsigned char Data){
	RS=1;
	RW=0;
	DATA=Data;
	
	EN=1;
	delay(1);
	EN=0;
	delay(5);
}

void display(){
	unsigned int i;
	for(i=0;i<=15;i++){
		LCD_Write(a[i]);
		
	}
	delay(500);
	LCD_Cmd(0x01);
	
	c[15]=a[0];
	for(i=0;i<=14;i++){
		c[i]=a[i+1];
	}
	for(i=0;i<=15;i++){
		a[i]=c[i];
	}
}

void main(){
	LCD_Cmd(0x38);
	LCD_Cmd(0x0C);
	//LCD_Write('A');
	while(1){
		//display();
	}
}