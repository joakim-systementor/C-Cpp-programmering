#include <stdio.h>
#include <string.h>

void str_test(char*, size_t);

// Typexempel på att när man jobbar med strängar så bör man använda sträng-funktionerna
int main() {
    char text[] = "I am a string!";
    char text30[30] = "I am a string!";

    printf("text: |%s|\ntext30: |%s|\n\n", text, text30);
    
    str_test(text, sizeof(text) / sizeof(text[0]));
    str_test(text30, sizeof(text30) / sizeof(text30[0]));
    return 0;
}

void str_test(char *text, size_t length) {
    int halfway = length / 2;
    int last_index = length - 1;
    size_t str_length = strlen(text);
    int str_halfway = str_length / 2;
    int str_last_index = str_length - 1;

    printf("Length: %zd, halfway: %d, last_index: %d\n", length, halfway, last_index);
    printf("Actual string:\nLength: %zd, halfway: %d, last_index: %d\n\n", str_length, str_halfway, str_last_index);
}
