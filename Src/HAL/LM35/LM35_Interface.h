/**
* @file    LM35_Interface.h
* @author  dev Basmala Mahmoud
* @author  rev Malak Mohammed
* @brief   Public interface for the LM35 temperature sensor driver.
* @details Contains the public function prototypes for reading temperature values.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H



#include <stdint.h>
#include "../../LIB/STD_TYPES.h"


uint16_t Lm35_ReadTemperature( );


#endif // LM35_INTERFACE_H
