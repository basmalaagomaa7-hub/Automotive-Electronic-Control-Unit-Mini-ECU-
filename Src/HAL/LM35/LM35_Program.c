/**
* @file    LM35_Program.c
* @author  dev Basmala Mahmoud  
* @author  rev Malak Mohammed
* @brief   Implements the LM35 temperature sensor driver.
* @details Reads the analog voltage from the LM35 sensor and converts it to temperature in degrees Celsius.
* @version 1.0
* @date    8/2/2026
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