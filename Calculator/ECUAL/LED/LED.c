/*
 * LED.c
 *
 * Created: 21-Nov-22 10:56:07 PM
 *  Author: Mahmoud
 */

#include "../../ECUAL/LED/LED.h"


void LED_init    (u8 LedNum)
{
	switch(LedNum)
	{
		case 1:
			DIO_init(LED_RED_PORT, LED_RED_PIN, OUT);
			break;
		case 2:
			DIO_init(LED_YLW_PORT, LED_YLW_PIN, OUT);
			break;
		case 3:
			DIO_init(LED_GRN_PORT, LED_GRN_PIN, OUT);
			break;
		default:
			// ERR
			break;
	}
}

void LED_on      (u8 LedNum)
{
	switch(LedNum)
	{
		case 1:
			DIO_write(LED_RED_PORT, LED_RED_PIN, HIGH);
			break;
		case 2:
			DIO_write(LED_YLW_PORT, LED_YLW_PIN, HIGH);
			break;
		case 3:
			DIO_write(LED_GRN_PORT, LED_GRN_PIN, HIGH);
			break;
		default:
			// ERR
			break;
	}
}

void LED_off     (u8 LedNum)
{
	switch(LedNum)
	{
		case 1:
			DIO_write(LED_RED_PORT, LED_RED_PIN, LOW);
			break;
		case 2:
			DIO_write(LED_YLW_PORT, LED_YLW_PIN, LOW);
			break;
		case 3:
			DIO_write(LED_GRN_PORT, LED_GRN_PIN, LOW);
			break;
		default:
			// ERR
			break;
	}
}

void LED_toggle  (u8 LedNum)
{
	switch(LedNum)
	{
		case 1:
			DIO_toggle(LED_RED_PORT, LED_RED_PIN);
			break;
		case 2:
			DIO_toggle(LED_YLW_PORT, LED_YLW_PIN);
			break;
		case 3:
			DIO_toggle(LED_GRN_PORT, LED_GRN_PIN);
			break;
		default:
			// ERR
			break;
	}
}

