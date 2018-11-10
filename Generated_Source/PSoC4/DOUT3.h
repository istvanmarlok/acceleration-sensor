/*******************************************************************************
* File Name: DOUT3.h  
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

#if !defined(CY_PINS_DOUT3_H) /* Pins DOUT3_H */
#define CY_PINS_DOUT3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DOUT3_aliases.h"


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
} DOUT3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DOUT3_Read(void);
void    DOUT3_Write(uint8 value);
uint8   DOUT3_ReadDataReg(void);
#if defined(DOUT3__PC) || (CY_PSOC4_4200L) 
    void    DOUT3_SetDriveMode(uint8 mode);
#endif
void    DOUT3_SetInterruptMode(uint16 position, uint16 mode);
uint8   DOUT3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DOUT3_Sleep(void); 
void DOUT3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DOUT3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DOUT3_DRIVE_MODE_BITS        (3)
    #define DOUT3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DOUT3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DOUT3_SetDriveMode() function.
         *  @{
         */
        #define DOUT3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DOUT3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DOUT3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DOUT3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DOUT3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DOUT3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DOUT3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DOUT3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DOUT3_MASK               DOUT3__MASK
#define DOUT3_SHIFT              DOUT3__SHIFT
#define DOUT3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DOUT3_SetInterruptMode() function.
     *  @{
     */
        #define DOUT3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DOUT3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DOUT3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DOUT3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DOUT3__SIO)
    #define DOUT3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DOUT3__PC) && (CY_PSOC4_4200L)
    #define DOUT3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DOUT3_USBIO_DISABLE              ((uint32)(~DOUT3_USBIO_ENABLE))
    #define DOUT3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DOUT3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DOUT3_USBIO_ENTER_SLEEP          ((uint32)((1u << DOUT3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DOUT3_USBIO_SUSPEND_DEL_SHIFT)))
    #define DOUT3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DOUT3_USBIO_SUSPEND_SHIFT)))
    #define DOUT3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DOUT3_USBIO_SUSPEND_DEL_SHIFT)))
    #define DOUT3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DOUT3__PC)
    /* Port Configuration */
    #define DOUT3_PC                 (* (reg32 *) DOUT3__PC)
#endif
/* Pin State */
#define DOUT3_PS                     (* (reg32 *) DOUT3__PS)
/* Data Register */
#define DOUT3_DR                     (* (reg32 *) DOUT3__DR)
/* Input Buffer Disable Override */
#define DOUT3_INP_DIS                (* (reg32 *) DOUT3__PC2)

/* Interrupt configuration Registers */
#define DOUT3_INTCFG                 (* (reg32 *) DOUT3__INTCFG)
#define DOUT3_INTSTAT                (* (reg32 *) DOUT3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DOUT3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DOUT3__SIO)
    #define DOUT3_SIO_REG            (* (reg32 *) DOUT3__SIO)
#endif /* (DOUT3__SIO_CFG) */

/* USBIO registers */
#if !defined(DOUT3__PC) && (CY_PSOC4_4200L)
    #define DOUT3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DOUT3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DOUT3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DOUT3_DRIVE_MODE_SHIFT       (0x00u)
#define DOUT3_DRIVE_MODE_MASK        (0x07u << DOUT3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DOUT3_H */


/* [] END OF FILE */
