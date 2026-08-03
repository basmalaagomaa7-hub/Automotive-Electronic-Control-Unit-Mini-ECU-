/**
* @file    Diagnostic_Interface.h
* @author  dev Maria Boules  
* @brief   Public interface of the diagnostic module.
* @details Declares APIs used to communicate diagnostic information over UART.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/


#ifndef DIAGNOSTIC_INTERFACE_H
#define DIAGNOSTIC_INTERFACE_H

#include <stdint.h>

void Diagnostic_Init(void);
void Diagnostic_SendReady(void);
void Diagnostic_SendEngineRunning(void);
void Diagnostic_SendSensorValues(uint16_t TemperatureCelsius,
                                 uint16_t BatteryAdcValue);
void Diagnostic_SendFault(uint8_t FaultCode);
void Diagnostic_SendStatus(uint8_t OperatingMode,
                           uint16_t TemperatureCelsius,
                           uint16_t BatteryAdcValue,
                           uint8_t PwmDutyCycle,
                           uint8_t FaultCode);
void Diagnostic_SendSystemInfo(void);
void Diagnostic_ShowStarting(void);
void Diagnostic_ShowSafeMode(void);

#endif
