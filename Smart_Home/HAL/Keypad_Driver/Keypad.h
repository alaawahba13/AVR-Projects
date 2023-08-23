/*
 * Keypad.h
 *
 *  Created on: 17 Jan 2023
 *      Author: Alaa Wahba
 */

#ifndef KEYPAD_DRIVER_KEYPAD_H_
#define KEYPAD_DRIVER_KEYPAD_H_
#include <C:/Users/Qebaa/OneDrive/Documents/eclipse-workspace/Garage_System/Atmega32/inc/DIO.h>
#include <util/delay.h>
#include "../../Library/BIT_MATH.h"

//Define the PORT , PIND & DDR register connected to keypad
#define Keypad_Row_PORT   		PORTC
#define Keypad_COL_PORT   		PORTD

#define Keypad_ROW_DDR			DDRC
#define Keypad_COL_DDR			DDRD

#define Keypad_ROW_PIN 		    	PINC

// Define the Keypad Cols & Rows pins
#define R0 					5
#define R1					4
#define R2 					3
#define R3					2

#define C0 					7
#define C1					6
#define C2 					5
#define C3					3


void Keypad_init();
char Keypad_Get_Key();

#endif /* KEYPAD_DRIVER_KEYPAD_H_ */
