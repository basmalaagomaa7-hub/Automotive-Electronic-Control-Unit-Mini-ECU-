/**
 * @file    Fan_Config.h
 * @author  dev Basmala Moahmoud  
 * @author  rev Maria Boules
 * @brief   Configuration parameters for the Fan driver.
 * @details Defines the fan control pin, port, and operating configuration.
 * @version 1.0
 * @date    8/2/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef FAN_CONFIG_H
#define FAN_CONFIG_H


// PWM Duty Cycle (%) 

#define FAN_STOP_DUTY            0U
#define FAN_LOW_SPEED_DUTY      30U
#define FAN_MEDIUM_SPEED_DUTY   60U
#define FAN_HIGH_SPEED_DUTY    100U

// Timer0 Clock 

#define FAN_TIMER_CLOCK   Timer0_Prescaller64

#endif