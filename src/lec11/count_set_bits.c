#include <stdio.h>

int main() {
    int a;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%d", &a);

    int temp = a;
    while (temp > 0) {
        if (temp & 1) count++;
        temp >>= 1;
    }

    printf("Number of set bits in %d: %d\n", a, count);
    return 0;
}
