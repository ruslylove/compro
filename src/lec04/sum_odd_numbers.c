#include <stdio.h>

int main() {
    int i, sum = 0;

    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("Skipping even number %d\n", i);
            continue;
        }
        printf("Adding odd number %d\n", i);
        sum += i;
    }

    printf("Sum of odd numbers (1-10): %d\n", sum);
    return 0;
}
