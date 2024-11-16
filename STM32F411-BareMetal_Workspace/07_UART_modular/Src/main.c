//UART2
// PA2 - uart2_tx
// PA3 - uart2_rx
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"


int main(void){

	UART2_tx_init();

	while(1){
		printf("hello from stm32..............................\n\r");
	}
}
