#include "adc.h"

uint32_t sensor_value;

int main(void){

	pa1_adc_interrupt_init();
	start_converstion();
	while(1)
	{
	}
}

static void adc_callback(void)
{
	sensor_value = ADC1->DR;
	//printf("Sensor value : %d \n\r",(int)sensor_value);

}
void ADC_IRQHandler(void)
{
	/*Check for eoc in SR*/
	if((ADC1->SR & SR_EOC) !=0)
	{
		/*Clear EOC*/
		ADC1->SR &=~SR_EOC;

		//Do something
		adc_callback();
	}
}
