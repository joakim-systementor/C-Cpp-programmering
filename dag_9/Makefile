CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = prog.exe
SOURCES = palindrome_v3.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS) $(wildcard *.o)

.PHONY: run clean
