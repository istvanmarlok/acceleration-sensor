/*******************************************************************************
* File Name: AN_Audio.h  
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

#if !defined(CY_PINS_AN_Audio_ALIASES_H) /* Pins AN_Audio_ALIASES_H */
#define CY_PINS_AN_Audio_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define AN_Audio_0			(AN_Audio__0__PC)
#define AN_Audio_0_PS		(AN_Audio__0__PS)
#define AN_Audio_0_PC		(AN_Audio__0__PC)
#define AN_Audio_0_DR		(AN_Audio__0__DR)
#define AN_Audio_0_SHIFT	(AN_Audio__0__SHIFT)
#define AN_Audio_0_INTR	((uint16)((uint16)0x0003u << (AN_Audio__0__SHIFT*2u)))

#define AN_Audio_INTR_ALL	 ((uint16)(AN_Audio_0_INTR))


#endif /* End Pins AN_Audio_ALIASES_H */


/* [] END OF FILE */
