/*
 * i2c.c
 *
 *  Created on: 24 лип. 2020 р.
 *      Author: MaxCm
 */
#include "stm32f10x.h"
#include "i2c.h"
#include "usedPeriphMonitor.h"

//PB6 - SCL, PB7 - SDA
ConfigResult configI2C1(I2CConfig * i2cConfig){
	//I2C_GenerateSTART()
		//I2C_GenerateSTOP()
		//I2C_CheckEvent()

	GPIO_InitTypeDef pinInitStruct;
	I2C_InitTypeDef i2cInitStruct;
	NVIC_InitTypeDef nvicInitStruct;

	if(getUsedPinsInGPIOB() & (GPIO_Pin_6 | GPIO_Pin_7)) {
		return Config_Fail;
	}
	setUsedPinsInGPIOB(GPIO_Pin_6 | GPIO_Pin_7);

	//config I2C
	i2cInitStruct.I2C_Mode = I2C_Mode_I2C;
	i2cInitStruct.I2C_ClockSpeed = i2cConfig->I2C_ClockSpeed;
	i2cInitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
	i2cInitStruct.I2C_Ack = i2cConfig->I2C_Ack;
	i2cInitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	i2cInitStruct.I2C_OwnAddress1 = i2cConfig->I2C_OwnAddress;
	I2C_Init(I2C1, &i2cInitStruct);
	I2C_GeneralCallCmd(I2C1, i2cConfig->I2C_GeneralCallCmd);
	I2C_ITConfig(I2C1, (I2C_IT_EVT | I2C_IT_ERR | I2C_IT_BUF), ENABLE);
	//config interrupts
	//for events
	nvicInitStruct.NVIC_IRQChannel = I2C1_EV_IRQn;
	nvicInitStruct.NVIC_IRQChannelCmd = ENABLE;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = IrqPrio_I2C1;
	nvicInitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&nvicInitStruct);
	//for errors
	nvicInitStruct.NVIC_IRQChannel = I2C1_ER_IRQn;
	nvicInitStruct.NVIC_IRQChannelCmd = ENABLE;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = IrqPrio_I2C1;
	nvicInitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&nvicInitStruct);

	//general call
	//config pins
	//PB6 - SCL, PB7 - SDA
	pinInitStruct.GPIO_Pin=GPIO_Pin_6 | GPIO_Pin_7;
	pinInitStruct.GPIO_Speed=GPIO_Speed_2MHz;
	pinInitStruct.GPIO_Mode=GPIO_Mode_AF_OD;
	GPIO_Init(GPIOB, &pinInitStruct);

	I2C_Cmd(I2C1, ENABLE);
	return Config_OK;
}

//PB10 - SCL, PB11 - SDA
ConfigResult configI2C2(I2CConfig * i2cConfig){
	//I2C_GenerateSTART()
		//I2C_GenerateSTOP()
		//I2C_CheckEvent()

	GPIO_InitTypeDef pinInitStruct;
	I2C_InitTypeDef i2cInitStruct;
	NVIC_InitTypeDef nvicInitStruct;

	if(getUsedPinsInGPIOB() & (GPIO_Pin_10 | GPIO_Pin_11)) {
		return Config_Fail;
	}
	setUsedPinsInGPIOB(GPIO_Pin_10 | GPIO_Pin_11);

	//config I2C
	i2cInitStruct.I2C_Mode = I2C_Mode_I2C;
	i2cInitStruct.I2C_ClockSpeed = i2cConfig->I2C_ClockSpeed;
	i2cInitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
	i2cInitStruct.I2C_Ack = i2cConfig->I2C_Ack;
	i2cInitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	i2cInitStruct.I2C_OwnAddress1 = i2cConfig->I2C_OwnAddress;
	I2C_Init(I2C2, &i2cInitStruct);
	I2C_GeneralCallCmd(I2C2, i2cConfig->I2C_GeneralCallCmd);
	I2C_ITConfig(I2C2, (I2C_IT_EVT | I2C_IT_ERR | I2C_IT_BUF), ENABLE);
	//config interrupts
	//for events
	nvicInitStruct.NVIC_IRQChannel = I2C2_EV_IRQn;
	nvicInitStruct.NVIC_IRQChannelCmd = ENABLE;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = IrqPrio_I2C2;
	nvicInitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&nvicInitStruct);
	//for errors
	nvicInitStruct.NVIC_IRQChannel = I2C2_ER_IRQn;
	nvicInitStruct.NVIC_IRQChannelCmd = ENABLE;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = IrqPrio_I2C2;
	nvicInitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&nvicInitStruct);

	//general call
	//config pins
	//PB10 - SCL, PB11 - SDA
	pinInitStruct.GPIO_Pin=GPIO_Pin_10 | GPIO_Pin_11;
	pinInitStruct.GPIO_Speed=GPIO_Speed_2MHz;
	pinInitStruct.GPIO_Mode=GPIO_Mode_AF_OD;
	GPIO_Init(GPIOB, &pinInitStruct);

	I2C_Cmd(I2C2, ENABLE);
	return Config_OK;
}


