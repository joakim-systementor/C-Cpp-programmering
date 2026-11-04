#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int main(void) {
    errno = 0;
    char *temp;
    char str[] = "123";
    // char str[] = "111111111111111111111111111111111111111111111111111111111111111"; // Out of range
    long val = strtol(str, &temp, 0);

    if (temp == str || *temp != '\0' ||
        ((val == LONG_MIN || val == LONG_MAX) && errno == ERANGE)) {
        // Raden under printar bara info till oss nu - inget vi gör i vanliga fall
        printf("temp: %s, val == LONG_MAX? (0/1): %d, errno: %d\n", temp, val == LONG_MAX, errno);
        printf("Could not convert '%s'. String is to long.\n", str);
        return 1;
    }

    printf("Värdet på strängen \"%s\" är %ld\n\n", str, val);

    return 0;
}
