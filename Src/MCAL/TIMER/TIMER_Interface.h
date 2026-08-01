/**
* @file    TIMER_Interface.h
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void TIMER0_Init(Timer0_Config_t Config);

void TIMER0_Start(uint8_t ClockSelectValue);

void TIMER0_Stop(void);
void TIMER0_SetPreload(uint8_t PreloadValue);
void TIMER0_SetCompare(uint8_t CompareValue);

void TIMER0_SetCallBackFunction(uint8_t TimerInterruptType, void (*PF)(void));

// comparevalue=2^n*DutyCycle
void TIMER0_SetPWMDutyCycle(uint8_t DutyCyclePercentage);

#endif // TIMER_INTERFACE_H
