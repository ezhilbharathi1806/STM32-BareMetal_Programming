//User led
// led green PD12
//led orange PD13
//led red PD14
//led blue PD15

// User Pushbutton PA0
#include "stm32f4xx.h"
#include "exti.h"

#define GPIODEN  (1U<<3)

#define LED_PIN_PD12  (1U<<12)
#define LED_PIN_PD13  (1U<<13)
#define LED_PIN_PD14  (1U<<14)
#define LED_PIN_PD15  (1U<<15)

#define PushButton_PA0  (1U<<0)

static void exti_callback(void);
void EXTI0_IRQHandler(void);

int main(void){

	//enable clock access to GPIOD
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

	pa0_exti_init();

	while(1){

	}
}

static void exti_callback(void){
	//printf("BTN Pressed...\n\r");
	GPIOD->ODR ^=(LED_PIN_PD12|LED_PIN_PD13|LED_PIN_PD14|LED_PIN_PD15);
}

void EXTI0_IRQHandler(void){
	if((EXTI->PR & LINE0)!=0){
		/*Clear PR flag*/
		EXTI->PR |=LINE0;
		//Do something...
		exti_callback();
	}

}
