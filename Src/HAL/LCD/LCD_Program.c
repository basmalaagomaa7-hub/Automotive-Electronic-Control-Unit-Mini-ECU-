#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

static void LCD_PulseEnable(void)
{
    DIO_WritePin(LCD_EN_GROUP, LCD_EN_PIN, 1U);
    _delay_us(2);
    DIO_WritePin(LCD_EN_GROUP, LCD_EN_PIN, 0U);
    _delay_us(50);
}

static void LCD_SendNibble(uint8_t Nibble)
{
    DIO_WritePin(LCD_D4_GROUP, LCD_D4_PIN, (Nibble >> 0U) & 1U);
    DIO_WritePin(LCD_D5_GROUP, LCD_D5_PIN, (Nibble >> 1U) & 1U);
    DIO_WritePin(LCD_D6_GROUP, LCD_D6_PIN, (Nibble >> 2U) & 1U);
    DIO_WritePin(LCD_D7_GROUP, LCD_D7_PIN, (Nibble >> 3U) & 1U);
    LCD_PulseEnable();
}

static void LCD_SendCommand(uint8_t Command)
{
    DIO_WritePin(LCD_RS_GROUP, LCD_RS_PIN, 0U);
    LCD_SendNibble(Command >> 4U);
    LCD_SendNibble(Command & 0x0FU);

    if((Command == 0x01U) || (Command == 0x02U))
    {
        _delay_ms(2);
    }
}

void LCD_Init(void)
{
    DIO_InitPin(LCD_RS_GROUP, LCD_RS_PIN, 1U);
    DIO_InitPin(LCD_EN_GROUP, LCD_EN_PIN, 1U);
    DIO_InitPin(LCD_D4_GROUP, LCD_D4_PIN, 1U);
    DIO_InitPin(LCD_D5_GROUP, LCD_D5_PIN, 1U);
    DIO_InitPin(LCD_D6_GROUP, LCD_D6_PIN, 1U);
    DIO_InitPin(LCD_D7_GROUP, LCD_D7_PIN, 1U);

    DIO_WritePin(LCD_RS_GROUP, LCD_RS_PIN, 0U);
    DIO_WritePin(LCD_EN_GROUP, LCD_EN_PIN, 0U);

    _delay_ms(40);
    LCD_SendNibble(0x03U);
    _delay_ms(5);
    LCD_SendNibble(0x03U);
    _delay_us(150);
    LCD_SendNibble(0x03U);
    LCD_SendNibble(0x02U);

    LCD_SendCommand(0x28U); /* 4-bit, 2 lines, 5x8 font */
    LCD_SendCommand(0x0CU); /* display on, cursor off */
    LCD_SendCommand(0x06U); /* increment cursor */
    LCD_Clear();
}

void LCD_Clear(void)
{
    LCD_SendCommand(0x01U);
}

void LCD_SetCursor(uint8_t Line, uint8_t Column)
{
    uint8_t Address;

    if(Column > 15U)
    {
        Column = 15U;
    }

    Address = (Line == LCD_LINE_2) ? (uint8_t)(0x40U + Column) : Column;
    LCD_SendCommand((uint8_t)(0x80U | Address));
}

void LCD_WriteCharacter(uint8_t Character)
{
    DIO_WritePin(LCD_RS_GROUP, LCD_RS_PIN, 1U);
    LCD_SendNibble(Character >> 4U);
    LCD_SendNibble(Character & 0x0FU);
}

void LCD_WriteString(const uint8_t *String)
{
    if(String == 0)
    {
        return;
    }

    while(*String != '\0')
    {
        LCD_WriteCharacter(*String);
        String++;
    }
}

void LCD_WriteNumber(uint32_t Number)
{
    uint8_t Digits[10];
    uint8_t Count = 0U;

    if(Number == 0U)
    {
        LCD_WriteCharacter('0');
        return;
    }

    while((Number > 0U) && (Count < 10U))
    {
        Digits[Count] = (uint8_t)('0' + (Number % 10U));
        Number /= 10U;
        Count++;
    }

    while(Count > 0U)
    {
        Count--;
        LCD_WriteCharacter(Digits[Count]);
    }
}
