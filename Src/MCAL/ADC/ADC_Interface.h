/**
* @file    ADC_Interface.h
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include <stdint.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../Atmega32regmap.h"
#include "ADC_Private.h"
#include "ADC_Config.h"


// Reference Selection 
// Adjust Result
// Enable 
// AutomaticORSingle 
// Interrupt Or Polling 
// Prescaler Select 
void ADC_Init(Adc_Config_t  Configuration);

// 
uint16_t ADC_ReadChannelPolling(uint8_t Channel);
// 
void ADC_StartConvserionInterrupt(uint8_t Channel);


// Auto // //Start Conversion 1 
// Single conversion // each Conversion 

#endif // ADC_INTERFACE_H
