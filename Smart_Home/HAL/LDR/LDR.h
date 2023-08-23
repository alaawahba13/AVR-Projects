/*
 * LDR.h
 *
 *  Created on: 16 Aug 2023
 *      Author: Alaa Wahba
 */

#ifndef LDR_LDR_H_
#define LDR_LDR_H_

#include "../../Atmega32/inc/ADC.h"

#define ADC_LDR 			ADC0


void LDR_init();
uint32 LDR_getLight();


#endif /* LM35_LM35_H_ */
