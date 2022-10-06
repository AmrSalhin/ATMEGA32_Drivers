/*
 * SPI_registers.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Amr Salhen
 */

#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

#define SPDR	*((volatile u8*)0x2F)		/*SPI Data Register*/

#define SPSR	*((volatile u8*)0x2E)		/*SPI Status Register*/
#define SPSR_SPIF		7					/*SPI interrupt flag*/
#define SPSR_SPI2X		0					/*Prescaler bit 2*/


#define SPCR	*((volatile u8*)0x2D)		/*SPI Control Register*/
#define SPCR_SPE		6					/*SPI Enable*/
#define SPCR_MSTR		4					/*Master bit*/
#define SPCR_SPR1		1					/*Prescaler bit 1*/
#define SPCR_SPR0		0					/*Prescaler bit 0*/


#endif /* SPI_REGISTERS_H_ */
