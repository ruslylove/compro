---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 3 - if-else and switch-case
class: lab
---

# Computer Programming
## Lab 3: if-else and switch-case

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Lab Outline

1.  Exercise using `if-else` clauses.
2.  Exercise using nested `if-else` clauses.
3.  Exercise using `switch-case` statements.

---

## Exercise 1: Character Classification (`if-else`)

* **Task:** Write a C program that reads a single character input from the user and classifies it according to the following rules using `if-else if-else` statements:
    1.  If the character is a digit (`'0'` through `'9'`), print `"It is a digit"`.
    2.  If the character is a lowercase letter (`'a'` through `'z'`), convert it to its corresponding uppercase letter and print the uppercase letter.
    3.  If the character is an uppercase letter (`'A'` through `'Z'`), print the character directly.
    4.  If the character is a space (`' '`), print `"It is blank"`.
    5.  For any other character, print `"It is not a visible character"`.
* **Hints:**
    * Use `scanf("%c", &your_char_var);` to read a single character.
    * Compare character variables using relational operators (e.g., `your_char >= 'a'`).
    * Remember the ASCII relationship between lowercase and uppercase letters for conversion.

---

## Lab Outline

1.  Exercise using `if-else` clauses.
2.  **Exercise using nested `if-else` clauses.**
3.  Exercise using `switch-case` statements.

---

## Exercise 2: Sports Recommendation (Nested `if-else`)

* **Task:** Write a C program that recommends a sport based on a student's gender and height.
* **Input:**
    * Gender: A single character, `'m'` for male or `'f'` for female.
    * Height: A positive floating-point number representing height in meters.
* **Logic:** Use nested `if-else` statements to implement the following rules:
    * **If gender is female (`'f'`):**
        * If height is less than 1.6m, recommend `"Taiji"`.
        * Otherwise (height >= 1.6m), recommend `"Volleyball"`.
    * **If gender is male (`'m'`):**
        * If height is less than 1.7m, recommend `"Football"`.
        * Otherwise (height >= 1.7m), recommend `"Basketball"`.
* **Output:** Print only the name of the recommended sport.
* **Example:** Input `'m'` and `1.75` should result in the output `"Basketball"`.

---

## Lab Outline

1.  Exercise using `if-else` clauses.
2.  Exercise using nested `if-else` clauses.
3.  **Exercise using `switch-case` statements.**

---

## Exercise 3: Simple Calculator (`switch-case`)

* **Task:** Write a C program that acts as a simple calculator.
* **Input:**
    1.  An integer number.
    2.  An operator character (`+`, `-`, `*`, `/`).
    3.  Another integer number.
* **Processing:**
    * Use a `switch-case` statement based on the operator character read.
    * Perform the corresponding arithmetic operation (`+`, `-`, `*`, `/`) on the two integers.
    * **Important:** For division (`/`), explicitly check if the second number (divisor) is zero. If it is, print an error message like `"Error: Division by zero"` instead of performing the division.
* **Output:** Print the calculated result of the operation, or the error message for division by zero.
