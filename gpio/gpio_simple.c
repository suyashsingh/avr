#include <avr/io.h>
#include <util/delay.h>

/*
 * Onboard led on PB5: Port B Pin 5
 */
int main()
{
	// set DDR
	DDRB |= (1 << 5);

	while(1)
	{
		// set high
		PORTB |= (1 << 5);
		_delay_ms(1000);
		PORTB &= ~(1 << 5);
		_delay_ms(1000);
	}

	return 0;
}
