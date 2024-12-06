
#ifndef ADC0808_H
#define ADC0808_H

#include <REGX52.H>

#define Vref 2.55

//Khai bao chan giao tiep ADC0808
#define ADC0808_DATA      P2
#define ADC0808_A         P0_0
#define ADC0808_B         P0_1
#define ADC0808_C         P0_2
#define ADC0808_ALE       P0_3
#define ADC0808_CLK       P0_4
#define ADC0808_START     P0_5
#define ADC0808_EOC       P0_6
#define ADC0808_OE        P0_7
 

unsigned char ADC0808_Read(unsigned char channel);



#endif