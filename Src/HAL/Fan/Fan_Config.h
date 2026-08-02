/**
 * @file Fan_Config.h
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