#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC |= 0xFF;
	while (1) {
		PORTC ^= 0xFF;
		_delay_ms(500);
	}
	return 0;
}

