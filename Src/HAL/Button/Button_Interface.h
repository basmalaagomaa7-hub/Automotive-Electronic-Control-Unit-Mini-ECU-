/**
* @file    Button_Interface.h
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H


#include <stdint.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../Mcal/DIO/DIO_Interface.h"

#include "Button_Private.h"
#include "Button_Config.h"

void Btn_Init(uint8_t BtnNumber);

uint8_t Btn_IsPressed(uint8_t BtnNumber);


#endif