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
#include "../../HAL/Buzzer/Buzzer_Interface.h"
#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/POT/POT_Interface.h"

#include "../../MCAL/ADC/ADC_Interface.h"

#include <util/delay.h>

SelfTest_Status_t SelfTest_Run(void)
{
    uint16_t BatteryVoltage;
    uint16_t Temperature;
    uint16_t ADCValue;


    // ADC Self Test
   
    ADCValue = ADC_ReadChannelPolling(SELFTEST_ADC_CHANNEL);

    if(ADCValue > SELFTEST_ADC_MAX_VALUE)
    {
        return SELF_TEST_FAILED;
    }

    // Battery Voltage Check
     
    BatteryVoltage = Pot_Read();

    if(BatteryVoltage < BATTERY_MIN_START_VALUE)
    {
        return SELF_TEST_FAILED;
    }

    // Temperature Sensor Check
    
    Temperature = Lm35_ReadTemperature();

    if(Temperature > MAX_ALLOWED_TEMPERATURE)
    {
        return SELF_TEST_FAILED;
    }

    
    // LED Test
    
   Led_on(ENGINE_LED_PORT, ENGINE_LED_PIN);
   Led_on(FAULT_LED_PORT, FAULT_LED_PIN);

    _delay_ms(SELFTEST_LED_DELAY);

    Led_off(ENGINE_LED_PORT, ENGINE_LED_PIN);
    Led_off(FAULT_LED_PORT, FAULT_LED_PIN);

    // Buzzer Test
    
    Buzzer_On();

    _delay_ms(SELFTEST_BUZZER_DELAY);

    Buzzer_Off();

    return SELF_TEST_PASSED;
}
