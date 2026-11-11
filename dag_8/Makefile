CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = prog.exe
SOURCES = terminalargument.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET) 2 42

clean:
	rm -f $(TARGET) $(OBJECTS) $(wildcard *.o)

.PHONY: run clean
