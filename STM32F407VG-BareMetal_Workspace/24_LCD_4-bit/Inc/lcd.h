//D0-D7 -> PA0-PA3
//RS -> PA4
//RW -> PA5
//E -> PA6

#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx.h"

void GPIO_Init(void);
void LCD_command(unsigned char command);
void LCD_data(char data);
void LCD_Init(void);
void LCD_string(unsigned char *s);

void delayMs(int delay);

#endif /* LCD_H_ */
