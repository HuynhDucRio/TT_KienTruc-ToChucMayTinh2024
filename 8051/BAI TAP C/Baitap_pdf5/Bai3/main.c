#include <REGX52.H>
void delayMS(unsigned int t);
sbit led1 = P2^1;
sbit led2 = P2^0;

sbit btnON = P3^2;
sbit btnOFF = P3^3;

void btn_setup()
{
	btnON = 1;
	btnOFF = 1;
	IT1 = 1;
	IT0 = 1;
	EA = 1;
	EX1 = 1;
	EX0 = 1;

}

void ISR_INT0() interrupt 0
{
	led1 = 1;
}

void ISR_INT1() interrupt 2
{
	led1 = 0;
}


void main(void)
{
	btn_setup();
	led1 = 0;
	led2 = 0;
	
	while(1){
	led2 = ~led2;
	delayMS(1000);
	
	
	}
}




void delayMS(unsigned int t)
{
	int i,j;
	for(i=0; i<t;i++)
		for(j=0;j<123;j++){}
}