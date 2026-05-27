#include <stdio.h>

int main() {
    int n = 5;
    long long factorial = 1;
    int i;

    if (n < 0) {
        printf("Factorial not defined for negative numbers.\n");
    } else {
        for (i = 1; i <= n; i++)
            factorial *= i;
        printf("Factorial of %d (%d!) = %lld\n", n, n, factorial);
    }
    return 0;
}
