#include <stdio.h>
#include <string.h>

struct Student {
    char  student_name[64];
    int   age;
    float gpa;
};

int main() {
    struct Student s1;

    strcpy(s1.student_name, "Alice");
    s1.age = 20;
    s1.gpa = 3.8;

    printf("Student Name: %s\n", s1.student_name);
    printf("Age:          %d\n", s1.age);
    printf("GPA:          %.2f\n", s1.gpa);
    return 0;
}
