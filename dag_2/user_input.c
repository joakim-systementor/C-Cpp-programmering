#include <stdio.h>
int main (void) {
    char user_input[100];

    while (1) {
        printf("Mata in namn, avsluta med '#': ");
        scanf("%s", &user_input);
        if (user_input[0] == '#') {
            printf("Hej då!\n");
            break;
        }
        printf("Hej %s!\n\n", &user_input);
    }

    return 0;
}