#include <stdio.h>

int main (void) {
    printf("Innan loopen\n");

    int i = 0;
    while (1) {
        printf("Loop start, i: %d\n", i);
        if (i++ == 4) {
            continue;
        }
        if (i == 10) {
            break;
        }
        printf("i: %d\n", i);
    }
    return 0;
}
