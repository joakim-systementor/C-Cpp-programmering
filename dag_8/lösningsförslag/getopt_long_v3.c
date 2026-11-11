#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include <string.h>

static bool parse_long(const char *str, long *value) {
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

static void print_usage(const char *program_name) {
    printf("Användning med argument:\n");
    printf("  %s [-h|--help] [-u|--upper] [-a|--add SIFFRA] NAMN ÅLDER\n",
           program_name);
    printf("Användning med fil:\n");
    printf("  %s [-h|--help] [-u|--upper] [-a|--add SIFFRA] [-f|--file FILNAMN]\n",
           program_name);
    printf("  Filen ska innehålla NAMN ÅLDER på varje rad.\n");
}

static bool print_person(char *name, long age, bool upper,
                         bool add, long added_years) {
    if (upper) {
        for (size_t i = 0; name[i] != '\0'; i++) {
            name[i] = (char)toupper((unsigned char)name[i]);
        }
    }

    char text[100];
    int written;

    if (add) {
        written = snprintf(text, sizeof(text), "%s är %ld år gammal om %ld år.\n",
                           name, age + added_years, added_years);
    }
    else {
        written = snprintf(text, sizeof(text), "%s är %ld år.\n", name, age);
    }

    if (written < 0 || (size_t)written >= sizeof(text)) {
        printf("Resultatet fick inte plats i textbufferten!\n");
        return false;
    }

    printf("%s", text);
    return true;
}

static bool read_people_from_file(const char *filename, bool upper,
                                  bool add, long added_years) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Kunde inte öppna filen %s\n", filename);
        return false;
    }

    char line[150];
    size_t line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char name[50];
        long age;
        char extra;
        line_number++;

        if (strchr(line, '\n') == NULL && !feof(file)) {
            printf("Rad %zu i filen är för lång!\n", line_number);
            fclose(file);
            return false;
        }

        int fields = sscanf(line, " %49s %ld %c", name, &age, &extra);

        if (fields != 2) {
            printf("Fel format på rad %zu i filen %s\n", line_number, filename);
            printf("Varje rad ska innehålla NAMN ÅLDER\n");
            fclose(file);
            return false;
        }

        if (!print_person(name, age, upper, add, added_years)) {
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

int main(int argc, char *argv[]) {
    static const struct option long_options[] = {
        {"upper", no_argument, NULL, 'u'},
        {"help", no_argument, NULL, 'h'},
        {"add", required_argument, NULL, 'a'},
        {"file", required_argument, NULL, 'f'},
        {NULL, 0, NULL, 0}
    };

    long age;
    long added_years = 0;
    bool upper = false;
    bool add = false;
    const char *filename = NULL;
    int option;
    char name[50];

    while ((option = getopt_long(argc, argv, "uha:f:", long_options, NULL)) != -1) {
        if (option == 'u') {
            upper = true;
        }
        else if (option == 'h') {
            printf("Hjälpavsnitt:\n");
            print_usage(argv[0]);
            return 0;
        }
        else if (option == 'a') {
            if (!parse_long(optarg, &added_years)) {
                printf("SIFFRA efter -a eller --add måste vara ett heltal!\n");
                return 1;
            }
            add = true;
        }
        else if (option == 'f') {
            filename = optarg;
        }
        else {
            printf("Ogiltig flagga!\n");
            print_usage(argv[0]);
            return 1;
        }
    }

    if (filename != NULL) {
        if (argc - optind != 0) {
            printf("Ange inte NAMN och ÅLDER när -f eller --file används!\n");
            print_usage(argv[0]);
            return 1;
        }

        if (!read_people_from_file(filename, upper, add, added_years)) {
            return 1;
        }

        return 0;
    }
    else {
        if (argc - optind != 2) {
            printf("Fel antal argument!\n");
            print_usage(argv[0]);
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
    }

    if (!print_person(name, age, upper, add, added_years)) {
        return 1;
    }

    return 0;
}
