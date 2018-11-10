/*******************************************************************************
* File Name: DOUT4.h  
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

#if !defined(CY_PINS_DOUT4_ALIASES_H) /* Pins DOUT4_ALIASES_H */
#define CY_PINS_DOUT4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DOUT4_0			(DOUT4__0__PC)
#define DOUT4_0_PS		(DOUT4__0__PS)
#define DOUT4_0_PC		(DOUT4__0__PC)
#define DOUT4_0_DR		(DOUT4__0__DR)
#define DOUT4_0_SHIFT	(DOUT4__0__SHIFT)
#define DOUT4_0_INTR	((uint16)((uint16)0x0003u << (DOUT4__0__SHIFT*2u)))

#define DOUT4_INTR_ALL	 ((uint16)(DOUT4_0_INTR))


#endif /* End Pins DOUT4_ALIASES_H */


/* [] END OF FILE */
