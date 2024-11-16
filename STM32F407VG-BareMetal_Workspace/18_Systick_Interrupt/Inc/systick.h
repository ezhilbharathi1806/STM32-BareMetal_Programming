
#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

void SystickDelayMs(uint32_t);
void systick_1hz_interrupt(void);

#endif /* SYSTICK_H_ */
