

#ifndef ECUAL_LCD_LCD_H_
#define ECUAL_LCD_LCD_H_

// Driver Inclusions

#include "../../MCAL/DIO/DIO.h"
#include "../../Library/STD.h"
#include <util/delay.h>


// Driver Macros

#define LCD_CMD_PORT_DIR	DDRB
#define LCD_CMD_PORT		PORTB

#define LCD_DATA_PORT_DIR	DDRA
#define LCD_DATA_PORT		PORTA

#define RS		1
#define RW		2
#define EN		3

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE


// Driver Functions Prototypes

void LCD_init (void);
void LCD_sendCMD (u8 cmnd);
void LCD_sendChar (u8 charData);
void LCD_sendString (u8 *str);
void LCD_createCustomCharacter (u8 *pattern, u8 location);
void LCD_CLR (void);
void LCD_SendNumber(int Number);
void LCD_GoToPos(u8 row, u8 col);


#endif /* ECUAL_LCD_LCD_H_ */
