/**
* @file    LM35_Program.c
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/
#include "LM35_Interface.h"
#include "LM35_Private.h"
#include "LM35_Config.h"

#include "../../MCAL/ADC/ADC_Interface.h"



uint16_t Lm35_ReadTemperature( )
{
    uint16_t AdcData;
    uint32_t SensorVoltage;
    uint16_t Temperature;

    // Read ADC channel connected to LM35
    AdcData = ADC_ReadChannelPolling(Lm35_Channel);

    // Convert ADC reading to sensor voltage (mV)
    SensorVoltage = ((uint32_t)AdcData * Lm35_ReferenceVoltage);

    SensorVoltage /= Lm35_MaxAdcValue;

    // Convert voltage to temperature
    Temperature = SensorVoltage / Lm35_SensorResolution;

    return Temperature;
}