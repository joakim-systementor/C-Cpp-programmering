#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "C programming";
    char str2[20];

    // copying part of str1 to str2
    strncpy(str2, str1, 5);
    str2[5] = '\0';

    printf("%s\n\n", str2); // C pro

    // copying str1 to str2
    strncpy(str2, str1, 20);

    printf("%s\n\n", str2); // C programming

    return 0;
}
