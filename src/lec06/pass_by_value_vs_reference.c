// Lecture 6: Pass-by-Value vs. Pass-by-Reference
#include <stdio.h>

// Pass by value — does NOT modify original
void increment(int num) {
    num = num + 1; // num is a copy
}

// Pass by reference (array) — DOES modify original
void double_elements(int arr[], int size) {
    for (int i=0; i<size; i++) {
        arr[i] *= 2; // Modifies original
    }
}

int main() {
    int x = 10;
    increment(x);
    printf("x after increment (unchanged): %d\n", x); // still 10

    int data[] = {1, 2, 3};
    double_elements(data, 3);
    printf("data after double_elements: %d %d %d\n", data[0], data[1], data[2]);
    // data is now {2, 4, 6}
    return 0;
}
