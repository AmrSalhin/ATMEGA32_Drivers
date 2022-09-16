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







u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{

	u8 Local_u8ErrorState = 0;
	if(Copy_u8Pin<=7){
		if(Copy_u8Value==DIO_u8PIN_LOW){
			switch(Copy_u8Port){
			case DIO_u8PORTA: Clr_bit(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB: Clr_bit(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC: Clr_bit(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD: Clr_bit(PORTD,Copy_u8Pin);break;
			default:Local_u8ErrorState=1;
			}
		}else if(Copy_u8Value==DIO_u8PIN_HIGH){
			switch(Copy_u8Port){
			case DIO_u8PORTA: Set_bit(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB: Set_bit(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC: Set_bit(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD: Set_bit(PORTD,Copy_u8Pin);break;
			default:Local_u8ErrorState=1;
			}
		}else{
			Local_u8ErrorState=1;
		}
	}else{
		Local_u8ErrorState=1;
	}


	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{

	u8 Local_u8ErrorState = 0;
	switch(Copy_u8Port){
	case DIO_u8PORTA: PORTA=Copy_u8Value;break;
	case DIO_u8PORTB: PORTB=Copy_u8Value;break;
	case DIO_u8PORTC: PORTC=Copy_u8Value;break;
	case DIO_u8PORTD: PORTD=Copy_u8Value;break;
	default:Local_u8ErrorState=1;
	}


	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8* Copy_pu8Value)
{

	u8 Local_u8ErrorState = 0;
	if((Copy_pu8Value!=NULL) && (Copy_u8Pin<=7)){

		switch(Copy_u8Port){
		case DIO_u8PORTA: *Copy_pu8Value=Get_bit(PINA,Copy_u8Pin);break;
		case DIO_u8PORTB: *Copy_pu8Value=Get_bit(PINB,Copy_u8Pin);break;
		case DIO_u8PORTC: *Copy_pu8Value=Get_bit(PINC,Copy_u8Pin);break;
		case DIO_u8PORTD: *Copy_pu8Value=Get_bit(PIND,Copy_u8Pin);break;
		default:Local_u8ErrorState=1;
		}

	}else{
		Local_u8ErrorState=1;
	}
		return Local_u8ErrorState;

}









