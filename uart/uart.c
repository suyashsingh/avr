/*
 * Transmit data over uart in polling mode
 */

#include <avr/io.h>
#include <util/delay.h>

#define TX_DELAY 1000

/*
 * Initialize uart
 *  - diable uart power down
 *  - set baud to 9600
 *  - set data width, parity, stop bits
 *  - enable transmitter
 */
void uart_init()
{
	// disable uart power down
	PRR |= (1 << PRUSART0);

	// set baud to 9600, UBRR = 0x68
	UBRR0H = (unsigned char) (0x68 >> 8);
	UBRR0L = (unsigned char) 0x68;

	// 8 bit data width 
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
	
	// enable transmitter
	UCSR0B = (1 << TXEN0);

}

/*
 * Transmit a character in polling mode
 */
void tx_char(char c)
{
	while( !(UCSR0A & (1 << UDRE0)) )
		;

	UDR0 = c;
}

int main()
{
	uart_init();

	while(1) {
		tx_char('a');
		_delay_ms(TX_DELAY);
	}

	return 0;
}
