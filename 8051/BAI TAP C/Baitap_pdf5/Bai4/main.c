#include <REGX51.H>

#define LED P1
sbit startBTN = P3^1;
sbit stopBTN = P3^2;
sbit pauseBTN = P3^3;
void delayMS(unsigned int t);

void setup()
{
	LED = 0x00;
	startBTN = 1;
	stopBTN = 1;
	pauseBTN = 1;
	
	IT0 = 1;
	IT1 = 0;
	EA = 1;
	EX0 = 1;
	EX1 = 1;
}

void ISR_STOP(void) interrupt 0
{
	LED = 0x00;
}
void ISR_PAUSE(void) interrupt 2
{
	
}


void main(void)
{
	setup();
	while(1)
	{
		if(startBTN == 0)
		{
			while(startBTN == 0)
			{
				LED = 0x01;
				delayMS(500);
			}
			while(startBTN == 1)
			{	
				if(LED == 0x80)
				{
					LED = 0x01;
					delayMS(500);
				}
				LED = LED << 1;
				delayMS(500);

			}
			
		}
	}
}


void delayMS(unsigned int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		int j;
		for(j=0;j<123;j++) {}
	}
}