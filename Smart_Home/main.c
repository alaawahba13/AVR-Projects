/*
 * main.c
 *
 *  Created on: 18 Jan 2023
 *      Author: Alaa Wahba
 */

#include "main.h"

uint8 pass[5];
const uint8 my_pass[] = "1234";
uint32 i = 0, count = 0;
uint32 light, temperature;

void CallBack_Buzz() {
	lcd_Clear_Screen();
	lcd_GOTO_XY(0, 4);
	lcd_send_String("FIRE ALARM");
	DIO_WritePin(BUZZ_PIN, BUZZ_PORT, HIGH);
	_delay_ms(3000);
	DIO_WritePin(BUZZ_PIN, BUZZ_PORT, LOW);
	_delay_ms(3000);
	display_Readings();

}
void check_count(int count) {
	if (count == MAX_COUNT) {
		lcd_Clear_Screen();
		lcd_GOTO_XY(0, 4);
		lcd_send_String("MAX COUNT");
		while (1) {
			DIO_WritePin(LED_PIN, LED_PORT, HIGH);
			_delay_ms(1000);
			DIO_WritePin(LED_PIN, LED_PORT, LOW);
			_delay_ms(1000);
		}
	}
}
void clc_screen() {

	lcd_Clear_Screen();
	lcd_GOTO_XY(0, 2);
	lcd_send_String("Enter Password: ");
	lcd_GOTO_XY(1, 6);
	i = 0;
	memset(pass, (uint8) 0, strlen(pass));

}
void checkMode() {
	uint8 mode;
	static uint8 auto_done = 0, bluetooth_done = 0, uart_done = 0;

	uint8 *uart_send =
			"Press on the following:\n 1.Lamp On\n 2.Lamp Off\n 3.Fan On \n4.Fan Off";
	uint8 uart_data = 0;
	mode = DIO_ReadPin(MODE_PIN, MODE_PORT);
	if (mode) {
		// Automatic
		if (!auto_done) {
			lcd_Clear_Screen();
			lcd_GOTO_XY(0, 2);
			lcd_send_String("Automatic mode");
			lcd_GOTO_XY(1, 4);
			lcd_send_String("activated");
			_delay_ms(1000);
			auto_done = 1;
			bluetooth_done = 0;
			uart_done = 0;
		}

		display_Readings();
		//LM35
		if (temperature >= 30) {
			DIO_WritePin(FAN_PIN, FAN_PORT, HIGH);

		} else {
			DIO_WritePin(FAN_PIN, FAN_PORT, LOW);

		}
		//LDR

		if (light >= 50) {
			DIO_WritePin(LAMP_PIN, LAMP_PORT, HIGH);

		} else {
			DIO_WritePin(LAMP_PIN, LAMP_PORT, LOW);

		}
	} else if (mode == BLUETOOTH_MODE) {
		// Bluetooth mode
		if (!bluetooth_done) {
			lcd_Clear_Screen();
			lcd_GOTO_XY(0, 2);
			lcd_send_String("Bluetooth mode");
			lcd_GOTO_XY(1, 4);
			lcd_send_String("activated");
			_delay_ms(1000);
			bluetooth_done = 1;
			auto_done = 0;
		}
		//Uart
		if (!uart_done) {
					USART_send_string_Asynch(uart_send);
					uart_done = 1; // To send the string only one time
				}
		display_Readings();


		USART_recievePeriodicData(&uart_data);

		switch (uart_data) {
		case '1':
			DIO_WritePin(LAMP_PIN, LAMP_PORT, HIGH);
			break;
		case '2':
			DIO_WritePin(LAMP_PIN, LAMP_PORT, LOW);
			break;
		case '3':
			DIO_WritePin(FAN_PIN, FAN_PORT, HIGH);
			break;
		case '4':
			DIO_WritePin(FAN_PIN, FAN_PORT, LOW);
			break;
		}
	}
}

void display_Readings() {
	static uint8 prevTemp = 0, prevLight = 0; // to refresh the readings only if they changed
	prevTemp = temperature;
	temperature = LM35_getTemperature();
	prevLight = light;
	light = LDR_getLight();
	if ((light != prevLight) || (temperature != prevTemp)) {
		lcd_Clear_Screen();
		lcd_GOTO_XY(0, 2);
		lcd_send_String("Temperature is:");
		lcd_display_number(temperature);
		lcd_GOTO_XY(1, 2);
		lcd_send_String("Light Percent:");
		lcd_display_number(100 - light);
		lcd_send_String("%");
		_delay_ms(500);
	}
}

int main(void) {
	/* 			variables						*/

	char key, flag = 0;
	/* 			intializations						*/
	DIO_initPin(MODE_PIN, MODE_PORT, INPUT);
	DIO_initPin(FAN_PIN, FAN_PORT, OUTPUT);
	DIO_initPin(BUZZ_PIN, BUZZ_PORT, OUTPUT);
	DIO_initPin(LED_PIN, LED_PORT, OUTPUT);
	DIO_initPin(LAMP_PIN, LAMP_PORT, OUTPUT);

	LM35_init();
	lcd_init();
	LDR_init();
	USART_init();
	Keypad_init();
	EXTI_Enable(EXTI0, Falling_Edge);
	EXTI_setCallBackFunction(EXTI0_Index, &CallBack_Buzz);
	/* 			lcd display						*/
	lcd_Clear_Screen();
	lcd_GOTO_XY(0, 2);
	lcd_send_String("Enter Password: ");
	lcd_GOTO_XY(1, 6);

	while (1) {
		if (!flag) {
			key = Keypad_Get_Key();
			if (key == CLC_SCREEN) {
				clc_screen();
			} else if (key == NO_KEY_PRESSED) {
				// DO NOTHING
			} else {
				lcd_Send_Char('*');
				pass[i] = key;
				i++;
				if (i == 4) {
					if (!strcmp(pass, my_pass)) {
						lcd_Clear_Screen();
						count = 0;
						lcd_GOTO_XY(0, 2);
						lcd_send_String("Welcome Home");
						_delay_ms(1000);
						flag = 1;
					} else {
						count++;
						check_count(count);
						lcd_Clear_Screen();
						lcd_GOTO_XY(0, 2);
						lcd_send_String("Wrong Password");
						_delay_ms(1000);
						clc_screen();
					}
				}
			}
		} else {
			checkMode();
		}
	}

	return 0;
}

