/**
* @file    Buzzer_Interface.h
* @author  dev Basmala Mahmoud
* @author  rev Malak Mohammed
* @brief   Public interface for the Buzzer driver.
* @details Contains the public function prototypes for buzzer control.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H


#include "../../MCAL/DIO/DIO_Interface.h"

void Buzzer_Init( );

void Buzzer_On( );

void Buzzer_Off( );

void Buzzer_Toggle( );


#endif // BUZZER_INTERFACE_H
