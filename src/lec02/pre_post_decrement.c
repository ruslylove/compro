// Lecture 2: Pre- vs. Post-Decrement Example
#include <stdio.h>

int main() {
  int a, b;
  int i = 4;

  // Post-decrement
  a = i--; // Step 1: a gets current i (4). Step 2: i becomes 3.
           // After this: a=4, i=3

  // Pre-decrement
  b = --i; // Step 1: i becomes 2. Step 2: b gets new i (2).
           // After this: b=2, i=2

  printf("Final: a = %d, b = %d\n", a, b);
  return 0;
}
