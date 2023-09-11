/*
 * main.h
 *
 *  Created on: 7 Sept 2023
 *      Author: Alaa Wahba
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "Atmega32/inc/DIO.h"

#include "HAL/LCD_Driver/LCD.h"
#include "HAL/Keypad_Driver/Keypad.h"
#include "HAL/RTC/RTC.h"
#include "HAL/FourDigit_7Seg/4D_7seg.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALARM_PIN		PIN_7
#define ALARM_PORT		PORT_B

#define MAX_ALARMS		5

/*
 *
 {{--h,--min,--sec,},
 {++h,++min,++sec,Enter},
 {SetAlarm,SetCountdown,'3','-'},
 {Disable,View,Stop,Snooze}

 };
 *
 * */

#endif /* MAIN_H_ */
