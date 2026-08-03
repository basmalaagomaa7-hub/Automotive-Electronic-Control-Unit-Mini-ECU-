/**
* @file    Button_Program.c
* @author  dev Basmala Mahmoud 
* @author  rev Malak Mohammed
* @brief   Implements the Button driver.
* @details Provides functions to initialize and read push button states.
* @version 1.0
* @date    8/3/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "Button_Interface.h"

/* Button Mapping */

static uint8_t BtnGroup[Btn_MaxNo] = BtnGroupValue;
static uint8_t BtnPin[Btn_MaxNo]   = BtnPinValue;

/*Initialize button pin as input
  and enable internal pull-up */
void Btn_Init(uint8_t BtnNumber)
{
    if((BtnNumber >= Btn_StartIndex) && (BtnNumber <= Btn_MaxNo))
    {
        /* Input Direction */
        DIO_InitPin(
            BtnGroup[BtnNumber - Btn_StartIndex],
            BtnPin[BtnNumber - Btn_StartIndex],
            Input);

        /* Enable Internal Pull-up */
        DIO_WritePin(
            BtnGroup[BtnNumber - Btn_StartIndex],
            BtnPin[BtnNumber - Btn_StartIndex],
            High);
    }
}

/*Btn_state
 Btn_Pressed
 Btn_NotPressed
 Btn_NotValidState */
uint8_t Btn_IsPressed(uint8_t BtnNumber)
{
    uint8_t BtnState = Btn_NotValidState;

    if((BtnNumber >= Btn_StartIndex) && (BtnNumber <= Btn_MaxNo))
    {
        DIO_ReadPin(
            BtnGroup[BtnNumber - Btn_StartIndex],
            BtnPin[BtnNumber - Btn_StartIndex],
            &BtnState);

        return BtnState;
    }

    return Btn_NotValidState;
}
