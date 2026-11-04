#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char str[] = "123";
    int val = 0;
    
    if (isdigit(str[0])) {
        val = atol(str);
    }
    else {
        printf("Could not convert %s. String does not start with a digit!\n\n", str);
        return 1;
    }

    printf("Värdet på strängen \"%s\" är %d\n\n", str, val);

    return 0;
}
