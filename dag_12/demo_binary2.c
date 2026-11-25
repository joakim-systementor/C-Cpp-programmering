#include <stdio.h>
#include <stdint.h>

uint8_t PORTB = 0;
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

int main (void) {
    // Sätt bit 4

    printf("Bit 4 satt: %u\n", (unsigned)PORTB);

    // Sätt bit 0 och 3

    printf("Bit 4, 3, och 0 satta: %u\n", (unsigned)PORTB);
    
    // Nollställ bit 0

    printf("Bit 4 och 3 satta: %u\n", (unsigned)PORTB);

    return 0;
}