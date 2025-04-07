---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 5 - Functions and Variables
class: lab
---

# Computer Programming
## Lab 5: Functions and Variables

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Lab Outline

* Exercises involving defining and calling functions.

---

## Exercise 1: Maximum of Three Numbers

* **Task:** Write a C program that finds the maximum of three floating-point numbers.
* **Requirements:**
    1.  Read three `float` numbers as input within the `main()` function.
    2.  Implement a function with the following signature to determine the maximum value:
        `int max3(float a, float b, float c)`
        *(Note: The original signature specifies an `int` return type, which might be intended to return an index or status rather than the maximum float value itself. Adjust implementation accordingly based on expected output, or consider returning `float` if the maximum value is desired.)*
    3.  Call the `max3` function from `main()` and print the result.

---

## Exercise 2: Greatest Common Divisor (GCD)

* **Task:** Write a C program to calculate the Greatest Common Divisor (GCD) of two integers.
* **Requirements:**
    1.  Read two integer numbers as input within the `main()` function.
    2.  Implement a function with the following signature to calculate the GCD:
        `int gcd(int a, int b)`
    3.  Call the `gcd` function from `main()` and print the resulting GCD.
* **Hint:** You can use the Euclidean algorithm (repeatedly applying the modulus operator) to find the GCD.

---

## Exercise 3: Approximate cos(x)

* **Task:** Write a C program to approximate the value of $\cos(x)$ using its Taylor series expansion:
    $\cos(x)=\sum_{n=1}^{\infty}\frac{(-1)^{(n-1)}x^{2n-2}}{(2n-2)!}=1-\frac{x^{2}}{2!} + \frac{x^{4}}{4!} - \frac{x^{6}}{6!} + \frac{x^{8}}{8!} - ...$
* **Requirements:**
    1.  Define a function `cosx(double x)` that takes the angle `x` (in radians) as input.
    2.  Inside the function, calculate the sum of the series terms. You'll need a loop and a condition to stop adding terms (e.g., when the terms become very small, similar to the `exp(x)` example in Lab 4).
    3.  The function should return the approximated `double` value of `cos(x)`.
    4.  In `main()`, get a value for `x` from the user, call `cosx()`, and print the result.

---

## Exercise 4: Largest Prime Number

* **Task:** Write a C program to find the largest prime number that is less than a given integer `N`.
* **Requirements:**
    1.  Read an integer `N` as input within the `main()` function.
    2.  Implement a helper function (e.g., `int isPrime(int num)`) that returns `1` if `num` is prime and `0` otherwise.
        * A number is prime if it's greater than 1 and only divisible by 1 and itself.
        * To check if `num` is prime, check for divisibility by integers from 2 up to `sqrt(num)` or `num / 2`. If any divide evenly, it's not prime.
    3.  In `main()`, loop downwards from `N-1`. For each number, call your `isPrime` function.
    4.  The first number found to be prime is the largest prime less than `N`. Print this number and exit or stop searching.
