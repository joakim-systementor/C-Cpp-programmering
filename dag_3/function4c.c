#include <stdio.h>

void addera(int* c) {
    *c = *c + 12;
    printf("%d\n", *c);
}

int main(void) {
    int c = 11;

    printf("%d\n", c);
    addera(&c);
    printf("%d\n", c);
    return 0;
}
