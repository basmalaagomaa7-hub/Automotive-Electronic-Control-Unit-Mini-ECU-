/**
* @file    GIE_Interface.h
* @author  dev CTRLDRIVE TEAM
* @author  rev Maria Boules 
* @brief   Public interface for the GIE driver.
* @details Contains the public function prototypes for enabling and disabling global interrupts.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef _GIE_INTERFACE_H
#define _GIE_INTERFACE_H
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../Atmega32regmap.h"
#include "GIE_Private.h"

void GIE_Enable();
void GIE_Disable();


#endif 