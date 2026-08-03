/**
 * @file ECU_Manager_Private.h
 * @author Malak Mohammed Ahmed
 * @author Eng. Hesham Ahmed
 * @brief Private header file for internal definitions of the ECU Manager module.
 * @details Contains module-private helper function prototypes, private macros,
 *          and internal constants used strictly within ECU_Manager_Program.c.
 * @version 1.0.0
 * @date 2026-08-02
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ECU_MANAGER_PRIVATE_H
#define ECU_MANAGER_PRIVATE_H

typedef enum
{
    ECU_STATE_OFF = 0,
    ECU_STATE_START,
    ECU_STATE_RUN,
    ECU_STATE_FAULT
} ECU_State_t;

// Internal state handlers - implemented and used only inside ECU_Manager_Program.c
static void ECU_State_Off_Handler(void);
static void ECU_State_Start_Handler(void);
static void ECU_State_Run_Handler(void);
static void ECU_State_Fault_Handler(void);

#endif // ECU_MANAGER_PRIVATE_H
