

#ifndef TIM_H_
#define TIM_H_

void tim2_1hz_init(void);
void tim4_PD12_output_compare(void);
void tim3_PA6_input_capture(void);

#define SR_UIF  (1U<<0)
#define SR_CC1IF (1U<<1)

#endif /* TIM_H_ */
