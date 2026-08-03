/**
* @file    FaultManager_Config.h
* @author  dev Maria Boules 
* @brief   Fault manager configuration.
* @details Contains configurable thresholds for fault detection and protection.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/


#ifndef _FAULT_MANAGER_CONFIG_H
#define _FAULT_MANAGER_CONFIG_H

#define FaultManager_MaxTemperature       90U

/* Simulator pinout */
#define FaultManager_BuzzerGroup           Dio_GroupB
#define FaultManager_BuzzerPin             Dio_Pin4

#define ECU_Manager_PowerLedGroup          Dio_GroupB
#define ECU_Manager_PowerLedPin            Dio_Pin0

#define ECU_Manager_EngineLedGroup         Dio_GroupB
#define ECU_Manager_EngineLedPin           Dio_Pin1

#define ECU_Manager_FaultLedGroup          Dio_GroupB
#define ECU_Manager_FaultLedPin            Dio_Pin2

#define ECU_Manager_WarningLedGroup        Dio_GroupB
#define ECU_Manager_WarningLedPin          Dio_Pin5

#endif
