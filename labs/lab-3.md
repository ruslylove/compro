---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 3 - if-else and switch-case
class: lab
routeAlias: lab3
---

# {{ $slidev.configs.subject }}
## Lab 3: if-else and switch-case

Presented by {{ $slidev.configs.presenter }}

Semester {{ $slidev.configs.semester }}

---

## Lab Outline

* **Exercise 1: Character Classification (`if-else`)**
    * Use an `if-else if-else` ladder to classify user input.
* **Exercise 2: Sports Recommendation (Nested `if-else`)**
    * Use nested `if-else` to handle dependent conditions.
* **Exercise 3: Simple Calculator (`switch-case`)**
    * Use a `switch-case` statement for multi-way branching based on an operator.
* **Exercise 4: Leap Year Checker (`if-else`)**
    * Use logical operators (`&&`, `||`) to check for leap year conditions.
* **Exercise 5: Vowel or Consonant (`switch-case`)**
    * Use `switch-case` fall-through to handle multiple conditions.
* **Exercise 6: Triangle Type Identifier (Nested `if-else`)**
    * Combine nested `if` with an `if-else if` ladder to classify triangle types.

---

## Objectives

* **Master conditional logic with `if-else` statements**
    * Build `if-else if-else` ladders for multi-way decisions.
    * Implement nested `if-else` structures for dependent conditions.
    * Formulate complex logical expressions using `&&` and `||` (e.g., leap year logic).
    * Combine validation checks with classification logic (e.g., triangle inequality).
* **Utilize the `switch-case` statement for selection**
    * Select code paths based on character or integer values.
    * Leverage `switch-case` fall-through to efficiently group similar cases (e.g., vowels).
    * Handle specific edge cases within a `case` block (e.g., division by zero).
* **Apply character and number properties**
    * Classify characters and numbers based on their properties and ASCII values.
    * Perform character case conversion.

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

## Exercise 2: Sports Recommendation (Nested `if-else`)

<Transform scale="0.9">


* **Task:** Write a C program that recommends a sport based on a student's gender and height.
* **📝 Flowchart First:** Before writing any code, you are required to draw a flowchart to visualize the program's logic.
* **Input:**
    * Gender: A single character, `'m'` for male or `'f'` for female.
    * Height: A positive floating-point number representing height in meters.
* **Logic:** Use nested `if-else` statements to implement the following rules:
    * **If gender is female (`'f'`):**
        * If height is less than 1.6m, recommend `"TaiChi"`.
        * Otherwise (height >= 1.6m), recommend `"Volleyball"`.
    * **If gender is male (`'m'`):**
        * If height is less than 1.7m, recommend `"Football"`.
        * Otherwise (height >= 1.7m), recommend `"Basketball"`.
* **Output:** Print only the name of the recommended sport.
* **Example:** Input `'m'` and `1.75` should result in the output `"Basketball"`.

</Transform>


---

## Exercise 3: Simple Calculator (`switch-case`)

* **Task:** Write a C program that acts as a simple calculator.
* **📝 Flowchart First:** Before coding, draw a flowchart for this exercise. Make sure it visualizes the `switch` logic and the special check for division by zero.
* **Input:**
    1.  An integer number.
    2.  An operator character (`+`, `-`, `*`, `/`).
    3.  Another integer number.
* **Processing:**
    * Use a `switch-case` statement based on the operator character read.
    * Perform the corresponding arithmetic operation (`+`, `-`, `*`, `/`) on the two integers.
    * **Important:** For division (`/`), explicitly check if the second number (divisor) is zero. If it is, print an error message like `"Error: Division by zero"` instead of performing the division.
* **Output:** Print the calculated result of the operation, or the error message for division by zero.

---

## Exercise 4: Leap Year Checker

* **Task:** Write a C program to check if a given year is a leap year.
* **Input:** An integer representing the year.
* **Logic:** A year is a leap year if it meets one of the following conditions:
    1.  It is divisible by 4 but **not** by 100.
    2.  It is divisible by 400.
* **Hint:** Use logical operators `&&` (AND) and `||` (OR) to combine these conditions in a single `if` statement. The condition can be expressed as `(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)`.
* **Output:** Print `"Leap Year"` or `"Not a Leap Year"`.

---

## Exercise 5: Vowel or Consonant

* **Task:** Write a C program that checks if a given alphabet character is a vowel or a consonant.
* **Input:** A single character.
* **Logic:**
    * Use a `switch-case` statement on the input character (you may want to convert it to lowercase first for simplicity).
    * The vowels are 'a', 'e', 'i', 'o', 'u'.
    * Use the **fall-through** feature to group all vowel cases together to execute the same code.
    * The `default` case can handle consonants.
    * **Challenge:** Add an initial `if` check to ensure the input is an alphabet character before using the `switch`.
* **Output:** Print `"Vowel"` or `"Consonant"` (or `"Not an alphabet"` if you add the check).

---

## Exercise 6: Triangle Type Identifier

<Transform scale="0.9">

* **Task:** Write a C program that takes three floating-point numbers representing the lengths of the sides of a triangle and determines if it is equilateral, isosceles, or scalene.
* **📝 Flowchart First:** A flowchart is required for this exercise. It should clearly show the initial validation check (triangle inequality) and the subsequent classification steps.
* **Input:** Three `float` values: `side1`, `side2`, `side3`.
* **Logic:**
    1.  **Validation First (Nested `if`)**: Check if the given sides can form a valid triangle using the **triangle inequality theorem**: the sum of the lengths of any two sides must be greater than the length of the third side. If not, print an error like `"Invalid triangle"`.
        * `(side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)`
    2.  **Classification (if valid)**:
        *   If all three sides are equal, it's `"Equilateral"`.
        *   Else if any two sides are equal, it's `"Isosceles"`.
        *   Else (no sides are equal), it's `"Scalene"`.
* **Output:** Print the type of triangle or the error message.



</Transform>

<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="assessment" title="Go to Assessment Rubric 📝"/>
</div>

---
src: ../lectures/flow_chart_selection.md
---





