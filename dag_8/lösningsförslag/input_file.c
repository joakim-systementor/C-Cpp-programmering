#include <stdio.h>

int main(void) {
    FILE *file = fopen("namn.txt", "r");
    char line[100];
    int line_no = 0;

    if (file == NULL) {
        printf("Error! Could not open file \"namn.txt\"!");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", ++line_no, line);
    }
    fclose(file);

    printf("\n");

    return 0;
}
