/**
* @file    Fan_Interface.h
* @author  dev Basmala Mahmoud 
* @author  rev Maria Boules
* @brief   Public interface for the Fan driver.
* @details Contains the public function prototypes for controlling the cooling fan.
* @version 1.0
* @date    8/2/2026  
* @copyright Copyright (c) 2026, Gestell Company
*/


#ifndef FAN_INTERFACE_H
#define FAN_INTERFACE_H

#include <stdint.h>

#include "Fan_Config.h"
#include "Fan_privite.h"

void Fan_Init(void);
void Fan_SetSpeed(Fan_Speed_t Speed);
void Fan_SetDutyCycle(uint8_t DutyCyclePercentage);

#endif