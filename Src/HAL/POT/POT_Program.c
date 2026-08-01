/**
* @file    POT_Program.c
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/
/**
* @file    POT_Program.c
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