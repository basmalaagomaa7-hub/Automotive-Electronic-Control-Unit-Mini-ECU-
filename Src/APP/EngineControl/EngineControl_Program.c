/**
* @file    EngineControl_Program.c
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/
#include "EngineControl_Interface.h"
#include "EngineControl_Private.h"
#include "EngineControl_Config.h"

#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/Buzzer/Buzzer_Interface.h"
#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/POT/POT_Interface.h"

static EngineState_t EngineState = ENGINE_STOPPED;

static uint16_t EngineTemp = 0;
static uint16_t BatteryLevel = 0;

void EngineControl_Init()
{
    Led_Init(ENGINE_LED_GROUP,
             ENGINE_LED_PIN,
             ENGINE_LED_CONNECTION);

    Buzzer_Init();

    Led_off(ENGINE_LED_GROUP,
            ENGINE_LED_PIN);

    Buzzer_Off();

    EngineState = ENGINE_STOPPED;
}

uint8_t EngineControl_Start()
{
    BatteryLevel = Pot_Read();
    EngineTemp = Lm35_ReadTemperature();

    if(BatteryLevel < ENGINE_MIN_BATTERY)
    {
        return 0;
    }

    if(EngineTemp > ENGINE_MAX_TEMP)
    {
        return 0;
    }

    Led_on(ENGINE_LED_GROUP,
           ENGINE_LED_PIN);

    EngineState = ENGINE_RUNNING;

    return 1;
}

void EngineControl_Stop()
{
    Led_off(ENGINE_LED_GROUP,
            ENGINE_LED_PIN);

    Buzzer_Off();

    EngineState = ENGINE_STOPPED;
}

void EngineControl_Update()
{
    if(EngineState == ENGINE_RUNNING)
    {
        EngineTemp = Lm35_ReadTemperature();

        BatteryLevel = Pot_Read();

        if((EngineTemp > ENGINE_MAX_TEMP) ||
           (BatteryLevel < ENGINE_MIN_BATTERY))
        {
            EngineControl_Stop();

            Buzzer_On();
        }
    }
}

EngineState_t EngineControl_GetState()
{
    return EngineState;
}

uint16_t EngineControl_GetTemperature()
{
    return EngineTemp;
}

uint16_t EngineControl_GetBattery()
{
    return BatteryLevel;
}