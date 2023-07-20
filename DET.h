/*
 * DET.h
 *
 * Created: 7/20/2023 1:42:09 AM
 *  Author: Mohamed Helal
 */ 


#ifndef DET_H_
#define DET_H_
/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define DET_VENDOR_ID                 (1000U)

/* Det Module Id */
#define DET_MODULE_ID                 (15U)

/* Instance Id */
#define DET_INSTANCE_ID               (0U)

/*
 * Det Software Module Version 1.0.0
 */
#define DET_SW_MAJOR_VERSION          (1U)
#define DET_SW_MINOR_VERSION          (0U)
#define DET_SW_PATCH_VERSION          (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DET_AR_MAJOR_VERSION          (4U)
#define DET_AR_MINOR_VERSION          (0U)
#define DET_AR_PATCH_VERSION          (3U)

/* Standard AUTOSAR types */
#include "Std_Types.h"


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void Det_ReportError( u16 ModuleId,
                      u8 InstanceId,
                      u8 ApiId,
					  u8 ErrorId );





#endif /* DET_H_ */