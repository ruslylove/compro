---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 9 - Pointers and File Operations
class: lab
---

# Computer Programming
## Lab 9: Pointers and File Operations

Presented by: Dr. Ruslee Sutthaweekul
Semester: 1/2025

---

## Lab Outline

1.  Pointer Exercises
2.  File Operation Exercise

---

## Exercise 1: Flip Array Elements using Pointers

* **Task:** Create a function `void flip(int *a, int sz)` that reverses the elements of an integer array *in place*.
* **Requirements:**
    1.  The function takes a pointer `a` to the first element of the array and the array size `sz`.
    2.  Inside the `flip` function, use pointer arithmetic (not array indexing `[]`) to access and swap elements.
    3.  Also create a function `void print_array(int *a, int sz)` to display the array contents using pointer arithmetic.
    4.  In `main`, declare an array, print it, call `flip`, and then print it again to show it's reversed.
* **Example:** `a = {11, 4, 31, 2, 5}` should become `a = {5, 2, 31, 4, 11}`.
* **Hint (Swap Logic):** Use two pointers, one starting at the beginning (`p = a`) and one at the end (`q = a + sz - 1`). Swap the values they point to (`*p`, `*q`). Move `p` forward (`p++`) and `q` backward (`q--`). Repeat until `p` and `q` cross each other (stop when `p >= q`).

---

## Code Snippet: `flip` function

```c
#include <stdio.h>

// Function to print array using pointers
void print_array(int *a, int sz) {
    int *p;
    int *end = a + sz; // Pointer to one past the last element
    printf("[ ");
    for (p = a; p < end; p++) {
        printf("%d ", *p); // Dereference pointer to get value
    }
    printf("]\n");
}

// Function to flip array elements using pointers
void flip(int *a, int sz) {
    int *p = a;          // Pointer to the start
    int *q = a + sz - 1; // Pointer to the end
    int temp;

    // Loop while start pointer is before end pointer
    while (p < q) {
        // Swap values pointed to by p and q
        temp = *p;
        *p = *q;
        *q = temp;

        // Move pointers towards the center
        p++;
        q--;
    }
}

int main() {
    int my_array[] = {11, 4, 31, 2, 5, 12, 15};
    int size = sizeof(my_array) / sizeof(my_array[0]); // Calculate array size

    printf("Original array: ");
    print_array(my_array, size);

    flip(my_array, size); // Reverse the array

    printf("Flipped array:  ");
    print_array(my_array, size);

    return 0;
}
```

---

## Exercise 2: Calculate Dot Product using Pointers

* **Task:** Define a function `float dotprod(float *a, float *b, int sz)` that calculates the dot product (scalar product) of two float arrays `a` and `b`, both of size `sz`.
* **Dot Product Formula:** $result = \sum_{i=0}^{sz-1} a_i \times b_i$
* **Requirements:**
    1.  The function takes pointers to the first elements of the two arrays (`a`, `b`) and their common size `sz`.
    2.  Use pointers (not array indexing `[]`) inside the function to iterate through the arrays and calculate the sum of the products of corresponding elements.
    3.  Return the resulting dot product (a float).
    4.  In `main`, declare and initialize two float arrays, call `dotprod`, and print the result.

---

## Code Snippet: `dotprod` function

```c
#include <stdio.h>

// Function to calculate dot product using pointers
float dotprod(float *a, float *b, int sz) {
    float *p_a = a;      // Pointer for array a
    float *p_b = b;      // Pointer for array b
    float *end_a = a + sz; // Pointer to one past the end of a
    float sum = 0.0f;

    // Loop until pointer reaches the end
    while (p_a < end_a) {
        // Multiply corresponding elements and add to sum
        sum += (*p_a) * (*p_b);

        // Move both pointers to the next element
        p_a++;
        p_b++;
    }
    return sum;
}

int main() {
    float vec1[] = {1.0f, 2.0f, 3.0f};
    float vec2[] = {4.0f, 5.0f, 6.0f};
    int size = sizeof(vec1) / sizeof(vec1[0]);
    float result;

    result = dotprod(vec1, vec2, size); // Calculate dot product

    // Expected: (1*4) + (2*5) + (3*6) = 4 + 10 + 18 = 32
    printf("Dot product = %.2f\n", result);

    return 0;
}
```

---

## Exercise 3: Alphabet Frequency Count

* **Task:** Write a program that reads text from a file named `input.txt` and counts the frequency of occurrence of each alphabet letter (case-insensitive).
* **Requirements:**
    1.  Assume `input.txt` exists and contains some text.
    2.  Read the file character by character until the end of the file (EOF) is reached.
    3.  For each character read, determine if it's an alphabet letter (`'a'`-`'z'` or `'A'`-`'Z'`).
    4.  Treat uppercase and lowercase letters the same (e.g., count 'a' and 'A' together).
    5.  Keep track of the counts for each of the 26 letters.
    6.  After reading the entire file, print the frequency counts for only those letters that appeared at least once.
* **Hints:**
    * Use an integer array `counts[26]` initialized to zeros, where `counts[0]` corresponds to 'a'/'A', `counts[1]` to 'b'/'B', etc.
    * Use `fopen("input.txt", "r")` to open the file. Remember to check for `NULL`.
    * Use `fgetc(fp)` to read one character at a time. It returns `EOF` at the end of the file.
    * Convert uppercase letters to lowercase (e.g., using `tolower()` from `<ctype.h>` or by adding `'a' - 'A'`) before calculating the array index (`index = lower_char - 'a'`).
    * Check if a character `c` is alphabetic using `isalpha(c)` from `<ctype.h>` or manually (`(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')`).
    * After reading, loop through your `counts` array and print the letter and its count if the count is greater than zero.
    * Remember to `fclose(fp)`.

---

## Lab Outline

1.  Pointer Exercises
2.  **File Operation Exercise**

---

## Exercise 4: Simple File Writing

* **Task:** Write a C program that creates (or overwrites) a text file named `hi.txt` and writes a single line of text into it.
* **Requirements:**
    1.  Open `hi.txt` in write mode (`"w"`). Handle potential file opening errors.
    2.  Write the string `"Hello, this is [Your Name]"` into the file (replace `[Your Name]` with your actual name).
    3.  Close the file properly.
* **Hints:**
    * Use `fopen("hi.txt", "w")`. Check the returned `FILE*` pointer against `NULL`.
    * Use `fprintf(fp, "Hello, this is %s\n", your_name_string);` to write the formatted string.
    * Use `fclose(fp);`.

---

## Code Snippet: File Writing

```c
#include <stdio.h>

int main() {
    char your_name[] = "Ruslee Sutthaweekul"; // Replace with your name
    FILE *fp = NULL; // File pointer

    // Open file in write mode
    fp = fopen("hi.txt", "w");

    // Check if file opened successfully
    if (fp == NULL) {
        perror("Error: File cannot be opened for writing");
        return 1; // Indicate error
    }

    // Write the string to the file
    fprintf(fp, "Hello, this is %s\n", your_name);

    // Close the file (important!)
    fclose(fp);

    printf("Successfully wrote to hi.txt\n");

    return 0;
}
```
*After running this program, check your working directory for a file named `hi.txt` containing the specified text.*