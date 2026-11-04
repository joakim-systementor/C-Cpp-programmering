#include <stdio.h>
#include <string.h>

int main(void) {
    const char str[] = "http://www.systementor.se";
    const char ch = '.';
    char *ret;

    ret = strchr(str, ch);

    printf("First occurance of |%c| is found at - |%s|\n", ch, ret);


    return 0;
}