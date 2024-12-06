#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"
#include "adc0808.h"

unsigned char temp, dv, chuc,tram;
void main(void)
{
	LCD_Init();		
	LCD_String_xy(0,0,"Hello World1");
	LCD_String_xy(1,0,"Nhiet do: ");

 	dv = chuc = 0; 
	while(1){
		temp=ADC0808_Read(1);
		dv = (temp%10) + 48;
		chuc = ((temp/10)%10) + 48;
		tram = (temp/100) + 48;
				
		LCD_SetPosition(1,10);	
		LCD_Char(tram);
		LCD_Char(chuc);
		LCD_Char(dv);

		delayMs(1000);
	}
}


