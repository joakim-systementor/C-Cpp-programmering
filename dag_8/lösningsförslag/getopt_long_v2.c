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
    static const struct option long_options[] = {
        {"upper", no_argument, NULL, 'u'},
        {"help", no_argument, NULL, 'h'},
        {"add", required_argument, NULL, 'a'},
        {NULL, 0, NULL, 0}
    };

    long age;
    long added_years = 0;
    bool upper = false;
    bool add = false;
    int option;
    char name[50];
    char text[100];

    while ((option = getopt_long(argc, argv, "uha:", long_options, NULL)) != -1) {
        if (option == 'u') {
            upper = true;
        }
        else if (option == 'h') {
            printf("Hjälpavsnitt:\n");
            printf("Användning: %s [-h|--help] [-u|--upper] [-a|--add SIFFRA] NAMN ÅLDER\n", argv[0]);
            return 0;
        }
        else if (option == 'a') {
            if (!parse_long(optarg, &added_years)) {
                printf("SIFFRA efter -a eller --add måste vara ett heltal!\n");
                return 1;
            }
            add = true;
        }
        else {
            printf("Ogiltig flagga! Användning: %s [-h|--help] [-u|--upper] [-a|--add SIFFRA] NAMN ÅLDER\n", argv[0]);
            return 1;
        }
    }

    if (argc - optind != 2) {
        printf("Fel antal argument! Användning: %s [-h|--help] [-u|--upper] [-a|--add SIFFRA] NAMN ÅLDER\n", argv[0]);
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

    if (add) {
        written = snprintf(text, sizeof(text), "%s är %ld år gammal om %ld år.\n",
                           name, age + added_years, added_years);
    }
    else {
        written = snprintf(text, sizeof(text), "%s är %ld år.\n", name, age);
    }

    if (written < 0 || (size_t)written >= sizeof(text)) {
        printf("Resultatet fick inte plats i textbufferten!\n");
        return 1;
    }

    printf("%s", text);

    return 0;
}
