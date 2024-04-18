#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/thermometer.h"
#include "../lib/lcd.h"

char buffer[10]; 

int main(void)
{   
    lcd_init(); 
     while(1) {
        lcd_clear_display(); 
        uint16_t temp = get_temperature(); 
        if (temp == 0x8000) {
            lcd_data('N');
            lcd_data('O');
            lcd_data(' ');
            lcd_data('D');
            lcd_data('E');
            lcd_data('V');
            lcd_data('I');
            lcd_data('C');
            lcd_data('E');
        } else {
            char buffer[10];
            temp_to_char(buffer);
            int i = 0; 
            while(buffer[i] != '.') { 
                lcd_data(buffer[i]);
                ++i; 
            }
            // now we have to print the '.' and 3 decimal digits
            lcd_data(buffer[i]); 
            lcd_data(buffer[i+1]);
            lcd_data(buffer[i+2]); 
            lcd_data(buffer[i+3]);  
        }
        
        _delay_ms(3000); // wait 3 sec until next measurement
    }
}

