//User led
// led green PD12
//Alternate function mapping registers
// port   |   AF2
//--------|--------
//PD12    |  TIM4_CH1
//PA6     |  TIM3_CH1

#include "stm32f4xx.h"
#include "tim.h"

int timestamp = 0 ;

int main(void){

	tim4_PD12_output_compare();
	tim3_PA6_input_capture();

	while(1){
		/*Wait until edge is captured*/
		while(!(TIM3->SR & SR_CC1IF)){}

		/*Read captured value*/
		timestamp =  TIM3->CCR1;

	}
}
