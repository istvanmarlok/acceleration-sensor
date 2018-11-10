/*******************************************************************************
* File Name: AN_Audio.c  
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
#include "AN_Audio.h"

static AN_Audio_BACKUP_STRUCT  AN_Audio_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: AN_Audio_Sleep
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
*  \snippet AN_Audio_SUT.c usage_AN_Audio_Sleep_Wakeup
*******************************************************************************/
void AN_Audio_Sleep(void)
{
    #if defined(AN_Audio__PC)
        AN_Audio_backup.pcState = AN_Audio_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            AN_Audio_backup.usbState = AN_Audio_CR1_REG;
            AN_Audio_USB_POWER_REG |= AN_Audio_USBIO_ENTER_SLEEP;
            AN_Audio_CR1_REG &= AN_Audio_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(AN_Audio__SIO)
        AN_Audio_backup.sioState = AN_Audio_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        AN_Audio_SIO_REG &= (uint32)(~AN_Audio_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: AN_Audio_Wakeup
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
*  Refer to AN_Audio_Sleep() for an example usage.
*******************************************************************************/
void AN_Audio_Wakeup(void)
{
    #if defined(AN_Audio__PC)
        AN_Audio_PC = AN_Audio_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            AN_Audio_USB_POWER_REG &= AN_Audio_USBIO_EXIT_SLEEP_PH1;
            AN_Audio_CR1_REG = AN_Audio_backup.usbState;
            AN_Audio_USB_POWER_REG &= AN_Audio_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(AN_Audio__SIO)
        AN_Audio_SIO_REG = AN_Audio_backup.sioState;
    #endif
}


/* [] END OF FILE */
