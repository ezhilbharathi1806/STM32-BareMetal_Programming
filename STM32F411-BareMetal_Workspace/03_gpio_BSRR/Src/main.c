#include "stm32f4xx.h"

#define GPIOAEN  (1U<<0)
#define LED_PIN  (1U<<5)

int main(void){

	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);
	while(1){
		GPIOA->BSRR = LED_PIN;  // bit set BS5=1
		for(uint32_t i=0;i<1000000; i++);

		GPIOA->BSRR = (1<<21);  // Bit-Reset BR21=1
		for(uint32_t i=0;i<1000000; i++);
	}
}
