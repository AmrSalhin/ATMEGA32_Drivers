/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     ADC                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define  ADMUX     *(volatile u8*)0x27)   //ADC MULTIPLEXER SELECTION REGISTER  
#define  ADMUX_REFS1      7               //REFRENCE SELECTION BIT1
#define  ADMUX_REFS0      6               //REFRENCE SELECTION BIT1
#define  ADMUX_ADLAR      5               //ADC LEFT ADJUST RESULT

#define ADCSRA      *((volatile u8*)0x26) //ADC CONTROL AND STATUS REGISTER A 
#define ADCSRA_ADEN     7                 //ADC ENABLE
#define ADCSRA_ADSC     6                 //START CONVERSION
#define ADCSRA_ADATE    5                 //AUTO TRIGGER ENABLE
#define ADCSRA_ADIF     4                 //INTERRUPT FLAG
#define ADCSRA_ADIE     3                 //INTERRUPT ENABLE
#define ADCSRA_ADBS2    2                 //PRESCALER BIT2
#define ADCSRA_ADBS1    1                 //PRESCALER BIT1
#define ADCSRA_ADBS0    0                 //PRESCALER BIT0


#define ADCH     *((volatile u8*)0x25)    //ADC HIGH REGISTER
 

#define ADCL    *((volatile u8*)0x24)     //ADC LOW REGISTER
 
#endif
