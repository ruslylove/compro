#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Student {
    char        student_name[64];
    struct Date birthday;
    float       gpa;
};

int main() {
    struct Student s1;
    strcpy(s1.student_name, "Grace");
    s1.birthday.day   = 15;
    s1.birthday.month =  6;
    s1.birthday.year  = 2003;
    s1.gpa = 3.9;

    printf("Name:     %s\n", s1.student_name);
    printf("Birthday: %d/%d/%d\n",
           s1.birthday.day, s1.birthday.month, s1.birthday.year);
    return 0;
}
