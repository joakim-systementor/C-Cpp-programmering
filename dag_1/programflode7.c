#include <stdio.h>

int main (void) {
    char val = 'c';
    
    switch (val) {
        case 'a':
            printf("A");
            break;
        case 'b':
            printf("B");
            break;
        case 'c':
            printf("C");
            break;
        case 'd':
            printf("D");
            break;
        default:
            printf("No match found.\n");
    }
    
    return 0;
}
