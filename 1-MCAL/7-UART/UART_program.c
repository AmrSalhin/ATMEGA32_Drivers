/*
 * UART.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Amr Salhen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_register.h"
#include "UART_interface.h"
#include "UART_configuration.h"
#include "UART_private.h"

void UART_voidInit(){
	u8 Local_u8RegisterValue;
	//Number Of Stop bits
#if		Stop_Bit_Select ==	One_bit
	Clr_bit(Local_u8RegisterValue,UCSRC_USBS);
#elif 	Stop_Bit_Select == Two_bits
	Set_bit(Local_u8RegisterValue,UCSRC_USBS);
#else
#error	"Wrong Configuration"
#endif
	//Parity bit mode selection
#if		Parity_Mode ==	DISABLE
	Clr_bit(Local_u8RegisterValue,UCSRC_UPM0);
	Clr_bit(Local_u8RegisterValue,UCSRC_UPM1);
#elif 	Parity_Mode == Even_Parity
	Clr_bit(Local_u8RegisterValue,UCSRC_UPM0);
	Set_bit(Local_u8RegisterValue,UCSRC_UPM1);
#elif	Parity_Mode == Odd_Parity
	Set_bit(Local_u8RegisterValue,UCSRC_UPM0);
	Set_bit(Local_u8RegisterValue,UCSRC_UPM1);
#else
#error	"Wrong Configuration"
#endif
	// USART Mode Selection
#if		USART_Mode_Select ==	Asynchronous
	Clr_bit(Local_u8RegisterValue,UCSRC_UMSEL);
#elif 	USART_Mode_Select ==	Asynchronous
	Set_bit(Local_u8RegisterValue,UCSRC_UMSEL);
#else
#error	"Wrong Configuration"
#endif
	//Number Of Data bits
#if		Number_Of_Data_Bits ==	Five_bits
	Clr_bit(Local_u8RegisterValue,UCSRC_UCSZ0);
	Clr_bit(Local_u8RegisterValue,UCSRC_UCSZ1);
	Clr_bit(UCSRB,UCSRB_UCSZ2);

#elif 	Number_Of_Data_Bits ==	Six_bits
	Set_bit(Local_u8RegisterValue,UCSRC_UCSZ0);
	Clr_bit(Local_u8RegisterValue,UCSRC_UCSZ1);
	Clr_bit(UCSRB,UCSRB_UCSZ2);
#elif	Number_Of_Data_Bits ==	Seven_bits
	Clr_bit(Local_u8RegisterValue,UCSRC_UCSZ0);
	Set_bit(Local_u8RegisterValue,UCSRC_UCSZ1);
	Clr_bit(UCSRB,UCSRB_UCSZ2);
#elif	Number_Of_Data_Bits ==	Eight_bits
	Set_bit(Local_u8RegisterValue,UCSRC_UCSZ0);
	Set_bit(Local_u8RegisterValue,UCSRC_UCSZ1);
	Clr_bit(UCSRB,UCSRB_UCSZ2);
#elif	Number_Of_Data_Bits ==	Nine_bits
	Set_bit(Local_u8RegisterValue,UCSRC_UCSZ0);
	Set_bit(Local_u8RegisterValue,UCSRC_UCSZ1);
	Set_bit(UCSRB,UCSRB_UCSZ2);
#else
#error	"Wrong in Data bits Number Configuration"
#endif

#if		Clock_Polarity ==	Falling_Edge
	Clr_bit(Local_u8RegisterValue,UCSRC_UCPOL);
#elif 	Clock_Polarity ==	Rising_Edge
	Set_bit(Local_u8RegisterValue,UCSRC_UCPOL);
#else
#error	"Wrong Clock Configuration"
#endif
	Set_bit(Local_u8RegisterValue,UCSRC_URSEL);
	UCSRC = Local_u8RegisterValue;

	//Baud rate 9600
	UBRRL=51;
	//Receiver enable
	UCSRB = Set_bit(UCSRB,UCSRB_RXEN);
	//Transmitter enable
	UCSRB = Set_bit(UCSRB,UCSRB_TXEN);
}
void UART_voidSendData(u8 Copy_u8Data){
	while(Get_bit(UCSRA,UCSRA_UDRE) == 0);
	UDR	= Copy_u8Data;
}
u8 UART_u8ReceiveData(){
	while(Get_bit(UCSRA,UCSRA_RXC) == 0);
	return UDR;
}
void UART_voidBaudRateSelect(u16 Local_u16BaudRate){
	if(Local_u16BaudRate <= 1041){
	Clr_bit(Local_u16BaudRate,15);
	UBRRL = Local_u16BaudRate;
	}
}
