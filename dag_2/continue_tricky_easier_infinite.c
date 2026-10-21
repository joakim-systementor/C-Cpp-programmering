#include <stdio.h>

int main (void) {
    printf("Innan loopen\n");

    int i = 0;
    while (1) {
        printf("Loop start, i: %d\n", i);
        if (i == 4) { // När i är 4, continue - dvs hoppa över utskriften i slutet OCH inkrementeringen av i - dvs vi kommer fastna på i = 4 och loopa oändligt
            continue;
        }
        if (i > 10) { // När i är större än 10, hoppa ur loopen inklusive utskriften i slutet
            break;
        }
        printf("i: %d\n", i++);
    }
    return 0;
}
