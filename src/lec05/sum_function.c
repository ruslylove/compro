#include <stdio.h>

int sum(int n) {
    int i, total = 0;
    for (i = 1; i <= n; i++)
        total += i;
    return total;
}

int main() {
    int limit = 5;
    int result = sum(limit);
    printf("Sum from 1 to %d is: %d\n", limit, result);
    return 0;
}
