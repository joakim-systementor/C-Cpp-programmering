#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1U << PB5); // setup

    while (1) { // loop
        PORTB |= (1U << PB5);
        _delay_ms(500);
        PORTB &= ~(1U << PB5);
        _delay_ms(500);
    }
    return 0;
}
