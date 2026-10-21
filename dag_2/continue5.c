#include <stdio.h>

int main (void) {
    // Skriv ut när i är jämnt
    for (int i = 0; i < 50; i++) {
        if (i % 2 == 1) { // Om i är udda, continue - dvs hoppa över utskriften
            continue;
        }
        printf("i: %d\n", i);
    }
    return 0;
}