---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lecture 7 - Strings
---

# Lecture 7: Strings
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---
layout: two-cols
---

## Lecture Outline

1.  **Strings in C**
    *   Concept: Character Arrays
    *   The Null Terminator (`\0`)
2.  **String Initialization and I/O**
    *   Declaration and Initialization
    *   Basic I/O with `printf` and `scanf`
    *   Safer Input with `fgets`
3.  **Standard String Library (`<string.h>`)**
    *   Finding Length: `strlen`
    *   Copying: `strcpy` (unsafe) & `strncpy` (safer)
    *   Concatenation: `strcat` (unsafe) & `strncat` (safer)
    *   Comparison: `strcmp`

:: right ::

4.  **Strings and Functions**
    *   Passing Strings to Functions
5.  **Arrays of Strings**
    *   Declaration and Processing
    *   Passing Arrays of Strings to Functions
6.  **Advanced String Examples**
    *   Example 1: Palindrome Checker
    *   Example 2: String Tokenization (`strtok`)
    *   Example 3: Basic String to Integer (`atoi`)

---

## Introduction to Strings in C

* C does not have a built-in string data type like some other languages (e.g., Python, Java).
* Instead, strings are represented and manipulated as **arrays of characters (`char`)**.
* **Convention:** A C string is terminated by a special character called the **null character**, which has an ASCII value of 0 and is represented as `\0`.
* This null terminator marks the end of the string data within the character array.
* The size of the `char` array must be large enough to hold all the characters of the string **plus** the null terminator (`\0`).

---

## Declaring and Initializing Strings

* Declare a `char` array of sufficient size.
* Initialize using:
    1.  **String Literal:** Enclose the characters in double quotes `""`. The compiler automatically adds the null terminator `\0`.
        ```c
        char greeting[20] = "Hello"; // Array size 20, stores 'H','e','l','l','o','\0'
                                     // Size needed: 5 chars + 1 null = 6. 20 is plenty.
        char empty_string[] = ""; // Stores only '\0', size is 1.
        ```
    2.  **Character Array Initializer:** List individual characters, **explicitly including `\0`**.
        ```c
        char name[] = {'J', 'o', 'h', 'n', '\0'}; // Equivalent to "John"
        ```

**Memory Representation for `char greeting[20] = "Hello";`**
```
Index: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ... | 19 |
Value: |'H'|'e'|'l'|'l'|'o'|'\0'| ? | ... | ?  |
                                  (Unused/Garbage)
```

* The null terminator `\0` is crucial for standard string functions to know where the string ends.

---
layout: two-cols
---

## String Input/Output (`scanf`, `printf`)

* Use the `%s` format specifier with `printf` and `scanf` to work with strings.
* **`printf("%s", char_array);`**: Prints characters from the array starting at the given address until it encounters the null terminator `\0`.
* **`scanf("%s", char_array);`**: Reads characters from standard input (keyboard) and stores them into the `char_array`.
    * It automatically adds the null terminator `\0` after the characters read.


:: right ::

* **WARNING:** `scanf("%s", ...)` stops reading at the first whitespace character (space, tab, newline). More importantly, it **does not check the size of the array**. If the user types more characters than the array can hold, it will cause a **buffer overflow** - a major security vulnerability!

    ```c {*}
    #include <stdio.h> 

    int main() {
        char name[10]; // Small buffer to demonstrate the danger

        printf("Enter your name: ");
        scanf("%s", name); // DANGEROUS! If user types "Christopher", it overflows.

        printf("Hello, %s!\n", name);
        return 0;
    }
    ```

---
layout: two-cols
---

## Safer String Input: `fgets`

* A much safer way to read strings is with `fgets()`.
* **Syntax:** `fgets(char *buffer, int size, FILE *stream);`
    * `buffer`: The character array to store the string.
    * `size`: The maximum number of characters to read (including the null terminator). This prevents buffer overflows.
    * `stream`: The input source (e.g., `stdin` for keyboard).
* **Behavior:**
    * Reads characters until a newline `\n` is found, `EOF` is reached, or `size - 1` characters have been read.


:: right ::

* **Includes the newline character `\n`** in the buffer if it was read. You often need to remove it.
* Always null-terminates the string.
    ```c {*}
    #include <stdio.h>
    #include <string.h> // For strcspn

    #define BUFFER_SIZE 20

    int main() {
        char full_name[BUFFER_SIZE];

        printf("Enter your full name: ");
        if (fgets(full_name, BUFFER_SIZE, stdin) != NULL) {
            // Remove the trailing newline, if it exists
            full_name[strcspn(full_name, "\n")] = 0;
            
            printf("Welcome, %s!\n", full_name);
        }
        return 0;
    }
    ```

---

## Standard String Library (`<string.h>`)

* C provides a standard library for common string operations. You must `#include <string.h>` to use them.
* These functions rely on the null terminator `\0` to know where strings end.

| Function | Description |
| :--- | :--- |
| `strlen(str)` | Returns the length of `str` (excluding `\0`). |
| `strcpy(dest, src)` | Copies `src` to `dest`. **UNSAFE** - no size check. |
| `strncpy(dest, src, n)` | Copies at most `n` characters. Safer, but may not null-terminate. |
| `strcat(dest, src)` | Appends `src` to `dest`. **UNSAFE** - no size check. |
| `strncat(dest, src, n)` | Appends at most `n` characters. Safer, always null-terminates. |
| `strcmp(str1, str2)` | Compares two strings lexicographically. |

---
layout: two-cols
---

## `strlen()` and `strcmp()`

* `strlen()`: Returns the number of characters before the `\0`.
* `strcmp()`: Compares strings alphabetically.
    * Returns `< 0` if `str1` comes before `str2`.
    * Returns `0` if `str1` is equal to `str2`.
    * Returns `> 0` if `str1` comes after `str2`.

:: right ::

```c {*}
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "apply";
    
    printf("Length of \"%s\" is %zu\n", str1, strlen(str1)); // Output: 5

    int comparison = strcmp(str1, str2);

    if (comparison == 0) {
        printf("\"%s\" and \"%s\" are equal.\n", str1, str2);
    } else if (comparison < 0) {
        printf("\"%s\" comes before \"%s\".\n", str1, str2);
    } else {
        printf("\"%s\" comes after \"%s\".\n", str1, str2);
    }
    // Output: "apple" comes before "apply".
    return 0;
}
```

---
layout: two-cols
---


## `strcpy()` and `strcat()` (Unsafe vs. Safer)

* **Unsafe versions (`strcpy`, `strcat`)** are a common source of bugs and security holes because they don't check if the destination buffer is large enough.
* **Safer versions (`strncpy`, `strncat`)** are preferred. They take a size argument to prevent writing past the end of the buffer.

:: right ::

```c {*}
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello";
    char src[] = ", World!";

    // Using the safer strncat
    // dest size - strlen(dest) - 1 gives remaining space for new chars
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("Concatenated: %s\n", dest); // Output: Hello, World!

    char new_dest[10];
    char long_src[] = "This is a very long string";

    // Using the safer strncpy
    strncpy(new_dest, long_src, sizeof(new_dest) - 1);
    new_dest[sizeof(new_dest) - 1] = '\0'; // Manually ensure null termination
    printf("Copied: %s\n", new_dest); // Output: This is a
    
    return 0;
}
```

---
layout: two-cols
---

## Passing Strings to Functions

*   Since strings are character arrays, they follow the same rules as passing other arrays to functions: they are **passed by reference**.
*   The function receives the memory address of the first character of the string.
*   This means the function can **directly modify** the original string in the calling function.
*   In a function parameter list, `char str[]` is equivalent to `char *str`.
*   Use `const char str[]` if the function should not modify the string. This is good practice for read-only operations.

:: right ::

```c {*}
#include <stdio.h>
#include <ctype.h> // For toupper()

// This function modifies the string in-place
void to_uppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char message[] = "hello world";
    
    printf("Original: %s\n", message);
    to_uppercase(message); // Pass the string (its address)
    printf("Uppercase: %s\n", message); // The original is changed

    return 0;
}
```

---

## Arrays of Strings

* An array of strings is essentially a 2D array of characters.
* **Declaration:** `char array_name[num_strings][max_string_length];`

```c {4-23}{maxHeight:'360px',lines:true}
#include <stdio.h>
#include <string.h>

int main() {
    // An array that can hold 4 strings, each up to 19 chars + null
    char names[4][20] = {
        "Alice",
        "Bob",
        "Charlie",
        "David"
    };

    // Print all names
    for (int i = 0; i < 4; i++) {
        printf("Name %d: %s\n", i + 1, names[i]);
    }

    // Modify a string in the array
    strcpy(names[1], "Robert");
    printf("\nAfter modification: %s\n", names[1]);

    return 0;
}
```

---
layout: two-cols
---

## Passing Arrays of Strings to Functions

*   To pass a 2D character array (an array of strings) to a function, you must specify the size of the second dimension (the max string length).
*   This is because the compiler needs to know the column size to calculate memory offsets.
*   **Syntax:** `void function_name(char arr[][MAX_LEN], int num_strings)`

:: right ::

```c {*}
#include <stdio.h>

#define NUM_NAMES 4
#define MAX_NAME_LEN 20

// The second dimension size (20) must be specified
void print_names(char names[][MAX_NAME_LEN], int size) {
    printf("--- List of Names ---\n");
    for (int i = 0; i < size; i++) {
        printf("- %s\n", names[i]);
    }
}

int main() {
    char names[NUM_NAMES][MAX_NAME_LEN] = {
        "Alice", "Bob", "Charlie", "David"
    };
    print_names(names, NUM_NAMES);
    return 0;
}
```
---
layout: two-cols
---

## Example 1: Palindrome Checker

*   A **palindrome** is a word or phrase that reads the same forwards and backwards (e.g., "racecar", "madam").
*   **Algorithm:**
    1.  Use two indices: `left` starting at the beginning (0) and `right` starting at the end (`strlen(str) - 1`).
    2.  In a loop, compare the characters at `str[left]` and `str[right]`.
    3.  If they are ever different, it's not a palindrome.
    4.  If they are the same, move the pointers closer: `left++`, `right--`.
    5.  Stop when `left` is no longer less than `right`.

:: right ::

```c {*}
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // For bool type

// Use const because we are not modifying the string
bool is_palindrome(const char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Mismatch found
        }
        left++;
        right--;
    }
    return true; // All characters matched
}

int main() {
    char test1[] = "racecar";
    char test2[] = "hello";
    printf("\"%s\" is a palindrome? %s\n", test1, is_palindrome(test1) ? "Yes" : "No");
    printf("\"%s\" is a palindrome? %s\n", test2, is_palindrome(test2) ? "Yes" : "No");
    return 0;
}
```

---
layout: two-cols
---

## Example 2: String Tokenization (`strtok`)

*   **Tokenization** is the process of breaking a string into smaller parts (tokens) based on a set of delimiters (like space, comma, etc.).
*   The `<string.h>` library provides `strtok()` for this.
*   **`char *strtok(char *str, const char *delims);`**
    *   **First call:** `strtok(original_string, " ,.-");`
        *   Finds the first token.
        *   It **modifies the original string** by placing `\0` where the delimiter was found.

:: right ::

*   **Subsequent calls:** `strtok(NULL, " ,.-");`
    *   Continues searching from where it left off.
    *   Returns `NULL` when no more tokens are found.



```c {*}{maxHeight:'360px',lines:true}
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "C is a powerful, general-purpose language.";
    const char delimiters[] = " ,.-"; // Space, comma, dot, hyphen
    
    printf("Original: \"%s\"\n", sentence);
    printf("Tokens:\n");

    // Get the first token
    char *token = strtok(sentence, delimiters);

    // Loop through the rest of the tokens
    while (token != NULL) {
        printf("  - %s\n", token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}
```

---
layout: two-cols
---

## Example 3: Basic String to Integer (`atoi`)

*   Often you need to convert a string of digits (e.g., `"123"`) into its integer equivalent (e.g., `123`).
*   The standard library has `atoi()` in `<stdlib.h>`, but implementing a simple version is a great exercise.
*   **Algorithm:**
    1.  Initialize an integer `result = 0`.
    2.  Iterate through each character of the string.
    3.  For each character, multiply the current `result` by 10.
    4.  Convert the character to its digit value (`'5' - '0' = 5`) and add it to `result`.
:: right ::

*   `result = result * 10 + (str[i] - '0');`



```c {*}{maxHeight:'430px',lines:true}
#include <stdio.h>

// A simple version of atoi, handles positive integers only
int simple_atoi(const char str[]) {
    int result = 0;
    int i = 0;

    // Iterate through each character of the string
    while (str[i] != '\0') {
        // Check if it's a digit
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            // Handle non-digit characters if necessary (e.g., break)
            break; 
        }
        i++;
    }
    return result;
}

int main() {
    char num_str[] = "1998";
    int value = simple_atoi(num_str);
    printf("String \"%s\" as an integer is %d\n", num_str, value);
    printf("Calculation: %d * 2 = %d\n", value, value * 2);
    return 0;
}
```

---
layout: two-cols
---

## Summary

*   **C Strings:** Are null-terminated (`\0`) character arrays. The array must be large enough for the characters plus the null terminator.
*   **String I/O:**
    *   `printf("%s", ...)` is used for output.
    *   `scanf("%s", ...)` is simple but **unsafe** due to buffer overflow risk.
    *   `fgets()` is the preferred, safer method for reading string input.
*   **`<string.h>` Library:** Provides essential functions (`strlen`, `strcmp`, `strncpy`, `strncat`, etc.) that operate on null-terminated strings.

::right::

*   **Passing to Functions:**
    *   Strings (as `char[]` or `char*`) are passed by reference, allowing functions to modify the original string.
    *   Arrays of strings (`char arr[][LEN]`) can also be passed, but the second dimension's size must be specified.
*   **Arrays of Strings:** Can be implemented as 2D character arrays, e.g., `char names[10][50];`.

<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="lab7" title="Go to Lab7 👩‍🔬"/>
</div>