#include <stdio.h>

int main() {
    unsigned char a = 60;  /* 0011 1100 */
    int shift = 2;

    unsigned char result = a << shift;  /* 1111 0000 */
    printf("%d << %d = %u\n", a, shift, result);
    printf("%d * (2^%d) = %d\n", a, shift, a * (1 << shift));
    return 0;
}
