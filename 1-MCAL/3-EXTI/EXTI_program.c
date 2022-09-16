/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     EXTI                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

/*Global Pointers to function*/
void(*EXTI_pvINT0Function)(void)=NULL;
void(*EXTI_pvINT1Function)(void)=NULL;
void(*EXTI_pvINT2Function)(void)=NULL;

void EXTI_voidInt0Init(void){

	/*Set sense control for INT0 to falling edge*/
#if  INT0_SENSE==LOW_LEVEL
	Clr_bit(MCUCR,MCUCR_ISC00);
	Clr_bit(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE==ON_CHNGE
	Set_bit(MCUCR,MCUCR_ISC00);
	Clr_bit(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE==FALLING_EDGE
	Clr_bit(MCUCR,MCUCR_ISC00);
	Set_bit(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE==RISING_EDGE
	Set_bit(MCUCR,MCUCR_ISC00);
	Set_bit(MCUCR,MCUCR_ISC01);
#else
#error "Wrong INT0 SENSE Configuration Option"
#endif

	/*CHECK Peripheral Interrupt ENABLE INITIAL STATE*/
#if INT0_INITIAL_STATE==ENABLED
	Set_bit(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE==DISABLED
	Clr_bit(GICR,GICR_INT0);
#else
	"WRONG INT0 Initial State"
#endif
}
void EXTI_voidInt1Init(void){
	/*Set INT1 Configuration Options*/
#if  INT1_SENSE==LOW_LEVEL
	Clr_bit(MCUCR,MCUCR_ISC10);
	Clr_bit(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE==ON_CHANGE
	Set_bit(MCUCR,MCUCR_ISC10);
	Clr_bit(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE==FALLING_EDGE
	Clr_bit(MCUCR,MCUCR_ISC10);
	Set_bit(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE==RISING_EDGE
	Set_bit(MCUCR,MCUCR_ISC10);
	Set_bit(MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT1 Configuration Option"

#endif
	/*Check Peripheral Interrupt Enable Initial State*/
#if INT1_INITIAL_STATE==ENABLED
	Set_bit(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE==DISABLED
	Clr_bit(GICR,GICR_INT1);
#else
#error "Wrong INT1 Initial State"
#endif

}
void EXTI_voidInt2Init(void){
	/*Set INT1 Configuration Options*/

#if INT1_SENSE==FALLING_EDGE
	Clr_bit(MCUCSR,MCUCSR_INT2);
#elif INT1_SENSE==RISING_EDGE
	Set_bit(MCUCSR,MCUCSR_INT2);
#else
#error "Wrong INT2 Configuration Option"
#endif
	/*Check Peripheral Interrupt Enable Initial State*/
#if INT1_INITIAL_STATE==ENABLED
	Set_bit(GICR,GICR_INT2);
#elif INT1_INITIAL_STATE==DISABLED
	Clr_bit(GICR,GICR_INT2);
#else
#error "Wrong INT2 Initial State"
#endif
}


u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense){

	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense){
	case LOW_LEVEL:
		Clr_bit(MCUCR,MCUCR_ISC00);
		Clr_bit(MCUCR,MCUCR_ISC01);
		break;
	case ON_CHANGE:
		Set_bit(MCUCR,MCUCR_ISC00);
		Clr_bit(MCUCR,MCUCR_ISC01);
		break;
	case FALLING_EDGE:
		Clr_bit(MCUCR,MCUCR_ISC00);
		Set_bit(MCUCR,MCUCR_ISC01);
		break;
	case RISING_EDGE:
		Set_bit(MCUCR,MCUCR_ISC00);
		Set_bit(MCUCR,MCUCR_ISC01);
		break;
	default:Local_u8ErrorState=NOK;break;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;
		switch(Copy_u8Sense){
		case LOW_LEVEL:
			Clr_bit(MCUCR,MCUCR_ISC10);
			Clr_bit(MCUCR,MCUCR_ISC11);
			break;
		case ON_CHANGE:
			Set_bit(MCUCR,MCUCR_ISC10);
			Clr_bit(MCUCR,MCUCR_ISC11);
			break;
		case FALLING_EDGE:
			Clr_bit(MCUCR,MCUCR_ISC10);
			Set_bit(MCUCR,MCUCR_ISC11);
			break;
		case RISING_EDGE:
			Set_bit(MCUCR,MCUCR_ISC10);
			Set_bit(MCUCR,MCUCR_ISC11);
			break;
		default:Local_u8ErrorState=NOK;break;
		}

		return Local_u8ErrorState;
}
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;
			switch(Copy_u8Sense){
			case FALLING_EDGE: Clr_bit(MCUCSR,MCUCSR_INT2);break;
			case RISING_EDGE:Set_bit(MCUCSR,MCUCSR_INT2);break;
			default:Local_u8ErrorState=NOK;break;
			}

			return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8Int){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Int){
	case INT0:Set_bit(GICR,GICR_INT0);break;
	case INT1:Set_bit(GICR,GICR_INT1);break;
	case INT2:Set_bit(GICR,GICR_INT2);break;
	default:Local_u8ErrorState=NOK;break;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8IntDisable(u8 Copy_u8Int){
	u8 Local_u8ErrorState=OK;
		switch(Copy_u8Int){
		case INT0:Clr_bit(GICR,GICR_INT0);break;
		case INT1:Clr_bit(GICR,GICR_INT1);break;
		case INT2:Clr_bit(GICR,GICR_INT2);break;
		default:Local_u8ErrorState=NOK;break;
		}

		return Local_u8ErrorState;
}


u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt0!=NULL){
		EXTI_pvINT0Function=Copy_pvInt0;
	}else{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt1!=NULL){
		EXTI_pvINT1Function=Copy_pvInt1;
	}else{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2)(void)){
	u8 Local_u8ErrorState=OK;
		if(Copy_pvInt2!=NULL){
			EXTI_pvINT2Function=Copy_pvInt2;
		}else{
			Local_u8ErrorState=NOK;
		}

		return Local_u8ErrorState;
}



void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{if(EXTI_pvINT0Function!=NULL){
	EXTI_pvINT0Function();
}
else{

}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	if(EXTI_pvINT1Function!=NULL){
		EXTI_pvINT1Function();
	}
	else{

	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	if(EXTI_pvINT2Function!=NULL){
		EXTI_pvINT2Function();
	}
	else{

	}
}



