/**
* @file    SelfTest_Interface.h
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef SELFTEST_INTERFACE_H
#define SELFTEST_INTERFACE_H


#include "../../LIB/STD_TYPES.h"


typedef enum
{
    SELF_TEST_FAILED = 0,
    SELF_TEST_PASSED
}SelfTest_Status_t;

SelfTest_Status_t SelfTest_Run(void);



#endif // SELFTEST_INTERFACE_H
