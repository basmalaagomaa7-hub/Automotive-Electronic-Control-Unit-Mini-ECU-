/**
* @file    EngineControl_Config.h
* @author  dev Basmala Mahmoud
* @author  rev Maria Boules 
* @brief   Configuration parameters for the EngineControl module.
* @details Contains configurable limits and PWM values used for engine control.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef ENGINECONTROL_CONFIG_H
#define ENGINECONTROL_CONFIG_H


// Battery Thresholds 

#define ENGINE_BATTERY_LOW_THRESHOLD      300U

// Temperature Thresholds 

#define ENGINE_TEMP_NORMAL_MAX            40U
#define ENGINE_TEMP_MEDIUM_MAX            60U
#define ENGINE_TEMP_HIGH_MAX              80U

/* Continuous fan-PWM mapping */
#define ENGINE_FAN_START_TEMP              30U
#define ENGINE_FAN_FULL_TEMP               85U


#endif // ENGINECONTROL_CONFIG_H
