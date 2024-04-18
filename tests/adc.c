#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/adc.h"

int main(void)
{
	adc_init(); 
    lcd_init();
	while (1) {
        uint16_t temp = adc_measure();
        uint16_t units = temp>>10;
        uint16_t decimal = (temp>>2) & 0b11111111;
        decimal *= 100;
        uint16_t dig1 = 0;
        while(decimal >= 2560) {
            dig1++;
            decimal -= 2550;
        }
        uint16_t dig2 = 0;
        while(decimal >= 256) {
            dig2++;
            decimal -= 255;
        }
        lcd_clear_display();
        lcd_data('0'+units);
        lcd_data('.');
        lcd_data('0'+dig1);
        lcd_data('0'+dig2);
        _delay_ms(1000);
	}
	return 0;
}

