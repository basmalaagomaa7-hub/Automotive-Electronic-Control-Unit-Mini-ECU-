/**
* @file    EngineControl_Interface.h
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef ENGINECONTROL_INTERFACE_H
#define ENGINECONTROL_INTERFACE_H

#include <stdint.h>
#include "../../LIB/STD_TYPES.h"

typedef enum
{
    ENGINE_STOPPED = 0,
    ENGINE_RUNNING
}EngineState_t;

void EngineControl_Init();

uint8_t EngineControl_Start();

void EngineControl_Stop();

void EngineControl_Update();

EngineState_t EngineControl_GetState();

uint16_t EngineControl_GetTemperature();

uint16_t EngineControl_GetBattery();


#endif // ENGINECONTROL_INTERFACE_H
