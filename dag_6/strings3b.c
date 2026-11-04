#include <stdio.h>
#include <string.h>

int main() {
    int const size = 20;
    char str1[50] = "C programming är den bästa programmeringen!"; // Orsakar odefinierat beteende innan vi lägger in '\0'
    char str2[size];

    // copying part of str1 to str2
    strncpy(str2, str1, 5);
    str2[5] = '\0';

    printf("%s\n\n", str2); // C pro

    // copying str1 to str2
    strcpy(str2, str1);
    str2[size - 1] = '\0';

    printf("%s\n\n", str2); // C programming är de

    return 0;
}
