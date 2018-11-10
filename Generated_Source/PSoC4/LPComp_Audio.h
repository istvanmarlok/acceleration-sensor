/*******************************************************************************
* File Name: LPComp_Audio.h
* Version 2.20
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Low Power Comparator component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COMPARATOR_LPComp_Audio_H)
#define CY_COMPARATOR_LPComp_Audio_H

#include "cytypes.h"
#include "cyfitter.h"


extern uint8  LPComp_Audio_initVar;


/***************************************
*  Conditional Compilation Parameters
****************************************/

#define LPComp_Audio_CY_LPCOMP_V0 (CYIPBLOCK_m0s8lpcomp_VERSION == 0u) 
#define LPComp_Audio_CY_LPCOMP_V2 (CYIPBLOCK_m0s8lpcomp_VERSION >= 2u) 


/**************************************
*        Function Prototypes
**************************************/

void    LPComp_Audio_Start(void);
void    LPComp_Audio_Init(void);
void    LPComp_Audio_Enable(void);
void    LPComp_Audio_Stop(void);
void    LPComp_Audio_SetSpeed(uint32 speed);
void    LPComp_Audio_SetInterruptMode(uint32 mode);
uint32  LPComp_Audio_GetInterruptSource(void);
void    LPComp_Audio_ClearInterrupt(uint32 interruptMask);
void    LPComp_Audio_SetInterrupt(uint32 interruptMask);
void    LPComp_Audio_SetHysteresis(uint32 hysteresis);
uint32  LPComp_Audio_GetCompare(void);
uint32  LPComp_Audio_ZeroCal(void);
void    LPComp_Audio_LoadTrim(uint32 trimVal);
void    LPComp_Audio_Sleep(void);
void    LPComp_Audio_Wakeup(void);
void    LPComp_Audio_SaveConfig(void);
void    LPComp_Audio_RestoreConfig(void);
#if(LPComp_Audio_CY_LPCOMP_V2)
    void    LPComp_Audio_SetOutputMode(uint32 mode);
    void    LPComp_Audio_SetInterruptMask(uint32 interruptMask);
    uint32  LPComp_Audio_GetInterruptMask(void);
    uint32  LPComp_Audio_GetInterruptSourceMasked(void);
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */


/**************************************
*           API Constants
**************************************/

#if(LPComp_Audio_CY_LPCOMP_V2)
    /* Constants for LPComp_Audio_SetOutputMode(), mode parameter */
    #define LPComp_Audio_OUT_PULSE      (0x00u)
    #define LPComp_Audio_OUT_SYNC       (0x01u)
    #define LPComp_Audio_OUT_DIRECT     (0x02u)
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */

#define LPComp_Audio_INTR_PARAM_MASK    (0x03u)
#define LPComp_Audio_SPEED_PARAM_MASK   (0x03u)

/* Constants for LPComp_Audio_SetSpeed(), speed parameter */
#define LPComp_Audio_MED_SPEED          (0x00u)
#define LPComp_Audio_HIGH_SPEED         (0x01u)
#define LPComp_Audio_LOW_SPEED          (0x02u)

/* Constants for LPComp_Audio_SetInterruptMode(), mode parameter */
#define LPComp_Audio_INTR_DISABLE       (0x00u)
#define LPComp_Audio_INTR_RISING        (0x01u)
#define LPComp_Audio_INTR_FALLING       (0x02u)
#define LPComp_Audio_INTR_BOTH          (0x03u)

/* Constants for LPComp_Audio_SetHysteresis(), hysteresis parameter */
#define LPComp_Audio_HYST_ENABLE        (0x00u)
#define LPComp_Audio_HYST_DISABLE       (0x01u)

/* Constants for LPComp_Audio_ZeroCal() */
#define LPComp_Audio_TRIMA_MASK         (0x1Fu)
#define LPComp_Audio_TRIMA_SIGNBIT      (4u)
#define LPComp_Audio_TRIMA_MAX_VALUE    (15u)
#define LPComp_Audio_TRIMB_MASK         (0x1Fu)
#define LPComp_Audio_TRIMB_SHIFT        (8u)
#define LPComp_Audio_TRIMB_SIGNBIT      (4u)
#define LPComp_Audio_TRIMB_MAX_VALUE    (15u)

/* Constants for LPComp_Audio_GetInterruptSource() and 
* LPComp_Audio_ClearInterrupt(), interruptMask parameter 
*/
#define LPComp_Audio_INTR_SHIFT         (LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_SHIFT)
#define LPComp_Audio_INTR               ((uint32)0x01u << LPComp_Audio_INTR_SHIFT)

/* Constants for LPComp_Audio_SetInterrupt(), interruptMask parameter */
#define LPComp_Audio_INTR_SET_SHIFT     (LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET_SHIFT)
#define LPComp_Audio_INTR_SET           ((uint32)0x01u << LPComp_Audio_INTR_SHIFT)

#if(LPComp_Audio_CY_LPCOMP_V2)
    /* Constants for LPComp_Audio_GetInterruptMask() and 
    * LPComp_Audio_SetInterruptMask(), interruptMask parameter 
    */
    #define LPComp_Audio_INTR_MASK_SHIFT    (LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK_SHIFT)
    #define LPComp_Audio_INTR_MASK          ((uint32)0x01u << LPComp_Audio_INTR_MASK_SHIFT)

    /* Constants for LPComp_Audio_GetInterruptSourceMasked() */ 
    #define LPComp_Audio_INTR_MASKED_SHIFT  (LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED_SHIFT)
    #define LPComp_Audio_INTR_MASKED        ((uint32)0x01u << LPComp_Audio_INTR_MASKED_SHIFT)
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */


/***************************************
* Enumerated Types and Parameters 
***************************************/

/* Enumerated Types LPCompSpeedType, Used in parameter Speed */
#define LPComp_Audio__LPC_LOW_SPEED 2
#define LPComp_Audio__LPC_MED_SPEED 0
#define LPComp_Audio__LPC_HIGH_SPEED 1


/* Enumerated Types LPCompInterruptType, Used in parameter Interrupt */
#define LPComp_Audio__LPC_INT_DISABLE 0
#define LPComp_Audio__LPC_INT_RISING 1
#define LPComp_Audio__LPC_INT_FALLING 2
#define LPComp_Audio__LPC_INT_BOTH 3


/* Enumerated Types LPCompHysteresisType, Used in parameter Hysteresis */
#define LPComp_Audio__LPC_DISABLE_HYST 1
#define LPComp_Audio__LPC_ENABLE_HYST 0


/* Enumerated Types OutputModeType, Used in parameter OutputMode */
#define LPComp_Audio__OUT_MODE_SYNC 1
#define LPComp_Audio__OUT_MODE_DIRECT 2
#define LPComp_Audio__OUT_MODE_PULSE 0



/***************************************
*   Initial Parameter Constants
****************************************/

#define LPComp_Audio_INTERRUPT    (1u)
#define LPComp_Audio_SPEED        (0u)
#define LPComp_Audio_HYSTERESIS   (1u)
#if (LPComp_Audio_CY_LPCOMP_V2)
    #define LPComp_Audio_OUT_MODE       (0u)
    #define LPComp_Audio_INTERRUPT_EN   (1u)
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */


/**************************************
*             Registers
**************************************/

#define LPComp_Audio_CONFIG_REG     (*(reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)
#define LPComp_Audio_CONFIG_PTR     ( (reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)

#define LPComp_Audio_DFT_REG        (*(reg32 *)CYREG_LPCOMP_DFT)
#define LPComp_Audio_DFT_PTR        ( (reg32 *)CYREG_LPCOMP_DFT)

#define LPComp_Audio_INTR_REG       (*(reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR)
#define LPComp_Audio_INTR_PTR       ( (reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR)

#define LPComp_Audio_INTR_SET_REG   (*(reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)
#define LPComp_Audio_INTR_SET_PTR   ( (reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)

#define LPComp_Audio_TRIMA_REG      (*(reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__TRIM_A)
#define LPComp_Audio_TRIMA_PTR      ( (reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__TRIM_A)

#define LPComp_Audio_TRIMB_REG      (*(reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__TRIM_B)
#define LPComp_Audio_TRIMB_PTR      ( (reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__TRIM_B)

#if(LPComp_Audio_CY_LPCOMP_V2)
    #define LPComp_Audio_INTR_MASK_REG    (*(reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 
    #define LPComp_Audio_INTR_MASK_PTR    ( (reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 

    #define LPComp_Audio_INTR_MASKED_REG  (*(reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
    #define LPComp_Audio_INTR_MASKED_PTR  ( (reg32 *)LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */


/***************************************
*        Registers Constants
***************************************/

#define LPComp_Audio_CONFIG_REG_SHIFT           (LPComp_Audio_cy_psoc4_lpcomp_1__LPCOMP_CONFIG_SHIFT)

/* LPComp_AudioLPComp_Audio_CONFIG_REG */
#define LPComp_Audio_CONFIG_SPEED_MODE_SHIFT    (0u)    /* [1:0]    Operating mode for the comparator      */
#define LPComp_Audio_CONFIG_HYST_SHIFT          (2u)    /* [2]      Add 10mV hysteresis to the comparator: 0-enable, 1-disable */
#define LPComp_Audio_CONFIG_INTR_SHIFT          (4u)    /* [5:4]    Sets Pulse/Interrupt mode              */
#define LPComp_Audio_CONFIG_OUT_SHIFT           (6u)    /* [6]      Current output value of the comparator    */
#define LPComp_Audio_CONFIG_EN_SHIFT            (7u)    /* [7]      Enable comparator */
#if(LPComp_Audio_CY_LPCOMP_V2)
    #define LPComp_Audio_CONFIG_DSI_BYPASS_SHIFT    (16u)   /* [16]   Bypass comparator output synchronization for DSI output  */
    #define LPComp_Audio_CONFIG_DSI_LEVEL_SHIFT     (17u)   /* [17]   Comparator DSI (trigger) out level: 0-pulse, 1-level  */
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */

#define LPComp_Audio_CONFIG_SPEED_MODE_MASK     (((uint32) 0x03u << LPComp_Audio_CONFIG_SPEED_MODE_SHIFT) << \
                                                    LPComp_Audio_CONFIG_REG_SHIFT)

#define LPComp_Audio_CONFIG_HYST                (((uint32) 0x01u << LPComp_Audio_CONFIG_HYST_SHIFT) << \
                                                    LPComp_Audio_CONFIG_REG_SHIFT)

#define LPComp_Audio_CONFIG_INTR_MASK           (((uint32) 0x03u << LPComp_Audio_CONFIG_INTR_SHIFT) << \
                                                    LPComp_Audio_CONFIG_REG_SHIFT)

#define LPComp_Audio_CONFIG_OUT                 (((uint32) 0x01u << LPComp_Audio_CONFIG_OUT_SHIFT) << \
                                                    LPComp_Audio_CONFIG_REG_SHIFT)

#define LPComp_Audio_CONFIG_EN                  (((uint32) 0x01u << LPComp_Audio_CONFIG_EN_SHIFT) << \
                                                    LPComp_Audio_CONFIG_REG_SHIFT)
#if(LPComp_Audio_CY_LPCOMP_V2)
    #define LPComp_Audio_CONFIG_DSI_BYPASS          (((uint32) 0x01u << LPComp_Audio_CONFIG_DSI_BYPASS_SHIFT) << \
                                                        (LPComp_Audio_CONFIG_REG_SHIFT/2))

    #define LPComp_Audio_CONFIG_DSI_LEVEL           (((uint32) 0x01u << LPComp_Audio_CONFIG_DSI_LEVEL_SHIFT) << \
                                                        (LPComp_Audio_CONFIG_REG_SHIFT/2))
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */


/* LPComp_AudioLPComp_Audio_DFT_REG */
#define LPComp_Audio_DFT_CAL_EN_SHIFT    (0u)    /* [0] Calibration enable */

#define LPComp_Audio_DFT_CAL_EN          ((uint32) 0x01u << LPComp_Audio_DFT_CAL_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define LPComp_Audio_GET_CONFIG_SPEED_MODE(mode)    ((uint32) ((((uint32) (mode) << LPComp_Audio_CONFIG_SPEED_MODE_SHIFT) << \
                                                            LPComp_Audio_CONFIG_REG_SHIFT) & \
                                                            LPComp_Audio_CONFIG_SPEED_MODE_MASK))

#define LPComp_Audio_GET_CONFIG_HYST(hysteresis)    ((0u != (hysteresis)) ? (LPComp_Audio_CONFIG_HYST) : (0u))

#define LPComp_Audio_GET_CONFIG_INTR(intType)   ((uint32) ((((uint32)(intType) << LPComp_Audio_CONFIG_INTR_SHIFT) << \
                                                    LPComp_Audio_CONFIG_REG_SHIFT) & \
                                                    LPComp_Audio_CONFIG_INTR_MASK))
#if(LPComp_Audio_CY_LPCOMP_V2)
    #define LPComp_Audio_GET_CONFIG_DSI_BYPASS(bypass)  ((0u != ((bypass) & LPComp_Audio_OUT_DIRECT)) ? \
                                                                    (LPComp_Audio_CONFIG_DSI_BYPASS) : (0u))
   
    #define LPComp_Audio_GET_CONFIG_DSI_LEVEL(level)    ((0u != ((level) & LPComp_Audio_OUT_SYNC)) ? \
                                                                    (LPComp_Audio_CONFIG_DSI_LEVEL) : (0u))
    
    #define LPComp_Audio_GET_INTR_MASK(mask)            ((0u != (mask)) ? (LPComp_Audio_INTR_MASK) : (0u))
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */

#if(LPComp_Audio_CY_LPCOMP_V0)
    #define LPComp_Audio_CONFIG_REG_DEFAULT (LPComp_Audio_GET_CONFIG_SPEED_MODE(LPComp_Audio_SPEED) |\
                                                 LPComp_Audio_GET_CONFIG_HYST(LPComp_Audio_HYSTERESIS))
#else
    #define LPComp_Audio_CONFIG_REG_DEFAULT (LPComp_Audio_GET_CONFIG_SPEED_MODE(LPComp_Audio_SPEED) |\
                                                 LPComp_Audio_GET_CONFIG_HYST(LPComp_Audio_HYSTERESIS)  |\
                                                 LPComp_Audio_GET_CONFIG_DSI_BYPASS(LPComp_Audio_OUT_MODE) |\
                                                 LPComp_Audio_GET_CONFIG_DSI_LEVEL(LPComp_Audio_OUT_MODE))
#endif /* (LPComp_Audio_CY_LPCOMP_V0) */

#if(LPComp_Audio_CY_LPCOMP_V2)
    #define LPComp_Audio_INTR_MASK_REG_DEFAULT  (LPComp_Audio_GET_INTR_MASK(LPComp_Audio_INTERRUPT_EN))
#endif /* (LPComp_Audio_CY_LPCOMP_V2) */


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define LPComp_Audio_CONFIG_FILT_SHIFT          (3u)    
#define LPComp_Audio_CONFIG_FILT                ((uint32)((uint32)((uint32)0x01u << \
                                                    LPComp_Audio_CONFIG_FILT_SHIFT) << LPComp_Audio_CONFIG_REG_SHIFT))

#define LPComp_Audio_DIGITAL_FILTER             (0u)

/* LPComp_Audio_SetFilter() parameters */
#define LPComp_Audio_FILT_DISABLE               (0x00u)
#define LPComp_Audio_FILT_ENABLE                (0x01u)

/* LPComp_Audio_SetSpeed() parameters */
#define LPComp_Audio_MEDSPEED                   (LPComp_Audio_MED_SPEED)
#define LPComp_Audio_HIGHSPEED                  (LPComp_Audio_HIGH_SPEED)
#define LPComp_Audio_LOWSPEED                   (LPComp_Audio_LOW_SPEED)

void    LPComp_Audio_SetFilter(uint32 filter);

#endif    /* CY_COMPARATOR_LPComp_Audio_H */


/* [] END OF FILE */
