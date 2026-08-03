/**
* @file    ADC_Program.c
* @author  dev Malak Mohammed 
* @author  rev Basmala Mahmoud
* @brief   Implements the ADC driver.
* @details Provides analog-to-digital conversion services using the ATmega32 ADC peripheral.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/



#include "ADC_Interface.h"
#include "ADC_Private.h"

static uint8_t ADC_LastChannel = 0xFFU;

static uint16_t ADC_DoSingleConversion(void)
{
    uint8_t LowByte;
    uint8_t HighByte;

    /* Clear any old completion flag by writing one, then start conversion. */
    ClearFlag(ADCSRA_Reg, Adc_ADIF);
    SetBit(ADCSRA_Reg, Adc_ADSC);

    while(ReadFlag(ADCSRA_Reg, Adc_ADIF) != FlagUp)
    {
        /* Poll until conversion is complete. */
    }

    /* For a right-adjusted result, ADCL must be read before ADCH. */
    LowByte = ADCL_Reg;
    HighByte = ADCH_Reg;

    ClearFlag(ADCSRA_Reg, Adc_ADIF);

    return ((uint16_t)HighByte << 8U) | LowByte;
}

void ADC_Init(Adc_Config_t Configuration)
{
    if(Configuration.ReferenceSelection == Adc_AREF)
    {
        ClearBit(ADMUX_Reg, Adc_REFS0);
        ClearBit(ADMUX_Reg, Adc_REFS1);
    }
    else if(Configuration.ReferenceSelection == Adc_AVCC)
    {
        SetBit(ADMUX_Reg, Adc_REFS0);
        ClearBit(ADMUX_Reg, Adc_REFS1);
    }
    else if(Configuration.ReferenceSelection == Adc_Internal)
    {
        SetBit(ADMUX_Reg, Adc_REFS0);
        SetBit(ADMUX_Reg, Adc_REFS1);
    }

    if(Configuration.AdjustResult == Adc_RightAdjust)
    {
        ClearBit(ADMUX_Reg, Adc_ADLAR);
    }
    else
    {
        SetBit(ADMUX_Reg, Adc_ADLAR);
    }

    if(Configuration.InterruptState == Enable)
    {
        SetBit(ADCSRA_Reg, Adc_ADIE);
    }
    else
    {
        ClearBit(ADCSRA_Reg, Adc_ADIE);
    }

    if(Configuration.AutomaticMode == AutoMode)
    {
        SetBit(ADCSRA_Reg, Adc_ADATE);
        SFIOR_Reg = (SFIOR_Reg & (uint8_t)(~Adc_ADTSMask)) |
                    (uint8_t)(Configuration.TriggerSource << Adc_ADTS0);
    }
    else
    {
        ClearBit(ADCSRA_Reg, Adc_ADATE);
    }

    ADCSRA_Reg = (ADCSRA_Reg & (uint8_t)(~Adc_PrescalerMask)) |
                 Configuration.PrescalerSelection;

    SetBit(ADCSRA_Reg, Adc_ADEN);
    ADC_LastChannel = 0xFFU;
}

uint16_t ADC_ReadChannelPolling(uint8_t Channel)
{
    Channel &= Adc_ChannelMask;

    if(Channel != ADC_LastChannel)
    {
        /*
         * After changing ADMUX, discard one conversion so the ADC sample-and-
         * hold capacitor settles on the new input. Without this, the first
         * reading can belong to the previous channel (PA0/PA1 cross-talk).
         */
        ADMUX_Reg = (ADMUX_Reg & (uint8_t)(~Adc_ChannelMask)) | Channel;
        (void)ADC_DoSingleConversion();
        ADC_LastChannel = Channel;
    }

    return ADC_DoSingleConversion();
}

void ADC_StartConvserionInterrupt(uint8_t Channel)
{
    Channel &= Adc_ChannelMask;
    ADMUX_Reg = (ADMUX_Reg & (uint8_t)(~Adc_ChannelMask)) | Channel;
    ADC_LastChannel = Channel;
    SetBit(ADCSRA_Reg, Adc_ADSC);
}

void ADC_SetCallback(void (*CopyFuncPtr)(uint16_t))
{
    ADC_CallBackPtr = CopyFuncPtr;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    uint8_t LowByte;
    uint8_t HighByte;
    uint16_t Result;

    LowByte = ADCL_Reg;
    HighByte = ADCH_Reg;
    Result = ((uint16_t)HighByte << 8U) | LowByte;

    if(ADC_CallBackPtr != Null)
    {
        ADC_CallBackPtr(Result);
    }
}
