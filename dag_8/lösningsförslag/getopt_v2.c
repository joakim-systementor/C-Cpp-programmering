#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>

static bool parse_long(const char *str, long *value)
{
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

int main(int argc, char *argv[])
{
    long age;
    bool upper = false;
    int option;
    char name[50];
    char text[80];

    while ((option = getopt(argc, argv, "uh")) != -1) {
        if (option == 'u') {
            upper = true;
        }
        else if (option == 'h') {
            printf("Hjälpavsnitt:\n");
            printf("Användning: %s [-h] [-u] NAMN ÅLDER\n", argv[0]);
        }
        else {
            printf("Ogiltig flagga! Användning: %s [-h] [-u] NAMN ÅLDER\n", argv[0]);
            return 1;
        }
    }

    if (argc - optind != 2) {
        printf("Fel antal argument! Användning: %s [-h] [-u] NAMN ÅLDER\n", argv[0]);
        return 1;
    }

    if (!parse_long(argv[optind + 1], &age)) {
        printf("ÅLDER måste vara ett heltal!\n");
        return 1;
    }

    int written = snprintf(name, sizeof(name), "%s", argv[optind]);

    if (written < 0 || (size_t)written >= sizeof(name)) {
        printf("NAMN är för långt!\n");
        return 1;
    }

    if (upper) {
        for (int i = 0; name[i] != '\0'; i++) {
            name[i] = (char)toupper((unsigned char)name[i]);
        }
    }

    written = snprintf(text, sizeof(text), "%s är %ld år.\n", name, age);

    if (written < 0 || (size_t)written >= sizeof(text)) {
        printf("Resultatet fick inte plats i textbufferten!\n");
        return 1;
    }

    printf("%s", text);

    return 0;
}
