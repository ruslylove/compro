---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 2 - Expressions
class: lab
routeAlias: lab2 
---

# Computer Programming
## Lab 2: Expressions

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Lab Outline

* **Exercise 1: Formatted Output**
    * Use `printf` with field width and alignment to format integers.
* **Exercise 2: Octal and Hexadecimal Output**
    * Display a number in different bases using `%o` and `%x`.
* **Exercise 3: Integer Arithmetic with Division and Modulus**
    * Use `/` and `%` to extract digits from an integer.
* **Exercise 4: Average Calculation**
    * Perform floating-point arithmetic to calculate an average.
* **Exercise 5: Character Capitalization**
    * Convert character case using ASCII properties and conditional logic.
* **Exercise 6: Swap Variable Values**
    * Implement a classic variable swap using a temporary variable.

---

## Objectives

* **Master formatted output with `printf()`**
    * Control field width and alignment (e.g., `%-5d`).
    * Display numbers in different bases (octal `%o`, hexadecimal `%x`).
* **Apply various C operators to build expressions**
    * Use arithmetic operators for calculations (e.g., average).
    * Use integer division (`/`) and modulus (`%`) to solve problems.
    * Use relational and logical operators for character classification.
* **Incorporate standard library functions**
    * Use `printf()` and `scanf()` for I/O.
* **Solve classic programming logic problems**
    * Implement variable swapping.
    * Perform character case conversion based on ASCII values.
    * Extract digits from a number.

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

## Exercise 3: Integer Arithmetic with Division and Modulus

* **Task:** Write a C program that:
    1.  Accepts a three-digit integer from the user (e.g., 479).
    2.  Calculates the sum of its individual digits.
    3.  Prints the sum.
* **Example:**
    *   Input: `479`
    *   Sum of digits: `4 + 7 + 9 = 20`
    *   Output: `The sum of the digits is: 20`
* **Hints:**
    *   Use the integer division operator (`/`) to remove the last digit. For example, `479 / 10` results in `47`.
    *   Use the modulus operator (`%`) to get the last digit. For example, `479 % 10` results in `9`.
    *   You will need to apply these operators multiple times to isolate each digit.

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

<Transform scale="0.8">

* **Examples:**
    * Input: `a`, Output: `A`
    * Input: `f`, Output: `F`
    * Input: `Z`, Output: `Z`
    * Input: `;`, Output: `;`
* **Hints:**
    * Recall that characters are represented by ASCII integer values.
    * You can compare characters directly (e.g., `ch >= 'a' && ch <= 'z'`).
    * The ASCII value difference between a lowercase letter and its corresponding uppercase letter is constant (e.g., `'a' - 'A'` is the same as `'b' - 'B'`, etc., which is 32). You can use this difference for conversion.

</Transform>

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

---
src: ./assessment.md
---