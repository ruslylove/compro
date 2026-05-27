#include <stdio.h>
#include "mylib.h"

int main() {
    float x = 3.4;
    int   a = 5;

    float y = square(x);
    printf("square(%.1f) = %.2f\n", x, y);

    if (isodd(a))
        printf("%d is odd\n", a);

    return 0;
}
