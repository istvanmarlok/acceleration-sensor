/*******************************************************************************
* File Name: IDAC_Light_Voltage.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "IDAC_Light_Voltage.h"

static IDAC_Light_Voltage_BACKUP_STRUCT  IDAC_Light_Voltage_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: IDAC_Light_Voltage_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet IDAC_Light_Voltage_SUT.c usage_IDAC_Light_Voltage_Sleep_Wakeup
*******************************************************************************/
void IDAC_Light_Voltage_Sleep(void)
{
    #if defined(IDAC_Light_Voltage__PC)
        IDAC_Light_Voltage_backup.pcState = IDAC_Light_Voltage_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            IDAC_Light_Voltage_backup.usbState = IDAC_Light_Voltage_CR1_REG;
            IDAC_Light_Voltage_USB_POWER_REG |= IDAC_Light_Voltage_USBIO_ENTER_SLEEP;
            IDAC_Light_Voltage_CR1_REG &= IDAC_Light_Voltage_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(IDAC_Light_Voltage__SIO)
        IDAC_Light_Voltage_backup.sioState = IDAC_Light_Voltage_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        IDAC_Light_Voltage_SIO_REG &= (uint32)(~IDAC_Light_Voltage_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: IDAC_Light_Voltage_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to IDAC_Light_Voltage_Sleep() for an example usage.
*******************************************************************************/
void IDAC_Light_Voltage_Wakeup(void)
{
    #if defined(IDAC_Light_Voltage__PC)
        IDAC_Light_Voltage_PC = IDAC_Light_Voltage_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            IDAC_Light_Voltage_USB_POWER_REG &= IDAC_Light_Voltage_USBIO_EXIT_SLEEP_PH1;
            IDAC_Light_Voltage_CR1_REG = IDAC_Light_Voltage_backup.usbState;
            IDAC_Light_Voltage_USB_POWER_REG &= IDAC_Light_Voltage_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(IDAC_Light_Voltage__SIO)
        IDAC_Light_Voltage_SIO_REG = IDAC_Light_Voltage_backup.sioState;
    #endif
}


/* [] END OF FILE */
