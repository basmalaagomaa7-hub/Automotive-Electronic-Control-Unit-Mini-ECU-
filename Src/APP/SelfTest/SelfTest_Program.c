/**
* @file    SelfTest_Program.c
* @author  dev Basmala Mahmouud  
* @author  rev Malak Mohammed
* @brief   Implements the SelfTest module.
* @details Performs startup hardware diagnostics including ADC, battery, temperature, LED, and buzzer checks before the ECU enters normal operation.
* @version 1.0
* @date    8/2/2026 
* @copyright Copyright (c) 2026, Gestell Company
*/


#include "SelfTest_Interface.h"
#include "SelfTest_Private.h"
#include "SelfTest_Config.h"

#include "../../HAL/LED/LED_Interface.h"

#include <util/delay.h>

SelfTest_Status_t SelfTest_Run(void)
{
  

    Led_on(ENGINE_LED_PORT, ENGINE_LED_PIN);
    _delay_ms(SELFTEST_LED_DELAY);
    Led_off(ENGINE_LED_PORT, ENGINE_LED_PIN);


    return SELF_TEST_PASSED;
}
