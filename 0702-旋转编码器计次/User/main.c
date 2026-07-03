#include <stm32f10x.h>
#include <Delay.h>
#include "OLED.h"
#include "Encoder.h"

int16_t NUM;

int main(void)
{
	OLED_Init();
	EncoderInit();
	
	OLED_ShowString(1, 1, "NUM:");
	
	while(1)
	{
		NUM += EncoderDiff_Get();
		OLED_ShowSignedNum(1, 5, NUM, 5);
	}
}
