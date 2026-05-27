#include <stdio.h>

int main() {
    int x;
    double S = 0.0;

    for (x = 1; x <= 5; x++) {
        S += 1.0 / (x * x);
    }

    printf("S = %f\n", S);
    return 0;
}
