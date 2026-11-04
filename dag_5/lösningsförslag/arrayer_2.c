#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int* array;
    int tal, antal;

    printf("Hur många tal vill du mata in? ");
    scanf("%d", &antal);
    getchar();

    array = (int *)malloc(antal * sizeof(int));

    if (array == NULL) {
        printf("Minnesallokeringen misslyckades!");
        return 1;
    }

    for (int i = 0; i < antal; ++i) {
        printf("Mata in ett heltal: ");
        scanf("%d", &tal);
        getchar();
        array[i] = tal;
    }

    tal = array[0];
    for (int i = 1; i < antal; ++i) {
        if (array[i] > tal) {
            tal = array[i];
        }
    }

    printf("Det största talet du matade in var: %d\n\n", tal);

    free(array);
    array = NULL;

    return 0;
}