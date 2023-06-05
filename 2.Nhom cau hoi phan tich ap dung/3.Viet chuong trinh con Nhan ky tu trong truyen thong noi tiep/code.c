#include <REGX51.H>
// Crystal 11.0592MHz
//Virtual Terminal - BaudRate(9600) - Databits(8bit) - Stopbit(1) 

// Cấu hình truyền thông nối tiếp
void UART_Init() {
    TMOD |= 0x20;       // Cấu hình Timer 1 chế độ 8-bit tự động nạp lại
    SCON = 0x50;        // Cấu hình UART: 8-bit truyền, không kiểm tra lỗi, truyền một chiều
    TH1 = 0xFD;  // Thiết lập tốc độ baud rate cho 9600
    TR1 = 1;            // Bật Timer 1
}

// Nhận ký tự
char UART_Receive() {
    while (!RI);        // Đợi cho đến khi nhận ký tự
    RI = 0;             // Reset cờ nhận
    return SBUF;        // Trả về ký tự nhận được
}

//Bổ sung thêm hàm Truyền ký tự 
//void UART_Transmit(unsigned char c){
//	SBUF=c;
//	while(!TI);
//	TI=0;
//}

void main() {
    UART_Init();    // Cấu hình truyền thông với baudrate 9600 bps
    while (1) {
       // Nhận ký tự từ truyền thông nối tiếp
		 // ví dụ hiển thị mã ascii của ký tự lên P2
		 P2=UART_Receive();
    }
}
