#include "stm32f103x6.h"

#define LED_PIN 0  // LED connected to PA0

void delay(volatile uint32_t count) {
    while (count--) {
        // Simple delay loop
    }
}

int main(){
	//enable clock access to GPIOA
	RCC->APB2ENR |= (1U<<2);  //IOPAEN

	//set pa0 pin as output pin 2MHz
	GPIOA->CRL &=~(1<<0);
	GPIOA->CRL |=(1<<1) ; //mode0 =10

	while(1){
		GPIOA->ODR ^=(1<<0);
		delay(100000);
	}
	return 0;
}
