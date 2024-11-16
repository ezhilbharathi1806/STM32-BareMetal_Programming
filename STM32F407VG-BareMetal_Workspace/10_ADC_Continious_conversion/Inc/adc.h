

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "stm32f4xx.h"

void pa1_adc_init(void);
uint32_t adc_read(void);
void start_converstion(void);

#endif /* ADC_H_ */
