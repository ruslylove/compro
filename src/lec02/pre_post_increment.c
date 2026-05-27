// Lecture 2: Pre- vs. Post-Increment/Decrement
#include <stdio.h>

int main() {
  int a, b;
  int i = 4;

  // Post-increment example
  a = i++; // Step 1: a gets current value of i (4). Step 2: i becomes 5.
           // Result after this line: a=4, i=5

  // Pre-increment example
  b = ++i; // Step 1: i becomes 6. Step 2: b gets new value of i (6).
           // Result after this line: b=6, i=6

  // Final values: a = 4, b = 6, i = 6
  printf("a = %d, b = %d, i = %d\n", a, b, i);
  return 0;
}
