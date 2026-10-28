CC = gcc
AR = ar

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Iinclude

LIBRARY = lib/libmathutils.a
OBJECTS = build/math_utils.o

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	mkdir -p lib
	$(AR) rcs $@ $^

build/%.o: src/%.c include/math_utils.h
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*.o $(LIBRARY)

.PHONY: all clean
