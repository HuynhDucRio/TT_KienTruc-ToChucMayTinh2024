#include <REGX52.H>

sbit led = P1^1;

void timer_50us_init(void)
{
	TMOD = 0x02;
	TH0 = 0xCE;
	TL0 = 0xCE;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}	
void ISR_Timer0() interrupt 1
{
	led = !led;
}

void main(void)
{
	led = 0;
	timer_50us_init();
	while(1)
	{}
}