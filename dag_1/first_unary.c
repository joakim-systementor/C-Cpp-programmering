#include <stdio.h>

int main(void) {
    printf("i++\n");
    for (int i = 0; i < 3; i) {
        printf("i: %d\n", i++);
    }

    printf("\n\n++i\n");
    for (int i = 0; i < 3; i) {
        printf("i: %d\n", ++i);
    }
}