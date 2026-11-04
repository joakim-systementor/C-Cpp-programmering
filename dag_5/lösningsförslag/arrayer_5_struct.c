#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float value;
    int timestamp;
} Measurement;

int main (void) {
    Measurement* measurements;
    float mätvärde, min, max, medel;
    int antal, timestamp;

    printf("Hur många mätvärden vill du mata in? ");
    scanf("%d", &antal);
    getchar();

    measurements = (Measurement *)malloc(antal * sizeof(Measurement));

    if (measurements == NULL) {
        printf("Minnesallokeringen misslyckades!");
        return 1;
    }

    for (int i = 0; i < antal; ++i) {
        printf("Mata in ett mätvärde: ");
        scanf("%f", &mätvärde);
        getchar();
        printf("Mata in ett datum: ");
        scanf("%d", &timestamp);
        getchar();
        measurements[i].value = mätvärde;
        measurements[i].timestamp = timestamp;
    }

    medel = min = max = measurements[0].value;
    for (int i = 1; i < antal; ++i) {
        medel += measurements[i].value;
        if (measurements[i].value > max) {
            max = measurements[i].value;
        }
        if (measurements[i].value < min) {
            min = measurements[i].value;
        }
    }
    medel /= antal;

    printf("\nArrayen: {\n");
    for (int i = 0; i < antal; ++i) {
        printf("Mätvärde: %.2f, Datum: %d\n", measurements[i].value, measurements[i].timestamp);
    }
    printf("}\n");
    printf("Min: %.2f, Max: %.2f, Medel: %.2f\n\n", min, max, medel);

    free(measurements);
    measurements = NULL;

    return 0;
}