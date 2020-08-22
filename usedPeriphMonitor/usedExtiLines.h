/*
 * used_exti.h
 *
 *  Created on: 24 лип. 2020 р.
 *      Author: MaxCm
 */

#ifndef USEDEXTILINES_H_
#define USEDEXTILINES_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void initUsedExtiLines();
uint32_t getUsedExtiLines();
void setUsedExtiLines(uint32_t lines);

#ifdef __cplusplus
}
#endif

#endif /* USEDEXTILINES_H_ */
