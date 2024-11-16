//UART2
// PA2 - uart2_tx
// PA3 - uart2_rx
#include <adc.h>
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

#define GPIOAEN  (1U<<0)
#define LED_PIN  (1U<<5)

uint8_t key;
int main(void){

	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	//swt PA5 as output pin
	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);

	uart2_txrx_init();

	while(1){
		key = uart2_read();
		if(key=='1'){
			GPIOA->ODR |=LED_PIN;
		}
		else{
			GPIOA->ODR &=~LED_PIN;
		}

	}
}
