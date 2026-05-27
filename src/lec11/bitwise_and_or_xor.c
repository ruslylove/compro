#include <stdio.h>

int main() {
    unsigned char a = 60;  /* 0011 1100 */
    unsigned char b = 13;  /* 0000 1101 */
    unsigned char result;

    result = a & b;  /* 0000 1100 */
    printf("%d & %d = %d\n", a, b, result);

    result = a | b;  /* 0011 1101 */
    printf("%d | %d = %d\n", a, b, result);

    result = a ^ b;  /* 0011 0001 */
    printf("%d ^ %d = %d\n", a, b, result);
    return 0;
}
