CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = calculator.exe
SOURCES = main.c math_utils.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: run clean
