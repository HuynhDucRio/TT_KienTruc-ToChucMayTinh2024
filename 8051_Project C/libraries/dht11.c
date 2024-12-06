#include "dht11.h"

unsigned char temp, humi;

unsigned char dht_read()
{
	unsigned char buffer[5]={0x00,0x00,0x00,0x00,0x00};    // mang de doc du lieu tren chan DATA 
	unsigned char ii,i;//,checksum;
	
	//GPIO_OUT_DHT11();
	dhtPin = 1;	//ideal
	delayUs(60);

	dhtPin = 0; //=0: write to mass		//GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	delayMs(20); // it nhat 18ms
	
	dhtPin = 1;							//GPIO_SetBits(GPIOB, GPIO_Pin_12);
	delayUs(40);       
	
	dhtPin = 1; //=1:float output	//GPIO_IN_DHT11();
	delayUs(60);	 //Cho 60us kiem tra muc tren chan DATA. 80us low
	//if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12))      // Neu chan DATA ko duoc keo xuong muc 0    
	if(dhtPin==1)
		return DHT_ER1 ;      // Tra ve gia tri 0    ==> ko giao tiep duoc voi DHT11
	while(dhtPin==0);    //Doi chan DaTa len 1
	delayUs(60);        // Chan Data o muc cao 80us
	
	if(dhtPin==0)        // Kiem tra muc tren chan DATA
		return DHT_ER2;
	while(dhtPin==1);     //Doi chan Data ve 0
	
	//Bat dau doc du lieu
	for(i=0;i<5;i++)  // nhan 5byte du lieu
	{
		for(ii=0;ii<8;ii++)     // nhan tung bit
		{    
			//while((!(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)))); //Doi Data len 1
			while(dhtPin==0);
			delayUs(45);
			//if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12))
			if(dhtPin==1)
			{
				buffer[i]|=(0x01<<(7-ii));	 //MSB first
				//while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) ;   //Doi Data xuong 0
				while(dhtPin==1);
			}
		}
	}
	//Tinh toan check sum
	//checksum=buffer[0]+buffer[1]+buffer[2]+buffer[3];
	//Kiem tra check sum
	//if((checksum)!=buffer[4])return DHT_ER;
	//Lay du lieu
	temp  =   buffer[2];
	humi =   buffer[0];
	dhtPin = 1;	//ideal
	return DHT_OK;
}
