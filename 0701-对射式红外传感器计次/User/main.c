#include <stm32f10x.h>
#include <Delay.h>
#include "OLED.h"
#include "CounterSensor.h"

int main(void)
{
	OLED_Init();
	CounterSensorInit();
	
	OLED_ShowString(1, 3, "HelloWorld!");
	
	while(1)
	{
		OLED_ShowNum(2, 1, GetCounterSensorCount(), 5);
	}
}
