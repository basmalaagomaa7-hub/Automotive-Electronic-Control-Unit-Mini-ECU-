/**
* @file    EngineControl_Program.c
* @author  dev Basmala Mahmoud 
* @author  rev Maria Boules
* @brief   Implements the EngineControl module.
* @details Reads engine sensors, controls the cooling fan PWM, and updates engine status indicators during normal operation.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "EngineControl_Interface.h"
#include "EngineControl_Config.h"

#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/POT/POT_Interface.h"
#include "../../HAL/Fan/Fan_Interface.h"
#include "../../HAL/LED/LED_Interface.h"

void EngineControl_Init(void)
{
    Fan_Init();
}

void EngineControl_Update(void)
{
    uint16_t BatteryVoltage;
    uint16_t Temperature;

    BatteryVoltage = Pot_Read();

    Temperature = Lm35_ReadTemperature();

    //Battery Status
    

    if(BatteryVoltage < ENGINE_BATTERY_LOW_THRESHOLD)
    {
        Led_on(FAULT_LED_PORT, FAULT_LED_PIN);
    }
    else
    {
         Led_off(FAULT_LED_PORT, FAULT_LED_PIN);
    }

    // Engine Status
    

    Led_on(ENGINE_LED_PORT, ENGINE_LED_PIN);

    //Fan Control
  

    if(Temperature <= ENGINE_TEMP_NORMAL_MAX)
    {
        Fan_SetSpeed(FAN_STOP);
    }
    else if(Temperature <= ENGINE_TEMP_MEDIUM_MAX)
    {
        Fan_SetSpeed(FAN_LOW_SPEED);
    }
    else if(Temperature <= ENGINE_TEMP_HIGH_MAX)
    {
        Fan_SetSpeed(FAN_MEDIUM_SPEED);
    }
    else
    {
        Fan_SetSpeed(FAN_HIGH_SPEED);
    }
}
