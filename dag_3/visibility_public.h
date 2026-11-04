#ifndef VISIBILITY_PUBLIC_H_
#define VISIBILITY_PUBLIC_H_

typedef enum {
    FALSKT,
    SANT,
} MY_PUBLIC_BOOL;

extern const int public_value;

void function_public(void);
#endif
