#include "lcd.h"

int main(void){
	LCD_Init();

	unsigned char buffer[8] = "Hello";
	while(1){
		LCD_command(0x80);
		LCD_data('H');

		LCD_command(0xC0);
		LCD_string(buffer);

		delayMs(1000);
		LCD_command(0x01);

		delayMs(500);

	}
}