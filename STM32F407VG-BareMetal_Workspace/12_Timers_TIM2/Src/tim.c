
#include "stm32f407xx.h"

#define TIM2EN  (1U<<0)
#define CR1_CEN (1U<<0)

void tim2_1hz_init(){
	//Enable clock access to tim2
	RCC->APB1ENR |= TIM2EN;

	//Set prescalar
	TIM2->PSC = 16000-1;  //16 000 000 / 1 6000 = 1 000 =1Khz ( 1ms tick)

	//set suto reload value
	TIM2->ARR =1000-1;   // 1000 ticks to generate 1 second delay

	//clear counter
	TIM2->CNT = 0;

	//Enable timer
	TIM2->CR1 |= CR1_CEN;
}
