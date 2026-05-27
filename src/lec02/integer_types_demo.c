#include <stdio.h>

int main() {
    short a = 0x8000; // Smallest signed short (-32768)
    short b = 0x7FFF; // Largest signed short (32767)
    short c = 0xFFFE; // Represents -2 in two's complement
    char  d = 0x80;   // Smallest signed char (-128)

    printf("a = %d, b = %d, c = %d\n", a, b, c);
    printf("d = %d\n", d);
    return 0;
}
