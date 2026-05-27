#include <stdio.h>

void try_to_modify(int x) {
    printf("Inside function (before): x = %d\n", x);
    x = 9;
    printf("Inside function (after):  x = %d\n", x);
}

int main() {
    int original_value = 10;
    printf("In main (before call): original_value = %d\n", original_value);
    try_to_modify(original_value);
    printf("In main (after call):  original_value = %d\n", original_value);
    return 0;
}
