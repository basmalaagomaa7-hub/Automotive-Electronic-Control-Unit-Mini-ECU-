/**
* @file    FaultManager_Interface.h
* @author  dev Maria Boulse 
* @brief   Public interface of the fault manager.
* @details Declares APIs used to detect, report, and clear system faults.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/



#ifndef _FAULT_MANAGER_INTERFACE_H
#define _FAULT_MANAGER_INTERFACE_H

#include <stdint.h>

#include "../../LIB/STD_TYPES.h"
#include "../../HAL/LED/LED_Interface.h"
#include "FaultManager_Config.h"
#include "FaultManager_Private.h"

void FaultManager_Init(void);
void FaultManager_Run(uint16_t TemperatureCelsius);
void FaultManager_CheckTemperature(uint16_t TemperatureCelsius);
void FaultManager_ISR(void);
void FaultManager_ClearFault(void);
uint8_t FaultManager_GetFaultState(void);

#endif
