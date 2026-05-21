#include "stm32f4xx.h"
#include "GPIO_Driver.h"
#include "Interrupts.h"
#include "PWM_Functions.h"

int main(void)
{
	// Initializing the user button
	PWM_Gpio_init();

	PWM_init();

}
