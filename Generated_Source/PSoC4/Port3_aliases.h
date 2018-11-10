/*******************************************************************************
* File Name: Port3.h  
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

#if !defined(CY_PINS_Port3_ALIASES_H) /* Pins Port3_ALIASES_H */
#define CY_PINS_Port3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Port3_0			(Port3__0__PC)
#define Port3_0_PS		(Port3__0__PS)
#define Port3_0_PC		(Port3__0__PC)
#define Port3_0_DR		(Port3__0__DR)
#define Port3_0_SHIFT	(Port3__0__SHIFT)
#define Port3_0_INTR	((uint16)((uint16)0x0003u << (Port3__0__SHIFT*2u)))

#define Port3_1			(Port3__1__PC)
#define Port3_1_PS		(Port3__1__PS)
#define Port3_1_PC		(Port3__1__PC)
#define Port3_1_DR		(Port3__1__DR)
#define Port3_1_SHIFT	(Port3__1__SHIFT)
#define Port3_1_INTR	((uint16)((uint16)0x0003u << (Port3__1__SHIFT*2u)))

#define Port3_2			(Port3__2__PC)
#define Port3_2_PS		(Port3__2__PS)
#define Port3_2_PC		(Port3__2__PC)
#define Port3_2_DR		(Port3__2__DR)
#define Port3_2_SHIFT	(Port3__2__SHIFT)
#define Port3_2_INTR	((uint16)((uint16)0x0003u << (Port3__2__SHIFT*2u)))

#define Port3_3			(Port3__3__PC)
#define Port3_3_PS		(Port3__3__PS)
#define Port3_3_PC		(Port3__3__PC)
#define Port3_3_DR		(Port3__3__DR)
#define Port3_3_SHIFT	(Port3__3__SHIFT)
#define Port3_3_INTR	((uint16)((uint16)0x0003u << (Port3__3__SHIFT*2u)))

#define Port3_4			(Port3__4__PC)
#define Port3_4_PS		(Port3__4__PS)
#define Port3_4_PC		(Port3__4__PC)
#define Port3_4_DR		(Port3__4__DR)
#define Port3_4_SHIFT	(Port3__4__SHIFT)
#define Port3_4_INTR	((uint16)((uint16)0x0003u << (Port3__4__SHIFT*2u)))

#define Port3_5			(Port3__5__PC)
#define Port3_5_PS		(Port3__5__PS)
#define Port3_5_PC		(Port3__5__PC)
#define Port3_5_DR		(Port3__5__DR)
#define Port3_5_SHIFT	(Port3__5__SHIFT)
#define Port3_5_INTR	((uint16)((uint16)0x0003u << (Port3__5__SHIFT*2u)))

#define Port3_INTR_ALL	 ((uint16)(Port3_0_INTR| Port3_1_INTR| Port3_2_INTR| Port3_3_INTR| Port3_4_INTR| Port3_5_INTR))
#define Port3_Vibration			(Port3__Vibration__PC)
#define Port3_Vibration_PS		(Port3__Vibration__PS)
#define Port3_Vibration_PC		(Port3__Vibration__PC)
#define Port3_Vibration_DR		(Port3__Vibration__DR)
#define Port3_Vibration_SHIFT	(Port3__Vibration__SHIFT)
#define Port3_Vibration_INTR	((uint16)((uint16)0x0003u << (Port3__0__SHIFT*2u)))

#define Port3_ACC_INT2			(Port3__ACC_INT2__PC)
#define Port3_ACC_INT2_PS		(Port3__ACC_INT2__PS)
#define Port3_ACC_INT2_PC		(Port3__ACC_INT2__PC)
#define Port3_ACC_INT2_DR		(Port3__ACC_INT2__DR)
#define Port3_ACC_INT2_SHIFT	(Port3__ACC_INT2__SHIFT)
#define Port3_ACC_INT2_INTR	((uint16)((uint16)0x0003u << (Port3__1__SHIFT*2u)))

#define Port3_ACC_INT1			(Port3__ACC_INT1__PC)
#define Port3_ACC_INT1_PS		(Port3__ACC_INT1__PS)
#define Port3_ACC_INT1_PC		(Port3__ACC_INT1__PC)
#define Port3_ACC_INT1_DR		(Port3__ACC_INT1__DR)
#define Port3_ACC_INT1_SHIFT	(Port3__ACC_INT1__SHIFT)
#define Port3_ACC_INT1_INTR	((uint16)((uint16)0x0003u << (Port3__2__SHIFT*2u)))

#define Port3_Ext_Bat_Enable			(Port3__Ext_Bat_Enable__PC)
#define Port3_Ext_Bat_Enable_PS		(Port3__Ext_Bat_Enable__PS)
#define Port3_Ext_Bat_Enable_PC		(Port3__Ext_Bat_Enable__PC)
#define Port3_Ext_Bat_Enable_DR		(Port3__Ext_Bat_Enable__DR)
#define Port3_Ext_Bat_Enable_SHIFT	(Port3__Ext_Bat_Enable__SHIFT)
#define Port3_Ext_Bat_Enable_INTR	((uint16)((uint16)0x0003u << (Port3__3__SHIFT*2u)))

#define Port3_CHG_Status			(Port3__CHG_Status__PC)
#define Port3_CHG_Status_PS		(Port3__CHG_Status__PS)
#define Port3_CHG_Status_PC		(Port3__CHG_Status__PC)
#define Port3_CHG_Status_DR		(Port3__CHG_Status__DR)
#define Port3_CHG_Status_SHIFT	(Port3__CHG_Status__SHIFT)
#define Port3_CHG_Status_INTR	((uint16)((uint16)0x0003u << (Port3__4__SHIFT*2u)))

#define Port3_Internal_Light			(Port3__Internal_Light__PC)
#define Port3_Internal_Light_PS		(Port3__Internal_Light__PS)
#define Port3_Internal_Light_PC		(Port3__Internal_Light__PC)
#define Port3_Internal_Light_DR		(Port3__Internal_Light__DR)
#define Port3_Internal_Light_SHIFT	(Port3__Internal_Light__SHIFT)
#define Port3_Internal_Light_INTR	((uint16)((uint16)0x0003u << (Port3__5__SHIFT*2u)))


#endif /* End Pins Port3_ALIASES_H */


/* [] END OF FILE */
