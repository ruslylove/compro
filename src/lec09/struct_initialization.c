#include <stdio.h>

struct Student {
    char  student_name[64];
    int   age;
    float gpa;
};

int main() {
    struct Student s1 = {"Carol", 19, 3.5};
    struct Student s2 = {.gpa = 3.9, .student_name = "David", .age = 22};

    printf("s1: Name=%s, Age=%d, GPA=%.1f\n", s1.student_name, s1.age, s1.gpa);
    printf("s2: Name=%s, Age=%d, GPA=%.1f\n", s2.student_name, s2.age, s2.gpa);
    return 0;
}
