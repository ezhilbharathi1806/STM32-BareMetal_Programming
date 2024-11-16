// user led PA5
//user Push-Button PC13

#include "stm32f4xx.h"

#define GPIOAEN  (1U<<0)
#define GPIOCEN  (1U<<2)
#define LED_PIN  (1U<<5)
#define BTN_PIN  (1<<13)

int main(void){

	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	// led = output mode
	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);

	//push-button = input-mode
	GPIOC->MODER &= ~((1<<26)|(1<<27));
	while(1){
		if(GPIOC->IDR &(1<<13)){
			GPIOA->ODR |=LED_PIN;
		}

		else{
			GPIOA->ODR &=~LED_PIN;
		}
	}
}
