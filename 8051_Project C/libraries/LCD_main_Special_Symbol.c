#include <REGX52.H>	  //built-in
#include "delay.h"
#include "LCD2004.h"

/* Custom char set for alphanumeric LCD Module */
	unsigned char Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };
	unsigned char Character2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
	unsigned char Character3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
	unsigned char Character4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
	unsigned char Character5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
	unsigned char Character6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
	unsigned char Character7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
	unsigned char Character8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };

void main(void)
{
	int i;
	char c = 'A';
	LCD_Init();		/* Initialization of LCD*/

	LCD_Custom_Char(0, Character1);  /* Build Character1 at position 0 */ 
	LCD_Custom_Char(1, Character2);  /* Build Character2 at position 1 */ 
	LCD_Custom_Char(2, Character3);  /* Build Character3 at position 2 */ 
	LCD_Custom_Char(3, Character4);  /* Build Character4 at position 3 */ 
	LCD_Custom_Char(4, Character5);  /* Build Character5 at position 4 */ 
	LCD_Custom_Char(5, Character6);  /* Build Character6 at position 5 */ 
	LCD_Custom_Char(6, Character7);  /* Build Character6 at position 6 */ 
	LCD_Custom_Char(7, Character8);  /* Build Character6 at position 7 */ 


	LCD_String_xy(0,0,"Huynh Hoang Ha"); //row: 0 , column: 0
	LCD_String_xy(1,0,"07119014");		 //row: 1 , column: 0
	
  	LCD_SetPosition(2,0);
	for(i=0;i<8;i++)
		LCD_Char(i);
					  
	//Choose starting Position: row:3, column:0
	LCD_SetPosition(3,0);
	LCD_String("Char: ");
	while(1){
		LCD_Char(c);		 
		c++;
		delayMs(1000);
	}
}


