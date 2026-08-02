/**
* @file    LED_Config.h
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#include "../../MCAL/DIO/DIO_Interface.h"

// power LED 
#define POWER_LED_PORT      Dio_GroupB
#define POWER_LED_PIN       Dio_Pin0

// Engine LED 
#define ENGINE_LED_PORT      Dio_GroupB
#define ENGINE_LED_PIN       Dio_Pin1

// Fault LED 
#define FAULT_LED_PORT       Dio_GroupB
#define FAULT_LED_PIN        Dio_Pin2

// Engine LED 
#define WARNING_LED_PORT      Dio_GroupB
#define WARNING_LED_PIN       Dio_Pin3

#endif // LED_CONFIG_H
