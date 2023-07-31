/*
 * REG.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Mahmoud
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

#include "../Library/STD.h"

/*************** DIO_REGISTERS *************/

#define PORTA      (*((volatile u8*)0x3B))
#define DDRA       (*((volatile u8*)0x3A))
#define PINA       (*((volatile u8*)0x39))

#define PORTB      (*((volatile u8*)0x38))
#define DDRB       (*((volatile u8*)0x37))
#define PINB       (*((volatile u8*)0x36))

#define PORTC      (*((volatile u8*)0x35))
#define DDRC       (*((volatile u8*)0x34))
#define PINC       (*((volatile u8*)0x33))

#define PORTD      (*((volatile u8*)0x32))
#define DDRD       (*((volatile u8*)0x31))
#define PIND       (*((volatile u8*)0x30))

/**************_EX_INT_REGISTERS_************/

#define SREG   (*(volatile u8*)(0x5F))
#define GICR   (*(volatile u8*)(0x5B))
#define GIFR   (*(volatile u8*)(0x5A))
#define MCUCR  (*(volatile u8*)(0x55))
#define MCUCSR (*(volatile u8*)(0x54))

/***************_ADC_REGISTERS_**************/

#define ADMUX           (*(volatile u8*)(0x27))
#define ADCSRA          (*(volatile u8*)(0x26))
#define ADCH            (*(volatile u8*)(0x25))
#define ADCL            (*(volatile u8*)(0x24))
#define ADC_VALUE       (*(volatile u16*)(0x24))
/***************_TIMER0_REGISTERS_**************/

#define TCNT0           (*(volatile u8*)(0x52))
#define TIMSK           (*(volatile u8*)(0x59))
#define TCCR0           (*(volatile u8*)(0x53))
#define TIFR            (*(volatile u8*)(0x58))
#define OCR0            (*(volatile u8*)(0x5C))

/***************_TIMER1_REGISTERS_**************/

#define TCCR1B          (*(volatile u8*)(0x4E))
#define TCCR1A          (*(volatile u8*)(0x4F))
#define OCR1A           (*(volatile u16*)(0x4A))


/***************_WDT_REGISTERS_**************/

#define WDTCR          (*(volatile u8*)(0x41))

/***************_UART_REGISTERS_**************/

#define UDR            (*(volatile u8*)(0x2C))
#define UCSRA          (*(volatile u8*)(0x2B))
#define UCSRB          (*(volatile u8*)(0x2A))
#define UCSRC          (*(volatile u8*)(0x40))
#define UBRRL          (*(volatile u8*)(0x29))

/***************_SPI_REGISTERS_**************/

#define SPCR          (*(volatile u8*)(0x2D))
#define SPDR          (*(volatile u8*)(0x2F))
#define SPSR          (*(volatile u8*)(0x2E))


#endif /* DIO_REG_H_ */
