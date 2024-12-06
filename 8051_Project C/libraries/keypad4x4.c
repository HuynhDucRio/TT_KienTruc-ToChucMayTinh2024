#include "keypad4x4.h"

const unsigned char ucaKeyPad[4][4] =           //Key Pad 4x3
{
    {'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},     
    {'C','0','=','+'}
};

void initKeypad()
{
	KEYPAD = 0x0F; //Make Row O/p & Col I/p
}

char ReadKeyPressed(void)
{
    char ucData='p';
    while('p' == ucData)
    {
        ucData = Check_Column();
    }
    return ucData;
}
char Check_Column(void)
{
    short siColNumber=0;

    for(siColNumber = 0; siColNumber <= MAX_ROW; siColNumber++)
    {
        DoResetRow(siColNumber); /*Reset the row*/
        if(COL_1 == 0)
        {
            delayMs(300);
            return ucaKeyPad[siColNumber][0];
        }
        if(COL_2 == 0)
        {
            delayMs(300);
            return ucaKeyPad[siColNumber][1];
        }
        if(COL_3 == 0)
        {
            delayMs(300);
            return ucaKeyPad[siColNumber][2];
        }
				if(COL_4 == 0)
        {
            delayMs(300);
            return ucaKeyPad[siColNumber][3];
        }
    }
    return 'p';
}
void DoResetRow(short siRowNumber)
{
    ROW_1=ROW_2=ROW_3=ROW_4= 1; /*Make all row high*/
    switch(siRowNumber)
    {
    case 0:
        ROW_1 =0;
        break;
    case 1:
        ROW_2 =0;
        break;
    case 2:
        ROW_3 =0;
        break;
    case 3:
        ROW_4 =0;
        break;
    }
}