#include <stdio.h>

#include "math_utils.h"
#include "menu.h"

void show_menu(void)
{
    int choice;
    double a;
    double b;

    printf("Miniräknare\n");
    printf("1. Addition\n");
    printf("2. Subtraktion\n");
    printf("3. Multiplikation\n");
    printf("4. Division\n");
    printf("5. Potens\n");
    printf("Val: ");

    if (scanf("%d", &choice) != 1) {
        printf("Ogiltigt val.\n");
        return;
    }

    printf("Ange två tal: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Ogiltig inmatning.\n");
        return;
    }

    switch (choice) {
    case 1:
        printf("Resultat: %g\n", add(a, b));
        break;
    case 2:
        printf("Resultat: %g\n", sub(a, b));
        break;
    case 3:
        printf("Resultat: %g\n", mult(a, b));
        break;
    case 4:
        if (b == 0.0) {
            printf("Det går inte att dividera med noll.\n");
        } else {
            printf("Resultat: %g\n", div_numbers(a, b));
        }
        break;
    case 5:
        printf("Resultat: %g\n", power(a, b));
        break;
    default:
        printf("Ogiltigt val.\n");
    }
}
