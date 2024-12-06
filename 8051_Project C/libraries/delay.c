#include "delay.h"


void delayMs(unsigned int t)
{
	int i,j;
	for(i=0;i<t;i++)
		for(j=0;j<123;j++) {}  //1ms
}

/*NOTE: 17<t<255 */
void DelayUs(unsigned char t)  //Timer0, Mode 2, NO Interrupt
{		
	TMOD = 0x02;	//Timer0, Mode 2
	TL0 = 255-t+17;  //Don't need TH, use 1 pulse.
	TF0 = 0;
	TR0 = 1;		//Start Timer0
	while(TF0==0);
	TR0 = 0;		//Stop Timer0
}