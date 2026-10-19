#include <stdio.h>

int main (void) {
    printf("A");
    if ((2 < 3) && (3 < 4)) {
        printf("B");
    }
    else if ((2 < 3) && ((3 < 4) || (4 < 3))) {
        printf("C");
    }
    else {
        printf("D");
    }
    printf("E\n");
    return 0;
}
