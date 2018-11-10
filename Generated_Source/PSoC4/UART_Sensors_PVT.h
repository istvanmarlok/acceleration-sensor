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

#if !defined(CY_SCB_PVT_UART_Sensors_H)
#define CY_SCB_PVT_UART_Sensors_H

#include "UART_Sensors.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UART_Sensors_SetI2CExtClkInterruptMode(interruptMask) UART_Sensors_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UART_Sensors_ClearI2CExtClkInterruptSource(interruptMask) UART_Sensors_CLEAR_INTR_I2C_EC(interruptMask)
#define UART_Sensors_GetI2CExtClkInterruptSource()                (UART_Sensors_INTR_I2C_EC_REG)
#define UART_Sensors_GetI2CExtClkInterruptMode()                  (UART_Sensors_INTR_I2C_EC_MASK_REG)
#define UART_Sensors_GetI2CExtClkInterruptSourceMasked()          (UART_Sensors_INTR_I2C_EC_MASKED_REG)

#if (!UART_Sensors_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define UART_Sensors_SetSpiExtClkInterruptMode(interruptMask) \
                                                                UART_Sensors_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define UART_Sensors_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                UART_Sensors_CLEAR_INTR_SPI_EC(interruptMask)
    #define UART_Sensors_GetExtSpiClkInterruptSource()                 (UART_Sensors_INTR_SPI_EC_REG)
    #define UART_Sensors_GetExtSpiClkInterruptMode()                   (UART_Sensors_INTR_SPI_EC_MASK_REG)
    #define UART_Sensors_GetExtSpiClkInterruptSourceMasked()           (UART_Sensors_INTR_SPI_EC_MASKED_REG)
#endif /* (!UART_Sensors_CY_SCBIP_V1) */

#if(UART_Sensors_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UART_Sensors_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (UART_Sensors_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (UART_Sensors_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_UART_Sensors_CUSTOM_INTR_HANDLER)
    extern cyisraddress UART_Sensors_customIntrHandler;
#endif /* !defined (CY_REMOVE_UART_Sensors_CUSTOM_INTR_HANDLER) */
#endif /* (UART_Sensors_SCB_IRQ_INTERNAL) */

extern UART_Sensors_BACKUP_STRUCT UART_Sensors_backup;

#if(UART_Sensors_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 UART_Sensors_scbMode;
    extern uint8 UART_Sensors_scbEnableWake;
    extern uint8 UART_Sensors_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 UART_Sensors_mode;
    extern uint8 UART_Sensors_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * UART_Sensors_rxBuffer;
    extern uint8   UART_Sensors_rxDataBits;
    extern uint32  UART_Sensors_rxBufferSize;

    extern volatile uint8 * UART_Sensors_txBuffer;
    extern uint8   UART_Sensors_txDataBits;
    extern uint32  UART_Sensors_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 UART_Sensors_numberOfAddr;
    extern uint8 UART_Sensors_subAddrSize;
#endif /* (UART_Sensors_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (UART_Sensors_SCB_MODE_I2C_CONST_CFG || \
        UART_Sensors_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 UART_Sensors_IntrTxMask;
#endif /* (! (UART_Sensors_SCB_MODE_I2C_CONST_CFG || \
              UART_Sensors_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(UART_Sensors_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define UART_Sensors_SCB_MODE_I2C_RUNTM_CFG     (UART_Sensors_SCB_MODE_I2C      == UART_Sensors_scbMode)
    #define UART_Sensors_SCB_MODE_SPI_RUNTM_CFG     (UART_Sensors_SCB_MODE_SPI      == UART_Sensors_scbMode)
    #define UART_Sensors_SCB_MODE_UART_RUNTM_CFG    (UART_Sensors_SCB_MODE_UART     == UART_Sensors_scbMode)
    #define UART_Sensors_SCB_MODE_EZI2C_RUNTM_CFG   (UART_Sensors_SCB_MODE_EZI2C    == UART_Sensors_scbMode)
    #define UART_Sensors_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (UART_Sensors_SCB_MODE_UNCONFIG == UART_Sensors_scbMode)

    /* Defines wakeup enable */
    #define UART_Sensors_SCB_WAKE_ENABLE_CHECK       (0u != UART_Sensors_scbEnableWake)
#endif /* (UART_Sensors_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!UART_Sensors_CY_SCBIP_V1)
    #define UART_Sensors_SCB_PINS_NUMBER    (7u)
#else
    #define UART_Sensors_SCB_PINS_NUMBER    (2u)
#endif /* (!UART_Sensors_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_UART_Sensors_H) */


/* [] END OF FILE */
