/*******************************************************************************
* File Name: DIN4.h  
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

#if !defined(CY_PINS_DIN4_ALIASES_H) /* Pins DIN4_ALIASES_H */
#define CY_PINS_DIN4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIN4_0			(DIN4__0__PC)
#define DIN4_0_PS		(DIN4__0__PS)
#define DIN4_0_PC		(DIN4__0__PC)
#define DIN4_0_DR		(DIN4__0__DR)
#define DIN4_0_SHIFT	(DIN4__0__SHIFT)
#define DIN4_0_INTR	((uint16)((uint16)0x0003u << (DIN4__0__SHIFT*2u)))

#define DIN4_INTR_ALL	 ((uint16)(DIN4_0_INTR))


#endif /* End Pins DIN4_ALIASES_H */


/* [] END OF FILE */
