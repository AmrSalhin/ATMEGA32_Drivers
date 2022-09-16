/*
 * Timer_config.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Amr Salhen
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*Options
 *  1-NORMAL
 *  2-PWM
 *  3-CTC
 *  4-FAST_PWM
 */

#define  TIMER0_MODE		FAST_PWM

/*Options
 *  1-DISABLE_TIMER
 *  2-PRESCALER0
 *  3-PRESCALER8
 *  4-PRESCALER64
 *  5-PRESCALER256
 *  6-PRESCALER1024
 *  7-EXTERNAL_CLC_FALING_EDGE
 *  8-EXTERNAL_CLC_RISING_EDGE
 */
#define	TIMER0_CLC		PRESCALER64

/*Options
 * 1-DISABLED
 * 2-ENABLED
 */
#define TIMER0_INT_STATE    ENABLED


#endif /* TIMER_CONFIG_H_ */
