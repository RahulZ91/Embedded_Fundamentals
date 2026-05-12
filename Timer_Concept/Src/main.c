#include "stm32f4xx.h"
#include "GPIO_Driver.h"
#include "Interrupts.h"

int main(void)
{
	// Initializing the user button
	//button_init();

	button_EXTI();


}
