#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define LED_RED_MASK    ((uint8_t)_BV(PB0))
#define LED_GREEN_MASK  ((uint8_t)_BV(PB1))
#define LED_BLUE_MASK   ((uint8_t)_BV(PB2))
#define LED_YELLOW_MASK ((uint8_t)_BV(PB3))

#define ALL_LEDS_MASK ((uint8_t)(LED_RED_MASK | LED_GREEN_MASK \
                                 | LED_BLUE_MASK | LED_YELLOW_MASK))

static void leds_init(void) {
    /* TODO: Konfigurera de fyra lysdiodernas pinnar som utgångar */
    /* TODO: Börja med alla fyra lysdioder släckta */
}

int main(void) {
    leds_init();

    while (1) {
        PORTB |= LED_RED_MASK;
        _delay_ms(500);

        /* TODO: Tänd grön utan att påverka övriga lysdioder */
        _delay_ms(500);

        /* TODO: Släck röd utan att påverka övriga lysdioder */
        _delay_ms(500);

        /* TODO: Växla blå lysdiod */
        _delay_ms(500);

        /* TODO: Tänd gul lysdiod */
        _delay_ms(500);

        /* TODO: Släck alla fyra lysdioder */
        _delay_ms(500);
    }

    return 0;
}
