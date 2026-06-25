#include <stm32f10x.h>
#include <Delay.h>


int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	while(1)
	{
		// GPIO_Write 与 GPIO_SetBits 的区别是write可以一次控制16个引脚状态，
		// SetBits只能通过|运算符写多个为高点位
		GPIO_Write(GPIOA, ~0x0001);  // A0
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0002);  // A1
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0004);  // A2
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0008);  // A3
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0010);  // A4
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0020);  // A5
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0040);  // A6
		Delay_ms(100);
	}
}


/*
// 方法二比较笨
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_TypeStruct0;
	GPIO_InitTypeDef GPIO_TypeStruct1;
	GPIO_InitTypeDef GPIO_TypeStruct2;
	GPIO_InitTypeDef GPIO_TypeStruct3;
	GPIO_InitTypeDef GPIO_TypeStruct4;
	GPIO_InitTypeDef GPIO_TypeStruct5;
	GPIO_InitTypeDef GPIO_TypeStruct6;
	GPIO_InitTypeDef GPIO_TypeStruct7;
	
	GPIO_TypeStruct0.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_TypeStruct1.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TypeStruct2.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TypeStruct3.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TypeStruct4.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TypeStruct5.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TypeStruct6.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TypeStruct7.GPIO_Mode = GPIO_Mode_Out_PP;
		
	GPIO_TypeStruct0.GPIO_Pin = GPIO_Pin_0;
	GPIO_TypeStruct1.GPIO_Pin = GPIO_Pin_1;
	GPIO_TypeStruct2.GPIO_Pin = GPIO_Pin_2;
	GPIO_TypeStruct3.GPIO_Pin = GPIO_Pin_3;
	GPIO_TypeStruct4.GPIO_Pin = GPIO_Pin_4;
	GPIO_TypeStruct5.GPIO_Pin = GPIO_Pin_5;
	GPIO_TypeStruct6.GPIO_Pin = GPIO_Pin_6;
	GPIO_TypeStruct7.GPIO_Pin = GPIO_Pin_7;
	
	GPIO_TypeStruct0.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeStruct1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeStruct2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeStruct3.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeStruct4.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeStruct5.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeStruct6.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_TypeStruct7.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_TypeStruct0);
	GPIO_Init(GPIOA, &GPIO_TypeStruct1);
	GPIO_Init(GPIOA, &GPIO_TypeStruct2);
	GPIO_Init(GPIOA, &GPIO_TypeStruct3);
	GPIO_Init(GPIOA, &GPIO_TypeStruct4);
	GPIO_Init(GPIOA, &GPIO_TypeStruct5);
	GPIO_Init(GPIOA, &GPIO_TypeStruct6);
	GPIO_Init(GPIOA, &GPIO_TypeStruct7);
	
	// GPIO_SetBits(GPIOA, GPIO_Pin_0);  // 高电平
	// GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);  // 高电平
	// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	
	// 这种方式有点问题：
	// GPIO_Init 时，默认是低电平，所以这种写法会在第一圈时所有等都是亮的
	// 要想默认都关闭，需要：
	GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |
						GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
						
	while(1)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
		Delay_ms(200);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
	}
}
*/
