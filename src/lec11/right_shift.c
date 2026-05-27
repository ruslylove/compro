#include <stdio.h>

int main() {
    unsigned char a = 60;  /* 0011 1100 */
    int shift = 2;

    unsigned char result = a >> shift;  /* 0000 1111 */
    printf("%u >> %d = %u\n", a, shift, result);
    printf("%u / (2^%d) = %d\n", a, shift, a / (1 << shift));

    signed char signed_a      = -60;
    signed char signed_result = signed_a >> shift;
    printf("%d >> %d = %d (implementation-defined for signed)\n",
           signed_a, shift, signed_result);
    return 0;
}
