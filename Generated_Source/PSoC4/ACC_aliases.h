/*******************************************************************************
* File Name: ACC.h  
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

#if !defined(CY_PINS_ACC_ALIASES_H) /* Pins ACC_ALIASES_H */
#define CY_PINS_ACC_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ACC_0			(ACC__0__PC)
#define ACC_0_PS		(ACC__0__PS)
#define ACC_0_PC		(ACC__0__PC)
#define ACC_0_DR		(ACC__0__DR)
#define ACC_0_SHIFT	(ACC__0__SHIFT)
#define ACC_0_INTR	((uint16)((uint16)0x0003u << (ACC__0__SHIFT*2u)))

#define ACC_1			(ACC__1__PC)
#define ACC_1_PS		(ACC__1__PS)
#define ACC_1_PC		(ACC__1__PC)
#define ACC_1_DR		(ACC__1__DR)
#define ACC_1_SHIFT	(ACC__1__SHIFT)
#define ACC_1_INTR	((uint16)((uint16)0x0003u << (ACC__1__SHIFT*2u)))

#define ACC_INTR_ALL	 ((uint16)(ACC_0_INTR| ACC_1_INTR))
#define ACC_INT2			(ACC__INT2__PC)
#define ACC_INT2_PS		(ACC__INT2__PS)
#define ACC_INT2_PC		(ACC__INT2__PC)
#define ACC_INT2_DR		(ACC__INT2__DR)
#define ACC_INT2_SHIFT	(ACC__INT2__SHIFT)
#define ACC_INT2_INTR	((uint16)((uint16)0x0003u << (ACC__0__SHIFT*2u)))

#define ACC_INT1			(ACC__INT1__PC)
#define ACC_INT1_PS		(ACC__INT1__PS)
#define ACC_INT1_PC		(ACC__INT1__PC)
#define ACC_INT1_DR		(ACC__INT1__DR)
#define ACC_INT1_SHIFT	(ACC__INT1__SHIFT)
#define ACC_INT1_INTR	((uint16)((uint16)0x0003u << (ACC__1__SHIFT*2u)))


#endif /* End Pins ACC_ALIASES_H */


/* [] END OF FILE */
