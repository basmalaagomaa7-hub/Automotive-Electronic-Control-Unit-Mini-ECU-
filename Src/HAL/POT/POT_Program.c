/**
* @file    POT_Program.c
* @author  dev Malak Mohammed  
* @author  rev Basmala Mahmoud
* @brief   Implements the POT driver.
* @details Reads the analog value from the potentiometer using the ADC peripheral.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/ADC/ADC_Interface.h"

#include "POT_Interface.h"
#include "POT_Config.h"
#include "POT_Private.h"

uint16_t Pot_Read()
{
    return ADC_ReadChannelPolling(Pot_Channel);
}
