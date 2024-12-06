#include <REGX52.H>

sbit led = P2^0;
sbit btnON = P3^2;
sbit btnOFF = P3^3;

void btn_setup()
{
	btnON = 1;
	btnOFF = 1;
	IT0 = 1; //Ngat bang canh xuong
	IT1 = 1; 
	EA  = 1; //Enable global
	EX0 = 1; //Enable interrupt0
	EX1 = 1;
}

void ISR_INT0(void) interrupt 0 //Ham ngat
{
	led = 1;
}
void ISR_INT1(void) interrupt 2 //Ham ngat
{
	led = 0;
}
void main(void)
{
	led = 0;
	btn_setup();
	while(1)
	{
	
	}
}