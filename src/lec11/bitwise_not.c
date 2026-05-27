#include <stdio.h>

int main() {
    unsigned char a = 60;          /* 0011 1100 */
    unsigned char result = ~a;     /* 1100 0011 */
    printf("~%d = %u\n", a, result);

    int signed_a      = 60;
    int signed_result = ~signed_a;
    printf("~%d (signed) = %d\n", signed_a, signed_result);
    return 0;
}
