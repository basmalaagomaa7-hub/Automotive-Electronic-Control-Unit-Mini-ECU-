/**
 * @file BatteryMonitor_Program.c
 * @brief Independent potentiometer/battery-level supervision.
 *
 * This module only uses the potentiometer reading from PA1/ADC1.
 * It does not inspect temperature and it never controls the engine,
 * temperature-fault LED, or cooling-fan PWM.
 */

#include "BatteryMonitor_Interface.h"
#include "BatteryMonitor_Config.h"

#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/Buzzer/Buzzer_Interface.h"
#include "../FaultManager/FaultManager_Config.h"

static uint8_t BatteryState = BatteryMonitor_BatteryNormal;

void BatteryMonitor_Init(void)
{
    BatteryState = BatteryMonitor_BatteryNormal;

    Led_Init(ECU_Manager_WarningLedGroup,
             ECU_Manager_WarningLedPin,
             SourceConnection);

    Led_off(ECU_Manager_WarningLedGroup,
            ECU_Manager_WarningLedPin);

    Buzzer_Off();
}

void BatteryMonitor_Run(uint16_t BatteryAdcValue)
{
    if(BatteryAdcValue < BATTERY_MONITOR_LOW_THRESHOLD)
    {
        BatteryState = BatteryMonitor_BatteryLow;

        Led_on(ECU_Manager_WarningLedGroup,
               ECU_Manager_WarningLedPin);
        Buzzer_On();
    }
    else
    {
        BatteryState = BatteryMonitor_BatteryNormal;

        Led_off(ECU_Manager_WarningLedGroup,
                ECU_Manager_WarningLedPin);
        Buzzer_Off();
    }
}

uint8_t BatteryMonitor_GetState(void)
{
    return BatteryState;
}
