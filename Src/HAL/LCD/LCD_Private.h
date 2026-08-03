#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

static void LCD_SendCommand(uint8_t Command);
static void LCD_SendNibble(uint8_t Nibble);
static void LCD_PulseEnable(void);

#endif
