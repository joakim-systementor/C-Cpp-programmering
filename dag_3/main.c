#include <stdio.h>
#include "math_utils.h"
//#include "incr.h"

int main(void) {
    int value = 10;
    printf("value: %d\n", value);

    value = my_double(value);
    printf("value: %d\n", value);

    value = add12(value);
    printf("value: %d\n", value);

    //increment(&value);
    //printf("value: %d\n", value);

    return 0;
}
