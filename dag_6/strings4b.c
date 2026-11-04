#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

// Version där vi vill lagra en int
int main(void) {
    errno = 0;
    char *temp;
    char str[] = "123";
    // char str[] = "111111111111111111111111"; // Out of range
    long val = strtol(str, &temp, 0);
    int value;

    if (temp == str || *temp != '\0' ||
        ((val == LONG_MIN || val == LONG_MAX) && errno == ERANGE)) {
        // Raden under printar bara info till oss nu - inget vi gör i vanliga fall
        printf("temp: %s, val == LONG_MAX? (0/1): %d, errno: %d\n", temp, val == LONG_MAX, errno);
        printf("Could not convert '%s'. String is to long.\n", str);
        return 1;
    }

    if ((val < INT_MIN) || (val > INT_MAX)) {
        printf("Could not convert %ld to integer. Value out or range.\n", val);
        return 1;
    }

    value = (int)val;
    printf("Värdet på strängen \"%s\" är %d\n\n", str, value);

    return 0;
}
