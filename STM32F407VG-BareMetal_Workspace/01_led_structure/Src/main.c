#include <stdint.h>

#define PERIPH_BASE    (0x40000000UL)
#define AHB1_OFFSET    (0x20000UL)
#define AHB1_BASE      (PERIPH_BASE+AHB1_OFFSET)

#define GPIOD_OFFSET   (0xC00UL)
#define GPIOD_BASE     (AHB1_BASE+GPIOD_OFFSET)

#define RCC_OFFSET     (0x3800UL)
#define RCC_BASE       (AHB1_BASE+RCC_OFFSET)


#define GPIODEN (1<<3)
#define __IO volatile

typedef struct
{
  __IO uint32_t dumy[12];
  __IO uint32_t AHB1ENR;       //!< RCC AHB1 peripheral clock register,
  } RCC_TypeDef;

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

#define RCC ((RCC_TypeDef*)RCC_BASE)
#define GPIOD ((GPIO_TypeDef*)GPIOD_BASE)

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;

	GPIOD->MODER |= (1<<24);
	GPIOD->MODER &= ~(1<<25);

	while(1){
		GPIOD->ODR ^=(1<<12);
		for(uint32_t i=0;i<1000000; i++);

	}
}


