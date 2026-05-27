// Lecture 5: Function Declaration (Prototypes)
#include <stdio.h>

// Function Declaration (Prototype)
int max(int num1, int num2); // Tells compiler 'max' exists

int main() {
    int m = max(10, 5); // OK: Compiler knows 'max' from declaration
    printf("Max is %d\n", m);
    return 0;
}

// Function Definition (can appear later in the file or in another file)
int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}
