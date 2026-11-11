CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = prog.exe
INPUT_PARAMETERS = --upper Joakim 39
SOURCES = getopt_long_v1.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET) $(INPUT_PARAMETERS)

clean:
	rm -f $(TARGET) $(OBJECTS) $(wildcard *.o)

.PHONY: run clean
