/*
 * DIO.h
 *
 * Created: 21-Nov-22 9:18:26 PM
 *  Author: Mahmoud
 */ 


#ifndef DIO_H_
#define DIO_H_

// Driver Inclusions

#include "../REG.h"
#include "../../Library/STD.h"
#include "../../Library/BIT_MATH.h"


// Driver Macros

#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'

#define PIN0	 0
#define PIN1	 1
#define PIN2	 2
#define PIN3	 3
#define PIN4	 4
#define PIN5	 5
#define PIN6	 6
#define PIN7	 7

#define IN		 0
#define OUT	 	 1

#define LOW		 0
#define HIGH 	 1


// Driver Functions Prototypes
void DIO_init   (u8 portNumber, u8 pinNumber, u8 pinDirection);
void DIO_write  (u8 portNumber, u8 pinNumber, u8 pinValue    );
void DIO_toggle (u8 portNumber, u8 pinNumber);
u8   DIO_read   (u8 portNumber, u8 pinNumber);

#endif /* DIO_H_ */
