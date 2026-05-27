#include <stdio.h>

int main() {
    float  x = 0.125;
    double y = 111111.111111;
    printf("Size of float:  %zu bytes\n", sizeof(x));
    printf("Size of double: %zu bytes\n", sizeof(y));
    return 0;
}
