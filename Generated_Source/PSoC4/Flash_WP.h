/*******************************************************************************
* File Name: Flash_WP.h  
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

#if !defined(CY_PINS_Flash_WP_H) /* Pins Flash_WP_H */
#define CY_PINS_Flash_WP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Flash_WP_aliases.h"


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
} Flash_WP_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Flash_WP_Read(void);
void    Flash_WP_Write(uint8 value);
uint8   Flash_WP_ReadDataReg(void);
#if defined(Flash_WP__PC) || (CY_PSOC4_4200L) 
    void    Flash_WP_SetDriveMode(uint8 mode);
#endif
void    Flash_WP_SetInterruptMode(uint16 position, uint16 mode);
uint8   Flash_WP_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Flash_WP_Sleep(void); 
void Flash_WP_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Flash_WP__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Flash_WP_DRIVE_MODE_BITS        (3)
    #define Flash_WP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Flash_WP_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Flash_WP_SetDriveMode() function.
         *  @{
         */
        #define Flash_WP_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Flash_WP_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Flash_WP_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Flash_WP_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Flash_WP_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Flash_WP_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Flash_WP_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Flash_WP_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Flash_WP_MASK               Flash_WP__MASK
#define Flash_WP_SHIFT              Flash_WP__SHIFT
#define Flash_WP_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Flash_WP_SetInterruptMode() function.
     *  @{
     */
        #define Flash_WP_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Flash_WP_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Flash_WP_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Flash_WP_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Flash_WP__SIO)
    #define Flash_WP_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Flash_WP__PC) && (CY_PSOC4_4200L)
    #define Flash_WP_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Flash_WP_USBIO_DISABLE              ((uint32)(~Flash_WP_USBIO_ENABLE))
    #define Flash_WP_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Flash_WP_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Flash_WP_USBIO_ENTER_SLEEP          ((uint32)((1u << Flash_WP_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Flash_WP_USBIO_SUSPEND_DEL_SHIFT)))
    #define Flash_WP_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Flash_WP_USBIO_SUSPEND_SHIFT)))
    #define Flash_WP_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Flash_WP_USBIO_SUSPEND_DEL_SHIFT)))
    #define Flash_WP_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Flash_WP__PC)
    /* Port Configuration */
    #define Flash_WP_PC                 (* (reg32 *) Flash_WP__PC)
#endif
/* Pin State */
#define Flash_WP_PS                     (* (reg32 *) Flash_WP__PS)
/* Data Register */
#define Flash_WP_DR                     (* (reg32 *) Flash_WP__DR)
/* Input Buffer Disable Override */
#define Flash_WP_INP_DIS                (* (reg32 *) Flash_WP__PC2)

/* Interrupt configuration Registers */
#define Flash_WP_INTCFG                 (* (reg32 *) Flash_WP__INTCFG)
#define Flash_WP_INTSTAT                (* (reg32 *) Flash_WP__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Flash_WP_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Flash_WP__SIO)
    #define Flash_WP_SIO_REG            (* (reg32 *) Flash_WP__SIO)
#endif /* (Flash_WP__SIO_CFG) */

/* USBIO registers */
#if !defined(Flash_WP__PC) && (CY_PSOC4_4200L)
    #define Flash_WP_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Flash_WP_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Flash_WP_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Flash_WP_DRIVE_MODE_SHIFT       (0x00u)
#define Flash_WP_DRIVE_MODE_MASK        (0x07u << Flash_WP_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Flash_WP_H */


/* [] END OF FILE */
