#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return (long long)n * factorial(n - 1);
}

int main() {
    int num = 5;
    printf("Factorial of %d = %lld\n", num, factorial(num));
    return 0;
}
