#include <stdio.h>

int main() {
    int x = 1, sum = 0, limit = 5;
    printf("DEBUG: Before loop: x=%d, sum=%d\n", x, sum);

    while (x <= limit) {
        printf("DEBUG: Start of iteration: x=%d\n", x);
        sum += x;
        printf("DEBUG: After adding x: sum=%d\n", sum);
        x++;
        printf("DEBUG: After incrementing x: x=%d\n", x);
    }

    printf("DEBUG: After loop: sum=%d\n", sum);
    printf("Final Sum = %d\n", sum);
    return 0;
}
