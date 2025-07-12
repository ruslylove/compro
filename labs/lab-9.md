---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 9 - Pointers and File Operations
class: lab
routeAlias: lab9
---

# Computer Programming
## Lab 9: Pointers and File Operations

Presented by {{ $slidev.configs.presenter }}

Semester {{ $slidev.configs.semester }}

---

## Objectives

*   **Master pointer fundamentals and arithmetic**
    *   Declare, initialize, and dereference pointers.
    *   Use pointer arithmetic to navigate arrays efficiently without using array indices.
*   **Use pointers with functions and arrays**
    *   Pass pointers to functions to allow direct modification of caller data (pass-by-reference).
    *   Implement algorithms using pointer notation for array access.
*   **Perform fundamental file I/O operations**
    *   Open, read from, write to, and close text files.
    *   Use `fopen`, `fprintf`, `fgetc`, and `fclose`.
    *   Handle file-related errors, such as a failure to open a file.
*   **Manage memory dynamically**
    *   Allocate and free memory on the heap using `malloc` and `free`.

---

## Lab Outline

*   **Exercise 1: Flip Array Elements using Pointers**
    *   Modify an array in-place using pointer arithmetic.
*   **Exercise 2: Calculate Dot Product using Pointers**
    *   Access multiple arrays in parallel using pointers.
*   **Exercise 3: Alphabet Frequency from File**
    *   Combine file reading with array manipulation.
*   **Exercise 4: Simple File Writing**
    *   Practice creating and writing to a new file.
*   **Exercise 5: Dynamic Array with `malloc`**
    *   Learn to allocate memory at runtime.
*   **Exercise 6: Copy a File**
    *   Read from one file and write the contents to another.

---

## Exercise 1: Flip Array Elements using Pointers

*   **Task:** Create a function `void flip(int *a, int sz)` that reverses an integer array *in place*.
*   **📝 Flowchart First:** Draw a flowchart for the `flip` function. It should visualize the two-pointer swapping logic.
*   **Requirements:**
    1.  The function must use pointer arithmetic (e.g., `*p`, `p++`), not array indexing (`a[i]`).
    2.  Use two pointers, one at the start and one at the end, moving towards the center and swapping elements.
    3.  In `main`, declare an array, print it, call `flip`, and print it again.
*   **Example:** `{11, 4, 31, 2, 5}` becomes `{5, 2, 31, 4, 11}`.

---

## Exercise 2: Calculate Dot Product using Pointers

*   **Task:** Define a function `float dotprod(float *a, float *b, int sz)` that calculates the dot product of two float arrays.
*   **📝 Flowchart First:** Draw a flowchart for the `dotprod` function, showing the loop that accumulates the sum using pointers.
*   **Dot Product:** $result = \sum_{i=0}^{sz-1} a_i \times b_i$
*   **Requirements:**
    1.  Use pointers, not array indexing, to iterate through the arrays.
    2.  Return the resulting `float` dot product.
    3.  In `main`, create two float arrays, call `dotprod`, and print the result.

---

## Exercise 3: Alphabet Frequency from File

*   **Task:** Read text from `input.txt` and count the frequency of each letter (case-insensitive).
*   **📝 Flowchart First:** Draw a high-level flowchart showing the main steps: Open File -> Loop (Read Char -> Process Char) -> Close File -> Print Results.
*   **Requirements:**
    1.  Open `input.txt` in read mode (`"r"`). Handle file opening errors.
    2.  Read the file character by character until `EOF`.
    3.  Use an integer array `counts[26]` to store frequencies.
    4.  For each character, if it's a letter, convert it to lowercase and increment the corresponding counter in your array.
    5.  After reading, print the counts for letters that appeared at least once.
    6.  Remember to `fclose()` the file.

---

## Exercise 4: Simple File Writing

*   **Task:** Write a program that creates a file named `hi.txt` and writes a single line of text to it.
*   **Requirements:**
    1.  Open `hi.txt` in write mode (`"w"`). Check if the `FILE*` is `NULL`.
    2.  Use `fprintf()` to write a string like `"Hello, this is [Your Name]"` into the file.
    3.  Close the file using `fclose()`.
    4.  Print a confirmation message to the console.

---

## Exercise 5: Dynamic Array with `malloc`

*   **Task:** Write a program that asks the user how many numbers they want to enter, allocates memory dynamically for them, reads the numbers, and then prints them.
*   **Concept:** `malloc` (memory allocation) allocates a block of memory on the heap and returns a pointer to it. This is essential when you don't know the size of an array at compile time.
*   **Requirements:**
    1.  Ask the user for an integer `n`.
    2.  Allocate space for `n` integers using `malloc`: `int *arr = (int*) malloc(n * sizeof(int));`.
    3.  Check if `malloc` returned `NULL` (which indicates an error).
    4.  If successful, loop `n` times to read integers from the user into the allocated array.
    5.  Print the contents of the array.
    6.  **Crucially**, free the allocated memory using `free(arr);`.

---

## Exercise 6: Copy a File

*   **Task:** Write a program that copies the content of a source file (`source.txt`) to a destination file (`destination.txt`).
*   **📝 Flowchart First:** Draw a flowchart for the file copy logic. It should include opening both files, the main read/write loop, and closing both files.
*   **Requirements:**
    1.  Open `source.txt` in read mode and `destination.txt` in write mode.
    2.  Handle errors for both file openings.
    3.  Read the source file character by character in a loop (`while ((c = fgetc(source_fp)) != EOF)`).
    4.  Write each character to the destination file using `fputc(c, dest_fp)`.
    5.  Close both files.
    6.  Before running, create a `source.txt` file with some sample text. After running, verify that `destination.txt` was created and contains the same text.

---
src: ./assessment.md
---