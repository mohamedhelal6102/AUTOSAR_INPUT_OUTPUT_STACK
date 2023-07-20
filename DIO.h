/*
 * DIO.h
 *
 * Created: 7/19/2023 4:26:23 PM
 *  Author: Mohamed Helal
 */ 
/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mohamed Helal	***********************/
/*****************		Layer:	I/0 DRIVERS		***********************/
/*****************		SWC:	DIO  			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef DIO_H_
#define DIO_H_
#include "DIO_REGS.h"
#include "DIO_Cng.h"
#include "STD_TYPES.h"
#include "DET.h"

#define DIO_NOT_INITIALIZED  1
#define DIO_INITIALIZED      0
#define DIO_VENDOR_ID    (1000U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (u8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (u8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (u8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (u8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (u8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (u8)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (u8)0x12

/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (u8)0x10

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (u8)0x11

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (u8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (u8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (u8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (u8)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (u8)0x20

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document).
 */
#define DIO_E_UNINIT                   (u8)0xF0
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef u8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef u8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef u8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef u8 Dio_PortLevelType;

/* Structure for Dio_ChannelGroup */
typedef struct
{
  /* Mask which defines the positions of the channel group */
  u8 mask;
  /* Position of the group from LSB */
  u8 offset;
  /* This shall be the port ID which the Channel group is defined. */
  Dio_PortType PortIndex;
} Dio_ChannelGroupType;

typedef struct
{
	/* Member contains the ID of the Port that this channel belongs to */
	Dio_PortType Port_Num;
	/* Member contains the ID of the Channel*/
	Dio_ChannelType Ch_Num;
}Dio_ConfigChannel;

/* Data Structure required for initializing the Dio Driver */
typedef struct
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO read Channel API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO Initialization API */
void Dio_Init(const Dio_ConfigType * ConfigPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif


#endif /* DIO_H_ */