/**
* @file    FaultManager_Program.c
* @author  dev Maria Boules 
* @brief   Fault manager implementation.
* @details Detects abnormal operating conditions, generates fault codes, and activates protection mechanisms.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/


#include "FaultManager_Interface.h"
#include "../Diagnostic/Diagnostic_Interface.h"

static volatile uint8_t FaultState = FaultManager_NoActiveFault;
static volatile uint8_t FaultInterruptFlag = FaultInterrupt_NotRaised;

void FaultManager_Init(void)
{
    FaultState = FaultManager_NoActiveFault;
    FaultInterruptFlag = FaultInterrupt_NotRaised;

    Led_Init(ECU_Manager_FaultLedGroup,
             ECU_Manager_FaultLedPin,
             SourceConnection);

    Led_off(ECU_Manager_FaultLedGroup,
            ECU_Manager_FaultLedPin);

}

void FaultManager_Run(uint16_t TemperatureCelsius)
{
    if(TemperatureCelsius > FaultManager_MaxTemperature)
    {
        if(FaultState == FaultManager_NoActiveFault)
        {
            FaultManager_CheckTemperature(TemperatureCelsius);

            if(FaultInterruptFlag == FaultInterrupt_Raised)
            {
                FaultManager_ISR();
            }
        }
    }
    else if(FaultState == FaultManager_ActiveFault)
    {
        /* The fault is not latched: it clears when temperature becomes safe. */
        FaultManager_ClearFault();
    }
}

void FaultManager_CheckTemperature(uint16_t TemperatureCelsius)
{
    if(TemperatureCelsius > FaultManager_MaxTemperature)
    {
        FaultState = FaultManager_ActiveFault;
        FaultInterruptFlag = FaultInterrupt_Raised;
    }
}

void FaultManager_ISR(void)
{
    FaultInterruptFlag = FaultInterrupt_NotRaised;

    if(FaultState == FaultManager_ActiveFault)
    {
        Led_on(ECU_Manager_FaultLedGroup,
               ECU_Manager_FaultLedPin);

        Diagnostic_SendFault(Fault_HighTemperature);
    }
}

void FaultManager_ClearFault(void)
{
    FaultState = FaultManager_NoActiveFault;
    FaultInterruptFlag = FaultInterrupt_NotRaised;

    Led_off(ECU_Manager_FaultLedGroup,
            ECU_Manager_FaultLedPin);

}

uint8_t FaultManager_GetFaultState(void)
{
    return FaultState;
}
