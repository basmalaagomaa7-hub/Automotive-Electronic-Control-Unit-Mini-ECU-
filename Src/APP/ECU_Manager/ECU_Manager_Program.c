/**
 * @file ECU_Manager_Program.c
 * @brief ECU state-machine implementation.
 */

#include "ECU_Manager_Interface.h"
#include "ECU_Manager_Private.h"
#include "ECU_Manager_Config.h"

#include "../SelfTest/SelfTest_Interface.h"
#include "../EngineControl/EngineControl_Interface.h"
#include "../FaultManager/FaultManager_Interface.h"
#include "../Diagnostic/Diagnostic_Interface.h"
#include "../BatteryMonitor/BatteryMonitor_Interface.h"

#include "../../HAL/Button/Button_Interface.h"
#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/POT/POT_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/Buzzer/Buzzer_Interface.h"

#include "../../MCAL/ADC/ADC_Interface.h"

static ECU_State_t CurrentState = ECU_STATE_OFF;

static void ECU_Hardware_Init(void)
{
    Adc_Config_t adcConfig;

    adcConfig.ReferenceSelection = Adc_AVCC;
    adcConfig.AdjustResult = Adc_RightAdjust;
    adcConfig.AutomaticMode = SingleMode;
    adcConfig.TriggerSource = 0U;
    adcConfig.InterruptState = Disable;
    adcConfig.PrescalerSelection = Adc_Prescaler_64;
    ADC_Init(adcConfig);

    Diagnostic_Init();

    Btn_Init(ECU_START_BUTTON_NUMBER);

    Led_Init(ECU_Manager_PowerLedGroup, ECU_Manager_PowerLedPin, SourceConnection);
    Led_Init(ECU_Manager_EngineLedGroup, ECU_Manager_EngineLedPin, SourceConnection);
    Led_Init(ECU_Manager_FaultLedGroup, ECU_Manager_FaultLedPin, SourceConnection);
    Led_Init(ECU_Manager_WarningLedGroup, ECU_Manager_WarningLedPin, SourceConnection);
    Buzzer_Init();

    Led_on(ECU_Manager_PowerLedGroup, ECU_Manager_PowerLedPin);
    Led_off(ECU_Manager_EngineLedGroup, ECU_Manager_EngineLedPin);
    Led_off(ECU_Manager_FaultLedGroup, ECU_Manager_FaultLedPin);
    Led_off(ECU_Manager_WarningLedGroup, ECU_Manager_WarningLedPin);
    Buzzer_Off();
}

void ECU_Manager_Init(void)
{
    ECU_Hardware_Init();
    FaultManager_Init();
    EngineControl_Init();
    BatteryMonitor_Init();

    Diagnostic_SendSystemInfo();
    Diagnostic_SendReady();

    CurrentState = ECU_STATE_OFF;
}

void ECU_Manager_Update(void)
{
    switch(CurrentState)
    {
        case ECU_STATE_OFF:
            ECU_State_Off_Handler();
            break;

        case ECU_STATE_START:
            ECU_State_Start_Handler();
            break;

        case ECU_STATE_RUN:
            ECU_State_Run_Handler();
            break;

        case ECU_STATE_FAULT:
            ECU_State_Fault_Handler();
            break;

        default:
            CurrentState = ECU_STATE_FAULT;
            break;
    }
}

static void ECU_State_Off_Handler(void)
{
    if(Btn_IsPressed(ECU_START_BUTTON_NUMBER) == Btn_Pressed)
    {
        CurrentState = ECU_STATE_START;
    }
}

static void ECU_State_Start_Handler(void)
{
    Diagnostic_ShowStarting();

    if(SelfTest_Run() == SELF_TEST_PASSED)
    {
        Led_off(ECU_Manager_FaultLedGroup, ECU_Manager_FaultLedPin);
        Led_on(ECU_Manager_EngineLedGroup, ECU_Manager_EngineLedPin);
        CurrentState = ECU_STATE_RUN;
        Diagnostic_SendEngineRunning();
    }
    else
    {
        /* PB2 is reserved only for an actual high-temperature fault. */
        Led_off(ECU_Manager_FaultLedGroup, ECU_Manager_FaultLedPin);
        Led_on(ECU_Manager_WarningLedGroup, ECU_Manager_WarningLedPin);
        Buzzer_Off();
        Diagnostic_SendFault(Fault_SensorFailure);
        CurrentState = ECU_STATE_FAULT;
    }
}

static void ECU_State_Run_Handler(void)
{
    uint16_t TemperatureCelsius;
    uint16_t BatteryAdcValue;

    /* Read each ADC channel once per cycle, then share the values. */
    TemperatureCelsius = Lm35_ReadTemperature();
    BatteryAdcValue = Pot_Read();

    /* Two independent checks: temperature and battery never share a condition. */
    FaultManager_Run(TemperatureCelsius);
    BatteryMonitor_Run(BatteryAdcValue);
    EngineControl_Update(TemperatureCelsius, BatteryAdcValue);

    /* Keep live readings visible while no temperature fault is active. */
    if(FaultManager_GetFaultState() == FaultManager_NoActiveFault)
    {
        Diagnostic_SendSensorValues(TemperatureCelsius, BatteryAdcValue);
    }
}

static void ECU_State_Fault_Handler(void)
{
    /* Reserved for unrecoverable startup faults only. */
}
