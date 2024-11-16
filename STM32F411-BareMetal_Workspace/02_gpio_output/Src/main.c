#include "stm32f4xx.h"

#define GPIOAEN  (1U<<0)
#define LED_PIN  (1U<<5)

int main(void){

	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	//swt PA5 as output pin
	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);
	while(1){
		GPIOA->ODR ^=(1<<5);
		for(uint32_t i=0;i<1000000; i++);
	}
}
