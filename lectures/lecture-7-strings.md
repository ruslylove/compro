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
4.  **Arrays of Strings**
    *   Declaration and Processing

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

## Summary

*   **C Strings:** Are null-terminated (`\0`) character arrays. The array must be large enough for the characters plus the null terminator.
*   **String I/O:**
    *   `printf("%s", ...)` is used for output.
    *   `scanf("%s", ...)` is simple but **unsafe** due to buffer overflow risk.
    *   `fgets()` is the preferred, safer method for reading string input as it limits the number of characters read.
*   **`<string.h>` Library:** Provides essential functions for string manipulation.
    *   `strlen()`: Finds the length.
    *   `strcmp()`: Compares two strings.
    *   `strcpy()` / `strcat()`: Unsafe copy/concatenation. **Avoid if possible.**
    *   `strncpy()` / `strncat()`: Safer versions that require a size limit.
*   **Arrays of Strings:** Can be implemented as 2D character arrays.

<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="lecture-8-struct-union-and-enum" title="Go to Lecture 8 ➡️"/>
</div>