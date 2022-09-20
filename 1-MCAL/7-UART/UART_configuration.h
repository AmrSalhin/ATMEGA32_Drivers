/*
 * UART_configuration.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Amr Salhen
 */

#ifndef UART_CONFIGURATION_H_
#define UART_CONFIGURATION_H_

/*
 * Options
 * 	1-ENABLE
 * 	2-DISABLE
 */
#define	Receive_Complete_Interrupet		DISABLE
#define	Transmit_Complete_Interrupet	DISABLE
#define	Data_Register_Empty_Interrupet	DISABLE
#define	Double_Transmission_Speed		DISABLE
#define	Receiver_Enable					ENABLE
#define	Transmitter_Enable				ENABLE
/*
 * Options
 *	1- Five_bits
 * 	2- Six_bits
 *	3- Seven_bits
 *	4- Eight_bits
 *	5-	Nine_bits
 */
#define	Number_Of_Data_Bits				Eight_bits

/*
 * Options
 *1-Asynchronous
 *2-synchronous
 */
#define	USART_Mode_Select				Asynchronous
/*
 *Options
 *1-Even_Parity
 *2-Odd_Parity
 */
#define	Parity_Mode						Even_Parity
/*
 * Options
 * 1-One_bit
 * 2-Two_bits
 */
#define	Stop_Bit_Select					One_bit
/*
 * Options
 * 1-Falling_Edge
 * 2-Rising_Edge
 */
#define	Clock_Polarity					Falling_Edge


#endif /* UART_CONFIGURATION_H_ */
