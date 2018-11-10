/***************************************************************************//**
* \file SPI_Flash_BOOT.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_SPI_Flash_H)
#define CY_SCB_BOOT_SPI_Flash_H

#include "SPI_Flash_PVT.h"

#if (SPI_Flash_SCB_MODE_I2C_INC)
    #include "SPI_Flash_I2C.h"
#endif /* (SPI_Flash_SCB_MODE_I2C_INC) */

#if (SPI_Flash_SCB_MODE_EZI2C_INC)
    #include "SPI_Flash_EZI2C.h"
#endif /* (SPI_Flash_SCB_MODE_EZI2C_INC) */

#if (SPI_Flash_SCB_MODE_SPI_INC || SPI_Flash_SCB_MODE_UART_INC)
    #include "SPI_Flash_SPI_UART.h"
#endif /* (SPI_Flash_SCB_MODE_SPI_INC || SPI_Flash_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define SPI_Flash_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI_Flash) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (SPI_Flash_SCB_MODE_I2C_INC)
    #define SPI_Flash_I2C_BTLDR_COMM_ENABLED     (SPI_Flash_BTLDR_COMM_ENABLED && \
                                                            (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             SPI_Flash_I2C_SLAVE_CONST))
#else
     #define SPI_Flash_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (SPI_Flash_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (SPI_Flash_SCB_MODE_EZI2C_INC)
    #define SPI_Flash_EZI2C_BTLDR_COMM_ENABLED   (SPI_Flash_BTLDR_COMM_ENABLED && \
                                                         SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define SPI_Flash_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (SPI_Flash_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (SPI_Flash_SCB_MODE_SPI_INC)
    #define SPI_Flash_SPI_BTLDR_COMM_ENABLED     (SPI_Flash_BTLDR_COMM_ENABLED && \
                                                            (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             SPI_Flash_SPI_SLAVE_CONST))
#else
        #define SPI_Flash_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (SPI_Flash_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (SPI_Flash_SCB_MODE_UART_INC)
       #define SPI_Flash_UART_BTLDR_COMM_ENABLED    (SPI_Flash_BTLDR_COMM_ENABLED && \
                                                            (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (SPI_Flash_UART_RX_DIRECTION && \
                                                              SPI_Flash_UART_TX_DIRECTION)))
#else
     #define SPI_Flash_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (SPI_Flash_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define SPI_Flash_BTLDR_COMM_MODE_ENABLED    (SPI_Flash_I2C_BTLDR_COMM_ENABLED   || \
                                                     SPI_Flash_SPI_BTLDR_COMM_ENABLED   || \
                                                     SPI_Flash_EZI2C_BTLDR_COMM_ENABLED || \
                                                     SPI_Flash_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void SPI_Flash_I2CCyBtldrCommStart(void);
    void SPI_Flash_I2CCyBtldrCommStop (void);
    void SPI_Flash_I2CCyBtldrCommReset(void);
    cystatus SPI_Flash_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_Flash_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_Flash_SCB_MODE_I2C_CONST_CFG)
        #define SPI_Flash_CyBtldrCommStart   SPI_Flash_I2CCyBtldrCommStart
        #define SPI_Flash_CyBtldrCommStop    SPI_Flash_I2CCyBtldrCommStop
        #define SPI_Flash_CyBtldrCommReset   SPI_Flash_I2CCyBtldrCommReset
        #define SPI_Flash_CyBtldrCommRead    SPI_Flash_I2CCyBtldrCommRead
        #define SPI_Flash_CyBtldrCommWrite   SPI_Flash_I2CCyBtldrCommWrite
    #endif /* (SPI_Flash_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void SPI_Flash_EzI2CCyBtldrCommStart(void);
    void SPI_Flash_EzI2CCyBtldrCommStop (void);
    void SPI_Flash_EzI2CCyBtldrCommReset(void);
    cystatus SPI_Flash_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_Flash_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_Flash_SCB_MODE_EZI2C_CONST_CFG)
        #define SPI_Flash_CyBtldrCommStart   SPI_Flash_EzI2CCyBtldrCommStart
        #define SPI_Flash_CyBtldrCommStop    SPI_Flash_EzI2CCyBtldrCommStop
        #define SPI_Flash_CyBtldrCommReset   SPI_Flash_EzI2CCyBtldrCommReset
        #define SPI_Flash_CyBtldrCommRead    SPI_Flash_EzI2CCyBtldrCommRead
        #define SPI_Flash_CyBtldrCommWrite   SPI_Flash_EzI2CCyBtldrCommWrite
    #endif /* (SPI_Flash_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void SPI_Flash_SpiCyBtldrCommStart(void);
    void SPI_Flash_SpiCyBtldrCommStop (void);
    void SPI_Flash_SpiCyBtldrCommReset(void);
    cystatus SPI_Flash_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_Flash_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_Flash_SCB_MODE_SPI_CONST_CFG)
        #define SPI_Flash_CyBtldrCommStart   SPI_Flash_SpiCyBtldrCommStart
        #define SPI_Flash_CyBtldrCommStop    SPI_Flash_SpiCyBtldrCommStop
        #define SPI_Flash_CyBtldrCommReset   SPI_Flash_SpiCyBtldrCommReset
        #define SPI_Flash_CyBtldrCommRead    SPI_Flash_SpiCyBtldrCommRead
        #define SPI_Flash_CyBtldrCommWrite   SPI_Flash_SpiCyBtldrCommWrite
    #endif /* (SPI_Flash_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void SPI_Flash_UartCyBtldrCommStart(void);
    void SPI_Flash_UartCyBtldrCommStop (void);
    void SPI_Flash_UartCyBtldrCommReset(void);
    cystatus SPI_Flash_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_Flash_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_Flash_SCB_MODE_UART_CONST_CFG)
        #define SPI_Flash_CyBtldrCommStart   SPI_Flash_UartCyBtldrCommStart
        #define SPI_Flash_CyBtldrCommStop    SPI_Flash_UartCyBtldrCommStop
        #define SPI_Flash_CyBtldrCommReset   SPI_Flash_UartCyBtldrCommReset
        #define SPI_Flash_CyBtldrCommRead    SPI_Flash_UartCyBtldrCommRead
        #define SPI_Flash_CyBtldrCommWrite   SPI_Flash_UartCyBtldrCommWrite
    #endif /* (SPI_Flash_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_BTLDR_COMM_ENABLED)
    #if (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void SPI_Flash_CyBtldrCommStart(void);
        void SPI_Flash_CyBtldrCommStop (void);
        void SPI_Flash_CyBtldrCommReset(void);
        cystatus SPI_Flash_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus SPI_Flash_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI_Flash)
        #define CyBtldrCommStart    SPI_Flash_CyBtldrCommStart
        #define CyBtldrCommStop     SPI_Flash_CyBtldrCommStop
        #define CyBtldrCommReset    SPI_Flash_CyBtldrCommReset
        #define CyBtldrCommWrite    SPI_Flash_CyBtldrCommWrite
        #define CyBtldrCommRead     SPI_Flash_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI_Flash) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Flash_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define SPI_Flash_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define SPI_Flash_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define SPI_Flash_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define SPI_Flash_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef SPI_Flash_SPI_BYTE_TO_BYTE
    #define SPI_Flash_SPI_BYTE_TO_BYTE   (6u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef SPI_Flash_UART_BYTE_TO_BYTE
    #define SPI_Flash_UART_BYTE_TO_BYTE  (2500u)
#endif /* SPI_Flash_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_SPI_Flash_H) */


/* [] END OF FILE */
