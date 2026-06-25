#include <stm32f10x.h>
#include <Delay.h>


int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_TypeStruct;
	GPIO_TypeStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TypeStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_TypeStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_TypeStruct);
	
	// GPIO_SetBits(GPIOA, GPIO_Pin_0);  // 高电平
	// GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);  // 高电平
	// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	
	while(1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		Delay_ms(200);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		Delay_ms(200);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(200);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(200);
	}
}
