/*
 * DIO.c
 *
 * Created: 21-Nov-22 9:18:13 PM
 *  Author: Mahmoud
 */ 

#include "DIO.h"


void DIO_init (u8 portNumber, u8 pinNumber, u8 pinDirection)
{
	switch (portNumber)
	{
		case PORT_A:
			if (pinDirection == OUT)
			{
				SET_BIT(DDRA, pinNumber);
			}
			else if (pinDirection == IN)
			{
				CLR_BIT(DDRA, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
		case PORT_B:
			if (pinDirection == OUT)
			{
				SET_BIT(DDRB, pinNumber);
			}
			else if (pinDirection == IN)
			{
				CLR_BIT(DDRB, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
		case PORT_C:
			if (pinDirection == OUT)
			{
				SET_BIT(DDRC, pinNumber);
			}
			else if (pinDirection == IN)
			{
				CLR_BIT(DDRC, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
		case PORT_D:
			if (pinDirection == OUT)
			{
				SET_BIT(DDRD, pinNumber);
			}
			else if (pinDirection == IN)
			{
				CLR_BIT(DDRD, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
	}
}

void DIO_write (u8 portNumber, u8 pinNumber, u8 pinValue)
{
	switch (portNumber)
	{
		case PORT_A:
			if (pinValue == HIGH)
			{
				SET_BIT(PORTA, pinNumber);
			}
			else if (pinValue == LOW)
			{
				CLR_BIT(PORTA, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
		case PORT_B:
			if (pinValue == HIGH)
			{
				SET_BIT(PORTB, pinNumber);
			}
			else if (pinValue == LOW)
			{
				CLR_BIT(PORTB, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
		case PORT_C:
			if (pinValue == HIGH)
			{
				SET_BIT(PORTC, pinNumber);
			}
			else if (pinValue == LOW)
			{
				CLR_BIT(PORTC, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
		case PORT_D:
			if (pinValue == HIGH)
			{
				SET_BIT(PORTD, pinNumber);
			}
			else if (pinValue == LOW)
			{
				CLR_BIT(PORTD, pinNumber);
			}
			else
			{
				// ERR
			}
			break;
	}
}

void DIO_toggle (u8 portNumber, u8 pinNumber)
{
	switch (portNumber)
	{
		case PORT_A:
			TOG_BIT(PORTA, pinNumber);
			break;
		case PORT_B:
			TOG_BIT(PORTB, pinNumber);
			break;
		case PORT_C:
			TOG_BIT(PORTC, pinNumber);
			break;
		case PORT_D:
			TOG_BIT(PORTD, pinNumber);
			break;
		default:
			// ERR
			break;
	}
}

u8   DIO_read (u8 portNumber, u8 pinNumber)
{
	u8 pinValue = 0;
	switch (portNumber)
	{
		case PORT_A:
			pinValue = GET_BIT(PINA, pinNumber);
			break;
		case PORT_B:
			pinValue = GET_BIT(PINB, pinNumber);
			break;
		case PORT_C:
			pinValue = GET_BIT(PINC, pinNumber);
			break;
		case PORT_D:
			pinValue = GET_BIT(PIND, pinNumber);
			break;
		default:
			// ERR
			break;
	}
	return pinValue;
}
