/*******************************************************************************
* File Name: U_Clk.h
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

#if !defined(CY_CLOCK_U_Clk_H)
#define CY_CLOCK_U_Clk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void U_Clk_StartEx(uint32 alignClkDiv);
#define U_Clk_Start() \
    U_Clk_StartEx(U_Clk__PA_DIV_ID)

#else

void U_Clk_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void U_Clk_Stop(void);

void U_Clk_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 U_Clk_GetDividerRegister(void);
uint8  U_Clk_GetFractionalDividerRegister(void);

#define U_Clk_Enable()                         U_Clk_Start()
#define U_Clk_Disable()                        U_Clk_Stop()
#define U_Clk_SetDividerRegister(clkDivider, reset)  \
    U_Clk_SetFractionalDividerRegister((clkDivider), 0u)
#define U_Clk_SetDivider(clkDivider)           U_Clk_SetDividerRegister((clkDivider), 1u)
#define U_Clk_SetDividerValue(clkDivider)      U_Clk_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define U_Clk_DIV_ID     U_Clk__DIV_ID

#define U_Clk_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define U_Clk_CTRL_REG   (*(reg32 *)U_Clk__CTRL_REGISTER)
#define U_Clk_DIV_REG    (*(reg32 *)U_Clk__DIV_REGISTER)

#define U_Clk_CMD_DIV_SHIFT          (0u)
#define U_Clk_CMD_PA_DIV_SHIFT       (8u)
#define U_Clk_CMD_DISABLE_SHIFT      (30u)
#define U_Clk_CMD_ENABLE_SHIFT       (31u)

#define U_Clk_CMD_DISABLE_MASK       ((uint32)((uint32)1u << U_Clk_CMD_DISABLE_SHIFT))
#define U_Clk_CMD_ENABLE_MASK        ((uint32)((uint32)1u << U_Clk_CMD_ENABLE_SHIFT))

#define U_Clk_DIV_FRAC_MASK  (0x000000F8u)
#define U_Clk_DIV_FRAC_SHIFT (3u)
#define U_Clk_DIV_INT_MASK   (0xFFFFFF00u)
#define U_Clk_DIV_INT_SHIFT  (8u)

#else 

#define U_Clk_DIV_REG        (*(reg32 *)U_Clk__REGISTER)
#define U_Clk_ENABLE_REG     U_Clk_DIV_REG
#define U_Clk_DIV_FRAC_MASK  U_Clk__FRAC_MASK
#define U_Clk_DIV_FRAC_SHIFT (16u)
#define U_Clk_DIV_INT_MASK   U_Clk__DIVIDER_MASK
#define U_Clk_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_U_Clk_H) */

/* [] END OF FILE */
