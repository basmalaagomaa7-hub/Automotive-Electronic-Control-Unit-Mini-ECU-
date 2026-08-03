/**
* @file    EXTI_Interface.h
* @author  dev CTRLDRIVE TEAM 
* @author  rev Malak Mohammed
* @brief   Public interface for the External Interrupt driver.
* @details Contains the public APIs for configuring external interrupts.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include <stdint.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../Atmega32regmap.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"


void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);


#endif // EXTI_INTERFACE_H
