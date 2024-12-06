
#include <REGX52.H>
//#include <at89x52.h>
unsigned char xdata *p;

void write_ram(unsigned int address, unsigned char wdata)
{
	p = (unsigned char xdata*)address;
	*p =  wdata;
}
unsigned char read_ram(unsigned int address)
{		
	unsigned char rdata;				  
	p = (unsigned char xdata*)address;
	rdata = *p;
	return rdata;
}

void delayMS(unsigned int t)
{
	int i,j;
	for(i=0;i<t;i++)
		for(j=0;j<123;j++)
			{}
}

void main(void)
{
	int i;
	unsigned char rdata;
	unsigned char wdata[]={1,2,4,8,16,32,64,128};
	for(i=0; i<8; i++)
	{
		write_ram(i,wdata[i]);//add=[10-17]
	}
	for(i=0;i<8;i++)
	{
		rdata = read_ram(i);
		P1 =  rdata;
		delayMS(100);
	}

         	
}