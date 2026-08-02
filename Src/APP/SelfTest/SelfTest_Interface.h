/**
* @file    SelfTest_Interface.h
* @author  dev Basmala Mahmoud  
* @author  rev Malak Mohammed
* @brief   Public interface for the SelfTest module.
* @details Contains the public data types and function prototypes used by other modules.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef SELFTEST_INTERFACE_H
#define SELFTEST_INTERFACE_H


#include "../../LIB/STD_TYPES.h"
#include "SelfTest_Private.h"


SelfTest_Status_t SelfTest_Run(void);



#endif // SELFTEST_INTERFACE_H
