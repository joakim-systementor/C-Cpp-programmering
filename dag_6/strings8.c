#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int age;
    char company[15];
} Employee;

int main(void) {
    char str[][30] = {"Stefan,50,Systementor", "Joakim,39,Systementor"};
    const char s[2] = ",";
    char *token;
    
    for (int i = 0; i < 2; ++i) {
        /* get the first token */
        token = strtok(str[i], s);
        
        int idx = 0;
        /* walk through other tokens */
        while (token != NULL) {
            switch (idx++) {
                case 0:
                    strncpy(employees[i].name, token, 10);
                    break;
                case 1:
                    employees[i].age = atoi(token); // OBS! FUSK! Jag gjorde det för att jag är lat! Gör INTE så här utan att kontrollera resultatet!
                    break;
                case 2:
                    strncpy(employees[i].company, token, 15);
                    break;
                default:
                    printf("Should not be able to get here. Skill issue.\n");
            }
            
            token = strtok(NULL, s);
        }
    }

    for (int i = 0; i < 2; ++i) {
        printf("Name: %s\nAge: %d\nCompany: %s\n\n", employees[i].name, employees[i].age, employees[i].company);
    }

    return 0;
}