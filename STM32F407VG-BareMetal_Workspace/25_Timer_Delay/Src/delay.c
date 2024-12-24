// herer we are using Timer2 to generate ms and us delays

#include "stm32f407xx.h"
#include <stdint.h>

#define TIM2EN		(1UL<<0)

void ms_delay(uint32_t delay){
	//Exable clock access to
	RCC->APB1ENR |= TIM2EN;

	//set prescalar value  // Prescaler: (System clock / Timer frequency) - 1.
	TIM2->PSC = 16000-1;  // 16Mhz/16000 = 1Khz (1 ms tick)

	//set Auto-Reload value
	TIM2->ARR = 1 ; //1ms tick to generate 1ms delay

	//clear counter
	TIM2->CNT = 0;

	//Enable timer
	TIM2->CR1 |= TIM_CR1_CEN;

	for(uint32_t i=0; i<delay; i++){
		while(!(TIM2->SR & TIM_SR_UIF));  // Wait until the update interrupt flag is set
		TIM2->SR &= ~TIM_SR_UIF;          // Clear the UIF flag
	}

	// Disable the timer
	TIM2->CR1 &= ~TIM_CR1_CEN;

}
void us_delay(uint32_t delay){
	//Exable clock access to
	RCC->APB1ENR |= TIM2EN;

	//set prescalar value  // Prescaler: (System clock / Timer frequency) - 1.
	TIM2->PSC = 16-1;  // 16Mhz/16 = 1Mhz (1us tick)

	//set Auto-Reload value
	TIM2->ARR = 1 ; //1us tick to generate 1us delay

	//clear counter
	TIM2->CNT = 0;

	//Enable timer
	TIM2->CR1 |= TIM_CR1_CEN;

	for(uint32_t i=0; i<delay; i++){
		while(!(TIM2->SR & TIM_SR_UIF));  // Wait until the update interrupt flag is set
		TIM2->SR &= ~TIM_SR_UIF;          // Clear the UIF flag
	}

	// Disable the timer
	TIM2->CR1 &= ~TIM_CR1_CEN;

}
