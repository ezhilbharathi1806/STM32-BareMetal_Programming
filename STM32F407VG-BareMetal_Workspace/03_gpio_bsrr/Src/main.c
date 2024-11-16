//User led
// led green PD12
//led orange PD13
//led red PD14
//led blue PD15
#include "stm32f4xx.h"

#define GPIODEN  (1U<<3)

// bit Set
#define BS12  (1U<<12)
#define BS13  (1U<<13)
#define BS14  (1U<<14)
#define BS15  (1U<<15)

//Bit Reset
#define BR12  (1U<<28)
#define BR13  (1U<<29)
#define BR14  (1U<<30)
#define BR15  (1U<<31)

int main(void){

	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIODEN;

	//set PD12 as output pin
	GPIOD->MODER |=(1<<24);
	GPIOD->MODER &=~(1<<25);

	//set PD13 as output pin
	GPIOD->MODER |=(1<<26);
	GPIOD->MODER &=~(1<<27);

	//set PD14 as output pin
	GPIOD->MODER |=(1<<28);
	GPIOD->MODER &=~(1<<29);

	//set PD12 as output pin
	GPIOD->MODER |=(1<<30);
	GPIOD->MODER &=~(1<<31);

	while(1){
		//Bit Set user leds on PD12, PD13, PD14, PD15 using BSRR
		GPIOD->BSRR |= BS12|BS13|BS14|BS15;
		for(uint32_t i=0;i<1000000; i++);

		//Bit Reset user leds on PD12, PD13, PD14, PD15 using BSRR
		GPIOD->BSRR |= BR12|BR13|BR14|BR15;
		for(uint32_t i=0;i<1000000; i++);
	}
}

