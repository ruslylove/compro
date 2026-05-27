#include <stdio.h>

int main() {
    int age = 30;
    int *ptr_age = &age;

    printf("Value of age (direct):      %d\n", age);
    printf("Value of age (via pointer): %d\n", *ptr_age);

    *ptr_age = 31;
    printf("New value of age (direct):  %d\n", age);

    int value_read = *ptr_age;
    printf("Value read via pointer:     %d\n", value_read);
    return 0;
}
