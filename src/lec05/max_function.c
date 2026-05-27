#include <stdio.h>

int max(int num1, int num2) {
    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}

int main() {
    int a = 10, b = 20;
    int maximum = max(a, b);
    printf("The maximum is: %d\n", maximum);
    return 0;
}
