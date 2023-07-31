/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "Atmega32/inc/DIO.h"
#include "HAL/Keypad_Driver/Keypad.h"
#include "HAL/LCD_Driver/LCD.h"

#include <stdio.h>
#include <string.h>

#define MAX 		2
char pass[5];
const char my_pass[] = "1234";
int i = 0, count = 0;

int main(void) {

	lcd_init();
	Keypad_init();
	DIO_initPin(PIN_0, PORT_A, OUTPUT);
	DIO_initPin(PIN_1, PORT_A, OUTPUT);
	DIO_initPin(PIN_2, PORT_A, OUTPUT);

	lcd_send_String("Enter Password: ");
	char key;

	while (1) {
		key = Keypad_Get_Key();
		if (key == '?') {
			lcd_Clear_Screen();
		} else if (key == 'A') {

		} else {
			lcd_Send_Char('*');
			pass[i] = key;
			i++;
			if (i == 4) {
				if (strcmp(pass, my_pass) == 0) {
					motor_direction();
					clc_screen();
					count = 0;
				} else {
					count++;
					check_count(count);
					lcd_Clear_Screen();
					lcd_send_String("Wrong Password");
					_delay_ms(1000);
					clc_screen();

				}
			}
		}

	}

	return 0;
}

void Forward() {
	DIO_WritePin(PIN_1, PORT_A, HIGH);
	DIO_WritePin(PIN_2, PORT_A, LOW);

}
void backward() {
	DIO_WritePin(PIN_2, PORT_A, HIGH);
	DIO_WritePin(PIN_1, PORT_A, LOW);

}
void stop() {
	DIO_WritePin(PIN_2, PORT_A, LOW);
	DIO_WritePin(PIN_1, PORT_A, LOW);
}
void motor_direction() {
	int flag = 1;
	lcd_Clear_Screen();
	lcd_send_String("Motor direction");
	lcd_GOTO_XY(1, 1);
	lcd_send_String("1.CW  2.ACW");
	while (flag) {
		char x = Keypad_Get_Key();
		if (x == '1') {
			flag = 0;
			Forward();
			lcd_Clear_Screen();
			lcd_send_String("Clockwise");
			_delay_ms(1000);
			stop();
		} else if (x == '2') {
			flag = 0;
			backward();
			lcd_Clear_Screen();
			lcd_send_String("Anti Clockwise");
			_delay_ms(1000);
			stop();
		}
	}
}

void check_count(int count) {
	if (count == MAX) {
		lcd_Clear_Screen();
		lcd_send_String("MAX COUNT");
		while (1) {
			DIO_WritePin(PIN_0, PORT_A, HIGH);
			_delay_ms(500);
			DIO_WritePin(PIN_0, PORT_A, LOW);
			_delay_ms(500);
		}
	}
}
void clc_screen() {

	lcd_Clear_Screen();
	lcd_send_String("Enter Password: ");
	i = 0;
	memset(pass, 0, strlen(pass));

}
