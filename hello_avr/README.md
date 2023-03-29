## Tool Chain installation on Ubuntu 20.04
```
sudo apt install avr-libc avrdude binutils-avr gcc-avr
```

## Build Commands

```
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
avr-gcc -mmcu=atmega328p led.o -o led
avr-objcopy -O ihex -R .eeprom led led.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex


Object Dump
avr-objdump -d led >led.lst

Copying Exsisting Flash
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:r:flash_backup.hex:i
```
##Links

[Balau's Blog, for build commands](https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/)
[For Makefile](https://www.tderflinger.com/en/arduino-blinking-led-pure-c)

