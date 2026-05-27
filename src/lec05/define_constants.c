#include <stdio.h>

#define PI        3.14159
#define MAX_VALUE 100

int main() {
    double circumference = 2 * PI * 10.0;
    if (circumference > MAX_VALUE)
        printf("Circumference exceeds max value.\n");
    printf("Circumference: %f\n", circumference);
    return 0;
}
