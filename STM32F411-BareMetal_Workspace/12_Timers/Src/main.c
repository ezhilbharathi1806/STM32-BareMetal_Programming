#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

#define GPIOAEN   (1U<<0)
#define LED_PIN  (1U<<5)

int main(void){

	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	//swt PA5 as output pin
	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);

	uart2_txrx_init();
	tim2_1hz_init();

	while(1){
		//wait for UIF
		while(!(TIM2->SR & SR_UIF)){}

		// clear UIF
		TIM2->SR &= ~SR_UIF;

		printf("A second passed.............. \n\r");
		GPIOA->ODR ^=(1<<5);
		systickDelayMs(1000);
	}
}
