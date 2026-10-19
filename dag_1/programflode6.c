#include <stdio.h>

int main (void) {
    int A = 20;
    int B = 30;
    printf("A");
    if (((A > 10) && (A < 21)) || ((A > 25) && (B < 50))) {
        printf("B");
    }
    printf("C\n");
    return 0;
}
