#ifndef GPIO_H
#define GPIO_H

/* gpio pin numbers for all ports */
typedef enum gpio_pin {
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5 = 5,
    PIN6,
    PIN7 /* not available for PORTC, DDRC & PINC */
} gpio_pin_t;

typedef enum pin_direction {
    PIN_INPUT = 0,
    PIN_OUTPUT,
    PIN_TRISATE
} pin_direction_t;

typedef enum pin_value {
    PIN_LOW = 0,
    PIN_HIGH
} pin_value_t;

typedef enum pin_config {
    PIN_GPIO_FUNC = 0,  /* gpio functionality */
    PIN_FUNC1           /* add more */
} pin_config_t;

/* gpio port addresses */
#define ADDR_PORTD      0x0B /* 0x2B */
#define ADDR_DDRD       0x0A /* 0x2A */
#define ADDR_PIND       0x09 /* 0x29 */

#define ADDR_PORTC      0x08 /* 0x28 */
#define ADDR_DDRC       0x07 /* 0x27 */
#define ADDR_PINC       0x06 /* 0x26 */

#define ADDR_PORTB      0x05 /* 0x25 */
#define ADDR_DDRB       0x04 /* 0x24 */
#define ADDR_PINB       0x03 /* 0x23 */

/* gpio api */
/* add checks for PIN7 for port c */
extern void get_pin_direction(uint8_t port, gpio_pin_t pin);
extern void set_pin_direction(uint8_t port, gpio_pin_t pin);

extern void set_pin_value(uint8_t port, gpio_pin_t pin);
extern void get_pin_value(uint8_t port, gpio_pin_t pin);

extern void get_pin_config(uint8_t port, gpio_pin_t pin);
extern void set_pin_config(uint8_t port, gpio_pin_t pin);

#endif /* GPIO_H */
