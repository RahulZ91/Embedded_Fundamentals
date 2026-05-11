/*
 * GPIO_Driver.c
 *
 *  Created on: May 10, 2026
 *      Author: hp
 */

#include "GPIO_Driver.h"
#include "stm32f446xx.h"

void button_init(void)
{
	// Start the clock for GPIO port C
	RCC->AHB1ENR |= 1<<2;

	// GPIO registers updated
	GPIOC->MODER &= ~(3 << 26);

	// GPIO PuPd - none
	GPIOC->PUPDR &= ~(3 << 26);
}

void button_EXTI(void)
{
	//Enable clock for SYSCFG
	RCC->AHB2ENR |= (1<<14);
	// Since the button is at Port C pin 13 - the extr is register 3
	SYSCFG->EXTICR[3] &= ~(0xF << 4);   // clear selection
	SYSCFG->EXTICR[3] |=  (0x2 << 4);   // PC = 0010

	// Interrupt for line 13 is unmasked ie is recognised
	EXTI->IMR |= (1 << 13);

	// enable for falling edge
	EXTI->FTSR |= (1<<13);

	//Enable NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);

}







