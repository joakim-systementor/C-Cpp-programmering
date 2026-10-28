CC = gcc

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Iinclude -Ilib/include
LDFLAGS =
LDLIBS = -lm

TARGET = build/calculator
MATH_LIBRARY = lib/libmathutils.a

SOURCES = src/main.c src/menu.c
OBJECTS = $(patsubst src/%.c,build/%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS) $(MATH_LIBRARY)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(MATH_LIBRARY) $(LDLIBS)

build/%.o: src/%.c include/menu.h lib/include/math_utils.h
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f build/*.o $(TARGET)

.PHONY: all run clean
