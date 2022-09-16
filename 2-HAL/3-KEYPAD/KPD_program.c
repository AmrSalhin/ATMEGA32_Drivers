/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     KPD                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/

#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"KPD_config.h"
#include"KPD_interface.h"
#include"KPD_private.h"

u8 KPD_u8GetPressedKey(void){
u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY,Local_u8ColumnIndex,Local_u8RowIndex,Local_u8PinState;
static u8 Local_u8ColumnArr[COLUMNS_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
static u8 Loca_u8RowARR[ROWS_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
static u8 Local_u8KPDArr[COLUMNS_NUM][ROWS_NUM]=KPD_ARR;
for(Local_u8ColumnIndex=0;Local_u8ColumnIndex<COLUMNS_NUM;Local_u8ColumnIndex++){
	/*Activate Current Column*/
	DIO_u8SetPinValue(KPD_COLUMNS_PORT,Local_u8ColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);
	for(Local_u8RowIndex=0;Local_u8RowIndex<ROWS_NUM;Local_u8RowIndex++){
/*Read The Current Row*/
		DIO_u8GetPinValue(KPD_ROWS_PORT,Loca_u8RowARR[Local_u8RowIndex],&Local_u8PinState);

		/*Check if switch is pressed*/
		if(DIO_u8PIN_LOW==Local_u8PinState){
			Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
			while(DIO_u8PIN_LOW==Local_u8PinState){
				/*Polling until the key is released*/
				DIO_u8GetPinValue(KPD_ROWS_PORT,Loca_u8RowARR[Local_u8RowIndex],&Local_u8PinState);
			}
			return Local_u8PressedKey;
		}

	}
	/*DeActivate Current Column*/
	DIO_u8SetPinValue(KPD_COLUMNS_PORT,Local_u8ColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);
}


return Local_u8PressedKey;
}

