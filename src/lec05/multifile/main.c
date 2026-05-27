// Lecture 5: Header Files (.h) vs. Source Files (.c): Example
#include <stdio.h>
#include "math_utils.h" // Include our custom header

int main() {
    int x = 5, y = 7;
    // We can use add() because its prototype
    // was included from math_utils.h
    int result = add(x, y);
    printf("The sum is: %d\n", result);
    return 0;
}
