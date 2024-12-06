
#ifndef LCD2004_H
#define LCD2004_H

#ifndef __AT89X51_H__
#define __AT89X51_H__
#include <REGX52.H>
#endif


#include "delay.h"

#define LCD_Port P1
sbit rs=P1^0;			/* Register select pin */
sbit rw=P1^1;			/* Read/Write pin */
sbit en=P1^2;			/* Enable pin */

									
void LCD_Command (char cmnd);
void LCD_SetPosition(char row, char pos);
void LCD_Char (char char_data);
void LCD_String (char *str);
void LCD_String_xy (unsigned char row, unsigned char pos, char *str);
void LCD_Init (void);
void LCD_Custom_Char (unsigned char loc, unsigned char *msg);


#endif