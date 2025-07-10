---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 5 - Functions and Variables
class: lab
routeAlias: lab5
---

# Computer Programming
## Lab 5: Functions and Variables

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Objectives

*   **Understand and define C functions**
    *   Learn the syntax for function declaration, definition, and invocation.
    *   Differentiate between function prototypes and function implementations.
*   **Use function parameters and return values**
    *   Pass data to functions using parameters (pass-by-value).
    *   Return a single value from a function using the `return` statement.
*   **Implement modular programming**
    *   Decompose a problem into smaller, manageable sub-problems solved by individual functions.
    *   Create reusable helper functions (e.g., `isPrime`, `gcd`).
*   **Explore variable scope and lifetime**
    *   Understand the difference between local variables (inside a function) and global variables.
    *   Use `static` variables to maintain state across function calls.
*   **Apply recursive thinking**
    *   Implement a recursive function where a function calls itself to solve a problem.

---

## Lab Outline

*   **Exercise 1: Maximum of Three Numbers**
    *   A simple function to practice parameters and return values.
*   **Exercise 2: Greatest Common Divisor (GCD)**
    *   Implement a classic algorithm (Euclidean) as a function.
*   **Exercise 3: Approximate cos(x)**
    *   Use a function to encapsulate a complex mathematical calculation.
*   **Exercise 4: Largest Prime Number**
    *   Combine loops and functions to solve a number theory problem.
*   **Exercise 5: Factorial with Recursion**
    *   Introduce the concept of a function calling itself.
*   **Exercise 6: Static Variable Counter**
    *   Demonstrate variable scope and lifetime with the `static` keyword.

---

## Exercise 1: Maximum of Three Numbers

*   **Task:** Write a C program that finds the maximum of three floating-point numbers.
*   **Requirements:**
    1.  Read three `float` numbers as input within the `main()` function.
    2.  Implement a function `float findMax(float a, float b, float c)` that returns the largest of the three numbers.
    3.  Call the `findMax` function from `main()` and print the result.

---

## Exercise 2: Greatest Common Divisor (GCD)

*   **Task:** Write a C program to calculate the Greatest Common Divisor (GCD) of two integers.
*   **📝 Flowchart First:** Before coding, draw a flowchart for the Euclidean algorithm that you will implement in the `gcd` function.
*   **Requirements:**
    1.  Read two integer numbers as input within the `main()` function.
    2.  Implement a function `int gcd(int a, int b)` to calculate the GCD.
    3.  Call the `gcd` function from `main()` and print the resulting GCD.
*   **Hint:** The Euclidean algorithm is an efficient method. For positive integers a and b, it's based on the principle that `gcd(a, b) = gcd(b, a % b)`. The base case is `gcd(a, 0) = a`.

---

## Exercise 3: Approximate cos(x)

*   **Task:** Write a C program to approximate the value of $\cos(x)$ using its Taylor series expansion:
    $\cos(x)=\sum_{n=0}^{\infty}\frac{(-1)^{n}x^{2n}}{(2n)!}=1-\frac{x^{2}}{2!} + \frac{x^{4}}{4!} - \frac{x^{6}}{6!} + ...$
*   **📝 Flowchart First:** Draw a flowchart for your `cosx` function. It should show the loop for summing the series terms and the condition for stopping.
*   **Requirements:**
    1.  Define a function `double cosx(double x)` that takes the angle `x` (in radians).
    2.  Inside the function, calculate the sum of the series. Stop when the absolute value of the term being added is less than a small precision value (e.g., `1e-6`).
    3.  The function should return the approximated `double` value of `cos(x)`.
    4.  In `main()`, get `x` from the user, call `cosx()`, and print the result.

---

## Exercise 4: Largest Prime Number

*   **Task:** Write a C program to find the largest prime number that is less than a given integer `N`.
*   **📝 Flowchart First:** Draw a flowchart for this program. It should show the main loop that calls the `isPrime` helper function.
*   **Requirements:**
    1.  Read an integer `N` as input within the `main()` function.
    2.  Implement a helper function `int isPrime(int num)` that returns `1` if `num` is prime and `0` otherwise.
    3.  In `main()`, loop downwards from `N-1`. For each number, call your `isPrime` function.
    4.  The first number found to be prime is the largest prime less than `N`. Print this number and stop searching.

---

## Exercise 5: Factorial with Recursion

*   **Task:** Write a C program to calculate the factorial of a non-negative integer using recursion.
*   **Definition:** The factorial of `n` (denoted `n!`) is the product of all positive integers up to `n`.
    *   $n! = n \times (n-1) \times (n-2) \times ... \times 1$
    *   $0! = 1$ (by definition)
*   **Recursive Formula:**
    *   `factorial(n) = n * factorial(n-1)`
    *   Base Case: `factorial(0) = 1`
*   **Requirements:**
    1.  Implement a function `long long factorial(int n)` that calculates the factorial recursively.
    2.  In `main()`, get an integer from the user, call the `factorial` function, and print the result.
    3.  Handle the case where the input is negative (factorial is not defined).

---

## Exercise 6: Static Variable Counter

*   **Task:** Write a program to demonstrate the use of a `static` local variable.
*   **Concept:** A `static` local variable retains its value between function calls. It is initialized only once.
*   **Requirements:**
    1.  Create a function `void counter_func(void)`.
    2.  Inside `counter_func`, declare a `static int count = 0;`.
    3.  Increment and print the `count` variable inside this function.
    4.  In `main()`, call `counter_func()` multiple times (e.g., in a loop for 5 times).
*   **Expected Output:**
    ```
    This function has been called 1 time(s).
    This function has been called 2 time(s).
    This function has been called 3 time(s).
    This function has been called 4 time(s).
    This function has been called 5 time(s).
    ```

---
src: ./assessment.md
---
