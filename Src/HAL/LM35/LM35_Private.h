/**
* @file    LM35_Private.h
* @author  dev Basmala Mahmoud  
* @author  rev Malak Mohammed
* @brief   Private declarations for the LM35 driver.
* @details Contains private macros and internal definitions used by the LM35 driver.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef LM35_PRIVATE_H
#define LM35_PRIVATE_H


// ADC maximum digital value
#define Lm35_MaxAdcValue          1023U

// ADC reference voltage in mV
#define Lm35_ReferenceVoltage     5000U

// LM35 output = 10mV / 1°C
#define Lm35_SensorResolution     10U


#endif // LM35_PRIVATE_H
