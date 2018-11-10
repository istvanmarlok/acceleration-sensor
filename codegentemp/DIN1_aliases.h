/*******************************************************************************
* File Name: DIN1.h  
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

#if !defined(CY_PINS_DIN1_ALIASES_H) /* Pins DIN1_ALIASES_H */
#define CY_PINS_DIN1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIN1_0			(DIN1__0__PC)
#define DIN1_0_PS		(DIN1__0__PS)
#define DIN1_0_PC		(DIN1__0__PC)
#define DIN1_0_DR		(DIN1__0__DR)
#define DIN1_0_SHIFT	(DIN1__0__SHIFT)
#define DIN1_0_INTR	((uint16)((uint16)0x0003u << (DIN1__0__SHIFT*2u)))

#define DIN1_INTR_ALL	 ((uint16)(DIN1_0_INTR))


#endif /* End Pins DIN1_ALIASES_H */


/* [] END OF FILE */
