// Lecture 5: Function Types: value return, void parameters
#include <stdio.h>

// Function Definition
int get_fixed_value(void) { // Returns int, takes no parameters
    return 42; // Returns a fixed integer value
}

// Example Usage
int main() {
    int value = get_fixed_value(); // Call the function
    printf("The fixed value is: %d\n", value);
    return 0;
}
