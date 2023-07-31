/*
 * button.c
 *
 * Created: 22-Nov-22 6:50:54 AM
 *  Author: Mahmoud
 */ 


#include "Motor.h"


void MTR_init    (u8 mtrNum)
{
	switch(mtrNum)
	{
		case 1:
			DIO_init(MTR1_PORT, MTR1_PIN_1, OUT);
			DIO_init(MTR1_PORT, MTR1_PIN_2, OUT);
			DIO_write(MTR1_PORT, MTR1_PIN_1, LOW);
			DIO_write(MTR1_PORT, MTR1_PIN_2, LOW);
			break;
		case 2:
			DIO_init(MTR2_PORT, MTR2_PIN_1, OUT);
			DIO_init(MTR2_PORT, MTR2_PIN_2, OUT);
			DIO_write(MTR2_PORT, MTR2_PIN_1, LOW);
			DIO_write(MTR2_PORT, MTR2_PIN_2, LOW);
			break;
		default:
			// ERR
			break;
	}
}

void MTR_ON_CW   (u8 mtrNum)
{
	switch(mtrNum)
	{
		case 1:
			DIO_write(MTR1_PORT, MTR1_PIN_1, HIGH);
			DIO_write(MTR1_PORT, MTR1_PIN_2, LOW );
			break;
		case 2:
			DIO_write(MTR2_PORT, MTR2_PIN_1, HIGH);
			DIO_write(MTR2_PORT, MTR2_PIN_2, LOW);
			break;
		default:
			// ERR
			break;
	}
}

void MTR_ON_CCW  (u8 mtrNum)
{
	switch(mtrNum)
	{
		case 1:
			DIO_write(MTR1_PORT, MTR1_PIN_1, LOW );
			DIO_write(MTR1_PORT, MTR1_PIN_2, HIGH);
			break;
		case 2:
			DIO_write(MTR2_PORT, MTR2_PIN_1, LOW );
			DIO_write(MTR2_PORT, MTR2_PIN_2, HIGH);
			break;
		default:
			// ERR
			break;
	}
}

void MTR_OFF     (u8 mtrNum)
{
	switch(mtrNum)
	{
		case 1:
			DIO_write(MTR1_PORT, MTR1_PIN_1, LOW);
			DIO_write(MTR1_PORT, MTR1_PIN_2, LOW);
			break;
		case 2:
			DIO_write(MTR2_PORT, MTR2_PIN_1, LOW);
			DIO_write(MTR2_PORT, MTR2_PIN_2, LOW);
			break;
		default:
			// ERR
			break;
	}
}
