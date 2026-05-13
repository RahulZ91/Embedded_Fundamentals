/*
 * GPIO_Driver.c
 *
 *  Created on: May 10, 2026
 *      Author: hp
 */

#include "GPIO_Driver.h"
#include "stm32f446xx.h"

void led_init(void)
{
	// Start the clock for GPIO port A
	RCC->AHB1ENR |= (1<<0);

	// GPIO registers updated
	GPIOA->MODER &= ~(0x03 <<10);
	GPIOA->MODER |= (0x01 <<10);

	// GPIO output type, speed
	GPIOA->OTYPER &=~(1<<5); // we need push pull
	GPIOA->OSPEEDR &=~(3<<10);
	GPIOA->OSPEEDR |=(1<<10);

}

void button_EXTI(void)
{
	//Enable clock for SYSCFG
	RCC->APB2ENR |= (1<<14);
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







