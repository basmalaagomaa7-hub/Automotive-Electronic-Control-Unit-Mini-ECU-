/**
* @file    Buzzer_Program.c
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/
#include "Buzzer_Interface.h"
#include "Buzzer_Private.h"
#include "Buzzer_Config.h"

void Buzzer_Init()
{
    DIO_InitPin(Buzzer_Group,Buzzer_Pin,Output);
}

void Buzzer_On()
{
    DIO_WritePin(Buzzer_Group,Buzzer_Pin,High);
}

void Buzzer_Off()
{
    DIO_WritePin(Buzzer_Group,Buzzer_Pin,Low);
}

void Buzzer_Toggle()
{
    DIO_TogglePin(Buzzer_Group, Buzzer_Pin);
}