
FILENAME=$1
echo "filename = ${FILENAME}"
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o "${FILENAME}.o" "${FILENAME}.c"
avr-gcc -mmcu=atmega328p "${FILENAME}.o" -o "${FILENAME}"
avr-objcopy -O ihex -R .eeprom "${FILENAME}" "${FILENAME}.hex"

