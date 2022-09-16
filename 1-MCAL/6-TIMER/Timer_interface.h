/*
 * Timer_interface.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Amr Salhen
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidinit();
void TIMER0_voidSetCompMatchValue(u8 Copy_u8value);

void TIMER1_voidinit();
void TIMER1_voidSetICR(u16 Copy_u8Top);
void TIMER1_voidSetChannelACompMatchValue(u8 Copy_u8value);

u8 TIMER0_u8setCallBack(void(*Copy_pvCallBack)(void));


#endif /* TIMER_INTERFACE_H_ */
