/***************************************************************************//**
* \file SPI_Flash_PM.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_Flash.h"
#include "SPI_Flash_PVT.h"

#if(SPI_Flash_SCB_MODE_I2C_INC)
    #include "SPI_Flash_I2C_PVT.h"
#endif /* (SPI_Flash_SCB_MODE_I2C_INC) */

#if(SPI_Flash_SCB_MODE_EZI2C_INC)
    #include "SPI_Flash_EZI2C_PVT.h"
#endif /* (SPI_Flash_SCB_MODE_EZI2C_INC) */

#if(SPI_Flash_SCB_MODE_SPI_INC || SPI_Flash_SCB_MODE_UART_INC)
    #include "SPI_Flash_SPI_UART_PVT.h"
#endif /* (SPI_Flash_SCB_MODE_SPI_INC || SPI_Flash_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG || \
   (SPI_Flash_SCB_MODE_I2C_CONST_CFG   && (!SPI_Flash_I2C_WAKE_ENABLE_CONST))   || \
   (SPI_Flash_SCB_MODE_EZI2C_CONST_CFG && (!SPI_Flash_EZI2C_WAKE_ENABLE_CONST)) || \
   (SPI_Flash_SCB_MODE_SPI_CONST_CFG   && (!SPI_Flash_SPI_WAKE_ENABLE_CONST))   || \
   (SPI_Flash_SCB_MODE_UART_CONST_CFG  && (!SPI_Flash_UART_WAKE_ENABLE_CONST)))

    SPI_Flash_BACKUP_STRUCT SPI_Flash_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: SPI_Flash_Sleep
****************************************************************************//**
*
*  Prepares the SPI_Flash component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the SPI_Flash_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void SPI_Flash_Sleep(void)
{
#if(SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPI_Flash_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPI_Flash_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI_Flash_I2CSaveConfig();
        }
        else if(SPI_Flash_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI_Flash_EzI2CSaveConfig();
        }
    #if(!SPI_Flash_CY_SCBIP_V1)
        else if(SPI_Flash_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI_Flash_SpiSaveConfig();
        }
        else if(SPI_Flash_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI_Flash_UartSaveConfig();
        }
    #endif /* (!SPI_Flash_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        SPI_Flash_backup.enableState = (uint8) SPI_Flash_GET_CTRL_ENABLED;

        if(0u != SPI_Flash_backup.enableState)
        {
            SPI_Flash_Stop();
        }
    }

#else

    #if (SPI_Flash_SCB_MODE_I2C_CONST_CFG && SPI_Flash_I2C_WAKE_ENABLE_CONST)
        SPI_Flash_I2CSaveConfig();

    #elif (SPI_Flash_SCB_MODE_EZI2C_CONST_CFG && SPI_Flash_EZI2C_WAKE_ENABLE_CONST)
        SPI_Flash_EzI2CSaveConfig();

    #elif (SPI_Flash_SCB_MODE_SPI_CONST_CFG && SPI_Flash_SPI_WAKE_ENABLE_CONST)
        SPI_Flash_SpiSaveConfig();

    #elif (SPI_Flash_SCB_MODE_UART_CONST_CFG && SPI_Flash_UART_WAKE_ENABLE_CONST)
        SPI_Flash_UartSaveConfig();

    #else

        SPI_Flash_backup.enableState = (uint8) SPI_Flash_GET_CTRL_ENABLED;

        if(0u != SPI_Flash_backup.enableState)
        {
            SPI_Flash_Stop();
        }

    #endif /* defined (SPI_Flash_SCB_MODE_I2C_CONST_CFG) && (SPI_Flash_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI_Flash_Wakeup
****************************************************************************//**
*
*  Prepares the SPI_Flash component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the SPI_Flash_Wakeup() function without first calling the 
*   SPI_Flash_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void SPI_Flash_Wakeup(void)
{
#if(SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPI_Flash_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPI_Flash_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI_Flash_I2CRestoreConfig();
        }
        else if(SPI_Flash_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI_Flash_EzI2CRestoreConfig();
        }
    #if(!SPI_Flash_CY_SCBIP_V1)
        else if(SPI_Flash_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI_Flash_SpiRestoreConfig();
        }
        else if(SPI_Flash_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI_Flash_UartRestoreConfig();
        }
    #endif /* (!SPI_Flash_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != SPI_Flash_backup.enableState)
        {
            SPI_Flash_Enable();
        }
    }

#else

    #if (SPI_Flash_SCB_MODE_I2C_CONST_CFG  && SPI_Flash_I2C_WAKE_ENABLE_CONST)
        SPI_Flash_I2CRestoreConfig();

    #elif (SPI_Flash_SCB_MODE_EZI2C_CONST_CFG && SPI_Flash_EZI2C_WAKE_ENABLE_CONST)
        SPI_Flash_EzI2CRestoreConfig();

    #elif (SPI_Flash_SCB_MODE_SPI_CONST_CFG && SPI_Flash_SPI_WAKE_ENABLE_CONST)
        SPI_Flash_SpiRestoreConfig();

    #elif (SPI_Flash_SCB_MODE_UART_CONST_CFG && SPI_Flash_UART_WAKE_ENABLE_CONST)
        SPI_Flash_UartRestoreConfig();

    #else

        if(0u != SPI_Flash_backup.enableState)
        {
            SPI_Flash_Enable();
        }

    #endif /* (SPI_Flash_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPI_Flash_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
