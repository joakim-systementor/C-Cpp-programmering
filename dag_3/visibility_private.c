#include <stdio.h>
#include "visibility_private.h"

typedef enum {
    FALSKT,
    SANT,
} MY_PRIVATE_BOOL;

const int not_actually_private_value = -42;
static const int private_value = -1;

void function_private(void) {
    MY_PRIVATE_BOOL my_bool = SANT;
    if (my_bool == SANT) {
        printf("Hej från function_private()! Mitt value är: %d\n", private_value);
    }
}
