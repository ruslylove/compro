#include <stdio.h>

void printArray(int arr[], int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void modifyArray(int arr[], int index, int newValue) {
    if (index >= 0)
        arr[index] = newValue;
}

int main() {
    int my_numbers[] = {10, 20, 30, 40, 50};
    int count = 5;

    printArray(my_numbers, count);
    modifyArray(my_numbers, 2, 999);
    printf("After modification:\n");
    printArray(my_numbers, count);
    return 0;
}
