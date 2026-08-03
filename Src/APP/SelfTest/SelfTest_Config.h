/**
* @file    SelfTest_Config.h
* @author  dev Basmala Mahmoud  
* @author  rev Malak Mohammed
* @brief   Configuration parameters for the SelfTest module.
* @details Contains configurable thresholds and timing values used during startup diagnostics.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/


#ifndef SELFTEST_CONFIG_H
#define SELFTEST_CONFIG_H

// ADC
#define SELFTEST_ADC_CHANNEL        Adc_SingleEndedChannel0
#define SELFTEST_ADC_MAX_VALUE      1023

// Battery 
#define BATTERY_MIN_START_VALUE     300

// Temperature 
#define MAX_ALLOWED_TEMPERATURE     150

// Delays 
#define SELFTEST_LED_DELAY          250
#define SELFTEST_BUZZER_DELAY       100

#endif // SELFTEST_CONFIG_H
