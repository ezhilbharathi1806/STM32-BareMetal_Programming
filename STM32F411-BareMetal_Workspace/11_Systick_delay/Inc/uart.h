#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"

void uart2_txrx_init(void);
uint8_t uart2_read(void);
void uart2_write(uint8_t ch);

#endif
