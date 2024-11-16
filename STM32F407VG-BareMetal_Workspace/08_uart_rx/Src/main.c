//UART2
// PA2 - uart2_tx
// PA3 - uart2_rx

#include "uart.h"

#define GPIODEN  (1U<<3)

#define LED_PIN_PD12  (1U<<12)

uint8_t key;

int main(void){

	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIODEN;

	//set PD12 as output pin
	GPIOD->MODER |=(1<<24);
	GPIOD->MODER &=~(1<<25);

	UART2_txrx_init();
	USART2_SendString("Hello\n");
	uart2_write('Y');
	printf("Hello from STM32F4........\n\r");

	while(1){

		key =  uart2_read();
		if(key == '1')
		{
			GPIOD->ODR |= LED_PIN_PD12;
		}
		else{
			GPIOD->ODR &= ~LED_PIN_PD12;
		}
	}
}



