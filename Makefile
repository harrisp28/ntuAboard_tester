MCU = atmega328pb
F_CPU = 16000000UL

CC = avr-gcc
LD = avr-ld
OBJCOPY = avr-objcopy

PACK_FOLDER=../pack

CFLAGS = -Wall -Wextra -B$(PACK_FOLDER)/gcc/dev/atmega328pb -I$(PACK_FOLDER)/include -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wl,--gc-sections -Os -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -gdwarf-3 -DLCD_PCA9555
LDFLAGS = -B$(PACK_FOLDER)/gcc/dev/atmega328pb -mmcu=$(MCU)

MAIN = main

SRC = $(MAIN).c ./lib/usart.c ./lib/esp8266.c ./lib/lcd.c  ./lib/twi_pca9555.c ./lib/keypad.c ./lib/onewire.c ./lib/adc.c ./lib/thermometer.c


all: $(MAIN)

$(MAIN): $(SRC:.c=.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(MAIN).hex: $(MAIN)
	avr-objcopy -O ihex $(MAIN) $(MAIN).hex

install: $(MAIN).hex
	avrdude -p m328pb -c xplainedmini -U flash:w:$(MAIN).hex

clean:
	rm -f $(MAIN) $(MAIN).hex $(MAIN).o ./lib/usart.o ./lib/esp8266.o ./lib/lcd.o  ./lib/twi_pca9555.o ./lib/therometer.o ./lib/keypad.o ./lib/onewire.o ./lib/adc.o ./lib/thermometer.o

.PHONY: all install clean
