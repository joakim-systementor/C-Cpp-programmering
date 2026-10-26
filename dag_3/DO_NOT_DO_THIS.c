#include <stdio.h>

// Här är ett exempel på varför vi INTE ska använda globala variabler

int i = 0;

void loop(void) {
    int value, i;

    for (int i = 0; i < 5; i++) {
        value = i;
        // här körs allt
    }
}

int main(void) {
    int värde;
    värde = i;
    loop();
    return 0;
}