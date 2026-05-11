#include "stm32f4xx.h"
#include "GPIO_Driver.h"
#include "Interrupts.h"

int main(void)
{
	button_init();

	button_EXTI();


}
