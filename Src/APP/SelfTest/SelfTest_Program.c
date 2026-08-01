#include "SelfTest_Interface.h"
#include "SelfTest_Private.h"
#include "SelfTest_Config.h"

#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/POT/POT_Interface.h"



uint8_t SelfTest_Run()
{
    uint16_t Temp;
    uint16_t Battery;

    Temp = Lm35_ReadTemperature();
    Battery = Pot_Read();

    if(Temp > SELFTEST_MAX_TEMP)
    {
        return SELFTEST_FAIL;
    }

    if(Battery < SELFTEST_MIN_BATTERY)
    {
        return SELFTEST_FAIL;
    }

    return SELFTEST_PASS;
}