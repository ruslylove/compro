---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
---

# Computer Programming
## Lecture 2: Basic Data Types & Using Expressions

Presented by: Dr. Ruslee Sutthaweekul

Semester 1/2025

---

## Outline

1.  **Understanding Data Representation Basics**
2.  Exploring C Data Types
3.  Working with Variables and Constants
4.  Handling Variable Input and Output
5.  Using Data Operators and Building Expressions
6.  Understanding Implicit and Explicit Data Type Conversion

---
layout: image-right
image: https://control.com/uploads/articles/Hex_1.jpg
---

## How Computers See Everything: Binary

* Computers fundamentally represent everything using binary code (0s and 1s).
    * This includes data like whole numbers, decimal numbers, and text.
    * It also applies to program instructions.
* Memory locations (cells) are identified using sequential numerical addresses.
* Understanding how binary code is generated is essential.
* For readability, octal (base-8) and hexadecimal (base-16) notations are often used as shorthand for binary.

---

## Number System Conversions: Decimal to Others

* **Converting Decimal to Binary (Base-2):**
    * Example: 49 (decimal) becomes `110001` (binary).
* **Converting Decimal to Octal (Base-8):**
    * Example: 49 (decimal) becomes `61` (octal).
* **Converting Decimal to Hexadecimal (Base-16):**
    * Example: 49 (decimal) becomes `31` (hexadecimal).

Can you spot the relationship between these number systems?

---

## Number System Conversions: Practice (Part 2)

Your turn! Convert the decimal number 60 into:

* Binary code:
* Octal code:
* Hexadecimal code:

---

## Number System Conversions: Practice Solution 

Here's the solution for converting decimal 60:

* Binary code: `111100`
* Octal code: `74`
* Hexadecimal code: `3C`

---

## Number System Conversions: Visualizing

(Original diagrams illustrated the conversion process for 60)

* Decimal to binary conversion steps.
* Decimal to octal conversion steps.
* Decimal to hexadecimal conversion steps.

---

## Number System Conversions: Fractions

Converting a decimal fraction to binary, e.g., `0.3125`:



Resulting binary fraction : `0.0101`

$0 \times 2^{-1} + 1 \times 2^{-2} + 0 \times 2^{-3} + 1 \times 2^{-4} = 0.3125$

---

## Number System Conversions: Back to Decimal

* Binary `111100` to Decimal:
    * $1\times2^{5}+1\times2^{4}+1\times2^{3}+1\times2^{2}+0\times2^{1}+0\times2^{0}=60$
* Octal `74` to Decimal:
    * $7\times8^{1}+4\times8^{0}=60$
* Hexadecimal `3C` to Decimal:
    * $3\times16^{1}+12\times16^{0}=60$ (Note: C represents 12)

---

## How Data Resides in Memory (Part 1)

* Data within computer memory is always stored in binary.
* Consider the integer 49, which is `110001` in binary.
    * It might be stored like: `0 1 1 0 0 0 1` (leading bit might be 0 for positive).
* Consider -49, represented as `1110001` (using a sign bit).
    * It might be stored like: `1 1 1 0 0 0 1`.
* The highest-order bit (leftmost) is often used to indicate the sign (0 for positive, 1 for negative). This applies to real numbers as well.
* Numbers are typically stored using standard sizes like 8 bits (1 byte), 16 bits (2 bytes), etc.
    * Example (1 byte): `1 0 1 1 0 0 0 1`

---
layout: two-cols
---

## How Data Resides in Memory (Part 2)

* When multiple data items are stored, they occupy consecutive memory locations (assuming each uses 1 byte here).

:: right ::

<img src="https://computerscience.chemeketa.edu/cs160Reader/_images/memory.png">

---

## How Data Resides in Memory (Part 3)

* An important consideration: What is the range of numbers representable within a fixed size, like 1 byte (8 bits)?
* If no sign is used (unsigned): binary `00000000` to `11111111`.
    * This corresponds to decimal 0 to 255.
* With 1 byte, we can represent $2^8 = 256$ distinct values.
* Memory limitations mean we can only represent a finite range of numbers.

---

## How Data Resides in Memory (Part 4)

If one bit is dedicated to the sign, how many different numbers can we represent in 1 byte?

????

---

## How Data Resides in Memory (Part 5)

* With a sign bit, the range changes. Using 8 bits (1 for sign, 7 for magnitude):
    * Typically allows for positive numbers (e.g., 1 to 127).
    * And negative numbers (e.g., -1 to -128 using two's complement).
    * Total distinct values are still 256, including zero.
* Some numbers, like decimal 3.3137, can only be approximated in binary due to finite representation.
    * E.g., $11.0101$ in binary.

---

## Representing Negative Numbers: Complements

| Original (Decimal) | Binary (Conceptual) | One’s Complement | Two’s Complement |
|---|---|---|---|
| 23 | `00010111` | `00010111` | `00010111` |
| -23 | `10010111` (Sign-Mag) | `11101000` | `11101001` |
| 33 | `00100001` | `00100001` | `00100001` |
| -33 | `10100001` (Sign-Mag) | `11011110` | `11011111` |

* Positive numbers have the same representation in original, one's, and two's complement.
* **One's Complement:** Invert all bits (0->1, 1->0).
* **Two's Complement:** Invert all bits, then add 1. This is the standard way computers represent signed integers.
* Why use complements? They simplify subtraction by turning it into an addition operation.
* Try finding the one's and two's complement for -17.

---

## Outline

1.  Understanding Data Representation Basics
2.  **Exploring C Data Types**
3.  Working with Variables and Constants
4.  Handling Variable Input and Output
5.  Using Data Operators and Building Expressions
6.  Understanding Implicit and Explicit Data Type Conversion

---

## Fundamental Data Types in C

* **Basic (Primitive) Types:**
    * `int`: For integers (whole numbers).
    * `char`: For single characters (stored as numbers).
    * `float`: For single-precision floating-point numbers (decimals).
    * `double`: For double-precision floating-point numbers.
    * `enum`: For enumerated types (sets of named integer constants).
* **Derived (Constructed) Types:**
    * Arrays: Collections of same-type elements (e.g., `int a[3]`).
    * `struct`: Structures grouping different data types.
    * `union`: Unions allowing different data types in the same memory location.
* **Pointer Types:**
    * Variables storing memory addresses (e.g., `float *p`).

---

## Integer Types in C

* Keywords: `int`, `short int` (or `short`), `long int` (or `long`).
* Modifiers: `signed` (allows negative/positive, default) or `unsigned` (only non-negative).
* The exact byte size (and thus range) of `short`, `int`, `long` can vary depending on the system architecture (e.g., 32-bit vs 64-bit).

**Typical Ranges (32-bit system example):**
```c
int a;            // Range: approx -2.1 billion to +2.1 billion
short b;          // Range: -32,768 to 32,767
long c;           // Range: often same as int on 32-bit, wider on 64-bit
unsigned int a1;  // Range: 0 to approx 4.2 billion
unsigned short b1;// Range: 0 to 65,535
```

* Commonly: `int` and `long` are 4 bytes, `short` is 2 bytes on 32-bit systems.

---

## Visualizing Integer Type Sizes

* Keywords: `int`, `short`, `long`
* Can be `signed` or `unsigned`.
* Size depends on the system.

(Original diagram illustrated relative byte sizes)

**Typical Ranges Reminder:**
```c
int a;            // Range: approx -2.1 billion to +2.1 billion
short b;          // Range: -32,768 to 32,767
long c;           // Range: often same as int on 32-bit, wider on 64-bit
unsigned int a1;  // Range: 0 to approx 4.2 billion
unsigned short b1;// Range: 0 to 65,535
```

---

## Integer Type Examples

```c
int main() {
  // Using hexadecimal representation for clarity with bit patterns
  short a = 0x8000; // Smallest signed short (-32768)
  short b = 0x7FFF; // Largest signed short (32767)
  short c = 0xFFFE; // Represents -2 in two's complement
  char d = 0x80;    // Smallest signed char (-128)

  // Printing their decimal values
  printf("a = %d, b = %d, c = %d\n", a, b, c);
  printf("d = %d\n", d); // Prints the integer value of char d
  return 0;
}
```

*(Output shows the decimal equivalents based on two's complement representation)*

---

## The Issue of Integer Overflow (Part 1)

Consider this code. Is there a problem?

```c
int main() {
  // Max value for unsigned short is 65535
  unsigned short b = 65537;
  return 0;
}
```

---

## The Issue of Integer Overflow (Part 2)

Yes, there's a problem with:
```c
int main() {
  unsigned short b = 65537; // Trying to store 65537
  return 0;
}
```

* The variable `b` cannot actually hold 65537 because the maximum for `unsigned short` is 65535.
* **Overflow** occurs. For unsigned types, the value typically "wraps around".
* Calculation: `65537 % 65536 = 1`. So, `b` will likely hold the value `1`.

---

**What about this case?**
```c 
int main() {
  // Signed short max is 32767
  short b = 65537;
  // Overflow for signed types is technically "undefined behavior",
  // meaning the result isn't guaranteed by the C standard.
  // Often, it might wrap around based on the two's complement pattern.
  // 65537 in 16 bits is ...0001. As a signed short, this pattern is often 1.
  return 0;
}
```

---

## The Issue of Integer Overflow (Part 3)

* Overflow can happen with any fixed-size primitive data type (`int`, `float`, `char`, etc.).
* This is a consequence of using a limited number of bytes to store potentially unlimited values.
* Always be mindful of the potential range of values your variables might need to hold.
* Try to estimate the maximum possible value to choose an appropriate data type.

---

## Floating-Point Number Types (Part 1)

* Keywords: `float`, `double`, `long double`
* Used to represent real numbers (numbers with decimal parts).
* Like integers, they use a fixed number of bytes (`float`: usually 4, `double`: usually 8).
* This means they cannot represent *all* real numbers perfectly; there's limited range and precision.

<img src = "https://numeral-systems.com/media/ieee-754/ieee-754-floating-point.webp">
Example representation of `3.14159` as a `float`: `0 0000100 110010010000111111001110`

* Sign: 0 (positive)
* Exponent: Represents the scale
* Significand: Represents the significant digits

---

## Floating-Point Number Types (Part 2)

* Keywords: `float`, `double`, `long double`

```c
// Single-precision float
float x = 0.125;         /* Typically ~7 decimal digits of precision */

// Double-precision float
double y = 111111.111111; /* Typically ~15 decimal digits of precision */
```

* The `sizeof()` operator tells you the size (in bytes) of a type or variable:

```c
#include <stdio.h>

int main() {
  float x = 0.125;
  double y = 111111.111111;
  // Use %zu format specifier for sizeof results (which are type size_t)
  printf("Size of float: %zu bytes\n", sizeof(x));
  printf("Size of double: %zu bytes\n", sizeof(y));
}
```

*(Expected Output: Size of float: 4 bytes, Size of double: 8 bytes)*

---

## Character Type (Part 1)

* Keyword: `char`
* Can be `signed` (default on many systems) or explicitly `unsigned`.
* Standard Size: 1 Byte (8 bits) on nearly all systems.
* Designed to hold a single character (like 'A', '?', '5').
* Internally, it stores the character's numerical **ASCII** code (e.g., 'A' is stored as the integer 65).
* You can initialize a `char` using the number or the character literal:

```c
char letter_code = 65;  // Initialize with ASCII value
char letter_char = 'A'; // Initialize with character literal (use single quotes)
```

---

## Character Type (Part 2)

* A `char` uses its 1 byte (8 bits) to represent characters mapped to integers.
* The range is typically 0 to 255 (for `unsigned char`) or -128 to 127 (for `signed char`).
* The **ASCII** (American Standard Code for Information Interchange) table defines the standard mapping between common characters and integers (0-127).

---

## Character Type (Part 3): Common ASCII Values

You should recognize these common character codes:

| Character(s) | ASCII Value(s) |
|---|---|
| Digits `'0'` to `'9'` | 48 to 57 |
| Uppercase `'A'` to `'Z'` | 65 to 90 |
| Lowercase `'a'` to `'z'` | 97 to 122 |
| Space (`' '`) | 32 |
| Newline (`'\n'`) | 10 |
| Tab (`'\t'`) | 9 |

---

**Code Example:**
```c
#include <stdio.h>

int main() {
  // Print character 'A' and its ASCII value (65)
  printf("Char 'A': Value=%d Symbol=%c \n", 'A', 'A');
  // Print character '1' and its ASCII value (49)
  printf("Char '1': Value=%d Symbol=%c \n", '1', '1');
  // Print character with ASCII value 66 ('B')
  printf("Code 66: Value=%d Symbol=%c \n", 66, 66);
  // Print character with ASCII value 50 ('2')
  printf("Code 50: Value=%d Symbol=%c \n", 50, 50);
}
```

**Output:**
```text
Char 'A': Value=65 Symbol=A
Char '1': Value=49 Symbol=1
Code 66: Value=66 Symbol=B
Code 50: Value=50 Symbol=2
```

---

## Summary of Data Type Sizes

* `char`: 1 byte
* `short`: 2 bytes
* `int`: 4 bytes
* `long`: 4 bytes (32-bit system) or 8 bytes (64-bit system)
* `float`: 4 bytes
* `double`: 8 bytes

* Choose data types based on the required range and precision.
* Avoid using larger types like `double` or `long` unnecessarily, as it consumes more memory.
* Note: A "string" in C is not a primitive type; it's typically handled as an array of `char`.

---

## Outline

1.  Understanding Data Representation Basics
2.  Exploring C Data Types
3.  **Working with Variables and Constants**
4.  Handling Variable Input and Output
5.  Using Data Operators and Building Expressions
6.  Understanding Implicit and Explicit Data Type Conversion

---

## Naming Variables: Identifiers (Part 1)

Rules for valid variable names (identifiers) in C:
* Can contain letters (a-z, A-Z), digits (0-9), and the underscore (`_`).
* Must begin with a letter or an underscore. (Starting with an underscore is often reserved for system use, so prefer letters).
* Names are case-sensitive (`myVar` is different from `myvar`).
* Cannot be a C reserved keyword (like `int`, `float`, `return`, `while`, etc.).

---

Which are valid?
* `distance` ✓
* `milesPerHour` ✓
* `x-ray` × (Hyphen `-` is not allowed)
* `2ndGrade` × (Cannot start with a digit)
* `$amount` × (Dollar sign `$` is not allowed)
* `_2nd` ✓ (Starts with underscore)
* `two&four` × (Ampersand `&` is not allowed)
* `_hi` ✓
* `return` × (Reserved keyword)

---

## Naming Variables: Style Conventions (Part 2)

Good style practices:
* Use meaningful names that indicate the variable's purpose.
* Be consistent with naming conventions (choose one and stick to it):
    * `camelCaseIdentifiers` (start lowercase, capitalize inner words)
    * `snake_case_identifiers` (use underscores to separate words)
* Use indentation consistently (usually 4 spaces or one tab) to show code structure within blocks (`{}`).

---

Example:
```c
#include <stdio.h>

int main() {
  // Using snake_case and meaningful names
  float rectangle_width = 3.0;
  float rectangle_height = 5.0;
  float calculated_area = 0.0;

  calculated_area = rectangle_width * rectangle_height;
  printf("The calculated area is: %f\n", calculated_area);

  return 0; // Indicates successful execution
}
```

---

## Using Descriptive Variable Names

Avoid short, cryptic names that make code hard to understand.

**Less Clear:**
```c
/* Volume calc */
int a, b, c; // What are a, b, c?
a = 3;
b = 2;
// Problem: (1/3) uses integer division, resulting in 0!
c = (1/3) * a * a * b;
```

**Much Better:**
```c
/* Calculate the volume of a square pyramid */
float base_length, pyramid_height, volume; // Use float for non-integer results
base_length = 3.0;
pyramid_height = 2.0;
// Use floating-point division (1.0/3.0)
volume = (1.0 / 3.0) * base_length * base_length * pyramid_height;
```

---

## Defining Constants

* Use the `const` keyword before the data type when declaring a variable.
* This makes the variable a constant, meaning its value **cannot be changed** after initialization.
* Constants must be initialized when declared.

```c
const int MAX_USERS = 100;
const float PI_APPROX = 3.14159;
```
Example:
```c
#include <stdio.h>

int main() {
  const float PI = 3.14159;
  float radius = 3.0;
  float circle_area = 0.0;

  // PI = 3.14; // Error! Cannot assign to a const variable.

  circle_area = PI * radius * radius; // Use the constant
  printf("Area: %f\n", circle_area);
  return 0;
}
```

---
---

## Variables vs. Constants in Memory (Conceptual)

* `int some_var;`
    * Action: Allocates memory space for an integer.
    * Initial Value: Undefined (contains whatever bits were previously in that memory location - "garbage").
* `int count = 3;`
    * Action: Allocates memory space for an integer and initializes it with the value 3.
    * Value: Binary representation of 3 (`...0011`).
* `const int MAX_COUNT = 3;`
    * Action: Allocates memory space, initializes it to 3, and marks it as read-only.
    * Value: Binary representation of 3. Attempts to modify it later will cause a compile error.

---

## Outline

1.  Understanding Data Representation Basics
2.  Exploring C Data Types
3.  Working with Variables and Constants
4.  **Handling Variable Input and Output**
5.  Using Data Operators and Building Expressions
6.  Understanding Implicit and Explicit Data Type Conversion

---

## Outputting Values: `printf()` Basics (Part 1)

* Syntax: `printf("format string with %identifiers", argument1, argument2, ...);`
* A standard C library function (defined in `stdio.h`).
* Used to print formatted output to the console (screen).
* The "format string" contains regular text and special **identifiers** (like `%d`, `%f`, `%c`) that correspond to the arguments provided after the string.
---

**Code Example:**
```c
#include <stdio.h>

int main() {
  int score = 95;
  float average = 88.7;
  char grade = 'A';

  printf("Score: %d\n", score);       // %d for integer
  printf("Average: %f\n", average);   // %f for float/double
  printf("Grade: %c\n", grade);       // %c for character
  // Multiple identifiers matched with arguments in order
  printf("Result - Score: %d, Grade: %c\n", score, grade);
}
```

**Output:**
```text
Score: 95
Average: 88.700000
Grade: A
Result - Score: 95, Grade: A
```

---

## Outputting Values: `printf()` identifiers (Part 2)

* Identifier (like `%d`) specify where and how an argument's value should be inserted into the output string.
* Each identifier corresponds to one argument following the format string, in sequential order.
* The type of identifier must match the type of the data being printed (e.g., use `%d` for an `int`, `%f` for a `float`).
* You need exactly one argument for each identifier in the format string.

---

**Code Example:**
```c
#include <stdio.h>

int main() {
  int quantity = 3;
  int items = 5;
  float price = 7.40;
  // '\n' creates a newline in the output
  printf("Quantity: %d\nItems: %d\nPrice: %f\n", quantity, items, price);
}
```

**Output:**
```text
Quantity: 3
Items: 5
Price: 7.400000
```

---

## Common `printf()` Format Specifiers

| Specifier | Description | Argument Type |
|---|---|---|
| `%c` | Single character | `char` |
| `%d` or `%i` | Signed decimal integer | `int` (or types promotable to `int` like `char`, `short`) |
| `%u` | Unsigned decimal integer | `unsigned int` |
| `%x` or `%X` | Unsigned hexadecimal integer (lowercase/uppercase) | `unsigned int` |
| `%o` | Unsigned octal integer | `unsigned int` |
| `%ld` | Signed long decimal integer | `long int` |
| `%lu`, `%lx`, `%lo` | Unsigned long integer (dec, hex, oct) | `unsigned long int` |

---

| Specifier | Description | Argument Type |
|---|---|---|
| `%f` | Decimal floating-point | `float` or `double` (float is promoted to double) |
| `%lf` | (Often same as `%f` in `printf`) | `double` |
| `%e` or `%E` | Scientific notation (e.g., 1.23e+02) | `double` |
| `%g` or `%G` | Use `%f` or `%e` depending on value | `double` |
| `%s` | String (null-terminated character array) | `char *` |
| `%p` | Pointer address | `void *` |
| `%zu` | Size_t integer (for `sizeof` results) | `size_t` |
| `%%` | Literal percent sign | N/A |

---

## `printf()` Example: Different Representations

Printing the same data using various format specifiers:

**Code:**
```c {*}{maxHeight:'200px'}
#include <stdio.h>

int main() {
  int code_num = 79; // ASCII for 'O'
  char letter = 'n'; // ASCII is 110

  // Print as decimal integers
  printf("As decimals: code_num = %d, letter = %d\n", code_num, (int)letter);
  // Print as characters
  printf("As characters: code_num = %c, letter = %c\n", code_num, letter);
  // Print as hexadecimal integers
  printf("As hex: code_num = %x, letter = %x\n", code_num, (int)letter);
}
```

**Output:**
```text
As decimals: code_num = 79, letter = 110
As characters: code_num = O, letter = n
As hex: code_num = 4f, letter = 6e
```

---

## Special Characters: Escape Sequences (Part 1)

* How do we represent characters that don't have a simple visual symbol, like "Tab" or "Newline"?
* How do we print characters that have special meaning in C strings, like the double quote `"` or the backslash `\` itself?
* We use **escape sequences**, which start with a backslash (`\`).

---

## Special Characters: Escape Sequences (Part 2)

* The backslash (`\`) signals that the next character (or sequence) has a special meaning.

| Escape Sequence | Represents |
|---|---|
| `\n` | Newline (moves cursor to the next line) |
| `\t` | Horizontal Tab |
| `\b` | Backspace |
| `\r` | Carriage Return (moves cursor to beginning of current line) |
| `\\` | Literal Backslash (`\`) |

---

| Escape Sequence | Represents |
|---|---|
| `\'` | Literal Single Quote (`'`) |
| `\"` | Literal Double Quote (`"`) |
| `\0` | Null character (important for strings) |

* Important: An escape sequence like `\n` counts as a **single** character.
* You can use them in character literals too: `char newline_char = '\n';`

---

## Reading User Input: `scanf()`

* Syntax: `scanf("format string with %identifiers", &variable1, &variable2, ...);`
* Another standard C library function (from `stdio.h`).
* Reads formatted input from the standard input (usually the keyboard).
* Uses identifiers similar to `printf` to specify the expected type of input.
* **Crucially**, you must provide the **memory address** of the variable where the input should be stored, using the address-of operator `&`.

**Example:** Read an integer from the user into variable `i`.
```c
int i;
printf("Enter an integer: ");
scanf("%d", &i); // Reads an integer, stores it at the address of i
```

* Analogy: `scanf` is like a delivery service. You give it the format (`%d`) of the package to expect and the address (`&i`) where it should be delivered.

---

## Important Notes for `scanf()`

* Use format specifiers matching the variable types (e.g., `%d` for `int`, `%f` for `float`, `%lf` for `double`, `%c` for `char`).
* Always use the `&` operator before each variable name in the argument list (except for strings/arrays, which work differently).
* When reading numbers (`%d`, `%f`, etc.):
    * `scanf` typically skips leading whitespace (spaces, tabs, newlines).
    * It reads characters that form a valid number until it encounters whitespace or a character that doesn't fit the number format. That non-fitting character is left in the input buffer for the next `scanf` call.
    * Example: Input ` 123.45 abc`. If using `scanf("%d", &num);`, it reads `123`, stores it in `num`, and leaves `.45 abc` in the buffer.
* When reading with `%c`:
    * It reads the **very next character**, including whitespace. If the user pressed Enter after previous input, `%c` might read the newline character (`\n`). This is a common source of bugs.

---

## `scanf()` Example

Reading an integer and a floating-point number:

**Code:**
```c {all|7|10|12|14|all}{lines:true, maxHeight:'200px'}
#include <stdio.h>

int main() {
  int quantity = 0;
  float price = 0.0;

  printf("Initial values: quantity = %d, price = %f\n", quantity, price);

  // Prompt the user
  printf("Enter quantity (integer) and price (float), separated by space: ");
  // Read the input values into the variables' memory locations
  scanf("%d %f", &quantity, &price);

  printf("Values after input: quantity = %d, price = %f\n", quantity, price);
  return 0;
}
```

**Example Interaction:**
```text 
Initial values: quantity = 0, price = 0.000000
Enter quantity (integer) and price (float), separated by space: 15 9.99
Values after input: quantity = 15, price = 9.990000
```

---

## Outline

1.  Understanding Data Representation Basics
2.  Exploring C Data Types
3.  Working with Variables and Constants
4.  Handling Variable Input and Output
5.  **Using Data Operators and Building Expressions**
6.  Understanding Implicit and Explicit Data Type Conversion

---

## What are Expressions?

An expression in C is a valid combination of:
* **Constants:** Fixed values like `5`, `3.14`, `'A'`. (Includes `const` variables).
* **Variables:** Named storage locations like `count`, `average`, `initial_char`.
* **Operators:** Symbols that perform operations like `+`, `-`, `*`, `/`, `%`, `=`, `==`, `&&`.
* **Function Calls:** Executing functions that may return a value, e.g., `printf(...)`, `scanf(...)`, `sqrt(x)`.

Expressions evaluate to produce a value.

---

## Key Operators in C

* **Arithmetic:** `+` (add), `-` (subtract), `*` (multiply), `/` (divide), `%` (modulus/remainder).
* **Relational (Comparison):** `==` (equal to), `!=` (not equal to), `>` (greater than), `<` (less than), `>=` (greater or equal), `<=` (less or equal). Result is typically 1 (true) or 0 (false).
* **Logical:** `&&` (logical AND), `||` (logical OR), `!` (logical NOT). Used with true/false values.
* **Bitwise:** Operate on individual bits: `&` (AND), `|` (OR), `^` (XOR), `~` (NOT/complement).
* **Shift:** Move bits left or right: `<<` (left shift), `>>` (right shift).
* **Assignment:** `=` (assign), `+=`, `-=`, `*=`, `/=`, `%=` (compound assignment).
* **Increment/Decrement:** `++` (add 1), `--` (subtract 1).
* **Conditional (Ternary):** `condition ? value_if_true : value_if_false`.
* **Others:** `sizeof` (get size), `&` (address-of), `*` (dereference pointer), `.` (struct member access), `->` (pointer struct member access), `()` (grouping/function call), `[]` (array access).

---

## Arithmetic Operator Precedence

The order in which operations are performed matters.

**Simplified Precedence Rules:**

| Operator(s) | Operation | Precedence Level | How it Groups (Associativity) |
|---|---|---|---|
| `()` | Parentheses (Grouping) | Highest | Left-to-right |
| `*`, `/`, `%` | Multiplication, Division, Modulus | Medium | Left-to-right |
| `+`, `-` | Addition, Subtraction | Lowest | Left-to-right |

* Operations with higher precedence are performed first.
* If operators have the same precedence, they are usually evaluated left-to-right.
* Use parentheses `()` to override default precedence or make the order explicit and clear.

---

*Example:* Average of 1, 2, 4.
`1 + 2 + 4 / 3` is evaluated as `1 + 2 + (4 / 3)` -> `1 + 2 + 1` -> `4` (because `4/3` is integer division).

To get the correct average, use: `(1 + 2 + 4) / 3` or `(1.0 + 2.0 + 4.0) / 3.0`.

---

## Precedence Examples

How are these evaluated?

| Expression | Default Evaluation | Result (Often Wrong) | Intended Calculation (Example) | Correct Expression |
|---|---|---|---|---|
| `2 + 3 + 5 / 3` | `2 + 3 + (5 / 3)` -> `2 + 3 + 1` | `6` | Average | `(2 + 3 + 5) / 3` -> `3` |
| `5 * 2 + 6 % 2` | `(5 * 2) + (6 % 2)` -> `10 + 0` | `10` | Multiply 5 by `(2 + 6) % 2` | `5 * ((2 + 6) % 2)` -> `0` |

*Tip:* When in doubt, use parentheses `()` to enforce the order you intend.

---

## The Division Operator `/` (Part 1)

* The result type often depends on the operand types.
* **Integer Division:** If **both** operands are integers (`int`, `char`, `short`, `long`), the result is also an integer. The fractional part (remainder) is discarded (truncated).

| Expression | Result | Reason |
|---|---|---|
| `5 / 2` | `2` | 5 divided by 2 is 2.5, truncated to 2 |
| `17 / 5` | `3` | 17 divided by 5 is 3.4, truncated to 3 |
| `-7 / 3` | `-2` | -7 divided by 3 is -2.33..., truncated towards zero to -2 |

---

## The Division Operator `/` (Part 2)

* **Floating-Point Division:** If **at least one** operand is a floating-point type (`float`, `double`), the result is a floating-point type. The other operand is implicitly converted (promoted) to float/double if necessary.

| Expression | Result | Reason |
|---|---|---|
| `5.0 / 2` | `2.5` | `2` is promoted to `2.0`, result is `double` |
| `17 / 5.0` | `3.4` | `17` is promoted to `17.0`, result is `double` |
| `5.0 / 2.0`| `2.5` | Both are `double`, result is `double` |

---

## The Modulus Operator `%`

* The modulus operator (`%`) calculates the **remainder** of an integer division.
* Both operands **must** be integer types (`int`, `char`, etc.). Using it with `float` or `double` is an error.
* The sign of the result typically matches the sign of the first operand (dividend) in modern C standards (C99 onwards).

| Expression | Result | Explanation |
|---|---|---|
| `5 % 2` | `1` | 5 / 2 is 2 remainder 1 |
| `17 % 5` | `2` | 17 / 5 is 3 remainder 2 |
| `12 % 3` | `0` | 12 / 3 is 4 remainder 0 |
| `-5 % 2` | `-1` | -5 / 2 is -2 remainder -1 |
| `5 % -2` | `1` | 5 / -2 is -2 remainder 1 |

---

## Practice Evaluating Arithmetic (Part 1)

What are the results of these expressions?

| Expression | Result? |
|---|---|
| `11 / 2` | ? |
| `11 % 2` | ? |
| `11 / 2.0`| ? |
| `5.0 / 2` | ? |

---

## Practice Evaluating Arithmetic (Part 2) - Answers

Let's check the results:

| Expression | Result | Explanation |
|---|---|---|
| `11 / 2` | `5` | Integer division (11/2 = 5.5 -> truncated to 5) |
| `11 % 2` | `1` | Remainder of 11 divided by 2 |
| `11 / 2.0`| `5.5` | Floating-point division (11 promoted to 11.0) |
| `5.0 / 2` | `2.5` | Floating-point division (2 promoted to 2.0) |

---

## Translating Math to C Expressions (Part 1)

| Mathematical Notation | C Expression | Important Notes |
|---|---|---|
| $a \div b$ or $\frac{a}{b}$ | `a / b` | Assumes `a` and `b` are declared variables. Result type depends on `a` and `b`. |
| $2x$ | `2 * x` | Multiplication (`*`) must always be written explicitly. |
| $\frac{x - 7}{2 + 3y}$ | `(x - 7) / (2 + 3 * y)` | Parentheses are essential to enforce the correct order of operations (numerator and denominator evaluated separately before division). |

---

## Practice Evaluating C Expressions (Part 2)

Calculate the value of each C expression:

| C Expression | Value? |
|---|---|
| `2 * (-3)` | ? |
| `4 * 5 - 15` | ? |
| `4 + 2 * 5` | ? |
| `7 / 2` | ? |
| `7 / 2.0` | ? |
| `2 / 5` | ? |
| `2.0 / 5.0` | ? |
| `2 / 5 * 5` | ? |
| `2.0 + 1.0 + 5 / 2` | ? |
| `5 % 2` | ? |
| `4 * 5 / 2 + 5 % 2` | ? |

---

## Practice Evaluating C Expressions (Part 3) - Results

Check your answers:

| C Expression | Value | Explanation |
|---|---|---|
| `2 * (-3)` | `-6` | Multiplication |
| `4 * 5 - 15` | `5` | `(4 * 5) - 15` -> `20 - 15` |
| `4 + 2 * 5` | `14` | `4 + (2 * 5)` -> `4 + 10` |
| `7 / 2` | `3` | Integer division |
| `7 / 2.0` | `3.5` | Floating-point division |
| `2 / 5` | `0` | Integer division |
| `2.0 / 5.0` | `0.4` | Floating-point division |
| `2 / 5 * 5` | `0` | `(2 / 5) * 5` -> `0 * 5` (Evaluated left-to-right) |
| `2.0 + 1.0 + 5 / 2` | `5.0` | `2.0 + 1.0 + (5 / 2)` -> `2.0 + 1.0 + 2` -> `3.0 + 2` -> `5.0` |
| `5 % 2` | `1` | Modulus (remainder) |
| `4 * 5 / 2 + 5 % 2` | `11` | `((4 * 5) / 2) + (5 % 2)` -> `(20 / 2) + 1` -> `10 + 1` |

---

## Assigning Values to Variables

* The assignment operator (`=`) stores the value of the expression on the right into the variable on the left.
* Be mindful of data types. Assigning a value of one type to a variable of another type might cause implicit conversion or data loss.
* Assigning a floating-point value to an integer variable **truncates** (cuts off) the decimal part.

```c
int main() {
  int number;
  number = 2.99; // The float 2.99 is converted to int 2 before assignment.
  printf("number = %d\n", number); // Output will be 2
}
```
* While C allows this, it's often unintentional. Be careful when mixing types in assignments.

---

## Compound Assignment Operators (Part 1)

These provide a concise way to modify a variable based on its current value.

| Standard Form | Shortcut Equivalent | Meaning |
|---|---|---|
| `var = var + value;` | `var += value;` | Add `value` to `var` |
| `var = var - value;` | `var -= value;` | Subtract `value` from `var` |
| `var = var * value;` | `var *= value;` | Multiply `var` by `value` |
| `var = var / value;` | `var /= value;` | Divide `var` by `value` |
| `var = var % value;` | `var %= value;` | Assign remainder of `var / value` to `var` |
| `m = m * (5 + 3);` | `m *= (5 + 3);` or `m *= 8;` | Works with expressions too |
| `k = k / (5 + 1);` | `k /= (5 + 1);` or `k /= 6;` | Parentheses respected |

---

## Compound Assignment Operators (Part 2)

More Examples:
```c
int a = 10;
int b = 20;
int c = 5;

a += 4;   // Equivalent to: a = a + 4;   (a becomes 14)
a -= 4;   // Equivalent to: a = a - 4;   (a becomes 10 again)
a *= b;   // Equivalent to: a = a * b;   (a becomes 10 * 20 = 200)
b /= 4+2; // Equivalent to: b = b / (4+2); (b becomes 20 / 6 = 3)
c %= 2+3; // Equivalent to: c = c % (2+3); (c becomes 5 % 5 = 0)
```

---

## Increment and Decrement Operators (Part 1)

Special shortcuts for adding or subtracting 1.

* **Increment Operator:** `++`
    * `i++` (**post-increment**): Uses the *current* value of `i` in the expression, then increments `i` by 1.
    * `++i` (**pre-increment**): Increments `i` by 1 *first*, then uses the *new* value of `i` in the expression.
* **Decrement Operator:** `--`
    * `i--` (**post-decrement**): Uses the *current* value of `i`, then decrements `i` by 1.
    * `--i` (**pre-decrement**): Decrements `i` by 1 *first*, then uses the *new* value.
* When used alone as a statement (`i++;` or `++i;`), the effect is simply `i = i + 1`. The difference matters when used *within* a larger expression or assignment.

---

## Pre- vs. Post-Increment/Decrement (Part 2)

The difference is crucial when assigning the result or using it in comparisons:

* `a = i++;` (Post-increment)
    1.  The current value of `i` is assigned to `a`.
    2.  `i` is incremented by 1.
* `a = ++i;` (Pre-increment)
    1.  `i` is incremented by 1.
    2.  The new value of `i` is assigned to `a`.

(Similar logic applies to `--`)

---

**Example Walkthrough:**
```c
int main() {
  int a, b;
  int i = 4;

  // Post-increment example
  a = i++; // Step 1: a gets current value of i (4). Step 2: i becomes 5.
           // Result after this line: a=4, i=5

  // Pre-increment example
  b = ++i; // Step 1: i becomes 6. Step 2: b gets new value of i (6).
           // Result after this line: b=6, i=6

  // Final values: a = 4, b = 6, i = 6
}
```

---

## Pre- vs. Post-Decrement Example (Part 3)

Test your understanding with decrement:
```c
int main() {
  int a, b;
  int i = 4;

  // Post-decrement
  a = i--; // Step 1: a gets current i (4). Step 2: i becomes 3.
           // After this: a=4, i=3

  // Pre-decrement
  b = --i; // Step 1: i becomes 2. Step 2: b gets new i (2).
           // After this: b=2, i=2

  printf("Final: a = %d, b = %d\n", a, b);
}
```

**Output:**
```text
Final: a = 4, b = 2
```

---

## The Conditional (Ternary) Operator

* Syntax: `condition ? expression_if_true : expression_if_false`
* A shorthand way to express a simple if-else choice within an expression.
* It takes three operands:
    1.  `condition`: An expression evaluated as true (non-zero) or false (zero).
    2.  `expression_if_true`: The value the entire ternary expression takes if `condition` is true.
    3.  `expression_if_false`: The value the entire ternary expression takes if `condition` is false.

---

**Example:** Find the maximum of `b` and `i`.
```c
int main() {
  int a, b = 3, i = 4;

  // If (b > i) is true, a = b. Otherwise, a = i.
  a = (b > i) ? b : i; // (3 > 4) is false, so a gets the value of i (4).

  // If (b == 3) is true, set b to 2. Otherwise, set b to 1.
  b = (b == 3) ? 2 : 1; // (3 == 3) is true, so b gets the value 2.

  printf("Result: a = %d, b = %d\n", a, b);
}
```

**Output:**
```text
Result: a = 4, b = 2
```

---

## Outline

1.  Understanding Data Representation Basics
2.  Exploring C Data Types
3.  Working with Variables and Constants
4.  Handling Variable Input and Output
5.  Using Data Operators and Building Expressions
6.  **Understanding Implicit and Explicit Data Type Conversion**

---

## Implicit Type Conversion (Promotion)

* C often automatically converts values from "narrower" data types (like `char` or `int`) to "wider" types (like `float` or `double`) within expressions to avoid losing information during calculations. This is called **promotion**.
* Consider `char + int + float + double`:

```c
  char initial = 'x'; // ASCII value (e.g., 120)
  // Expression evaluation involves promotions:
  double result = initial + 5 + 1.3 + 17300.0;

  // Step 1: initial + 5
  //         'x' (char) promoted to int. Result is int.
  // Step 2: (int result) + 1.3
  //         int result promoted to double. Result is double.
  // Step 3: (double result) + 17300.0
  //         double + double. Result is double.
  // Step 4: result = (double result)
  //         Assignment is fine.
```
* These conversions happen implicitly (automatically).

---

* **Demotion** (converting wider to narrower, e.g., `double` to `int`) happens automatically during assignment but can lose data (truncation).
    ```c
    int count = 0;
    count = 5.1; // double 5.1 is implicitly converted to int 5.
                 // Fractional part is lost. Risky if not intended.
    ```

---

## Explicit Type Conversion (Casting)

* You can force a type conversion using the **cast operator**: `(target_type)expression`.
* This explicitly tells the compiler to treat the `expression`'s value as `target_type`.

```c
  char initial = 'x';
  double result = (float)initial + (float)5 + 1.3 + 17300.0;

  // Step 1: (float)initial -> char explicitly cast to float.
  // Step 2: (float)5      -> int explicitly cast to float.
  // Step 3: (float) + (float) -> Result is float.
  // Step 4: (float) + 1.3   -> float promoted to double (implicit). Result double.
  // Step 5: (double) + 17300.0 -> double + double. Result double.
  // Step 6: result = (double) -> Assignment.
```
* Casting to a narrower type explicitly is still risky and truncates data:
```c
    int rounded_down = 0;
    float exact_value = 5.9;
    rounded_down = (int)exact_value; // Cast forces conversion.
                                     // float 5.9 becomes int 5.
                                     // rounded_down gets value 5.
```

---

* If you need mathematical rounding (not truncation) when converting float to int, use functions from `math.h`:
   ```c
    #include <math.h> // Required for round(), floor(), ceil()

    int rounded_val = 0;
    float source_val = 5.9;
    // rounded_val = (int)round(source_val); // round(5.9) is 6.0. (int)6.0 is 6.
    // rounded_val = (int)floor(source_val); // floor(5.9) is 5.0. (int)5.0 is 5.
    // rounded_val = (int)ceil(source_val);  // ceil(5.9) is 6.0. (int)6.0 is 6.
    ```
