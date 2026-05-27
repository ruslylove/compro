// Lecture 5: #define Directive: Function-Like Macros
#include <stdio.h>

// Simple macro (constant)
#define LIMIT 10

// Function-like macro (use parentheses!)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int num = 5;
    int sq = SQUARE(num); // Replaced by: int sq = ((num) * (num));
    int another_sq = SQUARE(num + 1); // Replaced by: ((num + 1) * (num + 1))

    int x = 3, y = 7;
    int maximum = MAX(x, y); // Replaced by: (((x) > (y)) ? (x) : (y))

    printf("Square of %d is %d\n", num, sq); // Output: 25
    printf("Square of %d is %d\n", num + 1, another_sq); // Output: 36
    printf("Max of %d and %d is %d\n", x, y, maximum); // Output: 7
    return 0;
}
