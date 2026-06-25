#include "stm32f10x.h"                  // Device header
#include "Delay.h"


void KEY_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_10 | GPIO_Pin_11);
}
  
uint8_t KEY_GetNum(void)
{
	uint8_t num = 0;
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0)
	{
		Delay_ms(20);
		
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0);
		
		Delay_ms(20);
		num = 1;
	}
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
		
		Delay_ms(20);
		num = 2;
	}
	
	return num;
}
