/*
 * SPI_program.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Amr Salhen
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_configuration.h"
#include "SPI_private.h"
#include "SPI_registers.h"

void SPI_voidMasterInit(){

	/*Master initialization*/
	Set_bit(SPCR,SPCR_MSTR);

	/*Clock prescaler divided by 16*/
	Set_bit(SPCR,SPCR_SPR0);
	Clr_bit(SPCR,SPCR_SPR1);
	Clr_bit(SPSR,SPSR_SPI2X);

	/*SPI Enable*/
	Set_bit(SPCR,SPCR_SPE);


}
void SPI_voidSlaveInit(){

	/*Master initialization*/
	Clr_bit(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	Set_bit(SPCR,SPCR_SPE);
}
u8	SPI_u8Trancieve(u8 Copy_u8Data){

	SPDR = Copy_u8Data;

	while(Get_bit(SPSR,SPSR_SPIF) == 0);

	return SPDR;

}
