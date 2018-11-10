/*******************************************************************************
* File Name: CPU_Clk.c
* Version 2.20
*
*  Description:
*   Provides system API for the clocking, interrupts and watchdog timer.
*
*  Note:
*   Documentation of the API's in this file is located in the
*   System Reference Guide provided with PSoC Creator.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <cydevice_trm.h>
#include "CPU_Clk.h"

#if defined CYREG_PERI_DIV_CMD

/*******************************************************************************
* Function Name: CPU_Clk_StartEx
********************************************************************************
*
* Summary:
*  Starts the clock, aligned to the specified running clock.
*
* Parameters:
*  alignClkDiv:  The divider to which phase alignment is performed when the
*    clock is started.
*
* Returns:
*  None
*
*******************************************************************************/
void CPU_Clk_StartEx(uint32 alignClkDiv)
{
    /* Make sure any previous start command has finished. */
    while((CPU_Clk_CMD_REG & CPU_Clk_CMD_ENABLE_MASK) != 0u)
    {
    }
    
    /* Specify the target divider and it's alignment divider, and enable. */
    CPU_Clk_CMD_REG =
        ((uint32)CPU_Clk__DIV_ID << CPU_Clk_CMD_DIV_SHIFT)|
        (alignClkDiv << CPU_Clk_CMD_PA_DIV_SHIFT) |
        (uint32)CPU_Clk_CMD_ENABLE_MASK;
}

#else

/*******************************************************************************
* Function Name: CPU_Clk_Start
********************************************************************************
*
* Summary:
*  Starts the clock.
*
* Parameters:
*  None
*
* Returns:
*  None
*
*******************************************************************************/

void CPU_Clk_Start(void)
{
    /* Set the bit to enable the clock. */
    CPU_Clk_ENABLE_REG |= CPU_Clk__ENABLE_MASK;
}

#endif /* CYREG_PERI_DIV_CMD */


/*******************************************************************************
* Function Name: CPU_Clk_Stop
********************************************************************************
*
* Summary:
*  Stops the clock and returns immediately. This API does not require the
*  source clock to be running but may return before the hardware is actually
*  disabled.
*
* Parameters:
*  None
*
* Returns:
*  None
*
*******************************************************************************/
void CPU_Clk_Stop(void)
{
#if defined CYREG_PERI_DIV_CMD

    /* Make sure any previous start command has finished. */
    while((CPU_Clk_CMD_REG & CPU_Clk_CMD_ENABLE_MASK) != 0u)
    {
    }
    
    /* Specify the target divider and it's alignment divider, and disable. */
    CPU_Clk_CMD_REG =
        ((uint32)CPU_Clk__DIV_ID << CPU_Clk_CMD_DIV_SHIFT)|
        ((uint32)CPU_Clk_CMD_DISABLE_MASK);

#else

    /* Clear the bit to disable the clock. */
    CPU_Clk_ENABLE_REG &= (uint32)(~CPU_Clk__ENABLE_MASK);
    
#endif /* CYREG_PERI_DIV_CMD */
}


/*******************************************************************************
* Function Name: CPU_Clk_SetFractionalDividerRegister
********************************************************************************
*
* Summary:
*  Modifies the clock divider and the fractional divider.
*
* Parameters:
*  clkDivider:  Divider register value (0-65535). This value is NOT the
*    divider; the clock hardware divides by clkDivider plus one. For example,
*    to divide the clock by 2, this parameter should be set to 1.
*  fracDivider:  Fractional Divider register value (0-31).
* Returns:
*  None
*
*******************************************************************************/
void CPU_Clk_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional)
{
    uint32 maskVal;
    uint32 regVal;
    
#if defined (CPU_Clk__FRAC_MASK) || defined (CYREG_PERI_DIV_CMD)
    
	/* get all but divider bits */
    maskVal = CPU_Clk_DIV_REG & 
                    (uint32)(~(uint32)(CPU_Clk_DIV_INT_MASK | CPU_Clk_DIV_FRAC_MASK)); 
	/* combine mask and new divider vals into 32-bit value */
    regVal = maskVal |
        ((uint32)((uint32)clkDivider <<  CPU_Clk_DIV_INT_SHIFT) & CPU_Clk_DIV_INT_MASK) |
        ((uint32)((uint32)clkFractional << CPU_Clk_DIV_FRAC_SHIFT) & CPU_Clk_DIV_FRAC_MASK);
    
#else
    /* get all but integer divider bits */
    maskVal = CPU_Clk_DIV_REG & (uint32)(~(uint32)CPU_Clk__DIVIDER_MASK);
    /* combine mask and new divider val into 32-bit value */
    regVal = clkDivider | maskVal;
    
#endif /* CPU_Clk__FRAC_MASK || CYREG_PERI_DIV_CMD */

    CPU_Clk_DIV_REG = regVal;
}


/*******************************************************************************
* Function Name: CPU_Clk_GetDividerRegister
********************************************************************************
*
* Summary:
*  Gets the clock divider register value.
*
* Parameters:
*  None
*
* Returns:
*  Divide value of the clock minus 1. For example, if the clock is set to
*  divide by 2, the return value will be 1.
*
*******************************************************************************/
uint16 CPU_Clk_GetDividerRegister(void)
{
    return (uint16)((CPU_Clk_DIV_REG & CPU_Clk_DIV_INT_MASK)
        >> CPU_Clk_DIV_INT_SHIFT);
}


/*******************************************************************************
* Function Name: CPU_Clk_GetFractionalDividerRegister
********************************************************************************
*
* Summary:
*  Gets the clock fractional divider register value.
*
* Parameters:
*  None
*
* Returns:
*  Fractional Divide value of the clock
*  0 if the fractional divider is not in use.
*
*******************************************************************************/
uint8 CPU_Clk_GetFractionalDividerRegister(void)
{
#if defined (CPU_Clk__FRAC_MASK)
    /* return fractional divider bits */
    return (uint8)((CPU_Clk_DIV_REG & CPU_Clk_DIV_FRAC_MASK)
        >> CPU_Clk_DIV_FRAC_SHIFT);
#else
    return 0u;
#endif /* CPU_Clk__FRAC_MASK */
}


/* [] END OF FILE */
