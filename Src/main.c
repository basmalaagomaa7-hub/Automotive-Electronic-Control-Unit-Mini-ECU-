/**
* @file    main.c
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/


#include "HAL/Button/Button_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

int main( )
{

  Buzzer_Init();

while(1)
{
    Buzzer_On();
    _delay_ms(500);

    Buzzer_Off();
    _delay_ms(500);
}
        //Led_Toggle(Dio_GroupB, Dio_Pin0);
        
   
}
