---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
---

# Computer Programming
## Lecture 3: Sequential and Conditional Program Flow

Presented by: Dr. Ruslee Sutthaweekul

Semester 1/2025

---

## Lecture Outline

1.  **Development Environments (Editors & IDEs)**
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
    * Including Logical Operators
6.  Working with Conditions

---

## Tools for Programming

* **Integrated Development Environments (IDEs):** Combine editor, compiler, debugger, etc.
    * Microsoft Visual Studio (Common default on Windows)
    * Dev-C++ (Recommended lightweight option)
    * Visual Studio Code (VSCode - Popular versatile editor with extensions)
    * Code::Blocks (Cross-platform IDE)
* **Text Editors + Compilers:** A more manual approach.
    * Use any text editor (Notepad++, Sublime Text, Vim, Emacs, etc.).
    * Pair with a C compiler:
        * Microsoft C compiler (Often part of Visual Studio)
        * GCC (GNU Compiler Collection - Recommended, standard on Linux/macOS)
        * ICC (Intel C Compiler - Known for optimization)
        * Turbo C (Historically significant, less common now)

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  **Fundamental Components of C Programs**
3.  Basic Program Structure
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
    * Including Logical Operators
6.  Working with Conditions

---

## Revisiting the First Program

* Create a file, typically named `main.c`.
* Use a text editor to write the code:

```c
// Include standard input/output library definitions
#include <stdio.h>

// Define the main function where execution begins
int main() { // Start of the main function block
    // Use printf to display text on the screen
    printf("Hello World!\n");

    // Indicate successful program termination
    return 0;
} // End of the main function block
```

---

## Key Program Components Explained

* **`#include <stdio.h>`:** This is a **preprocessor directive**. It instructs the compiler to include the contents of the `stdio.h` file, which contains declarations for standard input/output functions like `printf`.
* **`int main() { ... }`:** This defines the required **`main` function**. Program execution always starts here. `int` signifies that the function returns an integer value to the operating system. The curly braces `{}` enclose the function's code block.
* **`printf("Hello World!\n");`:** This is a **statement** that calls the `printf` function to display output. The text within the double quotes is the argument, and `\n` represents a newline character. Statements typically end with a semicolon `;`.
* **`return 0;`:** Another **statement** that exits the `main` function and returns the value `0` (conventionally meaning success) to the operating system.

---

## Other Essential Program Elements

* **Variables:** Named storage locations for data (e.g., `int age = 25;`). We covered these in the previous lecture.
* **Comments:** Explanatory text ignored by the compiler.
    * Multi-line comments: Start with `/*` and end with `*/`.
    * Single-line comments: Start with `//` and continue to the end of the line. Comments are crucial for making code understandable.

```c
/* This is a
   multi-line comment. */
int score = 100; // This is a single-line comment.
```

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  **Basic Program Structure**
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
    * Including Logical Operators
6.  Working with Conditions

---

## Basic C Program Structure

A typical simple C program follows this structure:

```c
// 1. Preprocessor Directives (like #include)
#include <stdio.h>
// ... other includes if needed ...

// 2. The main Function (entry point)
int main() { // Start of main block
    // 3. Variable Declarations (optional, but good practice)
    //    int number;
    //    float price;

    // 4. Program Statements (instructions to be executed)
    //    number = 10;
    //    price = 9.99;
    printf("Executing program...\n");
    //    ... more statements ...

    // 5. Return Statement (usually 0 for success)
    return 0;
} // End of main block
```

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  **Sequential Program Execution**
5.  Conditional Execution (`if-else`)
    * Including Logical Operators
6.  Working with Conditions

---

## Sequential Control Flow

* By default, C programs execute statements one after another, in the order they appear in the code, from top to bottom within a block (`{}`).
* This straightforward, step-by-step execution is called **sequential control**.

```c
#include <stdio.h>

int main() {
    printf("Step 1\n"); // This runs first
    printf("Step 2\n"); // This runs second
    printf("Step 3\n"); // This runs third
    return 0;
}
```

---

## Example: Swapping Two Variables (Sequential)

**Problem:** Swap the values stored in two integer variables, `a` and `b`.

**Incorrect Approach:**
```c
int a = 3, b = 5;
a = b; // Now a is 5
b = a; // Now b is also 5 (original value of a is lost!)
```

**Correct Approach (Using a temporary variable):**
```c {*}{lines:true, maxHeight:'120px'}
#include <stdio.h>

int main() {
    int a = 3, b = 5;
    int temp; // Temporary storage

    printf("Before swap: a = %d, b = %d\n", a, b);

    // Swap logic
    temp = a; // Store original value of a in temp (temp = 3)
    a = b;    // Assign value of b to a (a = 5)
    b = temp; // Assign original value of a (from temp) to b (b = 3)

    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
```

*Output:*
```text
Before swap: a = 3, b = 5
After swap: a = 5, b = 3
```

---

## Example: Calculating Circle Area (Sequential)

**Problem:** Calculate the area of a circle given its radius. Formula: Area = π * r²

```c
#include <stdio.h>

int main() {
    // Define PI as a constant
    const float PI = 3.14159;
    float radius;
    float area;

    // Get radius from user
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculate area (sequential steps)
    area = PI * radius * radius;

    // Display the result
    printf("The area of the circle is: %f\n", area);

    return 0;
}
```

*This program follows a sequence: define constants/variables, get input, calculate, display output.*

---

## Example: Fahrenheit to Celsius (Sequential)

**Problem:** Convert a temperature from Fahrenheit to Celsius. Formula: C = (F - 32) * 5 / 9

```c
#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    // Get Fahrenheit temperature from user
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Perform conversion calculation
    // Note: Using 5.0/9.0 ensures floating-point division
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

    // Display the Celsius temperature
    printf("Temperature in Celsius: %.2f\n", celsius); // %.2f formats to 2 decimal places

    return 0;
}
```

*Again, the steps are executed in order: get input, calculate, display output.*

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  Sequential Program Execution
5.  **Conditional Execution** (`if-else`)
    * Including Logical Operators
6.  Working with Conditions

---

## Conditional Control Flow

* Sequential execution isn't always sufficient. Often, programs need to make **decisions** based on certain conditions.
* We need the ability to execute different blocks of code depending on whether a condition is true or false.
* This is achieved using **conditional control** statements.

---

## The `if` Clause (Simple Form)

* Executes a block of code **only if** a specified condition is true (evaluates to non-zero).
* **Syntax:**
    ```c
    if (condition) {
        // Statements to execute if condition is true
        statement1;
        statement2;
        // ...
    }
    // Execution continues here regardless of the condition
    ```
* The `condition` is typically an expression that results in a true (non-zero) or false (zero) value, often using relational operators (`>`, `<`, `==`, etc.).
* If the condition is false (0), the entire block within the `{}` is skipped.
* Curly braces `{}` are technically optional if there's only one statement inside, but using them is **highly recommended** for clarity and avoiding errors.

---

## Simple `if` Example

**Problem:** Print a message only if a number is positive.

```c
#include <stdio.h>

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    // Check if the number is greater than 0
    if (number > 0) {
        // This block executes only if number > 0 is true
        printf("The number %d is positive.\n", number);
    }

    printf("End of program.\n"); // This always executes
    return 0;
}
```

---

## The `if-else` Clause

* Executes one block of code if a condition is true, and a *different* block if the condition is false.
* **Syntax:**
    ```c
    if (condition) {
        // Block 1: Executes if condition is true
        statementA1;
        statementA2;
    } else {
        // Block 2: Executes if condition is false
        statementB1;
        statementB2;
    }
    // Execution continues here after either Block 1 or Block 2 runs
    ```
* Exactly one of the two blocks (the `if` block or the `else` block) will be executed.

---

## `if-else` Example

**Problem:** Determine if a number is even or odd.

```c
#include <stdio.h>

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    // Check if the remainder when divided by 2 is 0
    if (number % 2 == 0) {
        // Condition is true: Number is even
        printf("%d is an even number.\n", number);
    } else {
        // Condition is false: Number is odd
        printf("%d is an odd number.\n", number);
    }

    return 0;
}
```

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
    * **Relational & Equality Operators**
    * Logical Operators
6.  Working with Conditions

---

## Conditions: Relational Operators

* Used to compare two values. Result is `1` (true) or `0` (false).

| Operator | Meaning                  | Example (`a=5`, `b=3`) | Result |
| :------- | :----------------------- | :--------------------- | :----- |
| `>`      | Greater than             | `a > b` (5 > 3)        | `1`    |
| `<`      | Less than                | `a < b` (5 < 3)        | `0`    |
| `>=`     | Greater than or equal to | `a >= 5` (5 >= 5)      | `1`    |
| `<=`     | Less than or equal to    | `b <= 2` (3 <= 2)      | `0`    |

---

## Conditions: Equality Operators

* Used to check if two values are equal or not equal. Result is `1` (true) or `0` (false).

| Operator | Meaning       | Example (`a=5`, `b=3`, `c=5`) | Result |
| :------- | :------------ | :---------------------------- | :----- |
| `==`     | Equal to      | `a == c` (5 == 5)             | `1`    |
| `!=`     | Not equal to  | `a != b` (5 != 3)             | `1`    |
| `==`     | Equal to      | `a == b` (5 == 3)             | `0`    |
| `!=`     | Not equal to  | `a != c` (5 != 5)             | `0`    |

**Common Mistake:** Using single `=` (assignment) instead of double `==` (equality comparison) in conditions. `if (a = 5)` assigns 5 to `a` and the condition becomes `if (5)`, which is always true! Use `if (a == 5)`.

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
    * Relational & Equality Operators
    * **Logical Operators**
6.  Working with Conditions

---

## Conditions: Logical Operators

* Used to combine or modify true/false conditions. Operate on values treated as true (non-zero) or false (zero). Result is `1` (true) or `0` (false).

| Operator | Meaning     | Example (`a=1`, `b=0`) | Result |
| :------- | :---------- | :--------------------- | :----- |
| `&&`     | Logical AND | `a && a` (T && T)      | `1`    |
| `&&`     | Logical AND | `a && b` (T && F)      | `0`    |
| `&&`     | Logical AND | `b && b` (F && F)      | `0`    |
| &#124;&#124;     | Logical OR  | `a` &#124;&#124; `a` (T &#124;&#124; T)      | `1`    |
| &#124;&#124;     | Logical OR  | `a` &#124;&#124; `b` (T &#124;&#124; F)      | `1`    |
| &#124;&#124;     | Logical OR  | `b` &#124;&#124; `b` (F &#124;&#124; F)      | `0`    |
---

| Operator | Meaning     | Example (`a=1`, `b=0`) | Result |
| :------- | :---------- | :--------------------- | :----- |
| `!`      | Logical NOT | `!a` (!T)              | `0`    |
| `!`      | Logical NOT | `!b` (!F)              | `1`    |

---

## Logical AND (`&&`)

* `condition1 && condition2` is true (`1`) **only if both** `condition1` and `condition2` are true (non-zero).
* **Short-circuiting:** If `condition1` evaluates to false (`0`), `condition2` is **not evaluated** because the overall result must be false.

**Truth Table:**

| condition1 | condition2 | `condition1 && condition2` |
| :--------- | :--------- | :------------------------- |
| False (0)  | False (0)  | False (0)                  |
| False (0)  | True (!=0) | False (0)                  |
| True (!=0) | False (0)  | False (0)                  |
| True (!=0) | True (!=0) | True (1)                   |

---

## Logical OR (`||`)

* `condition1 || condition2` is true (`1`) **if at least one** of `condition1` or `condition2` is true (non-zero).
* **Short-circuiting:** If `condition1` evaluates to true (`1`), `condition2` is **not evaluated** because the overall result must be true.

**Truth Table:**

| condition1 | condition2 | `condition1` &#124;&#124; `condition2` |
| :--------- | :--------- | :------------------------- |
| False (0)  | False (0)  | False (0)                  |
| False (0)  | True (!=0) | True (1)                   |
| True (!=0) | False (0)  | True (1)                   |
| True (!=0) | True (!=0) | True (1)                   |

---

## Logical NOT (`!`)

* `!condition` reverses the logical value of `condition`.
* If `condition` is true (non-zero), `!condition` is false (`0`).
* If `condition` is false (`0`), `!condition` is true (`1`).

**Truth Table:**

| condition  | `!condition` |
| :--------- | :----------- |
| False (0)  | True (1)     |
| True (!=0) | False (0)    |

---

## Operator Precedence (Including Logical)

Logical operators have lower precedence than relational/equality operators, which have lower precedence than arithmetic operators. `!` has higher precedence than `&&` and `||`. `&&` has higher precedence than `||`.

**Simplified Order (Highest to Lowest):**

1.  `!` (Logical NOT), `++`, `--` (Unary operators)
2.  `*`, `/`, `%` (Multiplicative)
3.  `+`, `-` (Additive)
4.  `<`, `<=`, `>`, `>=` (Relational)
5.  `==`, `!=` (Equality)
6.  `&&` (Logical AND)
7.  `||` (Logical OR)
8.  `=` (Assignment operators)

*Use parentheses `()` to clarify or override precedence.*
Example: `a > b && c < d` is evaluated as `(a > b) && (c < d)`.

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
6.  Working with Conditions
    * **Combining Operators**
    * Common Mistakes

---

## Combining Operators Example

**Problem:** Check if a number `x` is within the range [0, 10] (inclusive).

```c
int x = 5;
// Condition: x >= 0 AND x <= 10
if (x >= 0 && x <= 10) {
    printf("x is in the range [0, 10]\n");
} else {
    printf("x is outside the range [0, 10]\n");
}
```

**Problem:** Check if a character `ch` is NOT a vowel (uppercase or lowercase).

```c
char ch = 'b';
if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
      ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
    printf("%c is not a vowel.\n", ch);
} else {
    printf("%c is a vowel.\n", ch);
}
```

*(Alternatively, check if it IS a vowel and use the else block)*

---

## Common Mistake: `=` vs `==`

* Assignment (`=`): Stores a value in a variable. The expression itself evaluates to the value assigned.
* Equality (`==`): Compares two values. Evaluates to `1` (true) or `0` (false).

```c
int a = 0;

// Incorrect: Assignment used in condition
if (a = 5) { // Assigns 5 to 'a'. Condition becomes 'if (5)', which is TRUE.
    printf("This will always print if a = 5 is used!\n");
}

// Correct: Equality comparison used in condition
if (a == 5) { // Compares current value of 'a' with 5.
    printf("This prints only if a was already 5.\n");
}
```

*This is a frequent bug! Always double-check `=` vs `==` inside conditions.*

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
    * **Nested** `if-else`
    * `switch` statement
6.  Working with Conditions

---

## Nested `if-else` Clauses

* You can place `if` or `if-else` statements inside the blocks of other `if` or `else` statements. This allows for more complex decision-making structures.

**Syntax Example:**
```c
if (condition1) {
    // Code for condition1 being true
    if (condition2) {
        // Code for condition1 AND condition2 being true
    } else {
        // Code for condition1 true BUT condition2 false
    }
} else {
    // Code for condition1 being false
    if (condition3) {
        // Code for condition1 false BUT condition3 true
    } else {
        // Code for condition1 false AND condition3 false
    }
}
```

* Indentation is crucial for readability but doesn't affect the logic. The `else` always pairs with the nearest unmatched `if` unless braces `{}` dictate otherwise.

---

## Nested `if-else` Example: Max of Three

**Problem:** Find the largest of three numbers: `a`, `b`, `c`.

```c {*}{lines:true, maxHeight:'380px'}
#include <stdio.h>

int main() {
    int a = 10, b = 25, c = 15;
    int max;

    if (a > b) {
        // a is potentially the max (a > b)
        if (a > c) {
            max = a; // a > b and a > c
        } else {
            max = c; // c >= a and a > b => c is max
        }
    } else {
        // b is potentially the max (b >= a)
        if (b > c) {
            max = b; // b >= a and b > c
        } else {
            max = c; // c >= b and b >= a => c is max
        }
    }

    printf("The maximum value is: %d\n", max); // Output: 25
    return 0;
}
```

---

## The `if-else if-else` Ladder

* A common pattern for checking multiple mutually exclusive conditions in sequence.

**Syntax:**
```c
if (condition1) {
    // Block 1: Executes if condition1 is true
} else if (condition2) {
    // Block 2: Executes if condition1 false AND condition2 true
} else if (condition3) {
    // Block 3: Executes if cond1/cond2 false AND condition3 true
} // ... potentially more else if blocks
else {
    // Optional Final Else Block:
    // Executes if ALL preceding conditions were false
}
```

* Only one block in the entire ladder will be executed.

---

## `if-else if-else` Example: Grading

**Problem:** Assign a letter grade based on a score.

```c
#include <stdio.h>

int main() {
    int score = 75;
    char grade;

    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) { // Only checked if score < 90
        grade = 'B';
    } else if (score >= 70) { // Only checked if score < 80
        grade = 'C';
    } else if (score >= 60) { // Only checked if score < 70
        grade = 'D';
    } else { // Only runs if score < 60
        grade = 'F';
    }

    printf("Score: %d, Grade: %c\n", score, grade); // Output: Score: 75, Grade: C
    return 0;
}
```

---

## Lecture Outline

1.  Development Environments (Editors & IDEs)
2.  Fundamental Components of C Programs
3.  Basic Program Structure
4.  Sequential Program Execution
5.  Conditional Execution (`if-else`)
    * Nested `if-else`
    * **`switch` statement**
6.  Working with Conditions
---

## The `switch` Statement

* Provides an alternative way to select one code path from many, based on the value of an **integer** or **character** expression.
* Often clearer than long `if-else if` ladders when checking against multiple specific constant values.
* **Syntax:**
    ```c
    switch (expression) { // expression must evaluate to integer/char
        case constant_value_1:
            // Statements for case 1
            break; // IMPORTANT: Exits the switch
        case constant_value_2:
            // Statements for case 2
            break; // Exits the switch
        // ... more cases
        default: // Optional
            // Statements if no case matches
            break; // Optional but good practice
    }
    ```

---

## `switch` Statement Details 

* `expression`: The integer or character value to be checked.
* `case constant_value:`: Defines a label. The code following this label executes *if* `expression` matches `constant_value`. The value must be a constant known at compile time (literal like `1`, `'A'`, or a `const` variable).
* `break;`: **Crucial!** This statement causes execution to jump out of the `switch` block.
* **Fall-through:** If you **omit** `break`, execution will continue ("fall through") into the statements of the *next* `case` label below it. This is sometimes intentional but often a bug if forgotten.
* `default:`: An optional label. The code here executes if *none* of the other `case` values match the `expression`.

---

## `switch` Example: Month Names

**Problem:** Print the name of the month based on its number (1-12).

```c {*}{lines:true, maxHeight:'380px'}
#include <stdio.h>

int main() {
    int month_num = 3;

    switch (month_num) {
        case 1: printf("January\n"); break;
        case 2: printf("February\n"); break;
        case 3: printf("March\n"); break; // This case matches
        case 4: printf("April\n"); break;
        case 5: printf("May\n"); break;
        case 6: printf("June\n"); break;
        case 7: printf("July\n"); break;
        case 8: printf("August\n"); break;
        case 9: printf("September\n"); break;
        case 10: printf("October\n"); break;
        case 11: printf("November\n"); break;
        case 12: printf("December\n"); break;
        default: printf("Invalid month number\n"); break; // Handles numbers outside 1-12
    }
    // Output: March
    return 0;
}
```

---

## `switch` vs `if-else if` 

* Use `switch` when:
    * You are checking a single integer or character variable/expression against multiple **constant** values.
    * It often results in cleaner code than a long `if-else if` chain for this specific scenario.
* Use `if-else if` when:
    * You need to check complex conditions involving ranges (e.g., `score >= 90`).
    * You are comparing non-integer types (like floats, though direct equality check for floats is often problematic).
    * The conditions are not based on simple equality with constants.
