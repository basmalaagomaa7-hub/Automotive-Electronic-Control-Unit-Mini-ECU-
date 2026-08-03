/**
* @file    FaultManager_Private.h
* @author  dev Maria Boules 
* @brief   Private definitions of the fault manager.
* @details Contains internal fault codes, helper functions, and private declarations.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/


#ifndef _FAULT_MANAGER_PRIVATE_H
#define _FAULT_MANAGER_PRIVATE_H


#define FaultManager_NoActiveFault       0
#define FaultManager_ActiveFault         1

#define FaultInterrupt_NotRaised         0
#define FaultInterrupt_Raised            1

#define Fault_None                     0
#define Fault_HighTemperature          1
#define Fault_LowBattery               2
#define Fault_SensorFailure            3
#define Fault_AdcError                 4


#endif