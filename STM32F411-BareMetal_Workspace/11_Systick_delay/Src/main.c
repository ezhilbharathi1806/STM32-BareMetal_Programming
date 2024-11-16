#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"

#define GPIOAEN   (1U<<0)
#define LED_PIN  (1U<<5)

int main(void){

	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	//swt PA5 as output pin
	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);

	while(1){
		printf("A second passed.............. \n\r");
		GPIOA->ODR ^=(1<<5);
		systickDelayMs(1000);
	}
}
