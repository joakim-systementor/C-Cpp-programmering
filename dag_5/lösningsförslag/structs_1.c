#include <stdio.h>

typedef struct {
    char first_name[50];
    char last_name[50];
    char city[50];
    int birth_year;
} Student;

void input_student(Student*);
void print_student(const Student*);

int main(void) {
    Student student1, student2;

    input_student(&student1);
    input_student(&student2);

    printf("\n");
    print_student(&student1);
    print_student(&student2);

    return 0;
}

void input_student(Student* student) {
    printf("Mata in förnamn: ");
    scanf("%s", student->first_name);
    getchar();
    printf("Mata in efternamn: ");
    scanf("%s", student->last_name);
    getchar();
    printf("Mata in stad: ");
    scanf("%s", student->city);
    getchar();
    printf("Mata in födelseår: ");
    scanf("%d", &student->birth_year);
    getchar();
}

void print_student(const Student* student) {
    printf("Student:\n");
    printf("Namn: %s %s\n", student->first_name, student->last_name);
    printf("Stad: %s\n", student->city);
    printf("Födelseår: %d\n\n", student->birth_year);
}
