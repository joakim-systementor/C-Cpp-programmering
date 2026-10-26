#include <stdio.h>

 /* 
 Inparametern är en int* (int-pekare),
   dvs en variabel som pekar på ett utrymme i minnet där det ligger en int-variabel.
 */
void addera(int* c) {
    /* 
    Variabeln c pekar alltså på en adress i minnet.
    Vi använder *c för att komma åt värdet på den minnesadressen.
    */
    *c = *c + 12;
    printf("%d\n", *c);
}

int main(void) {
    int c = 11;

    printf("%d\n", c);
    // Vi skriver &c i funktionsanropet för att skicka en referens till c istället för värdet i sig
    addera(&c);
    printf("%d\n", c);
    return 0;
}
