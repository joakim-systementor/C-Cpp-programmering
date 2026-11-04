#include <stdio.h>

int main(void) {
    long long int loooooooong = 42;
    
    printf("Hello World!\n");
    printf("size of int: %d\n", sizeof(int));
    printf("size of short: %d\n", sizeof(short int));
    printf("size of char: %d\n", sizeof(char));
    printf("size of long long int: %d\n", sizeof(loooooooong));
    return 0;
}