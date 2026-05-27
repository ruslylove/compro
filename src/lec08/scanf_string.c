// Lecture 8: String Input/Output (scanf, printf)
#include <stdio.h>

int main() {
    char name[10]; // Small buffer to demonstrate the danger

    printf("Enter your name: ");
    scanf("%s", name); // DANGEROUS! If user types "Christopher", it overflows.

    printf("Hello, %s!\n", name);
    return 0;
}
