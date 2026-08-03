/**
* @file    DIO_Interface.h
* @author  dev CTRLDRIVE TEAM  
* @author  rev Basmala Mahmoud
* @brief   Public interface for the DIO driver.
* @details Contains the public APIs for digital input/output operations.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#include<stdint.h>
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../Atmega32regmap.h"
#include"DIO_Private.h"

// select direction  initpin 
void DIO_InitPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirState);
// outputvalue    writepin  
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);
// read  readpin 
// uint8_t DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber);
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState);
void DIO_TogglePin(uint8_t GroupName,uint8_t PinNumber);

// select direction  initGroup 
void DIO_InitGroup(uint8_t GroupName,uint8_t DirState);
// outputvalue    writeGroup   
void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue);
// read  readGroup  
void DIO_ReadGroup(uint8_t GroupName,uint8_t * InputStates);


#endif // DIO_INTERFACE_H
