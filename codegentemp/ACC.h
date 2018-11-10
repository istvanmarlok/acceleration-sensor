/*******************************************************************************
* File Name: ACC.h  
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

#if !defined(CY_PINS_ACC_H) /* Pins ACC_H */
#define CY_PINS_ACC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ACC_aliases.h"


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
} ACC_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ACC_Read(void);
void    ACC_Write(uint8 value);
uint8   ACC_ReadDataReg(void);
#if defined(ACC__PC) || (CY_PSOC4_4200L) 
    void    ACC_SetDriveMode(uint8 mode);
#endif
void    ACC_SetInterruptMode(uint16 position, uint16 mode);
uint8   ACC_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ACC_Sleep(void); 
void ACC_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ACC__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ACC_DRIVE_MODE_BITS        (3)
    #define ACC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ACC_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ACC_SetDriveMode() function.
         *  @{
         */
        #define ACC_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ACC_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ACC_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ACC_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ACC_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ACC_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ACC_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ACC_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ACC_MASK               ACC__MASK
#define ACC_SHIFT              ACC__SHIFT
#define ACC_WIDTH              2u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ACC_SetInterruptMode() function.
     *  @{
     */
        #define ACC_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ACC_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ACC_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ACC_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ACC__SIO)
    #define ACC_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ACC__PC) && (CY_PSOC4_4200L)
    #define ACC_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ACC_USBIO_DISABLE              ((uint32)(~ACC_USBIO_ENABLE))
    #define ACC_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ACC_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ACC_USBIO_ENTER_SLEEP          ((uint32)((1u << ACC_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ACC_USBIO_SUSPEND_DEL_SHIFT)))
    #define ACC_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ACC_USBIO_SUSPEND_SHIFT)))
    #define ACC_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ACC_USBIO_SUSPEND_DEL_SHIFT)))
    #define ACC_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ACC__PC)
    /* Port Configuration */
    #define ACC_PC                 (* (reg32 *) ACC__PC)
#endif
/* Pin State */
#define ACC_PS                     (* (reg32 *) ACC__PS)
/* Data Register */
#define ACC_DR                     (* (reg32 *) ACC__DR)
/* Input Buffer Disable Override */
#define ACC_INP_DIS                (* (reg32 *) ACC__PC2)

/* Interrupt configuration Registers */
#define ACC_INTCFG                 (* (reg32 *) ACC__INTCFG)
#define ACC_INTSTAT                (* (reg32 *) ACC__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ACC_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ACC__SIO)
    #define ACC_SIO_REG            (* (reg32 *) ACC__SIO)
#endif /* (ACC__SIO_CFG) */

/* USBIO registers */
#if !defined(ACC__PC) && (CY_PSOC4_4200L)
    #define ACC_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ACC_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ACC_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ACC_DRIVE_MODE_SHIFT       (0x00u)
#define ACC_DRIVE_MODE_MASK        (0x07u << ACC_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ACC_H */


/* [] END OF FILE */
