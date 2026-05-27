#include <stdio.h>

int main() {
    int a = 10, b = 25, c = 15;
    int max;

    if (a > b) {
        max = (a > c) ? a : c;
    } else {
        max = (b > c) ? b : c;
    }

    printf("The maximum value is: %d\n", max);
    return 0;
}
