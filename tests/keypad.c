#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/keypad.h"
#include "../lib/lcd.h"

int main(void)
{   
    keypad_init(); 
    lcd_init(); 
    while(1) {
        char c = keypad_to_ascii_pressed();
        if (c != 0) {
            lcd_clear_display();
            lcd_data(c);
        } 
    }
	return 0;
}

