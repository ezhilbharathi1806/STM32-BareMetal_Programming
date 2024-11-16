
#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

void UART2_tx_init(void);
void uart2_write(uint8_t ch);
void USART2_SendString(const char *str);

void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);

#endif /* UART_H_ */
