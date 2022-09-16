/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     DIO                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "SSD_register.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

u8 SSD_u8EnableSsd(SSD*SSD1){
	u8 Local_u8ErrorState = 0;
	if(SSD1->comman==SSD_u8Anode){
		/* replace DIO_u8SetPortDirection after fixing the problem in SetPinDirection function*/
		DIO_u8SetPortDirection(SSD1->EnablePort,DIO_u8PORT_OUTPUT);
		DIO_u8SetPinValue(SSD1->EnablePort,SSD1->EnaplePin,DIO_u8PIN_HIGH);
	}else if(SSD1->comman==SSD_u8Cathode){
		/* replace DIO_u8SetPortDirection after fixing the problem in SetPinDirection function*/
		DIO_u8SetPortDirection(SSD1->EnablePort,DIO_u8PORT_OUTPUT);
		DIO_u8SetPinValue(SSD1->EnablePort,SSD1->EnaplePin,DIO_u8PIN_LOW);
	}else{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD*SSD1){
	u8 Local_u8ErrorState = 0;
	u8 Local_u8SevenSegArr[10] = {0b00000000,0b00000001,0b00000010,0b00000011,
			0b00000100,0b00000101,0b00000110,0b00000111,0b00010000,0b00010001};
DIO_u8SetPortDirection(SSD1->Port,DIO_u8PORT_OUTPUT);
DIO_u8SetPortValue(SSD1->Port,Copy_u8Number);

	return Local_u8ErrorState;
}
