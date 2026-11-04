#include <stdio.h>
#include <string.h>

int main(void) {
    const char haystack[20] = "StefanHolmberg";
    const char needle[10] = "Holm";
    char *ret;

    ret = strstr(haystack, needle);

    if (ret == NULL) {
        printf("FINNS INTE\n");
    }
    else {
        printf("Vi hittade needlen: %s\n", ret);
    }

    return 0;
}