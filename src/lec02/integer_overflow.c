// Lecture 2: Integer Overflow
#include <stdio.h>

int main() {
  // Max value for unsigned short is 65535
  unsigned short b = 65537;
  // Overflow occurs. For unsigned types, the value typically "wraps around".
  // Calculation: 65537 % 65536 = 1. So, b will likely hold the value 1.
  printf("b = %d\n", b);
  return 0;
}
