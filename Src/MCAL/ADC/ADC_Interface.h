/**
* @file    ADC_Interface.h
* @author  dev Malak Mohammed  
* @author  rev Basmala Mahmoud
* @brief Public interface for the ADC driver.
* @details Contains the public APIs for analog-to-digital conversion.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/


#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
#include <stdint.h>
#include "../Atmega32regmap.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_Private.h"


void ADC_Init(Adc_Config_t  Configuration);
uint16_t ADC_ReadChannelPolling(uint8_t Channel);
void ADC_StartConvserionInterrupt(uint8_t Channel);
void ADC_SetCallback(void (*CopyFuncPtr)(uint16_t));




#endif