
#include "stm32f407xx.h"

#define TIM2EN  (1U<<0)
#define TIM3EN  (1U<<1)
#define TIM4EN	(1U<<2)
#define CR1_CEN (1U<<0)

#define OC1M_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)
#define CCMR1_CC1S  (1U<<0)

#define GPIODEN  (1U<<3)
#define GPIOAEN  (1U<<0)

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

void tim4_PD12_output_compare(void){
	//GPIOD Configuration
	//Enable clock access to GPIOD
	RCC->AHB1ENR |=GPIODEN;

	//Set PD12 mode to alternate function mode
	GPIOD->MODER &= ~(1<<24);
	GPIOD->MODER |= (1<<25);

	//Set PD12 alternate function type to TIM4_CH1 (AF2)
	GPIOD->AFR[1] |= (1U<<17);

	//configure TIM4
	//enable clock access to TIM4
	RCC->APB1ENR |= TIM4EN;

	/*Set prescaler value*/
	TIM4->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM4->ARR =  10000 - 1;  // 10 000 / 10 000 = 1

	//set output compare toggle mode
	TIM4->CCMR1 |= OC1M_TOGGLE;

	//enable TIM4_CH1 in compare mode
	TIM4->CCER |= CCER_CC1E;

	//Clear counter
	TIM4->CNT = 0;

	//Enable Timer 4
	TIM4->CR1 |= CR1_CEN;
}


void tim3_PA6_input_capture(void)
{

	 /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;

	/*Set PA6 mode to alternate function*/
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |=(1U<<13);

	/*Set PA6 alternate function type to TIM3_CH1 (AF02)*/
	GPIOA->AFR[0]|=(1U<<25);

	/*Enable clock access to tim3*/
	RCC->APB1ENR |=TIM3EN;

	/*Set Prescaler*/
	TIM3->PSC = 1600 -1; // 16 000 000 /16 000

	/*Set CH1 to input capture*/
	TIM3->CCMR1  = CCMR1_CC1S;

	/*Set CH1 to capture at rising edge*/
	TIM3->CCER  = CCER_CC1E;

	/*Enable TIM3*/
	TIM3->CR1 = CR1_CEN;


}

