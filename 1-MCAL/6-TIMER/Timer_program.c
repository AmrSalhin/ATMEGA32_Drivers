/*
 * Timer_program.c

 *
 *  Created on: Sep 10, 2022
 *      Author: Amr Salhen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer_interface.h"
#include "Timer_register.h"
#include "Timer_private.h"
#include "Timer_config.h"

static void (*Pv_TIMER0)(void);

void TIMER0_voidinit(){
	/*Choose TIMER0 MODE*/
#if	TIMER0_MODE ==	NORMAL
	Clr_bit(TCCR0,TCCR0_WGM00);
	Clr_bit(TCCR0,TCCR0_WGM01);
#elif TIMER0_MODE ==	PWM
	Set_bit(TCCR0,TCCR0_WGM00);
	Clr_bit(TCCR0,TCCR0_WGM01);
#elif	TIMER0_MODE ==	CTC
	Clr_bit(TCCR0,TCCR0_WGM00);
	Set_bit(TCCR0,TCCR0_WGM01);
#elif	TIMER0_MODE ==	FAST_PWM
	Set_bit(TCCR0,TCCR0_WGM00);
	Set_bit(TCCR0,TCCR0_WGM01);
//	should implement function to Choose Fast PWM Settings
	Set_bit(TCCR0,TCCR0_COM01);
	Set_bit(TCCR0,TCCR0_COM00);
#else
#error	"Wrong TIMER0 MODE Configuration"
#endif
	/*Output compare match interrupt enable*/
#if	TIMER0_INT_STATE ==	ENABLED
	Set_bit(TIMSK,TIMSK_OCIE0);
#elif	TIMER0_INT_STATE == DISABLED
	Clr_bit(TIMSK,TIMSK_OCIE0);
#error	"Wrong TIMER0 Interrupt Configuration "
#endif
	/*PreScaler /8*/
#if	TIMER0_CLC ==	DISABLE_TIMER
	Clr_bit(TCCR0,TCCR0_CS00);
	Clr_bit(TCCR0,TCCR0_CS01);
	Clr_bit(TCCR0,TCCR0_CS02);
#elif TIMER0_CLC ==	PRESCALER0
	Set_bit(TCCR0,TCCR0_CS00);
	Clr_bit(TCCR0,TCCR0_CS01);
	Clr_bit(TCCR0,TCCR0_CS02);
#elif	TIMER0_CLC ==	PRESCALER8
	Clr_bit(TCCR0,TCCR0_CS00);
	Set_bit(TCCR0,TCCR0_CS01);
	Clr_bit(TCCR0,TCCR0_CS02);
#elif	TIMER0_CLC ==	PRESCALER64
	Set_bit(TCCR0,TCCR0_CS00);
	Set_bit(TCCR0,TCCR0_CS01);
	Clr_bit(TCCR0,TCCR0_CS02);
#elif	TIMER0_CLC	==	PRESCALER256
	Clr_bit(TCCR0,TCCR0_CS00);
	Clr_bit(TCCR0,TCCR0_CS01);
	Set_bit(TCCR0,TCCR0_CS02);
#elif	TIMER0_CLC	==	PRESCALER1024
	Set_bit(TCCR0,TCCR0_CS00);
	Clr_bit(TCCR0,TCCR0_CS01);
	Set_bit(TCCR0,TCCR0_CS02);
#elif	TIMER0_CLC	==	EXTERNAL_CLC_FALING_EDGE
	Clr_bit(TCCR0,TCCR0_CS00);
	Set_bit(TCCR0,TCCR0_CS01);
	Set_bit(TCCR0,TCCR0_CS02);
#elif	TIMER0_CLC	==	EXTERNAL_CLC_RISING_EDGE
	Set_bit(TCCR0,TCCR0_CS00);
	Set_bit(TCCR0,TCCR0_CS01);
	Set_bit(TCCR0,TCCR0_CS02);
#else
#error	"Wrong TIMER0 CLOCK Configuration"
#endif

}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8value){
	OCR0=Copy_u8value;
}

u8 TIMER0_u8setCallBack(void(*Copy_pvCallBack)(void)){
	u8 Local_u8State =OK;
	if(*Copy_pvCallBack!=NULL){
		Pv_TIMER0=Copy_pvCallBack;
	}else{
		Local_u8State=NOK;
	}

	return Local_u8State;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{if(Pv_TIMER0!=NULL){
	Pv_TIMER0();
}
else{

}
}
