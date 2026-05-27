// Lecture 7: Passing Pointers to Functions: To Modify a Variable's Value
#include <stdio.h>

void add_five(int *num_ptr) {
    *num_ptr = *num_ptr + 5; // Modifies original
}

int main() {
    int x = 10;
    add_five(&x); // Pass address of x
    printf("x after add_five: %d\n", x); // Now, x is 15
    return 0;
}
