/*******************************************************************************
* File Name: IDAC_Light_Voltage.h  
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

#if !defined(CY_PINS_IDAC_Light_Voltage_H) /* Pins IDAC_Light_Voltage_H */
#define CY_PINS_IDAC_Light_Voltage_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IDAC_Light_Voltage_aliases.h"


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
} IDAC_Light_Voltage_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   IDAC_Light_Voltage_Read(void);
void    IDAC_Light_Voltage_Write(uint8 value);
uint8   IDAC_Light_Voltage_ReadDataReg(void);
#if defined(IDAC_Light_Voltage__PC) || (CY_PSOC4_4200L) 
    void    IDAC_Light_Voltage_SetDriveMode(uint8 mode);
#endif
void    IDAC_Light_Voltage_SetInterruptMode(uint16 position, uint16 mode);
uint8   IDAC_Light_Voltage_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void IDAC_Light_Voltage_Sleep(void); 
void IDAC_Light_Voltage_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(IDAC_Light_Voltage__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define IDAC_Light_Voltage_DRIVE_MODE_BITS        (3)
    #define IDAC_Light_Voltage_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IDAC_Light_Voltage_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the IDAC_Light_Voltage_SetDriveMode() function.
         *  @{
         */
        #define IDAC_Light_Voltage_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define IDAC_Light_Voltage_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define IDAC_Light_Voltage_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define IDAC_Light_Voltage_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define IDAC_Light_Voltage_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define IDAC_Light_Voltage_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define IDAC_Light_Voltage_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define IDAC_Light_Voltage_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define IDAC_Light_Voltage_MASK               IDAC_Light_Voltage__MASK
#define IDAC_Light_Voltage_SHIFT              IDAC_Light_Voltage__SHIFT
#define IDAC_Light_Voltage_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IDAC_Light_Voltage_SetInterruptMode() function.
     *  @{
     */
        #define IDAC_Light_Voltage_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define IDAC_Light_Voltage_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define IDAC_Light_Voltage_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define IDAC_Light_Voltage_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(IDAC_Light_Voltage__SIO)
    #define IDAC_Light_Voltage_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(IDAC_Light_Voltage__PC) && (CY_PSOC4_4200L)
    #define IDAC_Light_Voltage_USBIO_ENABLE               ((uint32)0x80000000u)
    #define IDAC_Light_Voltage_USBIO_DISABLE              ((uint32)(~IDAC_Light_Voltage_USBIO_ENABLE))
    #define IDAC_Light_Voltage_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define IDAC_Light_Voltage_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define IDAC_Light_Voltage_USBIO_ENTER_SLEEP          ((uint32)((1u << IDAC_Light_Voltage_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << IDAC_Light_Voltage_USBIO_SUSPEND_DEL_SHIFT)))
    #define IDAC_Light_Voltage_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << IDAC_Light_Voltage_USBIO_SUSPEND_SHIFT)))
    #define IDAC_Light_Voltage_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << IDAC_Light_Voltage_USBIO_SUSPEND_DEL_SHIFT)))
    #define IDAC_Light_Voltage_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(IDAC_Light_Voltage__PC)
    /* Port Configuration */
    #define IDAC_Light_Voltage_PC                 (* (reg32 *) IDAC_Light_Voltage__PC)
#endif
/* Pin State */
#define IDAC_Light_Voltage_PS                     (* (reg32 *) IDAC_Light_Voltage__PS)
/* Data Register */
#define IDAC_Light_Voltage_DR                     (* (reg32 *) IDAC_Light_Voltage__DR)
/* Input Buffer Disable Override */
#define IDAC_Light_Voltage_INP_DIS                (* (reg32 *) IDAC_Light_Voltage__PC2)

/* Interrupt configuration Registers */
#define IDAC_Light_Voltage_INTCFG                 (* (reg32 *) IDAC_Light_Voltage__INTCFG)
#define IDAC_Light_Voltage_INTSTAT                (* (reg32 *) IDAC_Light_Voltage__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define IDAC_Light_Voltage_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(IDAC_Light_Voltage__SIO)
    #define IDAC_Light_Voltage_SIO_REG            (* (reg32 *) IDAC_Light_Voltage__SIO)
#endif /* (IDAC_Light_Voltage__SIO_CFG) */

/* USBIO registers */
#if !defined(IDAC_Light_Voltage__PC) && (CY_PSOC4_4200L)
    #define IDAC_Light_Voltage_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define IDAC_Light_Voltage_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define IDAC_Light_Voltage_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define IDAC_Light_Voltage_DRIVE_MODE_SHIFT       (0x00u)
#define IDAC_Light_Voltage_DRIVE_MODE_MASK        (0x07u << IDAC_Light_Voltage_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins IDAC_Light_Voltage_H */


/* [] END OF FILE */
