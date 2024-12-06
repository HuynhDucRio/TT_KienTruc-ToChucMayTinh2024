#include <REGX52.H>

sbit LED = P2^1;
unsigned char flag = 0; //Co nhan
unsigned char revData; //Data nhan

void serial_init(void)
{
	TMOD = 0x20; //Timer1 mode 2
	TH1 = 0xFD; //set baudrate 9600
	SCON = 0x50;//Serial config
	TR1 = 1; //enable timer1
	EA = 1; //enable global interrupt
	ES = 1; //enable serial interrupt
}

void serial_send(unsigned char x) //Ham gui du lieu
{
	SBUF = x; 
	while(TI == 0);
	TI = 0;
}	

void serial_ISR(void) interrupt 4
{
	if(RI == 1)
	{
		revData = SBUF;
		RI = 0; //clear co RI da nhan xong
		flag = 1; // co bao vua nhan du lieu
	}
}

void main(void)
{
	LED = 0; //init state of led
	serial_init();
	while(1)
	{
		if (flag == 1) //check du lieu vua nhan
		{
			if(revData == '1')
				LED = 1;
			else
				LED = 0;
			serial_send(13);
			serial_send('O');
			serial_send('K');
			serial_send(13);	
			flag = 0; //xu li xong du lieu vua nhan thi clear co
		}
	}

}