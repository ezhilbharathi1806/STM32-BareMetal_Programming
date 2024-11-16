// led green PD12
#include <stdint.h>

#define PERIPH_BASE    (0x40000000UL)
#define AHB1_OFFSET    (0x20000UL)
#define AHB1_BASE      (PERIPH_BASE+AHB1_OFFSET)

#define GPIOD_OFFSET   (0xC00UL)
#define GPIOD_BASE     (AHB1_BASE+GPIOD_OFFSET)

#define RCC_OFFSET     (0x3800UL)
#define RCC_BASE       (AHB1_BASE+RCC_OFFSET)

#define RCC_AHB1EN_R_OFFSET  (0x30UL)
#define RCC_AHB1EN_R         (*(volatile uint32_t *)(RCC_BASE+RCC_AHB1EN_R_OFFSET))

#define MODE_R_OFFSET        (0x00UL)
#define GPIOD_MODE_R         (*(volatile uint32_t *)(GPIOD_BASE+MODE_R_OFFSET))

#define OD_R_OFFSET          (0x14UL)
#define GPIOD_OD_R           (*(volatile uint32_t *)(GPIOD_BASE+OD_R_OFFSET))

#define GPIODEN (1U<<3)

int main(void)
{
	RCC_AHB1EN_R |= GPIODEN;

	GPIOD_MODE_R |= (1<<24);
	GPIOD_MODE_R &= ~(1<<25);

	while(1){
		GPIOD_OD_R ^=(1<<12);
		for(uint32_t i=0;i<1000000; i++);

	}
}

