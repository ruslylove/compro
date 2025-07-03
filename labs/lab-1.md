---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 1 - Introduction to C Programming
class: lab
---

# Computer Programming
## Lab 1: Introduction to C Programming

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025


---

## Objectives

* **Familiarize yourself with the IDE (Dev C++)**
    * Learn how to create a new project, write code, compile, and run a program.
* **Understand and use simple expressions in C**
    * Perform basic arithmetic operations.
    * Assign values to variables.
* **Handle basic input and output operations**
    * Display information to the user using `printf()`.
    * Read input from the user using `scanf()`.

---

## Your Toolkit: The IDE

### What is an IDE?

An **I**ntegrated **D**evelopment **E**nvironment is a software application that provides comprehensive facilities to computer programmers for software development. Think of it as your all-in-one workbench for coding.

For this lab, we'll use **Dev C++**, a popular and simple IDE for beginners.

<img src="https://miro.medium.com/v2/resize:fit:254/1*8eQPCaYTvieOUxBxFAeBTw.png" style="margin:auto">

---

## Getting Started with Dev C++

1.  **Open Dev C++:** Launch the application.
2.  **Create a New Source File:**
    * Go to `File > New > Source File` or press `Ctrl+N`.
3.  **Write Your Code:** An empty editor will appear. This is where you'll type your C program.
4.  **Save Your File:**
    * Go to `File > Save As` or press `Ctrl+S`.
    * **Crucially, save your file with a `.c` extension** (e.g., `hello.c`).
5.  **Compile and Run:**
    * Go to `Execute > Compile & Run` or press `F11`.
    * Dev C++ will first compile your code (check for errors) and then run it if everything is correct. A console window will pop up to show your program's output.

---

## Simple Expressions in C

Expressions in C are combinations of values, variables, and operators that result in a single value.

### Arithmetic Operators

| Operator | Description      | Example       | Result |
| :------: | ---------------- | ------------- | :----: |
|   `+`    | Addition         | `5 + 3`       | `8`    |
|   `-`    | Subtraction      | `5 - 3`       | `2`    |
|   `*`    | Multiplication   | `5 * 3`       | `15`   |
|   `/`    | Division         | `5 / 3`       | `1`    |
|   `%`    | Modulus (remainder) | `5 % 3`    | `2`    |

---

## Variables and Expressions

Variables are used to store data. We can use expressions to calculate values and store them in variables.

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;
    int sum;
    int product;

    // Simple expression for addition
    sum = a + b;

    // Simple expression for multiplication
    product = a * b;

    printf("The sum is: %d\n", sum);
    printf("The product is: %d\n", product);

    return 0;
}
```

-----

## Input and Output in C

We need a way to communicate with our program.

  * **Output:** `printf()` - "prints" or displays information to the console.
  * **Input:** `scanf()` - "scans" or reads input from the user via the console.

To use these, you **must** include the standard input/output library: `#include <stdio.h>`

-----

## The `printf()` Function

The `printf()` function displays formatted output.

**Syntax:** `printf("format string", argument1, argument2, ...);`

The "format string" can contain text and **format specifiers**. Format specifiers are placeholders for the values of variables.

### Common Format Specifiers

| Specifier | Data Type |
| :-------: | --------- |
|   `%d`    | `int`     |
|   `%f`    | `float`   |
|   `%lf`   | `double`  |
|   `%c`    | `char`    |

**Example:**

```c
int age = 25;
printf("I am %d years old.", age);
```

**Output:**

```
I am 25 years old.
```

-----

## The `scanf()` Function

The `scanf()` function reads formatted input from the user.

**Syntax:** `scanf("format specifier", &variable_name);`

Notice the ampersand `&` before the variable name. This is the "address-of" operator, and it tells `scanf()` where to store the input value in memory. **It is essential\!**

**Example:**

```c
int user_age;

printf("Please enter your age: ");
scanf("%d", &user_age);

printf("You entered: %d\n", user_age);
```

-----

## Lab Exercise 1: Simple Calculator

Write a C program that does the following:

1.  Declares two integer variables, `num1` and `num2`.
2.  Prompts the user to enter the first number and stores it in `num1`.
3.  Prompts the user to enter the second number and stores it in `num2`.
4.  Calculates the sum, difference, product, and quotient of the two numbers.
5.  Prints the results of these calculations to the screen in a clear and readable format.

-----

## Solution: Simple Calculator

```c
#include <stdio.h>

int main() {
    int num1, num2;

    // Get input for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get input for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform calculations and print the results
    printf("Sum: %d + %d = %d\n", num1, num2, num1 + num2);
    printf("Difference: %d - %d = %d\n", num1, num2, num1 - num2);
    printf("Product: %d * %d = %d\n", num1, num2, num1 * num2);
    
    // Note: Integer division truncates the decimal part.
    printf("Quotient: %d / %d = %d\n", num1, num2, num1 / num2);

    return 0;
}
```

-----

## Lab Exercise 2: ASCII Art Name Tag 🏷️

**Your Task**: Create a program that asks for the user's name and their favorite single character. The program should then print their name inside a decorative ASCII art box made from that character.

**Example Interaction:**

```
Enter your name: BMO
Choose a character for the border: #
```

**Example Output:**

```
##########
#        #
#  BMO   #
#        #
##########
```

**Hint**: You will need to use `printf()` multiple times. Think about how to print the name with spaces around it.

-----

## Solution: ASCII Art Name Tag

```c
#include <stdio.h>

int main() {
    // 1. Declare variables for the name and border character
    char name[20]; // A string to hold the name, 20 chars max
    char border_char;

    // 2. Prompt for and read the user's name
    printf("Enter your name: ");
    scanf("%s", name); // For simple strings, %s works without &

    // 3. Prompt for and read the border character
    // Note the space before %c to consume any leftover newline from the previous scanf
    printf("Choose a character for the border: ");
    scanf(" %c", &border_char);

    // 4. Print the ASCII art box
    printf("\n"); // Add a space for neatness
    printf("%c%c%c%c%c%c%c%c%c%c\n", border_char, border_char, border_char, border_char, border_char, border_char, border_char, border_char, border_char, border_char);
    printf("%c        %c\n", border_char, border_char);
    printf("%c  %s   %c\n", border_char, name, border_char); // Print the name inside
    printf("%c        %c\n", border_char, border_char);
    printf("%c%c%c%c%c%c%c%c%c%c\n", border_char, border_char, border_char, border_char, border_char, border_char, border_char, border_char, border_char, border_char);

    return 0;
}
```


-----

## Lab Exercise 3: Build-A-Pet 🐾

**Your Task**: Let's create a better ASCII art cat. Write a program that asks the user for three characters to customize the cat's face: one for the eyes, one for the nose, and one for the whiskers. Display the customized cat using their characters.

**Example Interaction:**

```
Enter a character for the eyes: o
Enter a character for the nose: .
Enter a character for the whiskers: ~
```

**Example Output:**

```
  /\_/\
 ( o o )
 ~  .  ~
```

-----

## Solution: Build-A-Pet

```c {*}{maxHeight:'440px'}
#include <stdio.h>

int main() {
    // 1. Declare variables for the cat's features
    char eye_char, nose_char, whisker_char;

    // 2. Prompt for and get all inputs from the user
    // Note the leading space in " %c" to handle newlines correctly
    printf("Enter a character for the eyes: ");
    scanf(" %c", &eye_char);

    printf("Enter a character for the nose: ");
    scanf(" %c", &nose_char);

    printf("Enter a character for the whiskers: ");
    scanf(" %c", &whisker_char);

    // 3. Print the customized ASCII cat
    // To print one backslash '\', you must type two: '\\'.
    printf("\n"); // Adds a clean line before the output
    printf("  /\\_/\\\n");
    printf(" ( %c %c )\n", eye_char, eye_char);
    printf(" %c  %c  %c\n", whisker_char, nose_char, whisker_char);

    return 0;
}
```

---

## Assessment Criteria

This rubric evaluates your lab submission across four key areas:
1.  **Correctness & Functionality** (Does it work?)
2.  **Code Quality & Readability** (Is it well-written?)
3.  **Logic & Problem-Solving** (Is the approach sound?)
4.  **Adherence to Requirements** (Did you follow instructions?)

---

## Grading Scale

| **Level** | **Points** | **Description** |
| --------------------- | :--------: | ---------------------------------------------------------------------------- |
| **Excellent** |  `90-100`  | Exceeds all requirements; demonstrates deep understanding and elegant code.   |
| **Good** |  `80-89`   | Meets all requirements; code is functional and well-written.                 |
| **Satisfactory** |  `70-79`   | Meets most requirements; minor errors or areas for improvement exist.        |
| **Needs Improvement** |  `60-69`   | Fails to meet several key requirements; significant errors or misconceptions. |
| **Unsatisfactory** |   `< 60`   | The submission is incomplete or fundamentally flawed.                        |

---

## Detailed Rubric

### 1. Correctness & Functionality (40 Points)

| **Level** | **Points** | **Description** |
| --------------------- | :--------: | ------------------------------------------------------------------------------------------------------------ |
| **Excellent** |  `36-40`   | Program compiles without errors or warnings. Produces correct output for all test cases, including edge cases. |
| **Good** |  `32-35`   | Program compiles and runs. Produces correct output for most standard test cases. Minor errors on edge cases.   |
| **Satisfactory** |  `28-31`   | Program compiles, but may have minor runtime errors. Output is mostly correct but fails on several test cases. |
| **Needs Improvement** |  `24-27`   | Program fails to compile or has significant runtime errors. Output is consistently incorrect.                |
| **Unsatisfactory** |   `< 24`   | Program is non-functional or does not compile at all.                                                        |

---

### 2. Code Quality & Readability (30 Points)

| **Level** | **Points** | **Description** |
| --------------------- | :--------: | ---------------------------------------------------------------------------------------------------------------------- |
| **Excellent** |  `27-30`   | Code is clean, well-formatted, and easy to follow. Uses meaningful variable names. Includes clear and concise comments. |
| **Good** |  `24-26`   | Code is readable with consistent formatting. Variable names are adequate. Some comments are present where needed.      |
| **Satisfactory** |  `21-23`   | Code has inconsistent formatting or unclear variable names, making it somewhat difficult to read. Comments are sparse. |
| **Needs Improvement** |  `18-20`   | Code is poorly formatted and very difficult to understand. No meaningful variable names or comments.                 |
| **Unsatisfactory** |   `< 18`   | Code is a single block of unformatted text; completely unreadable.                                                     |

---

### 3. Logic & Problem-Solving (20 Points)

| **Level** | **Points** | **Description** |
| --------------------- | :--------: | ---------------------------------------------------------------------------------------------------------------- |
| **Excellent** |  `18-20`   | The chosen algorithm is efficient and elegant. Demonstrates a deep understanding of the underlying concepts.       |
| **Good** |  `16-17`   | The logic is sound and effectively solves the problem. The implementation is correct and logical.                |
| **Satisfactory** |  `14-15`   | The logic has minor flaws or is unnecessarily complex, but it generally works.                                   |
| **Needs Improvement** |  `12-13`   | The approach contains significant logical errors. The student's understanding of the problem seems limited.      |
| **Unsatisfactory** |   `< 12`   | The logic is fundamentally flawed or completely missing.                                                         |

---

### 4. Adherence to Requirements (10 Points)

| **Level** | **Points** | **Description** |
| --------------------- | :--------: | ---------------------------------------------------------------------------------------------------------------- |
| **Excellent** |   `10`     | All submission instructions were followed perfectly (e.g., file naming, format, including a README if required). |
| **Good** |    `8-9`   | Minor deviation from one instruction (e.g., slightly incorrect file name).                                       |
| **Satisfactory** |    `7`     | Multiple minor deviations from instructions.                                                                     |
| **Needs Improvement** |    `6`     | A major requirement was missed (e.g., wrong file type submitted).                                                |
| **Unsatisfactory** |    `< 6`   | Submission instructions were largely ignored.                                                                    |
