/*******************************************************************************
* File Name: Flash_WP.c  
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
#include "Flash_WP.h"

static Flash_WP_BACKUP_STRUCT  Flash_WP_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Flash_WP_Sleep
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
*  \snippet Flash_WP_SUT.c usage_Flash_WP_Sleep_Wakeup
*******************************************************************************/
void Flash_WP_Sleep(void)
{
    #if defined(Flash_WP__PC)
        Flash_WP_backup.pcState = Flash_WP_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Flash_WP_backup.usbState = Flash_WP_CR1_REG;
            Flash_WP_USB_POWER_REG |= Flash_WP_USBIO_ENTER_SLEEP;
            Flash_WP_CR1_REG &= Flash_WP_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Flash_WP__SIO)
        Flash_WP_backup.sioState = Flash_WP_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Flash_WP_SIO_REG &= (uint32)(~Flash_WP_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Flash_WP_Wakeup
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
*  Refer to Flash_WP_Sleep() for an example usage.
*******************************************************************************/
void Flash_WP_Wakeup(void)
{
    #if defined(Flash_WP__PC)
        Flash_WP_PC = Flash_WP_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Flash_WP_USB_POWER_REG &= Flash_WP_USBIO_EXIT_SLEEP_PH1;
            Flash_WP_CR1_REG = Flash_WP_backup.usbState;
            Flash_WP_USB_POWER_REG &= Flash_WP_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Flash_WP__SIO)
        Flash_WP_SIO_REG = Flash_WP_backup.sioState;
    #endif
}


/* [] END OF FILE */
