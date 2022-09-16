/*******************************************************************/
/*******************************************************************/
/*******************     Author:  Amr Ahmed           **************/
/*******************     Layer:   MCAL                **************/
/*******************     SWC:     EXTI                 **************/
/*******************     Version: 1.00                **************/
/*******************************************************************/
/*******************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONDIG_H_

/*Options
 *  1-Low level
 *  2-On change
 *  3-Falling Edge
 *  4-Rising Edge
 */
#define INT0_SENSE    FALLING_EDGE
#define INT1_SENSE    FALLING_EDGE

/*Options
 *  1-Falling Edge
 *  2-Rising Edge
 */
#define INT2_SENSE    FALLING_EDGE

/*Options
 *  1-ENABLED
 *  2-DISABLED
 */
#define INT0_INITIAL_STATE    ENABLED
#define INT1_INITIAL_STATE    ENABLED
#define INT2_INITIAL_STATE    DISABLED



#endif
