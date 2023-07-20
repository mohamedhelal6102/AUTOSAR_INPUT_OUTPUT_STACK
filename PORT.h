/*
 * PORT.h
 *
 * Created: 7/19/2023 6:29:33 PM
 *  Author: MOHAMED HELAL
 */ 
/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mohamed Helal	***********************/
/*****************		Layer:	I/0 DRIVERS		***********************/
/*****************		SWC:	PORT			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/


#ifndef PORT_H_
#define PORT_H_
/*******************************************************************************
*                              INCLUDES FILES                                  *
*******************************************************************************/
#include "STD_TYPES.h"
#include "DIO_REGS.h"
#include "DET.h"
#include "PORT_PBcng.h"
#define  MIN_NUM_OF_PINS       0
#define  MAX_NUM_OF_PINS       32
#define PORT_NOT_INITIALIZED   1
#define PORT_INITIALIZED       0
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Initialization */
#define PORT_INIT_SID                     (u8)0x00

/* Service ID for PORT SetPinDirection */
#define PORT_SET_PIN_DIRECTION_SID        (u8)0x01

/* Service ID for PORT Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID   (u8)0x02

/* Service ID for PORT Get Version Information */
#define PORT_GET_VERSION_INFO_SID         (u8)0x03

/* Service ID for PORT Set Pin Mode */
 #define PORT_SET_PIN_MODE_SID             (u8)0x04
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                  (u8)0x0A

/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE     (u8)0x0B

/* DET code to report API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG               (u8)0x0C

/* DET code to report API Port_SetPinMode called with invalid mode */
#define PORT_E_PARAM_INVALID_MODE         (u8)0x0D

/* DET code to report API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE          (u8)0x0E

/* DET code to report API service called without module initialization */
#define PORT_E_UNINIT                     (u8)0x0F

/* DET code to report APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER              (u8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/*Data type for the symbolic name of a port pin*/
typedef u8 Port_PinType;

/*Possible directions of a port pin*/
typedef enum {
	 PORT_PIN_IN, PORT_PIN_OUT
 } Port_PinDirectionType;

/*Different port pin modes*/
typedef u8 Port_PinModeType;

/* Type definition for Port_ID used by the Port APIs */
typedef u8 Port_IDType;

/* Pin config structure*/
typedef struct {
	// Number of the port.
	 Port_IDType Port_Num;
	// Number of the pin.
	 Port_PinType Pin_Num;
	// Direction of the pin.
	 Port_PinDirectionType Pin_Dir;
	// Pin level value.
	u8 Pin_Level;
	// Pin pullup rsistor.
	u8 PullUp;
	// pin direction changeable during runtime?.
	u8 Pin_Dir_Chang;
	// Pin mode changeable during runtime?.
	u8 Pin_Mode_Chang;
	// Mode of a given pin.
	Port_PinModeType Pin_Mode;
 } Pin_ConfigType;

 /*Type of the external data structure containing the initialization data for this module*/
typedef struct {
	 Pin_ConfigType Pin_config[MAX_NUM_OF_PINS];

 } Port_ConfigType;
	
  /*******************************************************************************
  *                      Function Prototypes                                    *
  *******************************************************************************/
  /* Function for Initializes the Port Driver module*/
  void Port_Init( const Port_ConfigType* ConfigPtr );

  /* Function for Sets the port pin direction*/
  
  void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
  

  /* Function for Refreshes port direction*/
  void Port_RefreshPortDirection( void );

  /* Function for Sets the port pin mode*/
  void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
  /*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H_ */