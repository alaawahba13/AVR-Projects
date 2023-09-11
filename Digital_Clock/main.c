/*
 * main.c
 *
 *  Created on: 7 Sept 2023
 *      Author: Alaa Wahba
 */

#include "main.h"

/*
 * Features :
 * snooze option				   done
 * adjustable time format		   done
 *
 * */

RTC_t rtc = { 0x23, 0x59, 0x30, 0x10, 0x09, 0x23, HOURS_24, HOURS_PM, SUN };
char time[50];
char date[50];

RTC_t current_rtc, alarm_rtc;
uint8 key;
 uint32 isSet = 0;
/*
void changeFormat() {
	// 24 to 12 hour mode
	if (current_rtc.mode == HOURS_24) {
		current_rtc.mode = HOURS_12;
		// Change alarm format
		if (alarm_rtc.hour > 0x12) {
			alarm_rtc.hour -= 0x12;
		} else if (alarm_rtc.hour == 0x00) {
			alarm_rtc.hour = 0x12;
		}
		// Change current format
		if (current_rtc.hour > 0x12) {
			current_rtc.AM_PM = HOURS_PM;
			current_rtc.hour -= 0x12;
		} else {
			if (current_rtc.hour == 0x00) {
				current_rtc.hour = 0x12;
			}
			current_rtc.AM_PM = HOURS_AM;

		}

	}
	// 12 to 24 hour mode
	else if (current_rtc.mode == HOURS_12) {
		current_rtc.mode = HOURS_24;
		// Change alarm
		if (alarm_rtc.AM_PM == HOURS_PM) {
			if (alarm_rtc.hour != 0x12) {
				alarm_rtc.hour += 0x12;
			}
		} else {
			if (alarm_rtc.hour == 0x12) {
				alarm_rtc.hour = 0x00;
			}
		}
		//
		if (current_rtc.AM_PM == HOURS_PM) {
			if (current_rtc.hour != 0x12) {
				current_rtc.hour += 0x12;
			}
		} else {
			if (current_rtc.hour == 0x12) {
				current_rtc.hour = 0x00;
			}
		}
	}
	RTC_setTimeDate(&current_rtc);

}*/

void viewAlarm() {
	lcd_Clear_Screen();
if (isSet) {
	sprintf(time, "Alarm is set for:       %.2x :%.2x :%.2x", alarm_rtc.hour,
			alarm_rtc.minute, alarm_rtc.second);
	lcd_GOTO_XY(0, 2);
	lcd_send_String(time);
	_delay_ms(1000);
	lcd_Clear_Screen();


	} else {
	lcd_GOTO_XY(0, 2);
	lcd_send_String("No Alarm");
	_delay_ms(1000);
	lcd_Clear_Screen();

}
}

void disableAlarm() {
	alarm_rtc.hour = 0x00;
	alarm_rtc.minute = 0x00;
	alarm_rtc.second = 0x00;
	lcd_Clear_Screen();
	lcd_GOTO_XY(0, 2);
	lcd_send_String("Alarm Disabled");
	_delay_ms(1000);
	lcd_Clear_Screen();
	isSet = 0;
}
void checkAlarm() {

	if ((alarm_rtc.hour == current_rtc.hour)
			&& (alarm_rtc.minute == current_rtc.minute)
			&& (alarm_rtc.second == current_rtc.second)) {
		DIO_WritePin(ALARM_PIN, ALARM_PORT, HIGH);
		lcd_Clear_Screen();
		lcd_GOTO_XY(0, 2);
		lcd_send_String("ALARM IS SET");
		while (key == 'A') {
			key = Keypad_Get_Key();
			if (key == '=') {  //stop alarm
				DIO_WritePin(ALARM_PIN, ALARM_PORT, LOW);
				lcd_Clear_Screen();
				disableAlarm();
			} else if (key == '+') { // snooze for 5 minutes
				alarm_rtc.minute += 0x01;
				DIO_WritePin(ALARM_PIN, ALARM_PORT, LOW);
				lcd_Clear_Screen();
				lcd_GOTO_XY(0, 2);
				lcd_send_String("Snoozing alarm...");
				_delay_ms(1000);
				lcd_Clear_Screen();

			}

		}

	}

}



void setAlarm() {
	char time[50];

	alarm_rtc = current_rtc;
	RTC_getDateTimeStr(&alarm_rtc, date, time);

	while (1) {
		key = Keypad_Get_Key();

		switch (key) {
		case '4':  // inc hours
			if (++alarm_rtc.hour == 0x24) {
				alarm_rtc.hour = 0x00;
			}
			break;
		case '5':
			if (++alarm_rtc.minute == 0x5a) {
				alarm_rtc.minute = 0x00;
				if (++alarm_rtc.hour == 0x24) {
					alarm_rtc.hour = 0x00;
				}
			}

			break;
		case '6':
			if (++alarm_rtc.second == 0x5a) {
				alarm_rtc.second = 0x00;
				if (++alarm_rtc.minute == 0x5a) {
					alarm_rtc.minute = 0x00;
					if (++alarm_rtc.hour == 0x24) {
						alarm_rtc.hour = 0x00;
					}
				}
			}
			break;
		case '7':		// dec hours
			if (--alarm_rtc.hour == 0xff) {
				alarm_rtc.hour = 0x23;
			}
			break;
		case '8':
			if (--alarm_rtc.minute == 0xff) {
				if (--alarm_rtc.hour == 0xff) {
					alarm_rtc.hour = 0x23;
				}
				alarm_rtc.minute = 0x59;
			}
			break;
		case '9':
			if (--alarm_rtc.second == 0xff) {
				if (--alarm_rtc.minute == 0xff) {
					if (--alarm_rtc.hour == 0xff) {
						alarm_rtc.hour = 0x23;
					}
					alarm_rtc.minute = 0x59;
				}
				alarm_rtc.second = 0x59;

			}

			break;
		case '*':
			isSet = 1;
			return;
			break;
		}
		lcd_GOTO_XY(0, 2);
		RTC_getDateTimeStr(&alarm_rtc, date, time);
		lcd_send_String(time);

	}


}

int main(void) {

	RTC_init();
	lcd_init();
	//SEG_4D_init();
	Keypad_init();
	DIO_initPin(ALARM_PIN, ALARM_PORT, OUTPUT);
	lcd_Clear_Screen();
	RTC_setTimeDate(&rtc);
	//uint16 x= 1234;


	while (1) {

		key = Keypad_Get_Key();

		switch (key) {
		case '?':
			disableAlarm();
			break;
		case '1':
			setAlarm();
			break;
		case '0':
			viewAlarm();
			break;
		}

		RTC_getDateTime(&current_rtc);
		RTC_getDateTimeStr(&current_rtc, date, time);
		lcd_GOTO_XY(0, 2);
		lcd_send_String(time);
		checkAlarm();


	}

	return 0;
}


