#include "LCD2004.h"


void LCD_Init (void)		/* LCD Initialize function */
{
	LCD_Port = 0x00;
	delayMs(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Command (0x02);	/* powerdown mode disable */
	LCD_Command (0x28);	/* 0010.1000 Initialization of 20X4 LCD in 4bit mode */
	LCD_Command (0x0F);	/* 0000.1110 Display ON Cursor OFF */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* Clear display */
	LCD_Command (0x80);	/* Cursor at home position */
}

void LCD_Command (char cmnd)	/* LCD20x4 command funtion */
{
	LCD_Port =(LCD_Port & 0x0F) | (cmnd & 0xF0);/* Send upper nibble */
	rs=0;			/* Command reg. */
	rw=0;			/* Write operation */
	en=1; 
	delayMs(1);
	en=0;
	delayMs(2);
	
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);/* Send lower nibble */
	en=1;			/* Enable pulse */
	delayMs(1);
	en=0;
	delayMs(5);
}

void LCD_SetPosition(char row, char pos)
{
	if (row == 0)
		LCD_Command((pos & 0x1F)+0x80);
	else if (row == 1)
		LCD_Command((pos & 0x1F)+0xC0);	 //		16x2: 16 cot. 0-15	=> 20x04. 0-19	. 1 1111
	else if (row == 2)
		LCD_Command((pos & 0x1F)+0x94);  //  1001.0100  | 0000.0110 = 1001.0110	=0x9A
	else if (row == 3)
		LCD_Command((pos & 0x1F)+0xD4);
}

void LCD_Char (char char_data)	/* LCD data write function */
{
	LCD_Port =(LCD_Port & 0x0F) | (char_data & 0xF0);/* Send upper nibble */
	rs=1;			/* Data reg.*/
	rw=0;			/* Write operation*/
	en=1;
	delayMs(1);
	en=0;
	delayMs(2);

	LCD_Port = (LCD_Port & 0x0F) | (char_data << 4);/* Send lower nibble */
	en=1;			/* Enable pulse */
	delayMs(1);
	en=0;
	delayMs(5);

}

void LCD_String (char *str)	/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);  /* Call LCD data write */
	}
}

void LCD_String_xy (unsigned char row, unsigned char pos, char *str)  /* Send string to LCD function */
{
	if (row == 0)
		LCD_Command((pos & 0x1F)+0x80);
	else if (row == 1)
		LCD_Command((pos & 0x1F)+0xC0);	 //		16x2: 16 cot. 0-15	=> 20x04. 0-19	. 1 1111
	else if (row == 2)
		LCD_Command((pos & 0x1F)+0x94);  //  1001.0100  | 0000.0110 = 1001.0110	=0x9A
	else if (row == 3)
		LCD_Command((pos & 0x1F)+0xD4);
	LCD_String(str);  	/* Call LCD string function */
}

void LCD_Custom_Char (unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
	/* Command 0x40 and onwards forces the device to point CGRAM address */
	LCD_Command (0x40 + (loc*8));
	for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_Char(msg[i]);      
    }   
}
