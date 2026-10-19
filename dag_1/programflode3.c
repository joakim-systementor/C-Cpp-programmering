#include <stdio.h>

int main (void) {
    printf("A");
    if (4 < 3) {
        printf("B");
    }
    else if (2 < 3) {
        printf("C");
    }
    else if (2 < 3) {
        printf("D");
    }
    else {
        printf("E");
    }
    printf("F\n");
    return 0;
}
