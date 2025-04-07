---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 4 - Loops
class: lab
---

# Computer Programming
## Lab 4: Loops

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Exercise 1: Approximate exp(x)

* **Task:** Write a C program to approximate the value of $e^x$ using its Taylor series expansion:
  $e^{x}=\sum_{n=0}^{\infty}\frac{x^{n}}{n!} = 1 + \frac{x}{1!} + \frac{x^{2}}{2!} + \frac{x^{3}}{3!} + ...$
* **Requirements:**
    * Read the value of `x` from the user.
    * Keep adding terms to the sum as long as the absolute value of the current term (`term = x^n / n!`) is greater than a predefined precision (e.g., `1e-6`).
* **Hints:**
    * Initialize `sum = 0.0`, `term = 1.0` (for the first term, n=0).
    * Use a loop (like `while`) that continues as long as `fabs(term) > precision`.
    * Inside the loop:
        * Add the current `term` to the `sum`.
        * Calculate the *next* term efficiently. Notice that the next term can be calculated from the current term: `term_next = term * x / (n+1)`. Update `term` for the next iteration.
        * Increment the term counter (`n`).
    * Include `<math.h>` for `fabs()`. Link with `-lm` if needed.

---

## Code Skeleton: Approximate exp(x)

```c
#include <stdio.h>
#include <math.h> // For fabs()

int main() {
    const double PRECISION = 1e-6; // Define precision threshold
    double term = 1.0; // First term (n=0, x^0/0!)
    double sum = 0.0;
    double x;
    int n = 0; // Term counter

    printf("Enter value for x: ");
    scanf("%lf", &x); // Use %lf for double

    // Loop while the absolute value of the term is significant
    while (fabs(term) > PRECISION) {
        // Add current term to sum
        sum += term;

        // Prepare for next term
        n++; // Increment term counter

        // Calculate next term based on current term
        // term_new = term_old * x / n
        term = term * x / n;
    }

    printf("Approximate value of exp(%.2f) = %lf\n", x, sum);
    printf("Actual value (using math.h): %lf\n", exp(x)); // For comparison

    return 0;
}
```

---

## Exercise 2: Perfect Numbers

* **Task:** Find and print all **perfect numbers** within the range [1, 10000].
* **Definition:** A perfect number is a positive integer that is equal to the sum of its proper positive divisors (the sum of its positive divisors excluding the number itself).
* **Example:** 6 is a perfect number because its proper divisors are 1, 2, and 3, and $1 + 2 + 3 = 6$. Another example is 28 ($1 + 2 + 4 + 7 + 14 = 28$).
* **Approach:**
    1. Use an outer loop to iterate through numbers `j` from 1 to 10000.
    2. For each `j`, use an inner loop to find all its proper divisors (`i` from 1 up to `j/2`).
    3. Sum these divisors.
    4. If the sum equals `j`, then `j` is a perfect number, so print it.

---

## Code: Finding Perfect Numbers

```c
#include <stdio.h>

int main() {
    int j, i, sum_of_divisors;

    printf("Perfect numbers between 1 and 10000:\n");

    // Outer loop: Check each number 'j' in the range
    for (j = 1; j <= 10000; j++) {
        sum_of_divisors = 0; // Reset sum for each 'j'

        // Inner loop: Find proper divisors 'i' of 'j'
        // (Optimization: only need to check up to j/2)
        for (i = 1; i <= j / 2; i++) {
            if (j % i == 0) { // Check if 'i' is a divisor
                sum_of_divisors += i;
            }
        }

        // Check if the sum of proper divisors equals the number itself
        if (sum_of_divisors == j && j != 1) { // (1 is not considered perfect conventionally)
            printf("%d\t", j);
        }
    } // End outer loop

    printf("\n");
    return 0;
}
// Expected Output: 6    28    496    8128
```

---

## Exercise 3: Decimal Fraction to Binary

* **Task:** Convert a decimal fraction (a number between 0 and 1, e.g., 0.625) into its binary representation.
* **Algorithm (Multiply by 2 Method):**
    1. Start with the decimal fraction `d`.
    2. Multiply `d` by 2.
    3. The integer part of the result (either 0 or 1) is the next binary digit.
    4. The fractional part of the result becomes the new `d` for the next step.
    5. Repeat steps 2-4 until the fractional part becomes zero or you reach the desired number of binary digits (precision).
* **Example:** Convert 0.625
    * 0.625 * 2 = **1**.25 -> Binary digit: 1, New fraction: 0.25
    * 0.25 * 2 = **0**.50 -> Binary digit: 0, New fraction: 0.50
    * 0.50 * 2 = **1**.00 -> Binary digit: 1, New fraction: 0.00 (Stop)
    * Result: 0.101 (binary)
* **Implementation:** Write a C program that takes a decimal fraction input and prints its binary representation up to a certain number of places.

---

## Code: Decimal Fraction to Binary

```c
#include <stdio.h>

#define MAX_BINARY_DIGITS 20 // Limit the number of binary digits to print

int main() {
    double decimal_fraction;
    int binary_digit;
    int count = 0;

    printf("Enter a decimal fraction between 0 and 1 (e.g., 0.625): ");
    scanf("%lf", &decimal_fraction);

    if (decimal_fraction <= 0 || decimal_fraction >= 1) {
        printf("Input must be between 0 and 1.\n");
        return 1;
    }

    printf("Binary representation: 0.");

    // Loop until fraction becomes 0 or max digits reached
    while (decimal_fraction > 0 && count < MAX_BINARY_DIGITS) {
        // Multiply by 2
        decimal_fraction *= 2.0;

        // Get the integer part (0 or 1)
        binary_digit = (int)decimal_fraction;

        // Print the binary digit
        printf("%d", binary_digit);

        // Subtract integer part to get the new fractional part
        decimal_fraction -= binary_digit; // Or use fmod(decimal_fraction, 1.0)

        count++;
    }

    printf("\n");
    return 0;
}
```


