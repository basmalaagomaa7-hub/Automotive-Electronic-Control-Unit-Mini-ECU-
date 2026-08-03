/**
* @file    Diagnostic_Program.c
* @author  dev Maria Boules 
* @brief   Fault manager implementation.
* @details Detects abnormal operating conditions, generates fault codes, and activates protection mechanisms.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/


#include "Diagnostic_Interface.h"
#include "Diagnostic_Private.h"
#include "Diagnostic_Config.h"

#include "../../HAL/LCD/LCD_Interface.h"
#include "../FaultManager/FaultManager_Private.h"

static void Diagnostic_ClearLine(uint8_t Line)
{
    uint8_t Index;
    LCD_SetCursor(Line, 0U);
    for(Index = 0U; Index < 16U; Index++)
    {
        LCD_WriteCharacter(' ');
    }
    LCD_SetCursor(Line, 0U);
}

static void Diagnostic_WriteMode(uint8_t OperatingMode)
{
    if(OperatingMode == Diagnostic_ModeOff)
    {
        LCD_WriteString((const uint8_t *)"OFF");
    }
    else if(OperatingMode == Diagnostic_ModeStart)
    {
        LCD_WriteString((const uint8_t *)"START");
    }
    else if(OperatingMode == Diagnostic_ModeRun)
    {
        LCD_WriteString((const uint8_t *)"RUN");
    }
    else if(OperatingMode == Diagnostic_ModeFault)
    {
        LCD_WriteString((const uint8_t *)"FAULT");
    }
    else
    {
        LCD_WriteString((const uint8_t *)"UNKNOWN");
    }
}

void Diagnostic_Init(void)
{
    LCD_Init();
}

void Diagnostic_SendReady(void)
{
    LCD_Clear();
    LCD_SetCursor(0U, 0U);
    LCD_WriteString((const uint8_t *)"ECU READY");
    LCD_SetCursor(1U, 0U);
    LCD_WriteString((const uint8_t *)"PRESS START");
}

void Diagnostic_ShowStarting(void)
{
    LCD_Clear();
    LCD_SetCursor(0U, 0U);
    LCD_WriteString((const uint8_t *)"SELF TEST...");
    LCD_SetCursor(1U, 0U);
    LCD_WriteString((const uint8_t *)"PLEASE WAIT");
}

void Diagnostic_SendEngineRunning(void)
{
    LCD_Clear();
    LCD_SetCursor(0U, 0U);
    LCD_WriteString((const uint8_t *)"ENGINE RUNNING");
}

void Diagnostic_SendSensorValues(uint16_t TemperatureCelsius,
                                 uint16_t BatteryAdcValue)
{
    Diagnostic_ClearLine(0U);
    LCD_WriteString((const uint8_t *)"TEMP:");
    LCD_WriteNumber(TemperatureCelsius);
    LCD_WriteCharacter((uint8_t)0xDFU);
    LCD_WriteCharacter('C');

    Diagnostic_ClearLine(1U);
    LCD_WriteString((const uint8_t *)"BAT ADC:");
    LCD_WriteNumber(BatteryAdcValue);
}

void Diagnostic_SendFault(uint8_t FaultCode)
{
    LCD_Clear();
    LCD_SetCursor(0U, 0U);

    if(FaultCode == Fault_None)
    {
        LCD_WriteString((const uint8_t *)"FAULT: NONE");
    }
    else if(FaultCode == Fault_HighTemperature)
    {
        LCD_WriteString((const uint8_t *)"FAULT F001");
        LCD_SetCursor(1U, 0U);
        LCD_WriteString((const uint8_t *)"HIGH TEMP");
    }
    else if(FaultCode == Fault_LowBattery)
    {
        LCD_WriteString((const uint8_t *)"FAULT F002");
        LCD_SetCursor(1U, 0U);
        LCD_WriteString((const uint8_t *)"LOW BATTERY");
    }
    else if(FaultCode == Fault_SensorFailure)
    {
        LCD_WriteString((const uint8_t *)"FAULT F003");
        LCD_SetCursor(1U, 0U);
        LCD_WriteString((const uint8_t *)"SENSOR FAILURE");
    }
    else if(FaultCode == Fault_AdcError)
    {
        LCD_WriteString((const uint8_t *)"FAULT F004");
        LCD_SetCursor(1U, 0U);
        LCD_WriteString((const uint8_t *)"ADC ERROR");
    }
    else
    {
        LCD_WriteString((const uint8_t *)"FAULT: UNKNOWN");
    }
}

void Diagnostic_SendStatus(uint8_t OperatingMode,
                           uint16_t TemperatureCelsius,
                           uint16_t BatteryAdcValue,
                           uint8_t PwmDutyCycle,
                           uint8_t FaultCode)
{
    (void)PwmDutyCycle;

    if(FaultCode != Fault_None)
    {
        Diagnostic_SendFault(FaultCode);
        return;
    }

    Diagnostic_ClearLine(0U);
    LCD_WriteString((const uint8_t *)"MODE:");
    Diagnostic_WriteMode(OperatingMode);
    LCD_WriteString((const uint8_t *)" T:");
    LCD_WriteNumber(TemperatureCelsius);

    Diagnostic_ClearLine(1U);
    LCD_WriteString((const uint8_t *)"BAT ADC:");
    LCD_WriteNumber(BatteryAdcValue);
}

void Diagnostic_SendSystemInfo(void)
{
    LCD_Clear();
    LCD_SetCursor(0U, 0U);
    LCD_WriteString((const uint8_t *)"MINI AUTO ECU");
    LCD_SetCursor(1U, 0U);
    LCD_WriteString((const uint8_t *)"ATMEGA32");
}

void Diagnostic_ShowSafeMode(void)
{
    LCD_Clear();
    LCD_SetCursor(0U, 0U);
    LCD_WriteString((const uint8_t *)"SYSTEM FAULT");
    LCD_SetCursor(1U, 0U);
    LCD_WriteString((const uint8_t *)"SAFE MODE");
}
