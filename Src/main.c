/**
 * @file main.c
 * @brief Mini Automotive ECU application entry point.
 */

#include "APP/ECU_Manager/ECU_Manager_Interface.h"

int main(void)
{
    ECU_Manager_Init();

    while(1)
    {
        ECU_Manager_Update();
    }

    return 0;
}
