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

int main(int argc, char *argv[]) {
    long age;

    if (argc != 3) {
        printf("Användning: %s NAMN ÅLDER\n\n", argv[0]);
        return 1;
    }

    if (!parse_long(argv[2], &age)) {
        printf("ÅLDER måste vara ett heltal!\n");
        return 1;
    }

    printf("%s är %ld år.\n\n", argv[1], age);

    return 0;
}
