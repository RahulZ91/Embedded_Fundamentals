#include "stm32f4xx.h"
#include "Interrupts.h"

int main(void)
{
	// Initializing the user button
	button_init();

	button_EXTI();


}
