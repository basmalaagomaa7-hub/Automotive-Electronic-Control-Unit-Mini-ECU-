/**
* @file    Fan_privite.h
* @author  dev Basmala Mahmoud 
* @author  rev Maria Boules
* @brief   Private declarations for the Fan driver.
* @details Contains private macros and definitions used only by the Fan driver.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef FAN_PRIVATE_H
#define FAN_PRIVATE_H

typedef enum
{
    FAN_STOP ,
    FAN_LOW_SPEED,
    FAN_MEDIUM_SPEED,
    FAN_HIGH_SPEED

}Fan_Speed_t;

// OC0 pin 

#define FAN_PWM_PIN   DIO_PIN3
#define FAN_PWM_PORT  DIO_PORTB

#endif
