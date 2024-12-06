#include <REGX52.H>
#include "delay.h"
sbit led1 = P1^0;
sbit led2 = P1^1;
sbit led3 = P1^2;
//Fcrystal = 11.0592MHz
unsigned char rev; //Du lieu nhan duoc
unsigned char flag = 0;
void setup(void)
{
	TMOD = 0x20; // timer1 mode 2
	TH1 = 0xFD; //baudrate 9600
	TL1 = 0xFD; 
	TR1 = 1; //enable timer1
	
	SCON = 0x50; //8bit data, Timer1(baudrate)
	
	EA = 1;//enable global interrupt
	ES = 1;//enable serial interrupt
}

void serial_send(unsigned char dta)//Ham gui du lieu
{
	SBUF = dta; //
	while(TI==0);//
	TI = 0;
}

void serial_receive(void) interrupt 4
{
	if(RI == 1) //doc du lieu khi RI len 1
	{
		rev = SBUF;//doc du lieu nhan duoc trong SBUF
		RI = 0; // clear RI sau khi doc
		flag = 1; //set co bao co du lieu moi
	}
}
void send_string(char x[]) //Ham gui chuoi
{
	int i =0;
	while(x[i])
	{
		serial_send(x[i]);
		i++;
	}

}
void main (void)
{
	setup();
	led1 = 0;
	led2 = 0;
	led3 =0;

	while(1)
	{
		if(flag == 1) // check co du lieu moi
		{
			switch (rev) // Switch case cac gia tri cua rev ung voi tung che do
			{
				case '1':
					led1 = 1;
					serial_send(13);
					send_string("led1 on");
					serial_send(13);
					break;
				case '2':
					led1 = 0;
					serial_send(13);
					send_string("led1 off");
					serial_send(13);
					break;
				case '3':
					led2 = 1;
					serial_send(13);
					send_string("led2 on");
					serial_send(13);
					break;
				case '4':
					led2 = 0;
					serial_send(13);
					send_string("led2 off");
					serial_send(13);
					break;
				case '5':
					while(rev == '5'); //Khi nhan '5' thi treo doi gia tri tiep theo de blink
					rev -= 0x30;			//Doi ki tu sang so lan blink
					serial_send(13);
					send_string("Led3 blink ");
					serial_send((rev+0x30));
					send_string(" times");
					while(rev != 0) // blink led3
						{
						led3 = !led3;
						delayMs(500);
						led3 = !led3;
						delayMs(500);
							rev--;
						}
						serial_send(13);
						send_string("Blink done!");
						serial_send(13);
					break;
				default:
					break;
			}
			flag = 0; //clear co sau khi da xu li xong du lieu vua nhan
		}
	}
}