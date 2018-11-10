/*******************************************************************************
* File Name: DIN4.c  
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
#include "DIN4.h"

static DIN4_BACKUP_STRUCT  DIN4_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DIN4_Sleep
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
*  \snippet DIN4_SUT.c usage_DIN4_Sleep_Wakeup
*******************************************************************************/
void DIN4_Sleep(void)
{
    #if defined(DIN4__PC)
        DIN4_backup.pcState = DIN4_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DIN4_backup.usbState = DIN4_CR1_REG;
            DIN4_USB_POWER_REG |= DIN4_USBIO_ENTER_SLEEP;
            DIN4_CR1_REG &= DIN4_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DIN4__SIO)
        DIN4_backup.sioState = DIN4_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DIN4_SIO_REG &= (uint32)(~DIN4_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DIN4_Wakeup
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
*  Refer to DIN4_Sleep() for an example usage.
*******************************************************************************/
void DIN4_Wakeup(void)
{
    #if defined(DIN4__PC)
        DIN4_PC = DIN4_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DIN4_USB_POWER_REG &= DIN4_USBIO_EXIT_SLEEP_PH1;
            DIN4_CR1_REG = DIN4_backup.usbState;
            DIN4_USB_POWER_REG &= DIN4_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DIN4__SIO)
        DIN4_SIO_REG = DIN4_backup.sioState;
    #endif
}


/* [] END OF FILE */
