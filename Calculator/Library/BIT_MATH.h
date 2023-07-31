/*
 * BIT_MATH.h
 *
 *  Created on: Nov 7, 2022
 *      Author: Mahmoud
 */

#ifndef LIBRARY_BIT_MATH_H_
#define LIBRARY_BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)

#endif /* LIBRARY_BIT_MATH_H_ */
