#include <stdio.h>

int main (void) {
    printf("Innan loopen\n");

    int i = 0;
    while (1) {
        printf("Loop start, i: %d\n", ++i); // ++i = inkrementera i INNAN beräkningen/funktionen kör - dvs innan printen
        if (i == 4) { // När i är 4, continue - dvs hoppa över utskriften i slutet
            continue;
        }
        if (i > 10) { // När i är större än 10, hoppa ur loopen inklusive utskriften i slutet
            break;
        }
        printf("i: %d\n", i);
    }
    return 0;
}
