#include <stdint.h>
#include <stdio.h>

static void print_binary8(uint8_t value) {
    for (int bit = 7; bit >= 0; bit--) {
        unsigned int mask = 1U << bit;
        putchar((value & mask) != 0U ? '1' : '0');

        if (bit == 4) {
            putchar(' ');
        }
    }
}

static void print_value(const char *label, uint8_t value) {
    printf("%-10s ", label);
    print_binary8(value);
    printf("  0x%02X  %3u\n", (unsigned int)value, (unsigned int)value);
}

int main(void) {
    uint8_t a = 0x35U;
    uint8_t b = 0x0FU;

    print_value("a", a);
    print_value("b", b);
    print_value("a & b", (uint8_t)(a & b));
    print_value("a | b", (uint8_t)(a | b));
    print_value("a ^ b", (uint8_t)(a ^ b));
    print_value("~a", (uint8_t)~a);
    print_value("a << 1", (uint8_t)(a << 1));
    print_value("a >> 2", (uint8_t)(a >> 2));

    return 0;
}
