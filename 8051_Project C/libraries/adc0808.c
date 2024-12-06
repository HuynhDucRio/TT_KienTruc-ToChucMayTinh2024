#include "adc0808.h"

/*Chương trình ngắt timer 0*/
void INT_Timer0() interrupt 1 {
	//ctr phuc vu ngat tao xung clock cho ADC0808
	ADC0808_CLK= !ADC0808_CLK; //Dao bit
}


/*Hàm đọc và điều khiển ADC0808*/
unsigned char ADC0808_Read(unsigned char channel){	
	unsigned char kq;

	//Tao xung clock cho ADC0808 – sẽ học sau
	TMOD=0x02;	//mode 02
	TH0=TL0=236;
	TR0=1;
	ET0=1;//Ngat timer0
	EA=1;//Cho phep ngat cuc bo

	ADC0808_DATA = 0xff;
	ADC0808_EOC = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;

	ADC0808_A = channel & 0x01;
	ADC0808_B = channel & 0x02;
	ADC0808_C = channel & 0x04;
	ADC0808_ALE = 1;
	ADC0808_START = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;
	while(ADC0808_EOC);  //still 1, when start = 0 (in short time)
	while(!ADC0808_EOC); //EOC=0
	ADC0808_OE = 1;
	kq = ADC0808_DATA;
	ADC0808_OE = 0;

/*
	ADC 8 bit. 
	=> ADC0808_DATA�= (Vin/Vref)*255
	=>�Vin = (ADC0808_DATA *�Vref)/255 (V)
	Voi: 0.01V = 1 do C.
	=> �temp�=�Vin/0.01
*/

	kq = kq*Vref*100/255;


	//stop Timer & all interrupts
	TR0=0;//Dung Timer
	ET0=0;//Cam Ngat timer0
	//EA=0;//Cam ngat toan cuc

	return kq;
}
