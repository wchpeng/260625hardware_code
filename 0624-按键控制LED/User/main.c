#include <stm32f10x.h>
#include <Delay.h>
#include "LED.h"
#include "Key.h"

int main(void)
{
	LED_init();
	KEY_init();
	
	while(1)
	{
		uint8_t num = KEY_GetNum();
		if(num == 1)
		{
			LED1_Turn();
		}
		else if(num == 2)
		{
			LED2_Turn();
		}
	}
}
