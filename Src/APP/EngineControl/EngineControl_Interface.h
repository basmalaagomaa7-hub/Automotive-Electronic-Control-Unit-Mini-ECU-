/**
* @file    EngineControl_Interface.h
* @author  dev Basmala Mahmoud  
* @author  rev Maria Boules
* @brief   Public interface for the EngineControl module.
* @details Contains the public function prototypes used to control engine operation.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/



#ifndef ENGINECONTROL_INTERFACE_H
#define ENGINECONTROL_INTERFACE_H

#include <stdint.h>

void EngineControl_Init(void);
void EngineControl_Update(uint16_t TemperatureCelsius,
                          uint16_t BatteryAdcValue);

#endif
