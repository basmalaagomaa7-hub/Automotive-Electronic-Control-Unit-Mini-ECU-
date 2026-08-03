/**
* @file    TIMER_Interface.h
* @author  dev CTRLDRIVE TEAM  
* @authorr rev Basmala Mahmoud
* @brief   Public interface for the Timer0 driver.
* @details Contains the public function prototypes for Timer0 configuration, delay generation, interrupts, and PWM control.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include <stdint.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../Atmega32regmap.h"
#include "TIMER_Private.h"
#include "TIMER_Config.h"

void TIMER0_Init(Timer0_Config_t Config);

void TIMER0_Start(uint8_t ClockSelectValue);

void TIMER0_Stop(void);
void TIMER0_SetPreload(uint8_t PreloadValue);
void TIMER0_SetCompare(uint8_t CompareValue);

void TIMER0_SetCallBackFunction(uint8_t TimerInterruptType, void (*PF)(void));

// comparevalue=2^n*DutyCycle
void TIMER0_SetPWMDutyCycle(uint8_t DutyCyclePercentage);

#endif // TIMER_INTERFACE_H
