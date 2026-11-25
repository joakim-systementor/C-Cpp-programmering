#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

#define LED_MASK ((uint8_t)(_BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3)))

/* TODO: Rätta typ och kvalificerare för dessa tre variabler */
volatile uint8_t sensor_address = 0x48U;
int temperature_tenths = -125;
uint8_t sample_ready = 0U;

// Startar en timer 
static void timer_init(void) {
    /* Timer 1 skapar ett avbrott ungefär en gång per sekund */
    TCCR1B = _BV(WGM12) | _BV(CS12) | _BV(CS10);
    OCR1A = 15624U;
    TIMSK1 = _BV(OCIE1A);
}

static int16_t read_temperature_tenths(uint8_t address) {
    static int16_t simulated_temperature = -125;

    (void)address; // Markerar bara att variabeln medvetet inte används - för att undvika varning vid kompilering
    simulated_temperature += 50;

    if (simulated_temperature > 300) {
        simulated_temperature = -125;
    }

    return simulated_temperature;
}

/* TODO: Begränsa funktionens synlighet till den här C-filen */
void update_status_leds(uint8_t pattern) {
    PORTB = (uint8_t)((PORTB & (uint8_t)~LED_MASK)
                      | (pattern & LED_MASK));
}

// Interrupt Service Routine - körs när TIMER1_COMPA_vect genererar ett interrupt
ISR(TIMER1_COMPA_vect) {
    sample_ready = 1U;
}

int main(void) {
    DDRB |= LED_MASK;
    PORTB &= (uint8_t)~LED_MASK;

    timer_init();
    sei(); // Slår igång interrupts

    while (1) {
        if (sample_ready != 0U) {
            sample_ready = 0U;
            temperature_tenths = read_temperature_tenths(sensor_address);

            uint8_t pattern = (uint8_t)((temperature_tenths + 400) / 50);
            update_status_leds(pattern);
        }
    }

    return 0;
}
