// Lecture 8: Passing Arrays of Strings to Functions
#include <stdio.h>

#define NUM_NAMES 4
#define MAX_NAME_LEN 20

// The second dimension size (20) must be specified
void print_names(char names[][MAX_NAME_LEN], int size) {
    printf("--- List of Names ---\n");
    for (int i = 0; i < size; i++) {
        printf("- %s\n", names[i]);
    }
}

int main() {
    char names[NUM_NAMES][MAX_NAME_LEN] = {
        "Alice", "Bob", "Charlie", "David"
    };
    print_names(names, NUM_NAMES);
    return 0;
}
