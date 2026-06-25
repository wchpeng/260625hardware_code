#include <stm32f10x.h>
#include <Delay.h>
#include "BUZZER.h"
#include "LIGHT.h"

int main(void)
{
	BUZZER_Init();
	LIGHT_Init();
	
	while(1)
	{
		if(LIGHT_GetNum() == 1)
		{
			BUZZER_ON();
		}
		else 
		{
			BUZZER_OFF();
		}
	}
}
