/**
* @file    Diagnostic_Private.h
* @author  dev Maria Boules
* @brief   Private definitions of the fault manager.
* @details Contains internal fault codes, helper functions, and private declarations.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef DIAGNOSTIC_PRIVATE_H
#define DIAGNOSTIC_PRIVATE_H

#include <stdint.h>

static void Diagnostic_ClearLine(uint8_t Line);
static void Diagnostic_WriteMode(uint8_t OperatingMode);

#endif
