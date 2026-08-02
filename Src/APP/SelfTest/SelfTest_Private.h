/**
* @file    SelfTest_Private.h
* @author  dev Basmala Mahmoud  
* @author  rev Malak Mohammed
* @brief   Private declarations for the SelfTest module.
* @details Contains internal helper function prototypes and private macros used only inside SelfTest_Program.c.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef SELFTEST_PRIVATE_H
#define SELFTEST_PRIVATE_H


#include <stdint.h>

typedef enum
{
    SELF_TEST_FAILED = 0,
    SELF_TEST_PASSED
}SelfTest_Status_t;


#endif // SELFTEST_PRIVATE_H
