#include <stdio.h>
#include "visibility_public.h"
#include "visibility_private.h"

extern const int not_actually_private_value;
extern const int private_value;

int main(void) {
    function_public();
    function_private();
    MY_PUBLIC_BOOL my_pub_bool_main = SANT;
    // MY_PRIVATE_BOOL my_priv_bool_main = SANT; // Ger kompileringsfel eftersom structs och enums blir privata även utan static när de ligger i c-fil

    if (my_pub_bool_main == SANT) {
        printf("Public value?: %d\n", public_value);
    }
    printf("Private value?: %d\n\n", not_actually_private_value);
    // printf("Private value?: %d\n\n", private_value); // Ger länkningsfel eftersom private_value har intern linkage genom static

    return 0;
}
