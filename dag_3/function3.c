#include <stdio.h>

void function(int, int[], char[]); // Deklaration
void function2(void) { printf("Hej från function2!\n"); } // Deklaration och definition i ett. MÅSTE ske ovanför platsen vi gör funktionanropet

int main(void) {
    int a = 20;
    int ar[5] = { 10, 20, 30, 40, 50 };
    char str[30] = "geeksforgeeks";
    function(a, &ar[0], &str[0]); // Anrop
    function2();
    return 0;
}

/* 
Detta är okej om function3 är en hjälpfunktion till function och inte används
på andra ställen i programmet.
Om funciton3 ska användas av flera funktioner bör den hellre deklareras ovanför main.
*/
void function3(void) { printf("Nu är vi i function3!\n\n"); }

void function(int a, int* ar, char* str) { // Definition
    int i;
    function3();
    printf("value of a is %d\n\n", a);
    for (i = 0; i < 5; i++) {
      printf("value of ar[%d] is %d\n", i, ar[i]);
    }
    printf("\nvalue of str is %s\n", str);
}
