// Lecture 5: Function Types: void return, void parameters
#include <stdio.h>

// Function Definition
void print_message(void) { // Returns void, takes no parameters
    printf("This is a message from a void function.\n");
}

// Example Usage
int main() {
    print_message(); // Call the function
    return 0;
}
