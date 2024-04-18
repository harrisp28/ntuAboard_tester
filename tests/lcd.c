#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/lcd.h"

uint8_t msg[] = {' ', ' ', 'H', 'E', 'L', 'L', 'O', 
                ' ', 'W', 'O', 'R', 'L', 'D', '!', ' ', ' ', }; 

int main(void)
{
    lcd_init();
    while(1) {
        int i; 
        for (i = 0; i < 16; ++i)
            lcd_data(msg[i]);
        _delay_ms(2000);
        lcd_clear_display();
        lcd_goto_line2();
        
        for (i = 0; i < 16; ++i)
            lcd_data(msg[i]);
        _delay_ms(2000);
        lcd_clear_display();
        lcd_goto_line1();
    }
    
	return 0;
}

