#include <stdio.h>

int main(){
    char result[100];

    int age = 50;
    float pi = 3.1415927;
    char name[] = "Stefan";

    sprintf(result, "Hej %s du är %d år och pi är ungefär %.2f", name, age, pi);

    printf("%s\n", result);

    return 0;
}
