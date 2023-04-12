#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define BLINK_DELAY_MS 100
#define DIR_IN	0
#define DIR_OUT	1
#define OP_LOW	0
#define OP_HIGH	1

void set_pin_direction(char *port, uint8_t pin, uint8_t dir)
{
	if (0 == strcmp(port , "PORTB")){
		(dir) ? (DDRB |= (1 << pin)) : (DDRB &= ~(1<<pin));

	} else if (0 == strcmp(port, "PORTC")) {
		(dir) ? (DDRC |= (1 << pin)) : (DDRC &= ~(1<<pin));

	} else if (0 == strcmp(port, "PORTD")) {
		(dir) ? (DDRD |= (1 << pin)) : (DDRD &= ~(1<<pin));

	}
}

void set_pin_value(char *port, uint8_t pin, uint8_t val)
{
	if (0 == strcmp(port , "PORTB")){
		(val) ? (PORTB |= (1 << pin)) : (PORTB &= ~(1<<pin));

	} else if (0 == strcmp(port, "PORTC")) {
		(val) ? (PORTC |= (1 << pin)) : (PORTC &= ~(1<<pin));

	} else if (0 == strcmp(port, "PORTD")) {
		(val) ? (PORTD |= (1 << pin)) : (PORTD &= ~(1<<pin));

	}
}

int main (void)
{
	/* set pin 5 of PORTB for output*/
	set_pin_direction("PORTB", 5, DIR_OUT);
	
	for(;;) {
		set_pin_value("PORTB", 5, OP_HIGH);
		_delay_ms(BLINK_DELAY_MS);
		set_pin_value("PORTB", 5, OP_LOW);
		_delay_ms(BLINK_DELAY_MS);
	}
}

