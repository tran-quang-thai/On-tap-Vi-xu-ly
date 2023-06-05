#include <REGX51.H>
sbit ADC_WR=P2^3;
sbit ADC_INTR=P2^4;
#define ADC_DATA P1

sbit LCD_RS=P2^0;
sbit LCD_RW=P2^1;
sbit LCD_EN=P2^2;
#define LCD_DATA P3

void delay(unsigned t){
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
unsigned char ADC_Read(){
	unsigned char temp;
	ADC_WR=0;
	delay(100);
	ADC_WR=1;
	delay(100);
	while(!ADC_INTR);
	temp=ADC_DATA;
	return temp;
}

void LCD_Cmd(unsigned char cmd){
	LCD_RS=0;
	LCD_RW=0;
	LCD_DATA=cmd;
	LCD_EN=0;
	delay(1);
	LCD_EN=1;
	delay(5);
}

void LCD_Write(unsigned char Data){
	LCD_RS=1;
	LCD_RW=0;
	LCD_DATA=Data;
	LCD_EN=0;
	delay(1);
	LCD_EN=1;
	delay(5);
}
void main(){
	unsigned char temp;
	LCD_Cmd(0x38);
	LCD_Cmd(0x0C);
	while(1){
		temp=ADC_Read();
		temp=temp/0.512;
		LCD_Cmd(0x01);
		LCD_Write(temp/10+48);
		LCD_Write(temp%10+48);
	}
}