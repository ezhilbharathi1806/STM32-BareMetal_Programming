//D0-D7 -> PA0-PA3
//RS -> PA4
//RW -> PA5
//E -> PA6

#include "lcd.h"

#define GPIOAEN	(1U<<0)

#define  RS		(1U<<4)
#define RW		(1U<<5)
#define E		(1U<<6)

void GPIO_Init(void){
	//enable clock access to PortA
	RCC->AHB1ENR |= GPIOAEN;

	//set output mode to PA0 to PA10 pins
	//PA0
	GPIOA->MODER |= (1U<<0);
	GPIOA->MODER &= (1U<<1);
	//PA1
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER &= (1U<<3);
	//PA2
	GPIOA->MODER |= (1U<<4);
	GPIOA->MODER &= (1U<<5);
	//PA3
	GPIOA->MODER |= (1U<<6);
	GPIOA->MODER &= (1U<<7);
	//PA4
	GPIOA->MODER |= (1U<<8);
	GPIOA->MODER &= (1U<<9);
	//PA5
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= (1U<<11);
	//PA6
	GPIOA->MODER |= (1U<<12);
	GPIOA->MODER &= (1U<<13);
	//PA7
	GPIOA->MODER |= (1U<<14);
	GPIOA->MODER &= (1U<<15);
	//PA8
	GPIOA->MODER |= (1U<<16);
	GPIOA->MODER &= (1U<<17);
	//PA9
	GPIOA->MODER |= (1U<<18);
	GPIOA->MODER &= (1U<<19);
	//PA10
	GPIOA->MODER |= (1U<<20);
	GPIOA->MODER &= (1U<<21);

}
void LCD_command(unsigned char command){
	//upper nibble
	GPIOA->ODR = (command>>4) & 0x0F;
	GPIOA->ODR &= ~RS;	//RS =0
	GPIOA->ODR &= ~RW;	//RW =0
	GPIOA->ODR |= E;	//E = 1
	delayMs(1);
	GPIOA->ODR &= ~E;	//E = 0

	//lower nibble
	GPIOA->ODR = (command & 0x0F);
	GPIOA->ODR &= ~RS;	//RS =0
	GPIOA->ODR &= ~RW;	//RW =0
	GPIOA->ODR |= E;	//E = 1
	delayMs(1);
	GPIOA->ODR &= ~E;	//E = 0

}
void LCD_data(char data){
	//upper nibble
	GPIOA->ODR = (data>>4) & 0x0F;
	GPIOA->ODR |= RS;	//RS =1
	GPIOA->ODR &= ~RW;	//RW =0
	GPIOA->ODR |= E;	//E = 1
	delayMs(1);
	GPIOA->ODR &= ~E;	//E = 0

	//lower nibble
	GPIOA->ODR = (data & 0x0F);
	GPIOA->ODR |= RS;	//RS =1
	GPIOA->ODR &= ~RW;	//RW =0
	GPIOA->ODR |= E;	//E = 1
	delayMs(1);
	GPIOA->ODR &= ~E;	//E = 0
}

void LCD_Init(void) {
    GPIO_Init();

    delayMs(30);
    LCD_command(0x30);
    delayMs(10);
    LCD_command(0x30);
    delayMs(1);
    LCD_command(0x30);

    LCD_command(0x28);      //set 4-bit data, 2-line, 5x7 font
    LCD_command(0x06);      //move cursor right after each char
    LCD_command(0x01);      //clear screen, move cursor to home
    LCD_command(0x0F);      //turn on display, cursor blinking
}

void LCD_string(unsigned char *s){
	while(*s!=0){
		LCD_data(*s++);
	}
}
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int delay) {
    int i;
    for (; delay > 0; delay--){
        for (i = 0; i < 3195; i++)
				{}
			}
}

