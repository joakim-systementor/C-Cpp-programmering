#include <stdio.h>

int main (void) {
    // Skriv ut när i är udda
    for (int i = 0; i < 50; i++) {
        if (i % 2 == 0) { // När i är jämnt, continue - dvs hoppa över utskriften
            continue;
        }
        printf("i: %d\n", i);
    }
    return 0;
}