/*******************************************************************************
* File Name: DIN8.h  
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

#if !defined(CY_PINS_DIN8_ALIASES_H) /* Pins DIN8_ALIASES_H */
#define CY_PINS_DIN8_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIN8_0			(DIN8__0__PC)
#define DIN8_0_PS		(DIN8__0__PS)
#define DIN8_0_PC		(DIN8__0__PC)
#define DIN8_0_DR		(DIN8__0__DR)
#define DIN8_0_SHIFT	(DIN8__0__SHIFT)
#define DIN8_0_INTR	((uint16)((uint16)0x0003u << (DIN8__0__SHIFT*2u)))

#define DIN8_INTR_ALL	 ((uint16)(DIN8_0_INTR))


#endif /* End Pins DIN8_ALIASES_H */


/* [] END OF FILE */
