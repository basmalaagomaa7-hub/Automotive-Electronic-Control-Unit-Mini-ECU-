/**
* @file    Buzzer_Config.h
* @author  dev Malak Mohammed 
* @author  rev Basmala Mahmoud
* @brief   Implements the Digital Input/Output (DIO) driver.
* @details Provides pin and port initialization, read, write, and toggle operations.
* @version 1.0
* @date    8/2/2026
* @copyright Copyright (c) 2026, Gestell Company
*/
 

#include "ADC_Interface.h"
#include "ADC_Private.h"


// Reference Selection ..done 
// Adjust Result  ..done
// AutomaticORSingle ..done 
// Interrupt Or Polling 
// Prescaler Select ..done 
// Enable ..done 


void ADC_Init(Adc_Config_t  Configuration){
if(Configuration.ReferenceSelection==Adc_AREF)
{
ClearBit(ADMUX_Reg,Adc_REFS0);
ClearBit(ADMUX_Reg,Adc_REFS1);


}
else if (Configuration.ReferenceSelection==Adc_AVCC ){
SetBit(ADMUX_Reg,Adc_REFS0);
ClearBit(ADMUX_Reg,Adc_REFS1);
}

else if(Configuration.ReferenceSelection==Adc_Internal)
{
SetBit(ADMUX_Reg,Adc_REFS0);
SetBit(ADMUX_Reg,Adc_REFS1);
}
 if(Configuration.AdjustResult==Adc_RightAdjust)
    {
      ClearBit(ADMUX_Reg,Adc_ADLAR);
    }
    else if(Configuration.AdjustResult==Adc_LeftAdjust)
    {
      SetBit(ADMUX_Reg,Adc_ADLAR);
    }
    if(Configuration.InterruptState==Enable)
    {
     SetBit(ADCSRA_Reg,Adc_ADIE);
    }
    else if(Configuration.InterruptState==Disable)
    {
     ClearBit(ADCSRA_Reg,Adc_ADIE);
    }
    // ---- Auto Trigger Enable (ADATE) + Trigger Source (SFIOR ADTS2:0) ----
    if (Configuration.AutomaticMode==AutoMode)
    {
        SetBit(ADCSRA_Reg,Adc_ADATE);
        // Select Trigger Source
        SFIOR_Reg = (SFIOR_Reg & ~Adc_ADTSMask) | (Configuration.TriggerSource << Adc_ADTS0);

    }
    else if (Configuration.AutomaticMode==SingleMode)
    {
        ClearBit(ADCSRA_Reg,Adc_ADATE);
    }
    // ---- Prescaler Select (ADPS2:0) ----
    ADCSRA_Reg=(ADCSRA_Reg&~Adc_PrescalerMask)|Configuration.PrescalerSelection;

//Enable ADC
SetBit(ADCSRA_Reg, Adc_ADEN);

}

// (polling) single conversion on the given channel
uint16_t ADC_ReadChannelPolling(uint8_t Channel){
    
     // Update Channel ADMUX 4 - 0 
    ADMUX_Reg=(ADMUX_Reg&~Adc_ChannelMask)|Channel;
    // Start Conversion 
    SetBit(ADCSRA_Reg,Adc_ADSC);
  
    while(ReadFlag(ADCSRA_Reg,Adc_ADIF)!=FlagUp); //// Do nothing, just wait
    //Manual Flag Clear 
    ClearFlag(ADCSRA_Reg,Adc_ADIF);
    
    return ADCData_Reg;
    
}

// starting a single conversion; result is collected later in the ISR
void ADC_StartConvserionInterrupt(uint8_t Channel)
{
    ADMUX_Reg=(ADMUX_Reg&~Adc_ChannelMask)|Channel;
    SetBit(ADCSRA_Reg,Adc_ADSC);
}

//  the ISR should call once conversion data is ready
void ADC_SetCallback(void (*CopyFuncPtr)(uint16_t))
{
    ADC_CallBackPtr = CopyFuncPtr;
}

// ISR for ADC Conversion Complete (ADIF) - hardware clears ADIF automatically
// when the interrupt vector is served

void __vector_16(void) __attribute__((signal));

// 2. The ISR implementation
void __vector_16(void)
{
    if (ADC_CallBackPtr != Null)
    {
        ADC_CallBackPtr(ADCData_Reg);
    }
}







