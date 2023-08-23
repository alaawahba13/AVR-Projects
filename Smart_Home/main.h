/*
 * main.h
 *
 *  Created on: 18 Aug 2023
 *      Author: Alaa Wahba
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "Atmega32/inc/DIO.h"
#include "Atmega32/inc/ADC.h"
#include "Atmega32/inc/EXTI.h"
#include "Atmega32/inc/USART.h"

#include "HAL/LCD_Driver/LCD.h"
#include "HAL/Keypad_Driver/Keypad.h"
#include "HAL/LM35/LM35.h"
#include "HAL/LDR/LDR.h"

#include <stdio.h>
#include <string.h>

#define MAX_COUNT 				2
#define AUTOMATIC_MODE			HIGH
#define BLUETOOTH_MODE			LOW
#define NO_KEY_PRESSED			'A'
#define CLC_SCREEN				'?'

#define MODE_PIN 				PIN_4
#define MODE_PORT 				PORT_D

#define FAN_PIN 				PIN_7
#define FAN_PORT 				PORT_C

#define LAMP_PIN 				PIN_7
#define LAMP_PORT 				PORT_A

#define LED_PIN 				PIN_7
#define LED_PORT 				PORT_B

#define BUZZ_PIN 				PIN_6
#define BUZZ_PORT 				PORT_C

void CallBack_Buzz();
void check_count(int count);
void clc_screen();
void checkMode();
void display_Readings();

#endif /* MAIN_H_ */
