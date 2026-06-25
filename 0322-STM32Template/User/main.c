#include <stm32f10x.h>


int main(void)
{
	/*
	// 直接操作寄存器
	RCC->APB2ENR = 0x00000010;
	GPIOC->CRH = 0x00300000;
	// GPIOC->ODR = 0x00002000;
	GPIOC->ODR = 0x00000000;
	*/
	
	// 使用标准库
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // 通用推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	// GPIO_SetBits(GPIOC, GPIO_Pin_13);  // 设置高电平(灭灯)
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);  // 设置低电平（亮灯）
	
	while(1)
	{
		
	}
}
