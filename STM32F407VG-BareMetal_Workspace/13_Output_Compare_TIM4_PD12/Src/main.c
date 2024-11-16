//User led
// led green PD12
//Alternate function mapping registers
// port   |   AF2
//--------|--------
//PD12    |  TIM4_CH1

#include "tim.h"


int main(void){

	tim4_PD12_output_compare();

	while(1){


	}
}
