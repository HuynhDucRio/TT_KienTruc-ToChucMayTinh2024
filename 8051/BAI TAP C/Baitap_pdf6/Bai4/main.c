#include <REGX52.H>
#define LED P2
void setup(void)
{
	LED = 0x00;
	
	EA = 1;
	ET0 = 1;
	IT0 = 1;
	TR0 = 1;
	
	TMOD = 0x01;
	TH0 = 0xFC;
	TL0 = 0x18;
}

unsigned int dcount = 0;
void ISR_Timer0() interrupt 1
{
	//auto clear Timer0 Flag (TF0)
	TH0 = 0xFC;
	TL0 = 0x18;
	
	if (dcount == 1000)
	{
		if (LED & 0x80)
		{
			LED = 0x00;
			dcount = 0;
		}
		else
		{
		LED = 0x01 | (LED << 1);
		dcount = 0;
		}
	} 
	else 
	{
		dcount++;
	}
	
}



void main (void)
{
	setup();
	while(1)
	{
	
	}
}