/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     GIE                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"
#include "GIE_interface.h"




void GIE_voidEnable(void){
	Set_bit(SREG,SREG_I);
}

void GIE_voidDisable(void){
	Clr_bit(SREG,SREG_I);
}




