/**
* @file    Button_Interface.h
* @author  dev Basmala Mahmoud  
* @author  rev Malak Mohammed
* @brief   Public interface for the Button driver.
* @details Contains the public function prototypes for reading push buttons.
* @version 1.0
* @date    8/3/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H


#include <stdint.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Button_Private.h"
#include "Button_Config.h"

void Btn_Init(uint8_t BtnNumber);

uint8_t Btn_IsPressed(uint8_t BtnNumber);


#endif