/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     DIO                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidIni(void);
void CLCD_voidSendString(const char* Copy_pcString);
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidWriteSpecialCharacter(u8* Copy_puPattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidSendNumber(u32 Copy_u32Number);



#endif
