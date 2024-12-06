
#ifndef KEYPAD4X4_H
#define KEYPAD4X4_H

#include <REGX52.H>
#include "delay.h"


//KEYPAD
#define MAX_ROW 4

#define KEYPAD P0
/*
KEYPAD
   COL_1 -   P0.0
   COL_2 -   P0.1
   COL_3 -   P0.2
	 COL_4 -   P0.3

   ROW_1 -   P0.4
   ROW_2 -   P0.5
   ROW_3 -   P0.6
   ROW_4 -   P0.7
*/

sbit COL_1 =  P0^0;
sbit COL_2 =  P0^1;
sbit COL_3 =  P0^2;
sbit COL_4 =  P0^3;

sbit ROW_1 =  P0^4;
sbit ROW_2 =  P0^5;
sbit ROW_3 =  P0^6;
sbit ROW_4 =  P0^7;

//Init Keypad
void initKeypad();

/*Reset The Row*/
void DoResetRow(short siRowNumber);
/*Check Columnn*/
char Check_Column(void);
/*Read Col Status*/
char ReadKeyPressed(void);


#endif