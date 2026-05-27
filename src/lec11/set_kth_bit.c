#include <stdio.h>

int main() {
    int n = 10;  /* 0000 1010 */
    int k = 2;   /* set bit position 2 (value 4) */

    printf("Original:  n = %d\n", n);
    n = n | (1 << k);
    printf("After set: n = %d\n", n);  /* 0000 1110 = 14 */
    return 0;
}
