/**
* @file    SelfTest_Program.c
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/
#include "SelfTest_Interface.h"
#include "SelfTest_Config.h"
#include "SelfTest_Private.h"

#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/POT/POT_Interface.h"
#include <stdint.h>

uint8_t SelfTest_Run()
{
    uint16_t Temp;
    uint16_t Pot;

    Temp = LM35_Read();
    Pot  = Pot_Read();

    if(Temp > TEMP_MAX)
    {
        return SELFTEST_FAIL;
    }

    if(Pot > POT_MAX)
    {
        return SELFTEST_FAIL;
    }
    return SELFTEST_PASS;
}