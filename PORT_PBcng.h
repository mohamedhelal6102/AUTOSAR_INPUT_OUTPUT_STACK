/*
 * PORT_PBcng.h
 *
 * Created: 7/19/2023 10:27:53 PM
 *  Author: Mohamed Helal
 */ 
/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mohamed Helal	***********************/
/*****************		Layer:	I/0 DRIVERS		***********************/
/*****************		SWC:	PORT			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/


#ifndef PORT_PBCNG_H_
#define PORT_PBCNG_H_

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                STD_ON

/* Configured Port ID's  */
#define PORT_A_NUM                           (Port_IDType)0 /* PORTA */
#define PORT_B_NUM                           (Port_IDType)1 /* PORTB */
#define PORT_C_NUM                           (Port_IDType)2 /* PORTC */
#define PORT_D_NUM                           (Port_IDType)3 /* PORTD */

/* Configured Channel ID's */
#define PORT_A_PIN_0                        (Port_PinType)0
#define PORT_A_PIN_1                        (Port_PinType)1
#define PORT_A_PIN_2                        (Port_PinType)2
#define PORT_A_PIN_3                        (Port_PinType)3
#define PORT_A_PIN_4                        (Port_PinType)4
#define PORT_A_PIN_5                        (Port_PinType)5
#define PORT_A_PIN_6                        (Port_PinType)6
#define PORT_A_PIN_7                        (Port_PinType)7

#define PORT_B_PIN_0                        (Port_PinType)0
#define PORT_B_PIN_1                        (Port_PinType)1
#define PORT_B_PIN_2                        (Port_PinType)2
#define PORT_B_PIN_3                        (Port_PinType)3
#define PORT_B_PIN_4                        (Port_PinType)4
#define PORT_B_PIN_5                        (Port_PinType)5
#define PORT_B_PIN_6                        (Port_PinType)6
#define PORT_B_PIN_7                        (Port_PinType)7

#define PORT_C_PIN_0                        (Port_PinType)0
#define PORT_C_PIN_1                        (Port_PinType)1
#define PORT_C_PIN_2                        (Port_PinType)2
#define PORT_C_PIN_3                        (Port_PinType)3
#define PORT_C_PIN_4                        (Port_PinType)4
#define PORT_C_PIN_5                        (Port_PinType)5
#define PORT_C_PIN_6                        (Port_PinType)6
#define PORT_C_PIN_7                        (Port_PinType)7

#define PORT_D_PIN_0                        (Port_PinType)0
#define PORT_D_PIN_1                        (Port_PinType)1
#define PORT_D_PIN_2                        (Port_PinType)2
#define PORT_D_PIN_3                        (Port_PinType)3
#define PORT_D_PIN_4                        (Port_PinType)4
#define PORT_D_PIN_5                        (Port_PinType)5
#define PORT_D_PIN_6                        (Port_PinType)6
#define PORT_D_PIN_7                        (Port_PinType)7

// Mode ID
#define DIO                 (Port_PinModeType)0
#define ADC                 (Port_PinModeType)1
#define PWM                 (Port_PinModeType)2
#define GPT                 (Port_PinModeType)3

// Pin Mode
#define PORT_A_PIN_0_MODE           DIO
#define PORT_A_PIN_1_MODE           DIO
#define PORT_A_PIN_2_MODE           DIO
#define PORT_A_PIN_3_MODE           DIO
#define PORT_A_PIN_4_MODE           DIO
#define PORT_A_PIN_5_MODE           DIO
#define PORT_A_PIN_6_MODE           DIO
#define PORT_A_PIN_7_MODE           DIO

#define PORT_B_PIN_0_MODE           DIO
#define PORT_B_PIN_1_MODE           DIO
#define PORT_B_PIN_2_MODE           DIO
#define PORT_B_PIN_3_MODE           DIO
#define PORT_B_PIN_4_MODE           DIO
#define PORT_B_PIN_5_MODE           DIO
#define PORT_B_PIN_6_MODE           DIO
#define PORT_B_PIN_7_MODE           DIO

#define PORT_C_PIN_0_MODE           DIO
#define PORT_C_PIN_1_MODE           DIO
#define PORT_C_PIN_2_MODE           DIO
#define PORT_C_PIN_3_MODE           DIO
#define PORT_C_PIN_4_MODE           DIO
#define PORT_C_PIN_5_MODE           DIO
#define PORT_C_PIN_6_MODE           DIO
#define PORT_C_PIN_7_MODE           DIO

#define PORT_D_PIN_0_MODE           DIO
#define PORT_D_PIN_1_MODE           DIO
#define PORT_D_PIN_2_MODE           DIO
#define PORT_D_PIN_3_MODE           DIO
#define PORT_D_PIN_4_MODE           DIO
#define PORT_D_PIN_5_MODE           DIO
#define PORT_D_PIN_6_MODE           DIO
#define PORT_D_PIN_7_MODE           DIO

// Pin direction
#define PORT_A_PIN_0_DIR            INPUT
#define PORT_A_PIN_1_DIR            INPUT
#define PORT_A_PIN_2_DIR            INPUT
#define PORT_A_PIN_3_DIR            INPUT
#define PORT_A_PIN_4_DIR            INPUT
#define PORT_A_PIN_5_DIR            INPUT
#define PORT_A_PIN_6_DIR            INPUT
#define PORT_A_PIN_7_DIR            INPUT

#define PORT_B_PIN_0_DIR            INPUT
#define PORT_B_PIN_1_DIR            INPUT
#define PORT_B_PIN_2_DIR            INPUT
#define PORT_B_PIN_3_DIR            INPUT
#define PORT_B_PIN_4_DIR            INPUT
#define PORT_B_PIN_5_DIR            INPUT
#define PORT_B_PIN_6_DIR            INPUT
#define PORT_B_PIN_7_DIR            INPUT

#define PORT_C_PIN_0_DIR            INPUT
#define PORT_C_PIN_1_DIR            INPUT
#define PORT_C_PIN_2_DIR            INPUT
#define PORT_C_PIN_3_DIR            INPUT
#define PORT_C_PIN_4_DIR            INPUT
#define PORT_C_PIN_5_DIR            INPUT 
#define PORT_C_PIN_6_DIR            INPUT
#define PORT_C_PIN_7_DIR            INPUT

#define PORT_D_PIN_0_DIR            INPUT
#define PORT_D_PIN_1_DIR            INPUT
#define PORT_D_PIN_2_DIR            INPUT 
#define PORT_D_PIN_3_DIR            INPUT
#define PORT_D_PIN_4_DIR            INPUT
#define PORT_D_PIN_5_DIR            INPUT
#define PORT_D_PIN_6_DIR            INPUT
#define PORT_D_PIN_7_DIR            INPUT

// Pin level.
#define PORT_A_PIN_0_LEVEL          STD_LOW
#define PORT_A_PIN_1_LEVEL          STD_LOW
#define PORT_A_PIN_2_LEVEL          STD_LOW
#define PORT_A_PIN_3_LEVEL          STD_LOW
#define PORT_A_PIN_4_LEVEL          STD_LOW
#define PORT_A_PIN_5_LEVEL          STD_LOW
#define PORT_A_PIN_6_LEVEL          STD_LOW
#define PORT_A_PIN_7_LEVEL          STD_LOW

#define PORT_B_PIN_0_LEVEL          STD_LOW
#define PORT_B_PIN_1_LEVEL          STD_LOW
#define PORT_B_PIN_2_LEVEL          STD_LOW
#define PORT_B_PIN_3_LEVEL          STD_LOW
#define PORT_B_PIN_4_LEVEL          STD_LOW
#define PORT_B_PIN_5_LEVEL          STD_LOW
#define PORT_B_PIN_6_LEVEL          STD_LOW
#define PORT_B_PIN_7_LEVEL          STD_LOW

#define PORT_C_PIN_0_LEVEL          STD_LOW
#define PORT_C_PIN_1_LEVEL          STD_LOW
#define PORT_C_PIN_2_LEVEL          STD_LOW
#define PORT_C_PIN_3_LEVEL          STD_LOW
#define PORT_C_PIN_4_LEVEL          STD_LOW
#define PORT_C_PIN_5_LEVEL          STD_LOW
#define PORT_C_PIN_6_LEVEL          STD_LOW
#define PORT_C_PIN_7_LEVEL          STD_LOW

#define PORT_D_PIN_0_LEVEL          STD_LOW
#define PORT_D_PIN_1_LEVEL          STD_LOW
#define PORT_D_PIN_2_LEVEL          STD_LOW // BUTTON_PIN_NUM
#define PORT_D_PIN_3_LEVEL          STD_LOW
#define PORT_D_PIN_4_LEVEL          STD_LOW
#define PORT_D_PIN_5_LEVEL          STD_LOW
#define PORT_D_PIN_6_LEVEL          STD_LOW
#define PORT_D_PIN_7_LEVEL          STD_LOW

// Pin PullUp.
#define PORT_A_PIN_0_PullUp         STD_LOW
#define PORT_A_PIN_1_PullUp         STD_LOW
#define PORT_A_PIN_2_PullUp         STD_LOW
#define PORT_A_PIN_3_PullUp         STD_LOW
#define PORT_A_PIN_4_PullUp         STD_LOW
#define PORT_A_PIN_5_PullUp         STD_LOW
#define PORT_A_PIN_6_PullUp         STD_LOW
#define PORT_A_PIN_7_PullUp         STD_LOW

#define PORT_B_PIN_0_PullUp         STD_LOW
#define PORT_B_PIN_1_PullUp         STD_LOW
#define PORT_B_PIN_2_PullUp         STD_LOW
#define PORT_B_PIN_3_PullUp         STD_LOW
#define PORT_B_PIN_4_PullUp         STD_LOW
#define PORT_B_PIN_5_PullUp         STD_LOW
#define PORT_B_PIN_6_PullUp         STD_LOW
#define PORT_B_PIN_7_PullUp         STD_LOW

#define PORT_C_PIN_0_PullUp         STD_LOW
#define PORT_C_PIN_1_PullUp         STD_LOW
#define PORT_C_PIN_2_PullUp         STD_LOW
#define PORT_C_PIN_3_PullUp         STD_LOW
#define PORT_C_PIN_4_PullUp         STD_LOW
#define PORT_C_PIN_5_PullUp         STD_LOW 
#define PORT_C_PIN_6_PullUp         STD_LOW
#define PORT_C_PIN_7_PullUp         STD_LOW

#define PORT_D_PIN_0_PullUp         STD_LOW
#define PORT_D_PIN_1_PullUp         STD_LOW
#define PORT_D_PIN_2_PullUp         STD_LOW
#define PORT_D_PIN_3_PullUp         STD_LOW
#define PORT_D_PIN_4_PullUp         STD_LOW
#define PORT_D_PIN_5_PullUp         STD_LOW
#define PORT_D_PIN_6_PullUp         STD_LOW
#define PORT_D_PIN_7_PullUp         STD_LOW

// Pin change direction.
#define PORT_A_PIN_0_DIR_CHANG         STD_OFF
#define PORT_A_PIN_1_DIR_CHANG         STD_OFF
#define PORT_A_PIN_2_DIR_CHANG         STD_OFF
#define PORT_A_PIN_3_DIR_CHANG         STD_OFF
#define PORT_A_PIN_4_DIR_CHANG         STD_OFF
#define PORT_A_PIN_5_DIR_CHANG         STD_OFF
#define PORT_A_PIN_6_DIR_CHANG         STD_OFF
#define PORT_A_PIN_7_DIR_CHANG         STD_OFF

#define PORT_B_PIN_0_DIR_CHANG         STD_OFF
#define PORT_B_PIN_1_DIR_CHANG         STD_OFF
#define PORT_B_PIN_2_DIR_CHANG         STD_OFF
#define PORT_B_PIN_3_DIR_CHANG         STD_OFF
#define PORT_B_PIN_4_DIR_CHANG         STD_OFF
#define PORT_B_PIN_5_DIR_CHANG         STD_OFF
#define PORT_B_PIN_6_DIR_CHANG         STD_OFF
#define PORT_B_PIN_7_DIR_CHANG         STD_OFF

#define PORT_C_PIN_0_DIR_CHANG         STD_OFF
#define PORT_C_PIN_1_DIR_CHANG         STD_OFF
#define PORT_C_PIN_2_DIR_CHANG         STD_OFF
#define PORT_C_PIN_3_DIR_CHANG         STD_OFF
#define PORT_C_PIN_4_DIR_CHANG         STD_OFF
#define PORT_C_PIN_5_DIR_CHANG         STD_OFF 
#define PORT_C_PIN_6_DIR_CHANG         STD_OFF
#define PORT_C_PIN_7_DIR_CHANG         STD_OFF

#define PORT_D_PIN_0_DIR_CHANG         STD_OFF
#define PORT_D_PIN_1_DIR_CHANG         STD_OFF
#define PORT_D_PIN_2_DIR_CHANG         STD_OFF 
#define PORT_D_PIN_3_DIR_CHANG         STD_OFF
#define PORT_D_PIN_4_DIR_CHANG         STD_OFF
#define PORT_D_PIN_5_DIR_CHANG         STD_OFF
#define PORT_D_PIN_6_DIR_CHANG         STD_OFF
#define PORT_D_PIN_7_DIR_CHANG         STD_OFF

// Pin mode change.
#define PORT_A_PIN_0_MODE_CHANG         STD_OFF
#define PORT_A_PIN_1_MODE_CHANG         STD_OFF
#define PORT_A_PIN_2_MODE_CHANG         STD_OFF
#define PORT_A_PIN_3_MODE_CHANG         STD_OFF
#define PORT_A_PIN_4_MODE_CHANG         STD_OFF
#define PORT_A_PIN_5_MODE_CHANG         STD_OFF
#define PORT_A_PIN_6_MODE_CHANG         STD_OFF
#define PORT_A_PIN_7_MODE_CHANG         STD_OFF

#define PORT_B_PIN_0_MODE_CHANG         STD_OFF
#define PORT_B_PIN_1_MODE_CHANG         STD_OFF
#define PORT_B_PIN_2_MODE_CHANG         STD_OFF
#define PORT_B_PIN_3_MODE_CHANG         STD_OFF
#define PORT_B_PIN_4_MODE_CHANG         STD_OFF
#define PORT_B_PIN_5_MODE_CHANG         STD_OFF
#define PORT_B_PIN_6_MODE_CHANG         STD_OFF
#define PORT_B_PIN_7_MODE_CHANG         STD_OFF

#define PORT_C_PIN_0_MODE_CHANG         STD_OFF
#define PORT_C_PIN_1_MODE_CHANG         STD_OFF
#define PORT_C_PIN_2_MODE_CHANG         STD_OFF
#define PORT_C_PIN_3_MODE_CHANG         STD_OFF
#define PORT_C_PIN_4_MODE_CHANG         STD_OFF
#define PORT_C_PIN_5_MODE_CHANG         STD_OFF 
#define PORT_C_PIN_6_MODE_CHANG         STD_OFF
#define PORT_C_PIN_7_MODE_CHANG         STD_OFF

#define PORT_D_PIN_0_MODE_CHANG         STD_OFF
#define PORT_D_PIN_1_MODE_CHANG         STD_OFF
#define PORT_D_PIN_2_MODE_CHANG         STD_OFF 
#define PORT_D_PIN_3_MODE_CHANG         STD_OFF
#define PORT_D_PIN_4_MODE_CHANG         STD_OFF
#define PORT_D_PIN_5_MODE_CHANG         STD_OFF
#define PORT_D_PIN_6_MODE_CHANG         STD_OFF
#define PORT_D_PIN_7_MODE_CHANG         STD_OFF

// Pin mode type

#define DIO_MODE                        0
#define ADC_MODE                        1
#define SPI_MODE                        2
#define UART_MODE                       3
#define TIMER_MODE                      4
#define I2C_MODE                        5

// Pin mode.
#define PORT_A_PIN_0_MODE         DIO_MODE
#define PORT_A_PIN_1_MODE         DIO_MODE
#define PORT_A_PIN_2_MODE         DIO_MODE
#define PORT_A_PIN_3_MODE         DIO_MODE
#define PORT_A_PIN_4_MODE         DIO_MODE
#define PORT_A_PIN_5_MODE         DIO_MODE
#define PORT_A_PIN_6_MODE         DIO_MODE
#define PORT_A_PIN_7_MODE         DIO_MODE

#define PORT_B_PIN_0_MODE         DIO_MODE
#define PORT_B_PIN_1_MODE         DIO_MODE
#define PORT_B_PIN_2_MODE         DIO_MODE
#define PORT_B_PIN_3_MODE         DIO_MODE
#define PORT_B_PIN_4_MODE         DIO_MODE
#define PORT_B_PIN_5_MODE         DIO_MODE
#define PORT_B_PIN_6_MODE         DIO_MODE
#define PORT_B_PIN_7_MODE         DIO_MODE

#define PORT_C_PIN_0_MODE         DIO_MODE
#define PORT_C_PIN_1_MODE         DIO_MODE
#define PORT_C_PIN_2_MODE         DIO_MODE
#define PORT_C_PIN_3_MODE         DIO_MODE
#define PORT_C_PIN_4_MODE         DIO_MODE
#define PORT_C_PIN_5_MODE         DIO_MODE 
#define PORT_C_PIN_6_MODE         DIO_MODE
#define PORT_C_PIN_7_MODE         DIO_MODE

#define PORT_D_PIN_0_MODE         DIO_MODE
#define PORT_D_PIN_1_MODE         DIO_MODE
#define PORT_D_PIN_2_MODE         DIO_MODE 
#define PORT_D_PIN_3_MODE         DIO_MODE
#define PORT_D_PIN_4_MODE         DIO_MODE
#define PORT_D_PIN_5_MODE         DIO_MODE
#define PORT_D_PIN_6_MODE         DIO_MODE
#define PORT_D_PIN_7_MODE         DIO_MODE




#endif /* PORT_PBCNG_H_ */