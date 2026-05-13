/*
 * Interrupts.c
 *
 *  Created on: May 10, 2026
 *      Author: hp
 */

#include "Interrupts.h"
#include "stm32f446xx.h"

void EXTI15_10_IRQHandler(void)
{
	// Clear the set flag
	if(EXTI->PR & (1<<13))
	{
		EXTI->PR |= (1<<13);
	}

	// Toggle LED
	USR_LED_Init();
	USR_LED_Toggle();


}

void USR_LED_Init(void)
{
	// clock enable
	RCC->AHB1ENR |= (1<<0);

	//Setup
	GPIOA->MODER |=(0x01<<10);
	GPIOA->OTYPER &= ~(1<<5);

}

void USR_LED_Toggle(void)
{
	// Toggle
	GPIOA->ODR ^=(1<<5);
}

void TIM2_IRQHandler(void)
{
	//check the UID bit
	if(TIM2->SR & (1<<0))
	{
		USR_LED_Toggle();
	}

	TIM2->SR &=~(1<<0);
}
