#include <stdio.h>
#include "visibility_public.h"

const int public_value = 42;

void function_public(void) {
    printf("Hej från function_public()! Mitt value är: %d\n", public_value);
}
