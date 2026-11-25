#include <stdio.h>
#include <stdint.h>

uint8_t PORTB = 0;
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

int main (void) {
    // Sätt bit 4 till 1 i PORTB
    PORTB |= (1U << PB4); // 0001 0000 = 16

    printf("Bit 4 satt: %u\n", (unsigned)PORTB);

    // Sätt bit 0 och 3 till 1 i PORTB
    PORTB |= ((1U << PB0) | (1U << PB3)); // 0001 1001 = 25

    printf("Bit 4, 3, och 0 satta: %u\n", (unsigned)PORTB);

    // Nollställ bit 0 i PORTB
    PORTB &= ~(1U << PB0); // 0001 1000 = 24

    printf("Bit 4 och 3 satta: %u\n", (unsigned)PORTB);

    return 0;
}