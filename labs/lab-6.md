---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 6 - Functions and Array
class: lab
---

# Computer Programming
## Lab 6: Functions and Array

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Lab Outline

1.  Function-based Exercises
2.  Applying Functions with Arrays/Strings

---

## Exercise 1: Narcissistic Numbers

* **Task:** Find and print all three-digit "Narcissistic" numbers (also known as Armstrong numbers).
* **Definition:** A three-digit number is Narcissistic if the sum of the cubes of its individual digits equals the number itself. Example: $153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153$.
* **Requirements:**
    1.  Implement a function `int isNarcNum(int a)` that returns `1` if `a` is a three-digit Narcissistic number, and `0` otherwise.
    2.  In `main()`, loop through numbers from 100 to 999.
    3.  Call `isNarcNum()` for each number.
    4.  Print the numbers that are identified as Narcissistic.
    5.  Format the output to display two Narcissistic numbers per line.
* **Hint:** To get individual digits of a number `a`, use integer division (`/`) and the modulus operator (`%`). Example: `hundreds = a / 100; tens = (a / 10) % 10; ones = a % 10;`

---

## Exercise 2: Palindrome Square Numbers

* **Task:** Find and print all numbers within a given range `[a, b]` that are both **palindromes** and **perfect squares**.
* **Definitions:**
    * **Palindrome:** A number that reads the same forwards and backwards (e.g., 121, 484).
    * **Perfect Square:** A number that is the square of an integer (e.g., 9 = 3², 16 = 4²).
* **Requirements:**
    1.  Define a function `int ispld(int n)` that returns `1` if `n` is a palindrome, `0` otherwise.
    2.  Define a function `int isqr(int n)` that returns `1` if `n` is a perfect square, `0` otherwise.
    3.  In `main()`, prompt the user for the range limits `a` and `b`.
    4.  Loop through numbers from `a` to `b`.
    5.  Call both `ispld()` and `isqr()` for each number.
    6.  If *both* functions return `1`, print the number.
* **Example Output (for a suitable range):** 0, 1, 4, 9, 121, 484, 676, ...

---

## Exercise 2: Palindrome/Square Function Details

* **Requirements for `ispld(int n)`:**
    * Must return `1` if `n` is a palindrome, `0` otherwise.
    * **Hint:** Reverse the number `n` and check if the reversed number is equal to the original `n`.
* **Requirements for `isqr(int n)`:**
    * Must return `1` if `n` is a perfect square, `0` otherwise.
    * **Hint:** Calculate the integer part of the square root of `n`. Square this integer result. If it equals the original `n`, then `n` is a perfect square. Use `sqrt()` from `<math.h>` and potentially cast to `int`. Remember to link with `-lm` if needed.

---

## Exercise 4: Convert Number String to Integer

* **Task:** Write a function that converts a string containing only digits (e.g., `"312"`) into its corresponding integer value (e.g., 312).
* **Function Signature:** `int str2num(char a[])`
* **Algorithm Outline:**
    1.  Determine the length of the input string `a` (e.g., using `strlen()` from `<string.h>`).
    2.  Initialize an integer result variable (e.g., `num = 0`).
    3.  Iterate through the string character by character (from left to right, or index 0 to length-1).
    4.  In each iteration:
        * Multiply the current `num` by 10 (`num = num * 10;`).
        * Convert the current character digit (e.g., `'3'`) to its integer equivalent (e.g., 3). Hint: `digit_value = char_digit - '0';`.
        * Add the `digit_value` to `num`.
    5.  Return the final `num`.
* **Example:** `"215"` -> `(0*10 + 2)` -> `(2*10 + 1)` -> `(21*10 + 5)` -> `215`.

---

## Exercise 4: `str2num` Function Interface

* Your `str2num` function should be callable from `main` like this:

```c
#include <stdio.h>
#include <string.h> // For strlen if used

// --- Your str2num function definition goes here ---
int str2num(char a[]) {
    // Implement the conversion logic
    int num = 0;
    int i = 0;
    while (a[i] != '\0') {
        if (a[i] >= '0' && a[i] <= '9') { // Basic validation
            num = num * 10 + (a[i] - '0');
        } else {
            // Handle non-digit characters if necessary (e.g., return error)
            return -1; // Or some error indication
        }
        i++;
    }
    return num;
}
// --- End of str2num function ---

int main() {
    char str[] = "215";
    int num = 0;

    num = str2num(str); // Call your function

    if (num != -1) { // Check for potential error return
        printf("String \"%s\" as integer: %d\n", str, num);
    } else {
        printf("Invalid number string input.\n");
    }

    return 0;
}
```

---

## Exercise 5: Convert Decimal to Hexadecimal String

* **Task:** Write a function that takes an integer `n` and prints its hexadecimal (base-16) string representation (e.g., print `"0x5822D"` for the input `361005`).
* **Function Signature:** `void dec2hexa(int n)`
* **Algorithm Outline (Recursive Division):**
    1.  Repeatedly divide the number `n` by 16.
    2.  Keep track of the remainders (which will be 0-15).
    3.  The sequence of remainders, read in reverse order, forms the hexadecimal digits.
    4.  Map remainders 10 through 15 to the characters 'A' through 'F'.
    5.  Print the resulting hexadecimal string (perhaps prefixed with "0x").
* **Hint:** This can be implemented recursively or iteratively using an array/string to store the remainders before printing in reverse.

---

## Exercise 5: `dec2hexa` Function Interface

* Your `dec2hexa` function should be callable from `main` like this:

```c
#include <stdio.h>

// --- Your dec2hexa function definition goes here ---
void dec2hexa(int n) {
    // Implement the conversion and printing logic
    // Example (iterative approach using an array):
    if (n == 0) {
        printf("0x0");
        return;
    }
    char hex_digits[20]; // Buffer to store hex digits in reverse
    int i = 0;
    int remainder;
    char hex_chars[] = "0123456789ABCDEF";

    int temp_n = n; // Use a temporary copy

    while (temp_n > 0) {
        remainder = temp_n % 16;
        hex_digits[i] = hex_chars[remainder];
        temp_n = temp_n / 16;
        i++;
    }

    printf("0x"); // Print prefix
    // Print digits in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex_digits[j]);
    }
}
// --- End of dec2hexa function ---

int main() {
    int num = 361005;

    printf("Decimal: %d\n", num);
    printf("Hexadecimal: ");
    dec2hexa(num); // Call your function
    printf("\n");

    return 0;
}
```