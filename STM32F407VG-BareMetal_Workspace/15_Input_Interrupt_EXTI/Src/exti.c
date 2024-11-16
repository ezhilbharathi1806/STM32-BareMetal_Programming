#include "exti.h"

#define GPIOAEN         (1U<<0)
#define SYSCFGEN		(1U<<14)

void pa0_exti_init(void){

	/*Disable global interrupts*/
	__disable_irq();

	//enable clock access to GPIOD
	RCC->AHB1ENR |= GPIOAEN;

	//set PA0 as input pin
	GPIOA->MODER &= ~((1U<<1)|(1U<<0));

	//Enable clock access to SYSCFG
	RCC->APB2ENR |=SYSCFGEN;

	//Select PORTA for EXTI0
	//SYSCFG->EXTICR[0] &= ~((1U<<3)|(1U<<2)|(1U<<1)|(1U<<0));

	//unmask EXTI0
	EXTI->IMR |= (1U<<0);

	//Select falling edge trigger
	EXTI->FTSR |= (1U<<0);

	//Enable EXTI0 line in NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);


	//Enabl global interrupt
	__enable_irq();

}
