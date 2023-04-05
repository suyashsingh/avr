## Tool Chain installation on Ubuntu 20.04
```
sudo apt install avr-libc avrdude binutils-avr gcc-avr
```

## Build Commands

```
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
avr-gcc -mmcu=atmega328p led.o -o led
avr-objcopy -O ihex -R .eeprom led led.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 57600 -U flash:w:led.hex


Object Dump
avr-objdump -d led >led.lst

Copying Exsisting Flash
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 57600 -U flash:r:flash_backup.hex:i
```

## Flashing Log
```
casper@casper:~/avr/hello_avr$ avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 57600 -U flash:r:flash_backup.hex:i

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e950f (probably m328p)
avrdude: reading flash memory:

Reading | ################################################## | 100% 7.71s

avrdude: writing output file "flash_backup.hex"

avrdude: safemode: Fuses OK (E:00, H:00, L:00)

avrdude done.  Thank you.

casper@casper:~/avr/hello_avr$
```
## Links
[Balau's Blog, for build commands] (https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/)
[For Makefile] (https://www.tderflinger.com/en/arduino-blinking-led-pure-c)

