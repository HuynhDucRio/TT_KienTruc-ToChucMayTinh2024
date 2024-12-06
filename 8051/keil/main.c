#include <REGX51.H>
void delayMS(unsigned int t);
unsigned char led7seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

#define LED P1
void dem00den99();

void main (void)
{
	LED = 0x00;
	
	while(1)
	{
		dem00den99();
	}
}
void delayMS(unsigned int t)
{
	int i,j;
	for(i=0; i<t;i++)
		for(j=0;j<123;j++){}
}

void dem00den99()
{
	int i;
	for(i=0;i<100;i++)
	{
		P2 = led7seg[i/10];
		P3 = led7seg[i%10];
		delayMS(100);
	}
}
