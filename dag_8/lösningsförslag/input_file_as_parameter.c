#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Användning: %s FIL\n\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    char line[100];
    int line_no = 0;

    if (file == NULL) {
        printf("Error! Could not open file \"%s\"!\n\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", ++line_no, line);
    }
    fclose(file);

    printf("\n\n");

    return 0;
}
