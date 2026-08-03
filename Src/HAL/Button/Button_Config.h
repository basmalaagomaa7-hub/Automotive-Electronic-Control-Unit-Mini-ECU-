/**
* @file    Button_Config.h
* @author  dev Basmala Mahmoud  
* @author  rev Malak Mohammed
* @brief Configuration parameters for the Button driver.
* @details Defines button ports, pins, and connection types.
* @version 1.0
* @date    8/3/2026
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H



#include "../../MCAL/DIO/DIO_Private.h"
#include "Button_Private.h"

/* Number of buttons */
#define Btn_MaxNo      4

/* Button 1 */
#define Btn1           1
#define Btn1_Group     Dio_GroupD
#define Btn1_Pin       Dio_Pin2

/* Button 2 */
#define Btn2           2
#define Btn2_Group     Dio_GroupC
#define Btn2_Pin       Dio_Pin1

/* Button 3 */
#define Btn3           3
#define Btn3_Group     Dio_GroupC
#define Btn3_Pin       Dio_Pin2

/* Button 4 */
#define Btn4           4
#define Btn4_Group     Dio_GroupC
#define Btn4_Pin       Dio_Pin3

/* Arrays */

#define BtnGroupValue  {Btn1_Group,Btn2_Group,Btn3_Group,Btn4_Group}
#define BtnPinValue    {Btn1_Pin,Btn2_Pin,Btn3_Pin,Btn4_Pin}


#endif // BUTTON_CONFIG_H
