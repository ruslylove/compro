#include <stdio.h>

int main() {
    int a = 3, b = 5;
    int temp;

    printf("Before swap: a = %d, b = %d\n", a, b);

    temp = a;
    a    = b;
    b    = temp;

    printf("After swap:  a = %d, b = %d\n", a, b);
    return 0;
}
