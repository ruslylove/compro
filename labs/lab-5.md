---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 5 - Functions
class: lab
routeAlias: lab5
---

# Computer Programming
## Lab 5: Functions

Presented by {{ $slidev.configs.presenter }}

Semester {{ $slidev.configs.semester }}

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
*   **Exercise 2: Temperature Converter**
    *   Practice modular design with multiple functions.
*   **Exercise 3: Approximate cos(x)**
    *   Use a function to encapsulate a complex mathematical calculation.
*   **Exercise 4: Greatest Common Divisor (GCD)**
    *   Implement a classic algorithm (Euclidean) as a function.
*   **Exercise 5: Sum of Digits with Recursion**
    *   Solve a problem using a simple recursive function.
*   **Exercise 6: Simple Event Logger**
    *   Demonstrate a practical use of a `static` variable.

---

## Exercise 1: Maximum of Three Numbers

*   **Task:** Write a C program that finds the maximum of three floating-point numbers.
*   **Requirements:**
    1.  Read three `float` numbers as input within the `main()` function.
    2.  Implement a function `float findMax(float a, float b, float c)` that returns the largest of the three numbers.
    3.  Call the `findMax` function from `main()` and print the result.

---

## Exercise 2: Temperature Converter

*   **Task:** Write a C program that provides a menu to convert temperatures between Celsius and Fahrenheit.
*   **📝 Flowchart First:** Before coding, draw a flowchart for the main logic of your program. It should show how the menu is displayed, how the user's choice is read, and how the appropriate function is called.
*   **Requirements:**
    1.  Implement two functions:
        *   `double celsiusToFahrenheit(double celsius);`
        *   `double fahrenheitToCelsius(double fahrenheit);`
    2.  In `main()`, display a menu asking the user to choose a conversion type (e.g., 1 for C to F, 2 for F to C).
    3.  Based on the user's choice, prompt for the temperature, call the appropriate function, and print the converted result with a clear label.
*   **Formulas:**
    *   Fahrenheit = (Celsius × 9/5) + 32
    *   Celsius = (Fahrenheit − 32) × 5/9

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

## Exercise 4: Greatest Common Divisor (GCD)

*   **Task:** Write a C program to calculate the Greatest Common Divisor (GCD) of two integers.
*   **📝 Flowchart First:** Before coding, draw a flowchart for the Euclidean algorithm that you will implement in the `gcd` function.
*   **Requirements:**
    1.  Read two integer numbers as input within the `main()` function.
    2.  Implement a function `int gcd(int a, int b)` to calculate the GCD.
    3.  Call the `gcd` function from `main()` and print the resulting GCD.
*   **Hint:** The Euclidean algorithm is an efficient method. For positive integers a and b, it's based on the principle that `gcd(a, b) = gcd(b, a % b)`. The base case is `gcd(a, 0) = a`. 
**Note:** This definition naturally leads to a recursive solution, but you can also implement it using a loop (iteratively). For this exercise, try to implement the recursive approach.

---

## Exercise 5: Sum of Digits with Recursion

*   **Task:** Write a C program to calculate the sum of the digits of a positive integer using recursion.
*   **Example:** For the number `987`, the sum is `9 + 8 + 7 = 24`.
*   **Recursive Thinking:**
    *   How can you break this problem down? The sum of digits for `987` is `7 + (sum of digits for 98)`.
    *   **Recursive Step:** `sum_digits(n) = (n % 10) + sum_digits(n / 10)`
    *   **Base Case:** What is the simplest input? If the number has only one digit (`n < 10`), the sum is just the number itself.
*   **Requirements:**
    1.  Implement a function `int sumDigits(int n)` that calculates the sum of digits recursively.
    2.  In `main()`, get a positive integer from the user, call the `sumDigits` function, and print the result.

---

## Exercise 6: Simple Event Logger

*   **Task:** Create a logging function that prefixes each message with a unique, sequential ID number.
*   **Concept:** Use a `static` local variable to keep track of the log entry number. This demonstrates a practical use case where a function needs to maintain state across multiple calls without using global variables.
*   **Requirements:**
    1.  Create a function `void log_event(const char* message)`.
    2.  Inside `log_event`, declare a `static int event_id = 1;`.
    3.  The function should print the message prefixed with the current `event_id`, like `Log [1]: User logged in.`.
    4.  Increment the `event_id` after printing.
    5.  In `main()`, call `log_event()` with different string messages to show the counter increasing.
*   **Expected Output:**
    ```
    Log [1]: System startup.
    Log [2]: User authentication successful.
    Log [3]: Data file loaded.
    ```


<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="assessment" title="Go to Assessment Rubric 📝"/>
</div>
