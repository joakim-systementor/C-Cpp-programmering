#include <stdio.h>
#include <stdlib.h>

int main (void) {
    float* array;
    float tal, min, max, medel;
    int antal;

    printf("Hur många mätvärden vill du mata in? ");
    scanf("%d", &antal);
    getchar();

    array = (float *)malloc(antal * sizeof(float));

    if (array == NULL) {
        printf("Minnesallokeringen misslyckades!");
        return 1;
    }

    for (int i = 0; i < antal; ++i) {
        printf("Mata in ett mätvärde: ");
        scanf("%f", &tal);
        getchar();
        array[i] = tal;
    }

    medel = min = max = array[0];
    for (int i = 1; i < antal; ++i) {
        medel += array[i];
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    medel /= antal;

    printf("Arrayen: { ");
    for (int i = 0; i < antal; ++i) {
        printf("%.2f ", array[i]);
    }
    printf("}\n");
    printf("Min: %.2f, Max: %.2f, Medel: %.2f\n\n", min, max, medel);

    free(array);
    array = NULL;

    return 0;
}