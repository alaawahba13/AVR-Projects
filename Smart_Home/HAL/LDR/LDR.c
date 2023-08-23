/*
 * LDR.c
 *
 *  Created on: 16 Aug 2023
 *      Author: Alaa Wahba
 */

#include "LDR.h"


void LDR_init(){
	ADC_pinConfig_t ADC_pinConfig ={VCC_5, RIGHT, PRESCALAR_64, DISABLE,SINGLE_CONVERSION ,NULL };
	ADC_init(&ADC_pinConfig);

}

uint32 LDR_getLight(){
	uint16 val;
	uint32 light;
	val = ADC_Read(ADC_LDR);
	light = (((uint32) val) * 100) / 1024;
	return light;
}
