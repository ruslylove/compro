#include <stdio.h>

double multiply(double a, double b) {
    return a * b;
}

int main() {
    double num1 = 10.5, num2 = 2.0;
    double product = multiply(num1, num2);
    printf("Product: %.2f\n", product);
    return 0;
}
