#include "uart.h"

#define GPIOAEN  (1U<<0)
#define UART2EN  (1U<<17)

#define CR1_TE   (1U<<3)
#define CR1_RE   (1U<<2)
#define CR1_UE   (1U<<13)

#define SR_TXE   (1U<<7)
#define SR_RXNE   (1U<<5)

#define SYS_FREQ 16000000UL
#define APB1_CLK SYS_FREQ

#define UART_BAUDRATE  115200

static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk, uint32_t BaudRate);


int __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}

void uart2_txrx_init(void){
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

	//set PA3 node to alternate function mode
	GPIOA->MODER &=~(1U<<6);
	GPIOA->MODER|=(1U<<7);

	//set PA3 alternate function type to UART_RX (AF07)
	GPIOA->AFR[0] |=(1U<<12);
	GPIOA->AFR[0] |=(1U<<13);
	GPIOA->AFR[0] |=(1U<<14);
	GPIOA->AFR[0] &=~(1U<<15);

	/***********************configureuart module***********************/
	//Enable clock access to UART2
	RCC->APB1ENR |=UART2EN;

	//Configure BaudRate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	//configure the transfer direction/ enable TE and RE in UART2_CR1
	USART2->CR1 = CR1_TE|CR1_RE;

	//Enable the UART Module
	USART2->CR1 = CR1_UE;

}

void uart2_write(uint8_t ch){
	//make sure the Transmit data register is empty
	while(!(USART2->SR & SR_TXE));

	//write to transmit data register
	USART2->DR = (ch & 0xFF);

}

uint8_t uart2_read(void){
	//make sure the receive data register is not empty
	while(!(USART2->SR & SR_RXNE));

	//Read data
	return USART2->DR;
}


static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk, uint32_t BaudRate){
	USARTx->BRR = (PeriphClk+(BaudRate/2U))/BaudRate;
}

