/*
 * button.h
 *
 * Created: 22-Nov-22 6:51:08 AM
 *  Author: Mahmoud
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


// Driver Inclusions

#include "../../MCAL/DIO/DIO.h"
#include "../../Library/STD.h"


// Driver Macros

#define BTN_1_PORT			PORT_D
#define BTN_2_PORT			PORT_B
#define BTN_3_PORT			PORT_B
#define BTN_4_PORT			PORT_B

#define BTN_1_PIN			PIN4
#define BTN_2_PIN			PIN2
#define BTN_3_PIN			PIN3
#define BTN_4_PIN			PIN4

#define BTN_1				1
#define BTN_2				2
#define BTN_3				3
#define BTN_4				4


#define BTN_PRESSED				HIGH
#define BTN_NOT_PRESSED			LOW


// Driver Functions Prototypes

void BTN_init  (u8 btnNum);
u8   BTN_read  (u8 btnNum);


#endif /* BUTTON_H_ */
