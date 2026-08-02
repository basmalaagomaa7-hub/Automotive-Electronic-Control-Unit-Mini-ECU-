/**
* @file    UART_Interface.h
* @author  dev Malak Mohammed  
* @author  rev Maria Boules
* @brief   Public interface for the UART driver.
* @details Contains the public APIs for serial communication.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/
#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

#include <stdint.h>

#include "../../Common/Definition.h"
#include "../../Common/Bitmath.h"
#include "../Atmega32regmap.h"

#include "UART_Private.h"
#include "UART_Config.h"

/*
    1- Mode Select -> Asynch / Synch 
    2- Stop Bit not -> 1Stop / 2 Stop 
    3- Parity Check status -> even / odd / disable 
    4- Size char -> 5:9
    5- speed mode -> normal/double
    6- baud rate -> rule
    7- interrupt select 
    8- Enable Select 
*/

/*Initialization API*/
void UART_Init(Uart_Config_t Uart_Config);//done 

/* Polling (Blocking)API*/
void UART_SendBytePolling(uint16_t Data);// done 
uint16_t UART_ReceiveBytePolling();//done 
void UART_SendStringPolling(uint8_t* String); // Characters //done 
void UART_ReceiveStringPolling(uint8_t* Buffer, uint8_t Terminator);//done 
void UART_SendBufferPolling(uint8_t * Buffer , uint16_t Length);//Raw Data //done 




/*Interrupt API*/
void UART_SendByteInterrupt(uint16_t Data); //done 

void UART_EnableRXInterrupt();//Done
void UART_EnableTXInterrupt();//Done
void UART_EnableREInterrupt();//Done

void UART_DisableRXInterrupt();//Done
void UART_DisableTXInterrupt();//Done
void UART_DisableREInterrupt();//Done

void UART_SetRXCallback(void (*PF)(uint16_t));//  Done
void UART_SetTXCallback(void (*PF)(void));//  Done
void UART_SetRECallback(void (*PF)(void));//  Done

/* Driver Control API */
void UART_EnableRX();//Done
void UART_EnableTX();//Done
void UART_DisableRX();//Done
void UART_DisableTX();//Done









#endif
