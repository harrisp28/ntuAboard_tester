#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= 0xFF;
	while (1) {
		PORTD ^= 0xFF;
		_delay_ms(500);
	}
	return 0;
}

