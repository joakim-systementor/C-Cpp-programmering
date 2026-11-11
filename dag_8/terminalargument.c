#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

bool parse_long(const char *str, long *value) {
    char *end;

    errno = 0;
    long parsed_value = strtol(str, &end, 10);

    if (errno == ERANGE || end == str) {
        return false;
    }

    while (isspace((unsigned char)*end)) {
        end++;
    }

    if (*end != '\0') {
        return false;
    }

    *value = parsed_value;
    return true;
}

// Vi förväntar oss 2 inparametrar
int main(int argc, char *argv[]) {
    long id, värde;

    if (argc != 3) {
        printf("Användning: %s ID VÄRDE\n\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    if (!parse_long(argv[1], &id)) {
        printf("ID måste vara ett heltal!\n");
        return 1;
    }
    if (!parse_long(argv[2], &värde)) {
        printf("VÄRDE måste vara ett heltal!\n");
        return 1;
    }

    printf("%s + %s = %ld\n\n", argv[1], argv[2], id + värde);

    return 0;
}
