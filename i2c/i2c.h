/*
 * i2c.h
 *
 *  Created on: 24 лип. 2020 р.
 *      Author: MaxCm
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include "stm32f10x.h"
#include "config.h"

typedef struct {
	uint32_t I2C_ClockSpeed;
	uint16_t I2C_Ack;
	uint16_t I2C_OwnAddress;
	FunctionalState	I2C_GeneralCallCmd;
} I2CConfig;

ConfigResult configI2C1(I2CConfig * i2cConfig);
ConfigResult configI2C2(I2CConfig * i2cConfig);

#endif /* I2C_H_ */
