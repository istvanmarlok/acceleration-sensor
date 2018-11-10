/*******************************************************************************
* File Name: AN_Ext_Light.h  
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

#if !defined(CY_PINS_AN_Ext_Light_H) /* Pins AN_Ext_Light_H */
#define CY_PINS_AN_Ext_Light_H

#include "cytypes.h"
#include "cyfitter.h"
#include "AN_Ext_Light_aliases.h"


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
} AN_Ext_Light_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   AN_Ext_Light_Read(void);
void    AN_Ext_Light_Write(uint8 value);
uint8   AN_Ext_Light_ReadDataReg(void);
#if defined(AN_Ext_Light__PC) || (CY_PSOC4_4200L) 
    void    AN_Ext_Light_SetDriveMode(uint8 mode);
#endif
void    AN_Ext_Light_SetInterruptMode(uint16 position, uint16 mode);
uint8   AN_Ext_Light_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void AN_Ext_Light_Sleep(void); 
void AN_Ext_Light_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(AN_Ext_Light__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define AN_Ext_Light_DRIVE_MODE_BITS        (3)
    #define AN_Ext_Light_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - AN_Ext_Light_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the AN_Ext_Light_SetDriveMode() function.
         *  @{
         */
        #define AN_Ext_Light_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define AN_Ext_Light_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define AN_Ext_Light_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define AN_Ext_Light_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define AN_Ext_Light_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define AN_Ext_Light_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define AN_Ext_Light_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define AN_Ext_Light_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define AN_Ext_Light_MASK               AN_Ext_Light__MASK
#define AN_Ext_Light_SHIFT              AN_Ext_Light__SHIFT
#define AN_Ext_Light_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AN_Ext_Light_SetInterruptMode() function.
     *  @{
     */
        #define AN_Ext_Light_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define AN_Ext_Light_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define AN_Ext_Light_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define AN_Ext_Light_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(AN_Ext_Light__SIO)
    #define AN_Ext_Light_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(AN_Ext_Light__PC) && (CY_PSOC4_4200L)
    #define AN_Ext_Light_USBIO_ENABLE               ((uint32)0x80000000u)
    #define AN_Ext_Light_USBIO_DISABLE              ((uint32)(~AN_Ext_Light_USBIO_ENABLE))
    #define AN_Ext_Light_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define AN_Ext_Light_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define AN_Ext_Light_USBIO_ENTER_SLEEP          ((uint32)((1u << AN_Ext_Light_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << AN_Ext_Light_USBIO_SUSPEND_DEL_SHIFT)))
    #define AN_Ext_Light_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << AN_Ext_Light_USBIO_SUSPEND_SHIFT)))
    #define AN_Ext_Light_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << AN_Ext_Light_USBIO_SUSPEND_DEL_SHIFT)))
    #define AN_Ext_Light_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(AN_Ext_Light__PC)
    /* Port Configuration */
    #define AN_Ext_Light_PC                 (* (reg32 *) AN_Ext_Light__PC)
#endif
/* Pin State */
#define AN_Ext_Light_PS                     (* (reg32 *) AN_Ext_Light__PS)
/* Data Register */
#define AN_Ext_Light_DR                     (* (reg32 *) AN_Ext_Light__DR)
/* Input Buffer Disable Override */
#define AN_Ext_Light_INP_DIS                (* (reg32 *) AN_Ext_Light__PC2)

/* Interrupt configuration Registers */
#define AN_Ext_Light_INTCFG                 (* (reg32 *) AN_Ext_Light__INTCFG)
#define AN_Ext_Light_INTSTAT                (* (reg32 *) AN_Ext_Light__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define AN_Ext_Light_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(AN_Ext_Light__SIO)
    #define AN_Ext_Light_SIO_REG            (* (reg32 *) AN_Ext_Light__SIO)
#endif /* (AN_Ext_Light__SIO_CFG) */

/* USBIO registers */
#if !defined(AN_Ext_Light__PC) && (CY_PSOC4_4200L)
    #define AN_Ext_Light_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define AN_Ext_Light_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define AN_Ext_Light_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define AN_Ext_Light_DRIVE_MODE_SHIFT       (0x00u)
#define AN_Ext_Light_DRIVE_MODE_MASK        (0x07u << AN_Ext_Light_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins AN_Ext_Light_H */


/* [] END OF FILE */
