
#include "stm32f407xx.h"

#define TIM2EN  (1U<<0)
#define CR1_CEN (1U<<0)

void tim2_1hz_init(){
	//Enable clock access to tim2
	RCC->APB1ENR |= TIM2EN;

	//Set prescalar
	TIM2->PSC = 1600-2;  //16 000 000 / 1 600 = 10 000

	//set suto reload value
	TIM2->ARR =10000-1;   // 10 000 / 10 000 = 1

	//clear counter
	TIM2->CNT = 0;

	//Enable timer
	TIM2->CR1 |= CR1_CEN;
}
