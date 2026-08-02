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