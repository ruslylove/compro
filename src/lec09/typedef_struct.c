// Lecture 9: The typedef Keyword with struct
#include <stdio.h>

// Original struct definition
struct ComplexNumber {
    double real;
    double imag;
};

// Using typedef to create an alias 'Complex'
typedef struct ComplexNumber Complex;

// Can also combine definition and typedef
typedef struct PointTag {
    int x;
    int y;
} Point; // 'Point' is now an alias for 'struct PointTag'

int main() {
    // Declare using the original name
    struct ComplexNumber c1;
    // Declare using the typedef'd alias 'Complex'
    Complex c2;

    // Declare using the typedef'd alias 'Point'
    Point p1 = {10, 20};

    c2.real = 1.0;
    c2.imag = -2.5;
    printf("Point p1: (%d, %d)\n", p1.x, p1.y);
    printf("Complex c2: %.1f + %.1fi\n", c2.real, c2.imag);

    return 0;
}
