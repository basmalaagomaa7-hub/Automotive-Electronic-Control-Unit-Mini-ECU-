/**
* @file    BIT_MATH.h
* @author (developer)  
* @author(reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SetBit(Reg,BitNo)      Reg|=(1<<BitNo)
#define ClearBit(Reg,BitNo)    Reg&=~(1<<BitNo)
#define ToggleBit(Reg,BitNo)   Reg^=(1<<BitNo)
#define ReadBit(Reg,BitNo)     (Reg>>BitNo)&0x01


#define ReadFlag(Reg,FlagNo)   ReadBit(Reg,FlagNo)
#define ClearFlag(Reg,FlagNo)  SetBit(Reg,FlagNo)


#endif // BIT_MATH_H
