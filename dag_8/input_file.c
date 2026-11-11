#include <stdio.h>

int main(void) {
    FILE *file = fopen("../dag_6/strings1.c", "r");
    char line[100];

    if (file == NULL) {
        printf("Kunde inte öppna filen test.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);

    return 0;
}
