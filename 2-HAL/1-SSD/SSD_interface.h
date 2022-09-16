/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     DIO                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_u8Anode   1
#define SSD_u8Cathode 0

typedef struct{
	u8 comman;
	u8 Port;
	u8 EnablePort;
	u8 EnaplePin;
}SSD;
u8 SSD_u8EnableSsd(SSD*SSD1);
u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD*SSD1);


#endif
