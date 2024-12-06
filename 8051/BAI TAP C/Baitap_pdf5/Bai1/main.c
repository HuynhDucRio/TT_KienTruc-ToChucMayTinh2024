#include <REGX52.H>

sbit LED = P2^1;
sbit OFF_BTN = P2^4;
sbit ON_BTN = P2^5;

void main(void)
{
		OFF_BTN = 1;
		ON_BTN = 1;
		LED = 0;
	while(1)
	{
		if(ON_BTN == 0)
		{
			LED = 1;
			while( ON_BTN == 0);
		}
		if(OFF_BTN == 0)
		{
			LED = 0;
			while( OFF_BTN == 0);
		}
	}
}