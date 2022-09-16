/*
 * Timer_register.h
 *
 *
 *      Author: Amr Salhen
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/**************************************************************/
/*******************TIMER0 Register0***************************/
/**************************************************************/
#define TCCR0   *((volatile u8*)0x53)
#define TCCR0_FOC0    7
#define TCCR0_WGM00   6       //Waveform Generation Mode Bit Description(0 Normal/1 PWM/0 CTC/1 Fast PWM)
#define TCCR0_WGM01   3		  //Waveform Generation Mode Bit Description(0 Normal/0 PWM/1 CTC/1 Fast PWM)
//Compare Output Mode, non-PWM Mode
//COM01 COM00 Description
//0 0 Normal port operation, OC0 disconnected.
//0 1 Toggle OC0 on compare match
//1 0 Clear OC0 on compare match
//1 1 Set OC0 on compare match
/**********************************************/
//Compare Output Mode, Fast PWM Mode(1)
//COM01 COM00 Description
//0 0 Normal port operation, OC0 disconnected.
//0 1 Reserved
//1 0 Clear OC0 on compare match, set OC0 at TOP
//1 1 Set OC0 on compare match, clear OC0 at TOP
/**********************************************/
//Compare Output Mode, Phase Correct PWM Mode
//COM01 COM00 Description
//0 0 Normal port operation, OC0 disconnected.
//0 1 Reserved
//1 0 Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
//1 1 Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
/**********************************************/
#define TCCR0_COM01   5
#define TCCR0_COM00   4
//Clock Select Bit Description
//CS02 CS01 CS00 Description
//0 0 0 No clock source (Timer/Counter stopped).
//0 0 1 clkI/O
//0 1 0 clkI/O/8
//0 1 1 clkI/O/64
//1 0 0 clkI/O/256
//1 0 1 clkI/O/1024
//1 1 0 External clock source on T0 pin. Clock on falling edge.
//1 1 1 External clock source on T0 pin. Clock on rising edge.
#define TCCR0_CS02    2
#define TCCR0_CS01    1
#define TCCR0_CS00    0

/*******************TCNT0 Register***************************/
#define TCNT0        *((volatile u8*)0x52)

/*******************OCR0 Register***************************/
#define OCR0        *((volatile u8*)0x5C)

/*******************TIMSK Register***************************/
#define TIMSK       *((volatile u8*)0x59)
//Output Compare Match Interrupt Enable
#define TIMSK_OCIE0    1
//Timer/Counter0 Overflow Interrupt Enable
#define TIMSK_TOIE0    0


/**************************************************************/
/*******************TIMER1 Registers***************************/
/**************************************************************/

#define TCCR1A        *((volatile u8*)0x4F)


#define TCCR1B        *((volatile u8*)0x4E)
#define TCNT1L        *((volatile u16*)0x4C)
#define OCR1AL        *((volatile u16*)0x4A)
#define OCR1BL        *((volatile u16*)0x48)
#define ICR1L        *((volatile u16*)0x46)






#endif /* TIMER_REGISTER_H_ */
