/*******************************************************************************
* File Name: RELAY2.h  
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

#if !defined(CY_PINS_RELAY2_H) /* Pins RELAY2_H */
#define CY_PINS_RELAY2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RELAY2_aliases.h"


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
} RELAY2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   RELAY2_Read(void);
void    RELAY2_Write(uint8 value);
uint8   RELAY2_ReadDataReg(void);
#if defined(RELAY2__PC) || (CY_PSOC4_4200L) 
    void    RELAY2_SetDriveMode(uint8 mode);
#endif
void    RELAY2_SetInterruptMode(uint16 position, uint16 mode);
uint8   RELAY2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void RELAY2_Sleep(void); 
void RELAY2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(RELAY2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define RELAY2_DRIVE_MODE_BITS        (3)
    #define RELAY2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RELAY2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the RELAY2_SetDriveMode() function.
         *  @{
         */
        #define RELAY2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define RELAY2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define RELAY2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define RELAY2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define RELAY2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define RELAY2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define RELAY2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define RELAY2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define RELAY2_MASK               RELAY2__MASK
#define RELAY2_SHIFT              RELAY2__SHIFT
#define RELAY2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RELAY2_SetInterruptMode() function.
     *  @{
     */
        #define RELAY2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define RELAY2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define RELAY2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define RELAY2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(RELAY2__SIO)
    #define RELAY2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(RELAY2__PC) && (CY_PSOC4_4200L)
    #define RELAY2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define RELAY2_USBIO_DISABLE              ((uint32)(~RELAY2_USBIO_ENABLE))
    #define RELAY2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define RELAY2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define RELAY2_USBIO_ENTER_SLEEP          ((uint32)((1u << RELAY2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << RELAY2_USBIO_SUSPEND_DEL_SHIFT)))
    #define RELAY2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << RELAY2_USBIO_SUSPEND_SHIFT)))
    #define RELAY2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << RELAY2_USBIO_SUSPEND_DEL_SHIFT)))
    #define RELAY2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(RELAY2__PC)
    /* Port Configuration */
    #define RELAY2_PC                 (* (reg32 *) RELAY2__PC)
#endif
/* Pin State */
#define RELAY2_PS                     (* (reg32 *) RELAY2__PS)
/* Data Register */
#define RELAY2_DR                     (* (reg32 *) RELAY2__DR)
/* Input Buffer Disable Override */
#define RELAY2_INP_DIS                (* (reg32 *) RELAY2__PC2)

/* Interrupt configuration Registers */
#define RELAY2_INTCFG                 (* (reg32 *) RELAY2__INTCFG)
#define RELAY2_INTSTAT                (* (reg32 *) RELAY2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define RELAY2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(RELAY2__SIO)
    #define RELAY2_SIO_REG            (* (reg32 *) RELAY2__SIO)
#endif /* (RELAY2__SIO_CFG) */

/* USBIO registers */
#if !defined(RELAY2__PC) && (CY_PSOC4_4200L)
    #define RELAY2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define RELAY2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define RELAY2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define RELAY2_DRIVE_MODE_SHIFT       (0x00u)
#define RELAY2_DRIVE_MODE_MASK        (0x07u << RELAY2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins RELAY2_H */


/* [] END OF FILE */
