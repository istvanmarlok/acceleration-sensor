/*******************************************************************************
* File Name: RELAY3.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RELAY3_ALIASES_H) /* Pins RELAY3_ALIASES_H */
#define CY_PINS_RELAY3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define RELAY3_0			(RELAY3__0__PC)
#define RELAY3_0_PS		(RELAY3__0__PS)
#define RELAY3_0_PC		(RELAY3__0__PC)
#define RELAY3_0_DR		(RELAY3__0__DR)
#define RELAY3_0_SHIFT	(RELAY3__0__SHIFT)
#define RELAY3_0_INTR	((uint16)((uint16)0x0003u << (RELAY3__0__SHIFT*2u)))

#define RELAY3_INTR_ALL	 ((uint16)(RELAY3_0_INTR))


#endif /* End Pins RELAY3_ALIASES_H */


/* [] END OF FILE */
