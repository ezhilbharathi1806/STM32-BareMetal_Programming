//UART2
// PA2 - uart2_tx
// PA3 - uart2_rx

#include "uart.h"

int main(void){

	UART2_tx_init();
	USART2_SendString("Hello\n");

	while(1){
		uart2_write('Y');
		printf("Hello from STM32F4........\n\r");
	}
}



