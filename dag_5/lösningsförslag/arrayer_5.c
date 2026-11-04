#include <stdio.h>
#include <stdlib.h>

int main (void) {
    float* measurements;
    int* timestamps;
    float mätvärde, min, max, medel;
    int antal, timestamp;

    printf("Hur många mätvärden vill du mata in? ");
    scanf("%d", &antal);
    getchar();

    measurements = (float *)malloc(antal * sizeof(float));

    if (measurements == NULL) {
        printf("Minnesallokeringen misslyckades!");
        return 1;
    }

    timestamps = (int *)malloc(antal * sizeof(int));

    if (timestamps == NULL) {
        printf("Minnesallokeringen misslyckades!");
        return 1;
    }

    for (int i = 0; i < antal; ++i) {
        printf("Mata in ett mätvärde: ");
        scanf("%f", &mätvärde);
        getchar();
        measurements[i] = mätvärde;
        printf("Mata in ett datum: ");
        scanf("%d", &timestamp);
        getchar();
        timestamps[i] = timestamp;
    }

    medel = min = max = measurements[0];
    for (int i = 1; i < antal; ++i) {
        medel += measurements[i];
        if (measurements[i] > max) {
            max = measurements[i];
        }
        if (measurements[i] < min) {
            min = measurements[i];
        }
    }
    medel /= antal;

    printf("\nArrayen: {\n");
    for (int i = 0; i < antal; ++i) {
        printf("Mätvärde: %.2f, Datum: %d\n", measurements[i], timestamps[i]);
    }
    printf("}\n");
    printf("Min: %.2f, Max: %.2f, Medel: %.2f\n\n", min, max, medel);

    free(measurements);
    measurements = NULL;
    free(timestamps);
    timestamps = NULL;

    return 0;
}