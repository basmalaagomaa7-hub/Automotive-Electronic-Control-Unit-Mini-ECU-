#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* 16x2 LCD, 4-bit mode. RW must be connected to GND. */
#define LCD_RS_GROUP    Dio_GroupC
#define LCD_RS_PIN      Dio_Pin0
#define LCD_EN_GROUP    Dio_GroupC
#define LCD_EN_PIN      Dio_Pin1
#define LCD_D4_GROUP    Dio_GroupC
#define LCD_D4_PIN      Dio_Pin2
#define LCD_D5_GROUP    Dio_GroupC
#define LCD_D5_PIN      Dio_Pin3
#define LCD_D6_GROUP    Dio_GroupC
#define LCD_D6_PIN      Dio_Pin4
#define LCD_D7_GROUP    Dio_GroupC
#define LCD_D7_PIN      Dio_Pin5

#define LCD_LINE_1      0U
#define LCD_LINE_2      1U

#endif
