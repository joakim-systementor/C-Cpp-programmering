#include <stdio.h>

int main (void) {
    // SKriv ut när i = 0, 1, 2, 4
    for (int i = 0; i < 50; i++) { // Loopa när i är mellan 0 och 49
        if (i == 3) { // Hoppa över utskriften när i är 3
            continue;
        }
        if (i == 5) { // Hoppa över utskriften och hoppa ur loopen när i är 5
            break;
        }
        printf("i: %d\n", i);
    }
    return 0;
}