// Lecture 5: Function Types: void return, with parameters
#include <stdio.h>

// Function Definition
void print_sum_and_diff(int x, int y) { // Returns void, takes two int parameters
    printf("Sum: %d\n", x + y);
    printf("Difference: %d\n", x - y);
}

// Example Usage
int main() {
    print_sum_and_diff(50, 15); // Call the function
    return 0;
}
