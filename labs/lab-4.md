---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 4 - Loops
class: lab
routeAlias: lab4
---

# Computer Programming
## Lab 4: Loops

Presented by {{ $slidev.configs.presenter }}

Semester {{ $slidev.configs.semester }}

---

## Lab Outline

* **Exercise 1: Guess the Number Game**
    * Use a `do-while` loop to create an interactive game.
* **Exercise 2: Prime Number Checker**
    * Use a `for` loop with a `break` statement for an efficient check.
* **Exercise 3: Pyramid Pattern**
    * Use nested `for` loops to print a character-based pattern.
* **Exercise 4: Approximate exp(x)**
    * Use a `while` loop for an iterative calculation based on a precision threshold.
* **Exercise 5: Decimal Fraction to Binary**
    * Use a `while` loop for a numerical conversion algorithm.
* **Exercise 6: Perfect Numbers**
    * Use nested `for` loops to find numbers with a specific property.

---

## Objectives

* **Master looping constructs for iterative tasks**
    * Implement `while` loops for condition-based repetition (e.g., Taylor series).
    * Use `do-while` loops for tasks that must execute at least once (e.g., games).
    * Build counter-controlled `for` loops for a known number of iterations.
    * Create `nested loops` to solve problems with 2D patterns or exhaustive searches (e.g., perfect numbers, pyramids).
* **Apply loop control statements**
    * Use `break` to exit a loop early when a condition is met (e.g., prime number check).
* **Develop algorithmic thinking**
    * Translate mathematical formulas and algorithms into C code (e.g., $e^x$, binary conversion).
    * Decompose problems into logical steps suitable for flowcharting and implementation.

---

## Exercise 1: Guess the Number Game

* **Task:** Write a simple "guess the number" game.
* **📝 Flowchart First:** A flowchart is required for this game. It should illustrate the `do-while` loop structure for handling guesses.
* **Logic:**
    1.  Define a "secret number" in your code (e.g., `int secret_number = 42;`).
    2.  Use a `do-while` loop to repeatedly prompt the user to enter their guess.
    3.  Inside the loop, read the user's guess.
    4.  Provide feedback:
        * If the guess is too high, print "Too high! Try again."
        * If the guess is too low, print "Too low! Try again."
    5.  The loop should continue as long as the user's guess is not equal to the secret number.
    6.  Once the user guesses correctly, the loop terminates. Print a congratulatory message like "Correct! You guessed the number."
* **Challenge:** Add a counter to track how many guesses the user took.

---

## Exercise 2: Prime Number Checker

* **Task:** Write a C program that asks the user for a positive integer and determines if it is a prime number.
* **📝 Flowchart First:** Draw a flowchart for your prime-checking logic. Show how the loop can terminate early using a `break`.
* **Definition:** A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
* **Logic:**
    1. Handle the base cases: numbers less than or equal to 1 are not prime. 2 is prime.
    2. For a number `n > 2`, loop from `i = 2` up to `sqrt(n)` (or `n / 2`).
    3. In each iteration, check if `n % i == 0`.
    4. If a divisor is found, the number is not prime. You can set a flag and use `break` to exit the loop immediately, as no more checks are needed.
    5. If the loop completes without finding any divisors, the number is prime.
* **Output:** Print a message like `"[number] is a prime number."` or `"[number] is not a prime number."`

---

## Exercise 3: Pyramid Pattern

* **Task:** Write a C program that takes an integer `N` as input and prints a pyramid of stars (`*`) with `N` rows.
* **📝 Flowchart First:** A flowchart is required. It should clearly show the nested loop structure: one for rows, one for leading spaces, and one for stars.
* **Example (for N = 5):**
    ```
        *
       ***
      *****
     *******
    *********
    ```
* **Hints:**
    * You will need nested `for` loops.
    * The outer loop will control the rows (from 1 to `N`).
    * An inner loop is needed to print the leading spaces for each row. The number of spaces decreases as the row number increases.
    * Another inner loop is needed to print the stars. The number of stars is `2 * row_number - 1`.

---

## Exercise 4: Approximate exp(x)

<Transform scale="0.8">

* **Task:** Write a C program to approximate the value of $e^x$ using its Taylor series expansion:
  $e^{x}=\sum_{n=0}^{\infty}\frac{x^{n}}{n!} = 1 + \frac{x}{1!} + \frac{x^{2}}{2!} + \frac{x^{3}}{3!} + ...$
* **📝 Flowchart First:** Before coding, draw a flowchart that visualizes the iterative process of summing terms until the precision threshold is met.
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

</Transform>

---

## Exercise 5: Decimal Fraction to Binary

<Transform scale="0.8">

* **Task:** Convert a decimal fraction (a number between 0 and 1, e.g., 0.625) into its binary representation.
* **📝 Flowchart First:** Draw a flowchart to illustrate the "Multiply by 2" algorithm. Show how the loop continues and how each binary digit is determined.
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

</Transform>

---

## Exercise 6: Perfect Numbers

* **Task:** Find and print all **perfect numbers** within the range [1, 10000].
* **📝 Flowchart First:** A flowchart is required for this exercise. It should clearly show the nested loop structure for checking each number and summing its divisors.
* **Definition:** A perfect number is a positive integer that is equal to the sum of its proper positive divisors (the sum of its positive divisors excluding the number itself).
* **Example:** 6 is a perfect number because its proper divisors are 1, 2, and 3, and $1 + 2 + 3 = 6$. Another example is 28 ($1 + 2 + 4 + 7 + 14 = 28$).
* **Approach:**
    1. Use an outer loop to iterate through numbers `j` from 1 to 10000.
    2. For each `j`, use an inner loop to find all its proper divisors (`i` from 1 up to `j/2`).
    3. Sum these divisors.
    4. If the sum equals `j`, then `j` is a perfect number, so print it.

---
src: ../lectures/flow_chart_loop.md
---
---
src: ./assessment.md
---
