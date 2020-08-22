/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f10x.h"
#include "board.h"
#include "config.h"
#include "spi.h"
#include "i2c.h"
#include "usedPeriphMonitor.h"

#include "LSM6DS3.h"

#define loopIfConfigFails(config) if(Config_Fail == config) while(1);

volatile uint8_t spiBuff[16];
volatile uint8_t xchangeDone;

typedef struct {
	XL_ODR odr;
	XL_FS fullScale;
	XL_BW bandwidth;
} AccelerometerConfig;

void writeData(uint8_t addr, uint8_t * buf, uint8_t size) {
	spiBuff[0] = 0x00 | addr;
	for (uint8_t i = 0; i < size; i++) {
		spiBuff[i+1] = buf[i];
	}
	xchangeDone = 0;
	GPIO_ResetBits(GPIOB, GPIO_Pin_11);
	startSpi2Exchange(size + 1);
	while (!xchangeDone);
	GPIO_SetBits(GPIOB, GPIO_Pin_11);
}

void readData(uint8_t addr, uint8_t * buf, uint8_t size) {
	spiBuff[0] = 0x80 | addr;
	xchangeDone = 0;
	GPIO_ResetBits(GPIOB, GPIO_Pin_11);
	startSpi2Exchange(size + 1);
	while (!xchangeDone);
	GPIO_SetBits(GPIOB, GPIO_Pin_11);
	for (uint8_t i = 0; i < size; i++) {
		buf[i] = spiBuff[i+1];
	}
}

void configSpiForLSM6DS3(){
	GPIO_InitTypeDef pinInitStruct;
	SPIConfig spiConfig;

	if (getUsedPinsInGPIOB() & GPIO_Pin_11) {
		while(1);
	}
	setUsedPinsInGPIOB(GPIO_Pin_11);

	spiConfig.SPI_CPHA = SPI_CPHA_2Edge;
	spiConfig.SPI_CPOL = SPI_CPOL_High;
	spiConfig.SPI_FirstBit = SPI_FirstBit_MSB;
	spiConfig.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
	spiConfig.buffer = (uint8_t *)spiBuff;
	loopIfConfigFails(configSPI2AsMaster(&spiConfig));
	//PB11 - CSN
	pinInitStruct.GPIO_Pin=GPIO_Pin_11;
	pinInitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	pinInitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_SetBits(GPIOB, GPIO_Pin_11);
	GPIO_Init(GPIOB, &pinInitStruct);
}

void configAccelerometer(AccelerometerConfig * config) {
	uint8_t b[1];
	b[0] = config -> odr | config -> fullScale | config -> bandwidth;
}

int main(){
	initUsedPeriphMonitor();
	SystemInit();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	loopIfConfigFails(setHsePinsUsed());
	loopIfConfigFails(setSwdPinsUsed());
	loopIfConfigFails(configLeds());
	loopIfConfigFails(configButtonForPolling());


	/*I2CConfig i2cConfig;
	i2cConfig.I2C_ClockSpeed = 100000;
	i2cConfig.I2C_Ack = I2C_Ack_Enable;
	i2cConfig.I2C_GeneralCallCmd = DISABLE;

	i2cConfig.I2C_OwnAddress = 1;
	loopIfConfigFails(configI2C1(&i2cConfig));
	i2cConfig.I2C_OwnAddress = 2;
	loopIfConfigFails(configI2C2(&i2cConfig));*/

	configSpiForLSM6DS3();
	pullUpUnusedPins();


	/*uint8_t b[10];
	readData(WHO_AM_I, b, 1);*/

	AccelerometerConfig ac;
	ac.odr = A_ODR_13;

	for(;;);
}
