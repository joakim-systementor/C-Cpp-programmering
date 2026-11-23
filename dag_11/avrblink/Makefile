CC = avr-gcc
LD = avr-ld
OBJCOPY = avr-objcopy
OBJISP = avrdude
AVRSIZE = avr-size
PORT ?= COM3 #?= /dev/ttyACM0 # För att kunna flasha måste detta kopplas till den port arduinon är inkopplad till
# På Linux kan man hitta det genom att köra kommandot <sudo dmesg | grep tty>
# På Windows får man nog kolla i device managern/enhetshanteraren, och det ser ut så här för COM3 som ett exempel: PORT = COM3

MCU = atmega328p
F_CPU = 16000000UL

CFLAGS = -Wall -Wextra -Wundef -pedantic \
		-Os -std=c11 -DF_CPU=$(F_CPU) -mmcu=$(MCU)
LDFLAGS = -mmcu=$(MCU) -Wl,--gc-sections

BIN = program.hex
SOURCES = main.c
OBJS = $(SOURCES:.c=.o)

all: $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -MD -MP -c -o $@ $<

%.elf: $(OBJS)
	$(CC) -Wl,-Map=$(@:.elf=.map) $(LDFLAGS) -o $@ $^
	$(AVRSIZE) $@

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Med detta kan man använda avrdude till att flasha vår hex-fil till en inkopplad arduino uno
isp: ${BIN}
	$(OBJISP) -F -V -c arduino -p ${MCU} -P ${PORT} -U flash:w:$<

clean:
	@rm -f $(BIN) $(BIN:.hex=.elf) $(OBJS) *.map *.P *.d

.PHONY: all isp clean
