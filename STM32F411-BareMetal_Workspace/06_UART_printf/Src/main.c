//UART2
// PA2 - uart2_tx
// PA3 - uart2_rx
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

#define GPIOAEN  (1U<<0)
#define UART2EN  (1U<<17)

#define CR1_TE   (1U<<3)
#define CR1_UE   (1U<<13);

#define SR_TXE   (1U<<7)

#define SYS_FREQ 16000000UL
#define APB1_CLK SYS_FREQ

#define UART_BAUDRATE  115200

void UART2_tx_init(void);
void uart2_write(uint8_t ch);
static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk, uint32_t BaudRate);


int main(void){

	UART2_tx_init();

	while(1){
		printf("hello from stm32..............................\n\r");
	}
}

int __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}

void UART2_tx_init(void){
	/*********************** Configure GPIO pin ***********************/
	//enable clock access to GPIO
	RCC->AHB1ENR |=GPIOAEN;

	//set PA2 node to alternate function mode
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER|=(1U<<5);

	//set PA2 alternate function type to UART_TX (AF07)
	GPIOA->AFR[0] |=(1U<<8);
	GPIOA->AFR[0] |=(1U<<9);
	GPIOA->AFR[0] |=(1U<<10);
	GPIOA->AFR[0] &=~(1U<<11);

	/***********************configureuart module***********************/
	//Enable clock access to UART2
	RCC->APB1ENR |=UART2EN;

	//Configure BaudRate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	//configure the transfer direction
	USART2->CR1 = CR1_TE;

	//Enable the UART Module
	USART2->CR1 = CR1_UE;

}

void uart2_write(uint8_t ch){
	//make sure the Transmit data register is empty
	while(!(USART2->SR & SR_TXE));

	//write to transmit data register
	USART2->DR = (ch & 0xFF);

}


static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk, uint32_t BaudRate){
	USARTx->BRR = (PeriphClk+(BaudRate/2U))/BaudRate;
}

