/*
 * LCD.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Mahmoud
 */

#include "LCD.h"

void LCD_init(void) /* LCD 8-bit Mode Initialize function */
{

	LCD_CMD_PORT_DIR = 0xFF; /* Make LCD command port direction as o/p */
	LCD_DATA_PORT_DIR = 0xFF; /* Make LCD data port direction as o/p */

	_delay_ms(20); /* LCD Power ON delay always >15ms */

#ifdef EIGHT_BIT_MODE				// Preprocessor directives
	LCD_sendCMD(0x38);		/* Initialization of 16X2 LCD in 8bit mode */
#endif

#ifdef FOUR_BIT_MODE
	LCD_sendCMD(0x02); /* Initialization of 16X2 LCD in 4bit mode */
	LCD_sendCMD(0x28);
#endif

	LCD_sendCMD(0x0C); /* Display ON Cursor OFF */
	LCD_sendCMD(0x06); /* Auto Increment cursor */
	LCD_sendCMD(0x01); /* clear display */

	_delay_ms(2); /* Clear display command delay> 1.63 ms */

	LCD_sendCMD(0x80); /* cursor at home position */

}

void LCD_sendCMD(u8 cmnd) {
#ifdef EIGHT_BIT_MODE
	LCD_DATA_PORT = cmnd ;
		LCD_CMD_PORT &= ~(1<<RS);	/* RS=O command register */  // CLEAR_BIT(LCD_CMD_PORT, RS)
		LCD_CMD_PORT &= ~(1<<RW);	/* RW=0 Write operation */

		/* Enable pulse */
		LCD_CMD_PORT |=  (1<<EN);
		_delay_ms(1);
		LCD_CMD_PORT &=  ~(1<<EN);

#endif

#ifdef FOUR_BIT_MODE
	LCD_DATA_PORT = cmnd & 0xF0;
	LCD_CMD_PORT &= ~(1 << RS); /* RS=O command register */ // CLEAR_BIT(LCD_CMD_PORT, RS)
	LCD_CMD_PORT &= ~(1 << RW); /* RW=0 Write operation */

	/* Enable pulse */
	LCD_CMD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_CMD_PORT &= ~(1 << EN);

	// 2
	LCD_DATA_PORT = cmnd << 4;
	LCD_CMD_PORT &= ~(1 << RS); /* RS=O command register */ // CLEAR_BIT(LCD_CMD_PORT, RS)
	LCD_CMD_PORT &= ~(1 << RW); /* RW=0 Write operation */

	/* Enable pulse */
	LCD_CMD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_CMD_PORT &= ~(1 << EN);
#endif
	_delay_ms(5);
}

void LCD_sendChar(u8 charData) {
#ifdef EIGHT_BIT_MODE
	LCD_DATA_PORT = charData ;
	LCD_CMD_PORT |= (1 << RS); /* RS=1 data register */
	LCD_CMD_PORT &= ~(1 << RW); /* RW=0 Write operation */

	/* Enable pulse */
	LCD_CMD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_CMD_PORT &= ~(1 << EN);
#endif
#ifdef FOUR_BIT_MODE
	LCD_DATA_PORT = charData &0xF0;
	LCD_CMD_PORT |= (1 << RS); /* RS=1 data register */
	LCD_CMD_PORT &= ~(1 << RW); /* RW=0 Write operation */

	/* Enable pulse */
	LCD_CMD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_CMD_PORT &= ~(1 << EN);

	LCD_DATA_PORT = charData <<4;
		LCD_CMD_PORT |= (1 << RS); /* RS=1 data register */
		LCD_CMD_PORT &= ~(1 << RW); /* RW=0 Write operation */

		/* Enable pulse */
		LCD_CMD_PORT |= (1 << EN);
		_delay_ms(1);
		LCD_CMD_PORT &= ~(1 << EN);
#endif
	_delay_ms(5);
}

void LCD_sendString(u8 *str) {
	u8 i = 0;
	for (i = 0; str[i] != 0; i++) {
		LCD_sendChar(str[i]);
	}
}

void LCD_GoToPos(u8 row, u8 col) {
	u8 Loc[2] = { 0x80, 0xc0 };
	LCD_sendChar(Loc[row] + col);
}

void LCD_createCustomCharacter(u8 *pattern, u8 location) {
	u8 i = 0;

	LCD_sendCMD(0x40 + (location * 8)); /* Send the Address of CGRAM */

	for (i = 0; i < 8; i++) {
		LCD_sendChar(pattern[i]); /* Pass the Bytes of pattern on LCD */
	}
}

void LCD_CLR(void) {
	LCD_sendCMD(0X01); /* clear display */
	LCD_sendCMD(0X80); /* cursor at home position */
}

void LCD_SendNumber(int Number){
  u8 str[7];
  // Converts Int to String
  sprintf(str,"%d",Number);
  LCD_sendString(str);
}
