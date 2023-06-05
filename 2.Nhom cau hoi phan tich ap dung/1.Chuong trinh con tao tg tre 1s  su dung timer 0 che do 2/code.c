#include <REGX51.H>

void delay() { // delay 1ms sử dụng timer 0 ,chế độ 2
	unsigned int i;
	for (i = 0; i < 5000; i++) {
		TMOD = 0x02; // Timer 0 chế độ 2
		TH0 = 0x38; // Thiết lập giá trị thanh ghi đếm cao của Timer 0
		TR0 = 1; // Khởi động Timer 0
		while (!TF0); // Chờ cho đến khi cờ tràn đếm (TF0) được set
		TF0 = 0; // Reset cờ tràn đếm của Timer 0
		TR0 = 0; // Tắt Timer 0
	}
}

void main(){
	while(1){
		P1_0=1;
		delay();
		P1_0=0;
		delay();
	}
}
		