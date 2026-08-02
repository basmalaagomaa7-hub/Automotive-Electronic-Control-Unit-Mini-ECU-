/**
* @file    Fan_Program.c
* @author  dev Basmala Mahmoud  
* @author  rev Maria Boules
* @brief   Implements the Fan driver.
* @details Provides functions to initialize, start, stop, and control the cooling fan.
* @version 1.0
* @date    8/2/2026  
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "Fan_Interface.h"
#include "Fan_Config.h"

#include "../../MCAL/Timer0/Timer0_Interface.h"

static Timer0_Config_t FanTimerConfig =
{
    .TimerMode         = Timer0_FastPWM,
    .PreloadValue      = ClearRegister,
    .CompareMatchValue = ClearRegister,
    .PWMOutputMode     = Timer0_OC0NinInverting,
    .DutyCycleInitValue= FAN_STOP_DUTY
};

void Fan_Init(void)
{
    TIMER0_Init(FanTimerConfig);

    TIMER0_SetPWMDutyCycle(FAN_STOP_DUTY);

    TIMER0_Start(FAN_TIMER_CLOCK);
}

void Fan_SetSpeed(Fan_Speed_t Speed)
{
    switch(Speed)
    {
        case FAN_STOP:
            TIMER0_SetPWMDutyCycle(FAN_STOP_DUTY);
            break;

        case FAN_LOW_SPEED:
            TIMER0_SetPWMDutyCycle(FAN_LOW_SPEED_DUTY);
            break;

        case FAN_MEDIUM_SPEED:
            TIMER0_SetPWMDutyCycle(FAN_MEDIUM_SPEED_DUTY);
            break;

        case FAN_HIGH_SPEED:
            TIMER0_SetPWMDutyCycle(FAN_HIGH_SPEED_DUTY);
            break;

        default:
            
            break;
    }
}
