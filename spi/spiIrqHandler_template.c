#include "stm32f10x.h"
#include "spi.h"

void DMA1_Channel2_IRQHandler(){
	DMA_ClearITPendingBit(DMA1_IT_TC2);
	DMA_Cmd(DMA1_Channel3, DISABLE);
	DMA_Cmd(DMA1_Channel2, DISABLE);

	//TODO: SPI1 x-change finished, add some logic
}

extern volatile uint8_t xchangeDone;

void DMA1_Channel4_IRQHandler(){
	DMA_ClearITPendingBit(DMA1_IT_TC4);
	DMA_Cmd(DMA1_Channel5, DISABLE);
	DMA_Cmd(DMA1_Channel4, DISABLE);

	//TODO: SPI2 x-change finished, add some logic
	//GPIO_SetBits(GPIOB, GPIO_Pin_11);
	xchangeDone = 1;
}
