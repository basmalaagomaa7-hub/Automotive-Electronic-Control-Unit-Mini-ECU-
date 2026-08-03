/**
* @file    GIE_Program.c
* @author  dev CTRLDRIVE TEAM
* @author  rev Maria Boules 
* @brief   Implements the GIE driver.
* @details Provides functions to enable and disable global interrupts by controlling the I-bit in the AVR Status Register (SREG).
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "GIE_Interface.h"



void GIE_Enable()
{
    SetBit(SERG_Reg,I_Bit);
}
void GIE_Disable()
{
    ClearBit(SERG_Reg,I_Bit);
}