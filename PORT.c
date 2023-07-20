/*
 * PORT.c
 *
 * Created: 7/19/2023 6:29:46 PM
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
#include "PORT.h"

/*GLOBAL VARAIBLES */
static Pin_ConfigType * Port_Pin_Config = NULL_PTR;
static u8 Port_Status = PORT_NOT_INITIALIZED;
/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
	Port_IDType *Port_Ptr = NULL_PTR;
	Port_PinType *Pin_PTR = NULL_PTR;
	u8 *DDR_Ptr = NULL_PTR;
	u8 error = FALSE;

#if (PORT_DEV_ERROR_DETECT==STD_ON)
      if (ConfigPtr == NULL_PTR)
          {
			  Det_ReportError(DET_MODULE_ID,DET_INSTANCE_ID,PORT_INIT_SID,PORT_E_PARAM_POINTER);
			  error =TRUE;
          }
      else
#endif
if(error=FALSE)
{
	
Port_Pin_Config = ConfigPtr->Pin_config;
volatile int i;
for (i = MIN_NUM_OF_PINS; i <= MAX_NUM_OF_PINS ; i++)
{
	switch(Port_Pin_Config[i].Port_Num)
	{
		case 0:	Port_Ptr = &PORTA_REG;
		Pin_PTR  = &PINA_REG;
		DDR_Ptr  = &DDRA_REG;

		break;
		case 1:	Port_Ptr = &PORTB_REG;
		Pin_PTR  = &PINB_REG;
		DDR_Ptr  = &DDRB_REG;
		break;
		case 2:	Port_Ptr = &PORTC_REG;
		Pin_PTR  = &PINC_REG;
		DDR_Ptr  = &DDRC_REG;
		break;
		case 3:	Port_Ptr = &PORTD_REG;
		Pin_PTR  = &PIND_REG;
		DDR_Ptr  = &DDRD_REG;
		break;
	}
	if (INPUT == (Port_Pin_Config[i].Pin_Dir))
	{
		CLEAR_BIT(*DDR_Ptr,Port_Pin_Config[i].Pin_Num);
		
		if (STD_HIGH == (Port_Pin_Config[i].PullUp))
		{
			SET_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
		}
		else if (STD_LOW == (Port_Pin_Config[i].PullUp))
		{
			CLEAR_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
		}
	}
	else if (OUTPUT == (Port_Pin_Config[i].Pin_Dir))
	{
		SET_BIT(*DDR_Ptr,Port_Pin_Config[i].Pin_Num);
		
		if (STD_HIGH == (Port_Pin_Config[i].Pin_Level))
		{
			SET_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
		}
		else if (STD_LOW == (Port_Pin_Config[i].Pin_Level))
		{
			CLEAR_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
		}
	}
	Port_Status=PORT_INITIALIZED;
}
}
}
/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Sets the port pin direction.
************************************************************************************/

 void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
 {
	 u8 *DDR_Ptr = NULL_PTR;
	 u8 error=FALSE;
 #if (PORT_DEV_ERROR_DETECT == STD_ON)
 /* check if the Port driver is initialized*/
 if (PORT_NOT_INITIALIZED == Port_Status)
 {
	 /* Report to DET  */
	 Det_ReportError(DET_MODULE_ID,DET_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,
	 PORT_E_UNINIT );
	 error = TRUE;
 }
 else {}
 /* check if Incorrect Port Pin ID passed*/
 if ((Pin > MAX_NUM_OF_PINS) || (Pin < MIN_NUM_OF_PINS ))
 {
	 /* Report to DET  */
	 Det_ReportError(DET_MODULE_ID,DET_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,
	 PORT_E_PARAM_PIN);
	 error = TRUE;
 }
 else {}
 /* check if Port Pin not configured as changeable */
 if (STD_OFF == Port_Pin_Config[Pin].Pin_Dir_Chang)
 {
	 /* Report to DET  */
	 Det_ReportError(DET_MODULE_ID,DET_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,
	 PORT_E_DIRECTION_UNCHANGEABLE);
	 error = TRUE;
 }
 else {}
 #endif
if (error=FALSE)
{

	 	
	switch(Port_Pin_Config[Pin].Port_Num)
	{
		case 0: DDR_Ptr=&DDRA_REG; break;
		case 1: DDR_Ptr=&DDRB_REG; break;
		case 2: DDR_Ptr=&DDRC_REG; break;
		case 3: DDR_Ptr=&DDRD_REG; break;
	}
	if(INPUT==Direction)
	{
		CLEAR_BIT(DDR_Ptr,Port_Pin_Config[Pin].Pin_Num);
	}
	else if(OUTPUT==Direction)
	{
		SET_BIT(DDR_Ptr,Port_Pin_Config[Pin].Pin_Num);
	}
 }
 }
 /************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Refreshes port direction.
 ************************************************************************************/
 void Port_RefreshPortDirection( void )
 {
	 u8 *DDR_Ptr = NULL_PTR;
	 u8 DDR_Value;
	 {
		 volatile int i;
		 for (i = MIN_NUM_OF_PINS; i <= MAX_NUM_OF_PINS; i+=8)
		 {
			 switch(Port_Pin_Config[i].Port_Num)
			 {
				 case 0:	DDR_Ptr  = &DDRA_REG;
				 break;
				 case 1:	DDR_Ptr  = &DDRB_REG;
				 break;
				 case 2:	DDR_Ptr  = &DDRC_REG;
				 break;
				 case 3:	DDR_Ptr  = &DDRD_REG;
				 break;
			 }
			 DDR_Value = *DDR_Ptr;
			 *DDR_Ptr = DDR_Value;
		 }
	 }
 }
 /************************************************************************************
 * Service Name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin mode.
 ************************************************************************************/
 
   void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
 {
 	u8 error = FALSE;
 	#if (PORT_DEV_ERROR_DETECT == STD_ON)
 	/* check if the Port driver is initialized*/
 	if (PORT_NOT_INITIALIZED == Port_Status)
 	{
	 	/* Report to DET  */
	 	Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
	 	PORT_E_UNINIT );
	 	error = TRUE;
 	}
 	else {}
 	/* check if Incorrect Port Pin ID passed*/
 	if ((Pin > MAX_NUM_OF_PINS) || (Pin < MIN_NUM_OF_PINS ))
 	{
	 	/* Report to DET  */
	 	Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
	 	PORT_E_PARAM_PIN);
	 	error = TRUE;
 	}
 	else {}
 	/* check if Incorrect Port Pin Mode passed*/
 	if ((Mode > I2C_MODE) || (Pin < DIO_MODE ))
 	{
	 	/* Report to DET  */
	 	Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
	 	PORT_E_PARAM_INVALID_MODE);
	 	error = TRUE;
 	}
 	else {}
 	/* check if Port Pin mode not configured as changeable */
 	if (STD_OFF == Port_Pin_Config[Pin].Pin_Mode_Chang)
 	{
	 	/* Report to DET  */
	 	Det_ReportError(DET_MODULE_ID,DET_INSTANCE_ID,PORT_SET_PIN_MODE_SID,
	 	PORT_E_MODE_UNCHANGEABLE);
	 	error = TRUE;
 	}
 	else {}
 	#endif
}