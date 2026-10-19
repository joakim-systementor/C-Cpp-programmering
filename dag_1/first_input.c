#include <stdio.h>

int main (void) {
    char name[20];
    printf("Vad heter du? ");
    scanf("%s", &name);
    printf("Hejsan %s\n", name);
    return 0;
}
