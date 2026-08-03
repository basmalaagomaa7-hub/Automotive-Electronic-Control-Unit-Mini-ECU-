/**
* @file    LED_Program.c
* @author  dev CTRLDRIVE TEAM
* @author  rev Basmala Mahmoud
* @brief   Implements the LED driver.
* @details Provides functions to initialize and control LEDs using the DIO driver.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#include"LED_Interface.h"

static uint8_t StaticConnectionType = 0 ; 
void Led_Init(uint8_t GroupName , uint8_t PinNumber,uint8_t ConnectionType)
{
    DIO_InitPin(GroupName,PinNumber,Output);
    StaticConnectionType=ConnectionType;
}
void Led_on(uint8_t GroupName , uint8_t PinNumber )
{
    if(StaticConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }
        else if (StaticConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
 
        }

}

void Led_off(uint8_t GroupName , uint8_t PinNumber)
{

    if(StaticConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
        }
        else if (StaticConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }

}


void Led_Toggle(uint8_t GroupName , uint8_t PinNumber)
{

    DIO_TogglePin(GroupName,PinNumber);

}
