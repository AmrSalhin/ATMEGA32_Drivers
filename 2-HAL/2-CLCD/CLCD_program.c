/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   HAL                **************/
/*******************     SWC:     CLCD                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"


void CLCD_voidSendCommand(u8 Copy_u8Command){
	/*Set RS pin to low*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW Pin to LOW but it is connected to ground by default in my kit
Set Data Pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);


}

void CLCD_voidSendData(u8 Copy_u8Data){

	/*Set RS pin to HIGH*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	//	Set RW Pin to LOW but it is connected to ground by default in my kit
	//Set Data Pins
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);


}

void CLCD_voidIni(void){
	/*Wait for more than 30ms*/
	_delay_ms(45);
	/*set number of lines and font size*/
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00111000);
	/*Display ON,disable cursor,no blinking*/
	CLCD_voidSendCommand(0b00001100);
	/*Display Clear*/
	CLCD_voidSendCommand(1);



}

void CLCD_voidSendString(const char* Copy_pcString){
	u8 Local_u8Counter=0;

	while(Copy_pcString[Local_u8Counter]!='\0'){
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos){
	u8 Local_u8Address;
	if(Copy_u8XPos==0){

		Local_u8Address=Copy_u8YPos;

	}else if(Copy_u8XPos==1){

		Local_u8Address=Copy_u8YPos+0x40;
	}else if(Copy_u8XPos==2){
		Local_u8Address=Copy_u8YPos+0x14;
	}else if(Copy_u8XPos==3){
		Local_u8Address=Copy_u8YPos+0x54;
	}

	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_puPattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos){

	u8 Local_u8CGRamAddress=0,Local_u8Iterator;
	/*calculate the CGRam address*/
	Local_u8CGRamAddress=Copy_u8PatternNumber*8;
	/*send CGRam Address Command*/
	CLCD_voidSendCommand(Local_u8CGRamAddress+64);
	/*write the pattern in CGRam*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
		CLCD_voidSendData(Copy_puPattern[Local_u8Iterator]);

	}
	/*Go back to DDRam*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display the pattern*/
	CLCD_voidSendData(Copy_u8PatternNumber);

}

void CLCD_voidSendNumber(u32 Copy_u32Number){
	u8 Local_u8Counter;
	char Local_charNumber[10]={0};
	for(Local_u8Counter=0;Copy_u32Number>0;Local_u8Counter++){
		//Reminder+'0'=ASCI value of the number EX:255%10=5
		Local_charNumber[Local_u8Counter]=Copy_u32Number%10+'0';
		//clear stored number EX:255/10=25
		Copy_u32Number=Copy_u32Number/10;
	}
	u8 Local_u8DigitsNumber=Local_u8Counter-1;
	Local_u8Counter=0;
	//Reversing the order and Send the String
	while(Local_charNumber[Local_u8Counter]!='\0'){
		CLCD_voidSendData(Local_charNumber[Local_u8DigitsNumber]);
		Local_u8DigitsNumber--;
		Local_u8Counter++;
	}
}
