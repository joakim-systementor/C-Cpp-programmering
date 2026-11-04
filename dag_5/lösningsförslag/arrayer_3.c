#include <stdio.h>

int main(void) {
    int array[5] = {7, 34, 42, 3, 9};

    printf("Arrayen i början: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < 5; ++i) {
        if (array[i] % 2 == 1) {
            array[i] = 0;
        }
    }
    printf("\n");

    printf("Arrayen i slutet: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    return 0;
}