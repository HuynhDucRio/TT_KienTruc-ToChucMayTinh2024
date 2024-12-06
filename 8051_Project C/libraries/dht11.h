
#ifndef DHT11_H
#define DHT11_H

#include <REGX52.H>
#include "delay.h"

#define DHT_ER1 0
#define DHT_ER2 1
#define DHT_OK 2

sbit dhtPin = P1^1;

extern unsigned char temp, humi;

unsigned char dht_read();



#endif