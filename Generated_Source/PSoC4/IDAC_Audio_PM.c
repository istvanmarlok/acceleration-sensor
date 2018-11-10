/*******************************************************************************
* File Name: IDAC_Audio_PM.c
* Version 1.10
*
* Description:
*  This file provides Low power mode APIs for IDAC_P4 component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IDAC_Audio.h"


static IDAC_Audio_BACKUP_STRUCT IDAC_Audio_backup;


/*******************************************************************************
* Function Name: IDAC_Audio_SaveConfig
********************************************************************************
*
* Summary:
*  Saves component state before sleep
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
*******************************************************************************/
void IDAC_Audio_SaveConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC_Audio_Sleep
********************************************************************************
*
* Summary:
*  Calls _SaveConfig() function
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IDAC_Audio_Sleep(void)
{
        if(0u != (IDAC_Audio_IDAC_CONTROL_REG & ((uint32)IDAC_Audio_IDAC_MODE_MASK <<
        IDAC_Audio_IDAC_MODE_POSITION)))
        {
            IDAC_Audio_backup.enableState = 1u;
        }
        else
        {
            IDAC_Audio_backup.enableState = 0u;
        }

    IDAC_Audio_Stop();
    IDAC_Audio_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC_Audio_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores component state after wakeup
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
*******************************************************************************/
void IDAC_Audio_RestoreConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC_Audio_Wakeup
********************************************************************************
*
* Summary:
*  Calls _RestoreConfig() function
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IDAC_Audio_Wakeup(void)
{
    /* Restore IDAC register settings */
    IDAC_Audio_RestoreConfig();
    if(IDAC_Audio_backup.enableState == 1u)
    {
        /* Enable operation */
        IDAC_Audio_Enable();
    } /* Do nothing if the component was disabled before */

}


/* [] END OF FILE */
