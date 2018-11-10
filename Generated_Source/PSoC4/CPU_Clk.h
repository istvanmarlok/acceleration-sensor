/*******************************************************************************
* File Name: CPU_Clk.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CPU_Clk_H)
#define CY_CLOCK_CPU_Clk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void CPU_Clk_StartEx(uint32 alignClkDiv);
#define CPU_Clk_Start() \
    CPU_Clk_StartEx(CPU_Clk__PA_DIV_ID)

#else

void CPU_Clk_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void CPU_Clk_Stop(void);

void CPU_Clk_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CPU_Clk_GetDividerRegister(void);
uint8  CPU_Clk_GetFractionalDividerRegister(void);

#define CPU_Clk_Enable()                         CPU_Clk_Start()
#define CPU_Clk_Disable()                        CPU_Clk_Stop()
#define CPU_Clk_SetDividerRegister(clkDivider, reset)  \
    CPU_Clk_SetFractionalDividerRegister((clkDivider), 0u)
#define CPU_Clk_SetDivider(clkDivider)           CPU_Clk_SetDividerRegister((clkDivider), 1u)
#define CPU_Clk_SetDividerValue(clkDivider)      CPU_Clk_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define CPU_Clk_DIV_ID     CPU_Clk__DIV_ID

#define CPU_Clk_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define CPU_Clk_CTRL_REG   (*(reg32 *)CPU_Clk__CTRL_REGISTER)
#define CPU_Clk_DIV_REG    (*(reg32 *)CPU_Clk__DIV_REGISTER)

#define CPU_Clk_CMD_DIV_SHIFT          (0u)
#define CPU_Clk_CMD_PA_DIV_SHIFT       (8u)
#define CPU_Clk_CMD_DISABLE_SHIFT      (30u)
#define CPU_Clk_CMD_ENABLE_SHIFT       (31u)

#define CPU_Clk_CMD_DISABLE_MASK       ((uint32)((uint32)1u << CPU_Clk_CMD_DISABLE_SHIFT))
#define CPU_Clk_CMD_ENABLE_MASK        ((uint32)((uint32)1u << CPU_Clk_CMD_ENABLE_SHIFT))

#define CPU_Clk_DIV_FRAC_MASK  (0x000000F8u)
#define CPU_Clk_DIV_FRAC_SHIFT (3u)
#define CPU_Clk_DIV_INT_MASK   (0xFFFFFF00u)
#define CPU_Clk_DIV_INT_SHIFT  (8u)

#else 

#define CPU_Clk_DIV_REG        (*(reg32 *)CPU_Clk__REGISTER)
#define CPU_Clk_ENABLE_REG     CPU_Clk_DIV_REG
#define CPU_Clk_DIV_FRAC_MASK  CPU_Clk__FRAC_MASK
#define CPU_Clk_DIV_FRAC_SHIFT (16u)
#define CPU_Clk_DIV_INT_MASK   CPU_Clk__DIVIDER_MASK
#define CPU_Clk_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_CPU_Clk_H) */

/* [] END OF FILE */
