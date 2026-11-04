#include <stdio.h>

int main(void) {
    char str1[] = "Hello";
    char* str2 = "Hej";

    str1[0] = 'h';
    // str2[0] = 'h'; // Det är de thär som menas med att str2 inte får ändras. Ger Segmentation fault.

    printf("%s\n%s\n\n", str1, str2);

    // str1 = str2; // Fungerar ej då str1 är deklarerad som en array
    str2 = str1;
    printf("%s\n%s\n\n", str1, str2);

    return 0;
}
