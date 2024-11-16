//User led
// led green PD12
//led orange PD13
//led red PD14
//led blue PD15
#include "stm32f4xx.h"
#include "systick.h"

#define GPIODEN  (1U<<3)

#define LED_PIN_PD12  (1U<<12)
#define LED_PIN_PD13  (1U<<13)
#define LED_PIN_PD14  (1U<<14)
#define LED_PIN_PD15  (1U<<15)

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
		//Toggle user leds on PD12, PD13, PD14, PD15
		GPIOD->ODR ^=(LED_PIN_PD12|LED_PIN_PD13|LED_PIN_PD14|LED_PIN_PD15);

		SystickDelayMs(100);
		//for(uint32_t i=0;i<1000000; i++);
	}
}
