#include <stdio.h>

int main() {
    int a, b = 3, i = 4;

    /* (3 > 4) is false, so a gets i (4) */
    a = (b > i) ? b : i;
    /* (3 == 3) is true, so b gets 2 */
    b = (b == 3) ? 2 : 1;

    printf("Result: a = %d, b = %d\n", a, b);
    return 0;
}
