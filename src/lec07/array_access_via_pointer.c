#include <stdio.h>

int main() {
    int numbers[] = {100, 200, 300, 400, 500};
    int *ptr = numbers;
    int i;

    printf("Array notation:\n");
    for (i = 0; i < 5; i++)
        printf("numbers[%d] = %d\n", i, numbers[i]);

    printf("\nPointer arithmetic (*(ptr + i)):\n");
    for (i = 0; i < 5; i++)
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));

    printf("\nIncrementing pointer:\n");
    ptr = numbers;
    for (i = 0; i < 5; i++) {
        printf("Value: %d  addr: %p\n", *ptr, (void *)ptr);
        ptr++;
    }
    return 0;
}
