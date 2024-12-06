#include <REGX52.H>

sbit led = P2^1;
unsigned int dcount = 0;
void ISR_Timer0() interrupt 1
{
	//auto clear Timer0 Flag (TF0)
	TH0 = 0xFC;
	TL0 = 0x18;
	dcount++;
}

void timer0_1ms_init(void)
{
	TMOD = 0x01; // MOD1: 16-bit
	TH0 = 0xFC;
	TL0 = 0x18;
	IE = 0x82; //Enable global and timer0 interrupt
	TR0 = 1;
}

void delayMS(unsigned int t)
{
	dcount = 0;
	while (dcount < t);
}

void main(void)
{
	timer0_1ms_init();
	while(1)
	{
		led = !led;
		delayMS(500);
	}
}