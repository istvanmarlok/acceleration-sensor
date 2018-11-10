/*******************************************************************************
* File Name: DIN2.h  
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

#if !defined(CY_PINS_DIN2_ALIASES_H) /* Pins DIN2_ALIASES_H */
#define CY_PINS_DIN2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIN2_0			(DIN2__0__PC)
#define DIN2_0_PS		(DIN2__0__PS)
#define DIN2_0_PC		(DIN2__0__PC)
#define DIN2_0_DR		(DIN2__0__DR)
#define DIN2_0_SHIFT	(DIN2__0__SHIFT)
#define DIN2_0_INTR	((uint16)((uint16)0x0003u << (DIN2__0__SHIFT*2u)))

#define DIN2_INTR_ALL	 ((uint16)(DIN2_0_INTR))


#endif /* End Pins DIN2_ALIASES_H */


/* [] END OF FILE */
