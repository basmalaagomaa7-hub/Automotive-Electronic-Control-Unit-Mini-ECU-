#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <stdint.h>

void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t Line, uint8_t Column);
void LCD_WriteCharacter(uint8_t Character);
void LCD_WriteString(const uint8_t *String);
void LCD_WriteNumber(uint32_t Number);

#endif
