/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_SPI_Flash_H)
#define CY_SCB_PVT_SPI_Flash_H

#include "SPI_Flash.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define SPI_Flash_SetI2CExtClkInterruptMode(interruptMask) SPI_Flash_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define SPI_Flash_ClearI2CExtClkInterruptSource(interruptMask) SPI_Flash_CLEAR_INTR_I2C_EC(interruptMask)
#define SPI_Flash_GetI2CExtClkInterruptSource()                (SPI_Flash_INTR_I2C_EC_REG)
#define SPI_Flash_GetI2CExtClkInterruptMode()                  (SPI_Flash_INTR_I2C_EC_MASK_REG)
#define SPI_Flash_GetI2CExtClkInterruptSourceMasked()          (SPI_Flash_INTR_I2C_EC_MASKED_REG)

#if (!SPI_Flash_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define SPI_Flash_SetSpiExtClkInterruptMode(interruptMask) \
                                                                SPI_Flash_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define SPI_Flash_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                SPI_Flash_CLEAR_INTR_SPI_EC(interruptMask)
    #define SPI_Flash_GetExtSpiClkInterruptSource()                 (SPI_Flash_INTR_SPI_EC_REG)
    #define SPI_Flash_GetExtSpiClkInterruptMode()                   (SPI_Flash_INTR_SPI_EC_MASK_REG)
    #define SPI_Flash_GetExtSpiClkInterruptSourceMasked()           (SPI_Flash_INTR_SPI_EC_MASKED_REG)
#endif /* (!SPI_Flash_CY_SCBIP_V1) */

#if(SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void SPI_Flash_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (SPI_Flash_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_SPI_Flash_CUSTOM_INTR_HANDLER)
    extern cyisraddress SPI_Flash_customIntrHandler;
#endif /* !defined (CY_REMOVE_SPI_Flash_CUSTOM_INTR_HANDLER) */
#endif /* (SPI_Flash_SCB_IRQ_INTERNAL) */

extern SPI_Flash_BACKUP_STRUCT SPI_Flash_backup;

#if(SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 SPI_Flash_scbMode;
    extern uint8 SPI_Flash_scbEnableWake;
    extern uint8 SPI_Flash_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 SPI_Flash_mode;
    extern uint8 SPI_Flash_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * SPI_Flash_rxBuffer;
    extern uint8   SPI_Flash_rxDataBits;
    extern uint32  SPI_Flash_rxBufferSize;

    extern volatile uint8 * SPI_Flash_txBuffer;
    extern uint8   SPI_Flash_txDataBits;
    extern uint32  SPI_Flash_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 SPI_Flash_numberOfAddr;
    extern uint8 SPI_Flash_subAddrSize;
#endif /* (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (SPI_Flash_SCB_MODE_I2C_CONST_CFG || \
        SPI_Flash_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 SPI_Flash_IntrTxMask;
#endif /* (! (SPI_Flash_SCB_MODE_I2C_CONST_CFG || \
              SPI_Flash_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define SPI_Flash_SCB_MODE_I2C_RUNTM_CFG     (SPI_Flash_SCB_MODE_I2C      == SPI_Flash_scbMode)
    #define SPI_Flash_SCB_MODE_SPI_RUNTM_CFG     (SPI_Flash_SCB_MODE_SPI      == SPI_Flash_scbMode)
    #define SPI_Flash_SCB_MODE_UART_RUNTM_CFG    (SPI_Flash_SCB_MODE_UART     == SPI_Flash_scbMode)
    #define SPI_Flash_SCB_MODE_EZI2C_RUNTM_CFG   (SPI_Flash_SCB_MODE_EZI2C    == SPI_Flash_scbMode)
    #define SPI_Flash_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (SPI_Flash_SCB_MODE_UNCONFIG == SPI_Flash_scbMode)

    /* Defines wakeup enable */
    #define SPI_Flash_SCB_WAKE_ENABLE_CHECK       (0u != SPI_Flash_scbEnableWake)
#endif /* (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!SPI_Flash_CY_SCBIP_V1)
    #define SPI_Flash_SCB_PINS_NUMBER    (7u)
#else
    #define SPI_Flash_SCB_PINS_NUMBER    (2u)
#endif /* (!SPI_Flash_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_SPI_Flash_H) */


/* [] END OF FILE */
