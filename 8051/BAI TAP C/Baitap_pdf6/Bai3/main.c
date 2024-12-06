#include <REGX52.H>
#define LED P2
unsigned int dcount = 0;
sbit DC = P1^0;
sbit startBTN = P3^2;
sbit stopBTN = P3^3;

void setup(void)
{
	DC = 0;
	startBTN = 1;
	stopBTN = 1;
	
	EA = 1;
	EX0 = 1;
	ET0 = 1;
	ET1 = 1;
	
	TMOD = 0x12;
	TH0 = 0x00;
	TL0 = 0x00;
	
	TH1 = 0xFC;
	TL1 = 0x18;
	TR1 = 1;
}

void delayMS(unsigned int t)
{
	dcount = 0;
	while (dcount<t);
}
void ISR_timer0() interrupt 1
{
	DC = !DC;
}

void ISR_timer1() interrupt 3
{
	TH1 = 0xFC;
	TL1 = 0x18;
	dcount++;
}
void ISR_start() interrupt 0
{
	TR0 = 1;
	EX0 = 0;
	EX1 = 1;
	TR1 = 1;
}

void ISR_stop() interrupt 2
{

	TR0 = 0;
	DC = 0;
	EX0 = 1;
	EX1 = 0;
	TR1 = 0;
}

void main (void)
{
	setup();
	while(1)
	{
		if( TR0 == 1)
		{
			int i;
			for(i=5;i >= 0;i--)
			{
				LED = i;
				if( i == 0)
				{
					TR0 = 0;
					DC = 0;
					EX0 = 1;
					EX1 = 0;
				}
				delayMS(1000);
			}	
		}
	}
}