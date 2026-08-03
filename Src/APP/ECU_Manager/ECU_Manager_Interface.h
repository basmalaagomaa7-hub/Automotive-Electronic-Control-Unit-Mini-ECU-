/**
 * @file ECU_Manager_Interface.h
 * @author Malak Mohammed Ahmed
 * @author Eng. Hesham Ahmed
 * @brief Public interface header file for the ECU Manager module.
 * @details Exposes top-level system operating states and function prototypes
 *          required to initialize and drive the ECU state machine execution loop.
 * @version 1.0.0
 * @date 2026-08-02
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ECU_MANAGER_INTERFACE_H
#define ECU_MANAGER_INTERFACE_H

#include "../../LIB/STD_TYPES.h"


void ECU_Manager_Init(void);
void ECU_Manager_Update(void);


#endif // ECU_MANAGER_INTERFACE_H
