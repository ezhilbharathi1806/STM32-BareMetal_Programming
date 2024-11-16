#include <stdint.h>

#define PERIPH_BASE    (0x40000000UL)
#define AHB1_OFFSET    (0x20000UL)
#define AHB1_BASE      (PERIPH_BASE+AHB1_OFFSET)

#define GPIOA_OFFSET   (0x00UL)
#define GPIOA_BASE     (AHB1_BASE+GPIOA_OFFSET)

#define RCC_OFFSET     (0x3800UL)
#define RCC_BASE       (AHB1_BASE+RCC_OFFSET)

#define RCC_AHB1EN_R_OFFSET  (0x30UL)
#define RCC_AHB1EN_R         (*(volatile uint32_t *)(RCC_BASE+RCC_AHB1EN_R_OFFSET))

#define MODE_R_OFFSET        (0x00UL)
#define GPIOA_MODE_R         (*(volatile uint32_t *)(GPIOA_BASE+MODE_R_OFFSET))

#define OD_R_OFFSET          (0x14UL)
#define GPIOA_OD_R           (*(volatile uint32_t *)(GPIOA_BASE+OD_R_OFFSET))

#define GPIOAEN (1<<0)

int main(void)
{
	RCC_AHB1EN_R |= GPIOAEN;

	GPIOA_MODE_R |= (1<<10);
	GPIOA_MODE_R &= ~(1<<11);

	while(1){
		GPIOA_OD_R ^=(1<<5);
		for(uint32_t i=0;i<1000000; i++);

	}
}

