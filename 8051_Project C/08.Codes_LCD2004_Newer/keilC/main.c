#include <REGX52.H>	  //built-in
#include "delay.h"
#include "LCD2004.h"

void main(void)
{
	char c = 'A';

	LCD_Init();		/* Initialization of LCD*/
	LCD_String_xy(0,0,"Huynh Hoang Ha"); //row: 0 , column: 0
	LCD_String_xy(1,0,"07119014");		 //row: 1 , column: 0
	LCD_String_xy(2,0,"KTMT");  		 //row: 2 , column: 0
	
	//Choose starting Position: row:3, column:0
	LCD_SetPosition(3,0);
	LCD_String("Char: ");
	while(1){
		LCD_Char(c);
		c++;
		delayMs(1000);
	}
}


