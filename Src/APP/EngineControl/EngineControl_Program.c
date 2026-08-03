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

#include "../../HAL/Fan/Fan_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/Buzzer/Buzzer_Interface.h"

#include "../FaultManager/FaultManager_Config.h"

static uint8_t EngineControl_CalculateFanDuty(uint16_t TemperatureCelsius)
{
    if(TemperatureCelsius <= ENGINE_FAN_START_TEMP)
    {
        return 0U;
    }

    if(TemperatureCelsius >= ENGINE_FAN_FULL_TEMP)
    {
        return 100U;
    }

    return (uint8_t)(((TemperatureCelsius - ENGINE_FAN_START_TEMP) * 100UL) /
                     (ENGINE_FAN_FULL_TEMP - ENGINE_FAN_START_TEMP));
}

void EngineControl_Init(void)
{
    Led_Init(ECU_Manager_EngineLedGroup,
             ECU_Manager_EngineLedPin,
             SourceConnection);

    Led_off(ECU_Manager_EngineLedGroup,
            ECU_Manager_EngineLedPin);

    Fan_Init();
    Fan_SetDutyCycle(0U);
}

void EngineControl_Update(uint16_t TemperatureCelsius,
                          uint16_t BatteryAdcValue)
{
    uint8_t FanDutyCycle;

    /* Battery monitoring is handled independently by BatteryMonitor. */
    (void)BatteryAdcValue;

    /* Engine status follows the temperature fault continuously. */
    if(TemperatureCelsius > FaultManager_MaxTemperature)
    {
        Led_off(ECU_Manager_EngineLedGroup,
                ECU_Manager_EngineLedPin);
    }
    else
    {
        Led_on(ECU_Manager_EngineLedGroup,
               ECU_Manager_EngineLedPin);
    }

    /* Fan PWM follows the LM35 reading continuously. */
    FanDutyCycle = EngineControl_CalculateFanDuty(TemperatureCelsius);
    Fan_SetDutyCycle(FanDutyCycle);
}
