#include <stdio.h>

int main (void) {
    for (int i = 0; i < 5; i++) { // Loopa när i är mellan 0 och 4
        if (i == 3) { // När i är 3, continue - dvs hoppa över utskriften
            continue;
        }
        printf("i: %d\n", i);
    }
    return 0;
}