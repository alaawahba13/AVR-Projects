/*
 * button.c
 *
 * Created: 22-Nov-22 6:50:54 AM
 *  Author: Mahmoud
 */ 


#include "button.h"


void BTN_init  (u8 btnNum)
{
	switch(btnNum)
	{
		case 1:
			DIO_init (BTN_1_PORT, BTN_1_PIN, IN);
			DIO_write(BTN_1_PORT, BTN_1_PIN, LOW);
			break;
		case 2:
			DIO_init (BTN_2_PORT, BTN_2_PIN, IN);
			DIO_write(BTN_2_PORT, BTN_2_PIN, LOW);
			break;
		case 3:
			DIO_init (BTN_3_PORT, BTN_3_PIN, IN);
			DIO_write(BTN_3_PORT, BTN_3_PIN, LOW);
			break;
		case 4:
			DIO_init (BTN_4_PORT, BTN_4_PIN, IN);
			DIO_write(BTN_4_PORT, BTN_4_PIN, LOW);
			break;
		default:
			// ERR
			break;
	}
}

u8   BTN_read  (u8 btnNum)
{
	u8 btnValue = 0;
	switch(btnNum)
	{
		case 1:
			btnValue = DIO_read(BTN_1_PORT, BTN_1_PIN);
			break;
		case 2:
			btnValue = DIO_read(BTN_2_PORT, BTN_2_PIN);
			break;
		case 3:
			btnValue = DIO_read(BTN_3_PORT, BTN_3_PIN);
			break;
		case 4:
			btnValue = DIO_read(BTN_4_PORT, BTN_4_PIN);
			break;
		default:
			// ERR
			break;
	}
	return btnValue;
}

