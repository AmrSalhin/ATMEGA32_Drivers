/*
 * UART_interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Amr Salhen
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit();
void UART_voidSendData(u8 Copy_u8Data);
u8 UART_u8ReceiveData();


#endif /* UART_INTERFACE_H_ */
