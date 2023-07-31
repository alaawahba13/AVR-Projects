/*
 * Motot.h
 *
 * Created: 22-Nov-22 6:51:08 AM
 *  Author: Mahmoud
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_


// Driver Inclusions

#include "../../MCAL/DIO/DIO.h"
#include "../../Library/STD.h"


// Driver Macros

#define MTR1_PORT					PORT_C
#define MTR2_PORT					PORT_B

#define MTR1_PIN_1					PIN0
#define MTR1_PIN_2					PIN1
#define MTR2_PIN_1					PIN3
#define MTR2_PIN_2					PIN4

#define MTR1						1
#define MTR2						2


// Driver Functions Prototypes

void MTR_init    (u8 mtrNum);
void MTR_ON_CW   (u8 mtrNum);
void MTR_ON_CCW  (u8 mtrNum);
void MTR_OFF     (u8 mtrNum);

#endif /* MOTOR_H_ */
