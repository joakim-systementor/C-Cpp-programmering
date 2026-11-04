#include <stdio.h>

int main (void) {
    int array[4], tal;

    for (int i = 0; i < 4; ++i) {
        printf("Mata in ett heltal: ");
        scanf("%d", &tal);
        getchar();
        array[i] = tal;
    }

    tal = array[0];
    for (int i = 1; i < 4; ++i) {
        if (array[i] > tal) {
            tal = array[i];
        }
    }

    printf("Det största talet du matade in var: %d\n\n", tal);

    return 0;
}