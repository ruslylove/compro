#include <stdio.h>

int main() {
    int x = 1;
    double S = 0.0;

    while (x <= 5) {
        S += 1.0 / (x * x);
        x++;
    }

    printf("S = %f\n", S);
    return 0;
}
