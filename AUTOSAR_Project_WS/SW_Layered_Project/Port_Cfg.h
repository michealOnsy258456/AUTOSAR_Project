/*
 * Port_PBcfg.h
 *
 *  Created on: Mar 3, 2020
 *      Author: micheal_onsy
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION  	  (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for Set Pin Mode API */
#define PORT_SET_PIN_MODE_API                (STD_OFF)

/* Pre-compile option for presence of Port_SetPinDirection API*/
#define PORT_SET_PIN_DIRECTION_API                (STD_ON)

/* Number of the configured Dio Channels */
#define PORT_CONFIGURED_CHANNLES             (32U)

/* PORT Configured the Initial value to channels ID's  */
#define PORTA_PIN0_INIT_VALUE (initial_Low)
#define PORTA_PIN1_INIT_VALUE (initial_Low)
#define PORTA_PIN2_INIT_VALUE (initial_Low)
#define PORTA_PIN3_INIT_VALUE (initial_Low)
#define PORTA_PIN4_INIT_VALUE (initial_Low)
#define PORTA_PIN5_INIT_VALUE (initial_Low)
#define PORTA_PIN6_INIT_VALUE (initial_Low)
#define PORTA_PIN7_INIT_VALUE (initial_Low)
#define PORTB_PIN0_INIT_VALUE (initial_Low)
#define PORTB_PIN1_INIT_VALUE (initial_Low)
#define PORTB_PIN2_INIT_VALUE (initial_Low)
#define PORTB_PIN3_INIT_VALUE (initial_Low)
#define PORTB_PIN4_INIT_VALUE (initial_Low)
#define PORTB_PIN5_INIT_VALUE (initial_Low)
#define PORTB_PIN6_INIT_VALUE (initial_Low)
#define PORTB_PIN7_INIT_VALUE (initial_Low)
#define PORTC_PIN0_INIT_VALUE (initial_Low)
#define PORTC_PIN1_INIT_VALUE (initial_Low)
#define PORTC_PIN2_INIT_VALUE (initial_Low)
#define PORTC_PIN3_INIT_VALUE (initial_Low)
#define PORTC_PIN4_INIT_VALUE (initial_Low)
#define PORTC_PIN5_INIT_VALUE (initial_Low)
#define PORTC_PIN6_INIT_VALUE (initial_Low)
#define PORTC_PIN7_INIT_VALUE (initial_Low)
#define PORTD_PIN0_INIT_VALUE (initial_Low)
#define PORTD_PIN1_INIT_VALUE (initial_Low)
#define PORTD_PIN2_INIT_VALUE (initial_Low)
#define PORTD_PIN3_INIT_VALUE (initial_Low)
#define PORTD_PIN4_INIT_VALUE (initial_Low)
#define PORTD_PIN5_INIT_VALUE (initial_Low)
#define PORTD_PIN6_INIT_VALUE (initial_Low)
#define PORTD_PIN7_INIT_VALUE (initial_Low)

/* PORT Configured Channel ID's */
#define	PORTA_PIN0_DIRECTION (PORT_PIN_IN)
#define PORTA_PIN1_DIRECTION (PORT_PIN_IN)
#define PORTA_PIN2_DIRECTION (PORT_PIN_IN)
#define PORTA_PIN3_DIRECTION (PORT_PIN_IN)
#define PORTA_PIN4_DIRECTION (PORT_PIN_IN)
#define PORTA_PIN5_DIRECTION (PORT_PIN_IN)
#define PORTA_PIN6_DIRECTION (PORT_PIN_IN)
#define PORTA_PIN7_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN0_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN1_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN2_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN3_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN4_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN5_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN6_DIRECTION (PORT_PIN_IN)
#define PORTB_PIN7_DIRECTION (PORT_PIN_IN)
#define PORTC_PIN0_DIRECTION (PORT_PIN_IN)
#define PORTC_PIN1_DIRECTION (PORT_PIN_IN)
#define PORTC_PIN2_DIRECTION (PORT_PIN_IN)
#define PORTC_PIN3_DIRECTION (PORT_PIN_IN)
#define PORTC_PIN4_DIRECTION (PORT_PIN_IN)
#define PORTC_PIN5_DIRECTION (PORT_PIN_OUT)
#define PORTC_PIN6_DIRECTION (PORT_PIN_IN)
#define PORTC_PIN7_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN0_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN1_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN2_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN3_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN4_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN5_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN6_DIRECTION (PORT_PIN_IN)
#define PORTD_PIN7_DIRECTION (PORT_PIN_IN)



/************************************************************/
/* Description : Modes for pins                         */
#define PORTA_PIN0_Mode (Disable_Pullup)
#define PORTA_PIN1_Mode (Disable_Pullup)
#define PORTA_PIN2_Mode (Disable_Pullup)
#define PORTA_PIN3_Mode (Disable_Pullup)
#define PORTA_PIN4_Mode (Disable_Pullup)
#define PORTA_PIN5_Mode (Disable_Pullup)
#define PORTA_PIN6_Mode (Disable_Pullup)
#define PORTA_PIN7_Mode (Disable_Pullup)
#define PORTB_PIN0_Mode (Disable_Pullup)
#define PORTB_PIN1_Mode (Disable_Pullup)
#define PORTB_PIN2_Mode (Disable_Pullup)
#define PORTB_PIN3_Mode (Disable_Pullup)
#define PORTB_PIN4_Mode (Disable_Pullup)
#define PORTB_PIN5_Mode (Disable_Pullup)
#define PORTB_PIN6_Mode (Disable_Pullup)
#define PORTB_PIN7_Mode (Disable_Pullup)
#define PORTC_PIN0_Mode (Disable_Pullup)
#define PORTC_PIN1_Mode (Disable_Pullup)
#define PORTC_PIN2_Mode (Disable_Pullup)
#define PORTC_PIN3_Mode (Disable_Pullup)
#define PORTC_PIN4_Mode (Disable_Pullup)
#define PORTC_PIN5_Mode (Disable_Pullup)
#define PORTC_PIN6_Mode (Disable_Pullup)
#define PORTC_PIN7_Mode (Disable_Pullup)
#define PORTD_PIN0_Mode (Disable_Pullup)
#define PORTD_PIN1_Mode (Disable_Pullup)
#define PORTD_PIN2_Mode (Disable_Pullup)
#define PORTD_PIN3_Mode (Disable_Pullup)
#define PORTD_PIN4_Mode (Disable_Pullup)
#define PORTD_PIN5_Mode (Disable_Pullup)
#define PORTD_PIN6_Mode (Disable_Pullup)
#define PORTD_PIN7_Mode (Disable_Pullup)



#endif /* PORT_CFG_H_ */
