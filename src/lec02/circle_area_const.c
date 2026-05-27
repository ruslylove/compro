#include <stdio.h>

int main() {
    const float PI = 3.14159;
    float radius     = 3.0;
    float circle_area;

    // PI = 3.14; // Error: cannot assign to a const variable

    circle_area = PI * radius * radius;
    printf("Area: %f\n", circle_area);
    return 0;
}
