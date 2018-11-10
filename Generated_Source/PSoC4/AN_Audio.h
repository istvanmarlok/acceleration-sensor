/*******************************************************************************
* File Name: AN_Audio.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_AN_Audio_H) /* Pins AN_Audio_H */
#define CY_PINS_AN_Audio_H

#include "cytypes.h"
#include "cyfitter.h"
#include "AN_Audio_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} AN_Audio_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   AN_Audio_Read(void);
void    AN_Audio_Write(uint8 value);
uint8   AN_Audio_ReadDataReg(void);
#if defined(AN_Audio__PC) || (CY_PSOC4_4200L) 
    void    AN_Audio_SetDriveMode(uint8 mode);
#endif
void    AN_Audio_SetInterruptMode(uint16 position, uint16 mode);
uint8   AN_Audio_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void AN_Audio_Sleep(void); 
void AN_Audio_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(AN_Audio__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define AN_Audio_DRIVE_MODE_BITS        (3)
    #define AN_Audio_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - AN_Audio_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the AN_Audio_SetDriveMode() function.
         *  @{
         */
        #define AN_Audio_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define AN_Audio_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define AN_Audio_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define AN_Audio_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define AN_Audio_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define AN_Audio_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define AN_Audio_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define AN_Audio_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define AN_Audio_MASK               AN_Audio__MASK
#define AN_Audio_SHIFT              AN_Audio__SHIFT
#define AN_Audio_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AN_Audio_SetInterruptMode() function.
     *  @{
     */
        #define AN_Audio_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define AN_Audio_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define AN_Audio_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define AN_Audio_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(AN_Audio__SIO)
    #define AN_Audio_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(AN_Audio__PC) && (CY_PSOC4_4200L)
    #define AN_Audio_USBIO_ENABLE               ((uint32)0x80000000u)
    #define AN_Audio_USBIO_DISABLE              ((uint32)(~AN_Audio_USBIO_ENABLE))
    #define AN_Audio_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define AN_Audio_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define AN_Audio_USBIO_ENTER_SLEEP          ((uint32)((1u << AN_Audio_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << AN_Audio_USBIO_SUSPEND_DEL_SHIFT)))
    #define AN_Audio_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << AN_Audio_USBIO_SUSPEND_SHIFT)))
    #define AN_Audio_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << AN_Audio_USBIO_SUSPEND_DEL_SHIFT)))
    #define AN_Audio_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(AN_Audio__PC)
    /* Port Configuration */
    #define AN_Audio_PC                 (* (reg32 *) AN_Audio__PC)
#endif
/* Pin State */
#define AN_Audio_PS                     (* (reg32 *) AN_Audio__PS)
/* Data Register */
#define AN_Audio_DR                     (* (reg32 *) AN_Audio__DR)
/* Input Buffer Disable Override */
#define AN_Audio_INP_DIS                (* (reg32 *) AN_Audio__PC2)

/* Interrupt configuration Registers */
#define AN_Audio_INTCFG                 (* (reg32 *) AN_Audio__INTCFG)
#define AN_Audio_INTSTAT                (* (reg32 *) AN_Audio__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define AN_Audio_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(AN_Audio__SIO)
    #define AN_Audio_SIO_REG            (* (reg32 *) AN_Audio__SIO)
#endif /* (AN_Audio__SIO_CFG) */

/* USBIO registers */
#if !defined(AN_Audio__PC) && (CY_PSOC4_4200L)
    #define AN_Audio_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define AN_Audio_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define AN_Audio_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define AN_Audio_DRIVE_MODE_SHIFT       (0x00u)
#define AN_Audio_DRIVE_MODE_MASK        (0x07u << AN_Audio_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins AN_Audio_H */


/* [] END OF FILE */
