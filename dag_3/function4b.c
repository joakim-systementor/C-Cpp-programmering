#include <stdio.h>

int addera(int c) {
    c = c + 12;
    printf("%d\n", c);
    return c;
}

int main(void) {
    int c = 11, res;

    printf("%d\n", c);
    res = addera(c);
    printf("%d\n", res);
    return 0;
}
