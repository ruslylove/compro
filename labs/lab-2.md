---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 2 - Expressions
class: lab
---

# Computer Programming
## Lab 2: Expressions

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Lab Outline

* Exercises involving C expressions, operators, and formatted output.

---

## Exercise 1: Formatted Output

* **Task:** Write a C program to print the following six integer numbers: 123, 451, 332, 271, 74, 54.
* **Format Requirements:**
    * Print the numbers in two rows, with three numbers per row.
    * Each number should occupy a field width of exactly 5 characters.
    * Numbers should be **left-aligned** within their fields.
* **Hint:** Use the `%-5d` format specifier in `printf`.
* **Expected Output:**
    ```
    123  451  332
    271  74   54
    ```
    *(Spaces shown here for clarity; actual output will depend on terminal spacing)*

---

## Exercise 2: Octal and Hexadecimal Output

* **Task:** Write a C program that accepts an integer input from the user and then outputs that number's representation in both octal (base-8) and hexadecimal (base-16) formats.
* **Hints:**
    * Use `%o` format specifier for octal output.
    * Use `%x` (lowercase hex) or `%X` (uppercase hex) for hexadecimal output.
* **Starting Code:**
    ```c
    #include <stdio.h>

    int main() {
        int a = 0;
        printf("Enter an integer: ");
        scanf("%d", &a);

        // Add code here to print 'a' in octal and hexadecimal formats

        return 0;
    }
    ```

---

## Exercise 3: Conditional Operator and Square Root

* **Task:** Write a C program that:
    1.  Accepts two integer inputs, `a` and `b`, from the user.
    2.  Determines the maximum (larger) of the two numbers.
    3.  Calculates and outputs the square root of the maximum value found.
* **Hints:**
    * Use the conditional (ternary) operator `(condition ? value_if_true : value_if_false)` to find the maximum efficiently.
    * Use the `sqrt()` function to calculate the square root. This function returns a `double`.
    * You must include the math library header file: `#include <math.h>`.
    * When compiling code that uses `math.h` functions, you might need to link the math library explicitly using the `-lm` flag with `gcc`: `gcc your_code.c -o your_program -lm`.

---

## Exercise 4: Average Calculation

* **Task:** Write a C program that accepts four real numbers (floating-point values) as input from the user and then calculates and outputs their average.
* **Hints:**
    * Use `float` or `double` data types for the input numbers and the average.
    * Use the `%f` format specifier with `scanf` to read floating-point numbers.
    * Remember the formula for average: `sum / count`.

---

## Exercise 5: Character Capitalization

* **Task:** Write a C program that:
    1.  Accepts a single character input from the user.
    2.  If the input character is a lowercase letter (`'a'` through `'z'`), output its corresponding uppercase letter.
    3.  Otherwise (if it's not a lowercase letter), output the original character unchanged.
* **Examples:**
    * Input: `a`, Output: `A`
    * Input: `f`, Output: `F`
    * Input: `Z`, Output: `Z`
    * Input: `;`, Output: `;`
* **Hints:**
    * Recall that characters are represented by ASCII integer values.
    * You can compare characters directly (e.g., `ch >= 'a' && ch <= 'z'`).
    * The ASCII value difference between a lowercase letter and its corresponding uppercase letter is constant (e.g., `'a' - 'A'` is the same as `'b' - 'B'`, etc., which is 32). You can use this difference for conversion.

---

## Exercise 6: Swap Variable Values

* **Task:** Write a C program that:
    1.  Accepts two integer inputs, `a` and `b`, from the user.
    2.  Swaps the values stored in variables `a` and `b`.
    3.  Prints the values of `a` and `b` *after* the swap has occurred.
* **Example Interaction:**
    ```
    Enter first integer: 10
    Enter second integer: 20
    After swap: a = 20, b = 10
    ```
* **Hint:** You will likely need a third, temporary integer variable to hold one of the values during the swap process.
