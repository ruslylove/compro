// Lecture 6: Out-of-Bounds Access Example
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Valid indices: 0, 1, 2, 3, 4
    int bad_index = 5; // Invalid index! (Should be 0-4)
    int very_bad_index = 100; // Way outside
    int negative_index = -1; // Invalid

    printf("arr[0] = %d\n", arr[0]); // OK

    // Accessing OUTSIDE the array bounds - UNDEFINED BEHAVIOR!
    printf("Attempting access arr[5]...\n");
    // The following line might crash, print garbage, or seem to work...
    // printf("arr[5] = %d\n", arr[bad_index]);

    printf("Attempting access arr[100]...\n");
    // printf("arr[100] = %d\n", arr[very_bad_index]); // Even worse!

    printf("Attempting access arr[-1]...\n");
    // printf("arr[-1] = %d\n", arr[negative_index]); // Also undefined!

    printf("Attempting to WRITE outside bounds...\n");
    // arr[bad_index] = 999; // Corrupts memory outside the array!

    printf("Program continuing (maybe?)\n");
    return 0;
}
