
#ifndef DELAY_H
#define DELAY_H

#ifndef __AT89X51_H__
#define __AT89X51_H__
#include <REGX52.H>
#endif

void delayMs(unsigned int t);
//delayUs(t): t>=20us (At least). f_crystal = 12MHz
void delayUs(unsigned char t);  //Timer0, Mode 2, NO Interrupt
void delay12Us();

#endif