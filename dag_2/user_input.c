#include <stdio.h>
#include <windows.h> // Denna + SetConsole-readerna är ETT av sätten att få svenska tecken i terminalen för windows

int main (void) {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
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