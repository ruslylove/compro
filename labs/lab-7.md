---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 7 - Functions and Arrays (2)
class: lab
routeAlias: lab7
---

# Computer Programming
## Lab 7: Functions and Arrays (2)

Presented by {{ $slidev.configs.presenter }}

Semester {{ $slidev.configs.semester }}

---

## Objectives

*   **Perform advanced array and string manipulation**
    *   Implement complex algorithms for sorting, searching, and data transformation on arrays.
    *   Write functions for sophisticated string processing, such as parsing and cleaning.
*   **Work with multi-dimensional arrays**
    *   Pass 2D arrays to functions to represent and manipulate matrices or grids.
*   **Develop robust in-place algorithms**
    *   Create functions that modify arrays or strings directly in memory without needing extra copies, saving space.
*   **Combine loops, conditional logic, and functions**
    *   Solve multi-step problems by integrating different programming constructs into a cohesive solution.

---

## Lab Outline

*   **Exercise 1: Character Frequency Count**
    *   Use an array as a frequency map to count character occurrences in a string.
*   **Exercise 2: Insert into Sorted Array**
    *   Manipulate a sorted array to insert new elements while maintaining order.
*   **Exercise 3: Remove Redundant Blanks from String**
    *   Perform in-place string cleaning and normalization.
*   **Exercise 4: Matrix Addition**
    *   Work with 2D arrays by passing them to a function.
*   **Exercise 5: Reverse a String In-Place**
    *   Modify a character array directly to reverse its contents.
*   **Exercise 6: Find the Longest Word**
    *   Parse a string to identify and extract information.

---

## Exercise 1: Character Frequency Count

*   **Task:** Write a C program to count the frequency of each alphabet character within a given string (case-insensitive).
*   **📝 Flowchart First:** Draw a flowchart for your program. It should show the loop that iterates through the string, the logic for identifying and converting characters, and the final loop for printing the results.
*   **Requirements:**
    *   Count 'a' and 'A' together, 'b' and 'B' together, etc.
    *   Print frequency counts only for letters that appear at least once.
*   **Hints:**
    *   Use an integer array `int freq[26];` initialized to zeros.
    *   Iterate through the string. If a character is a letter, convert it to lowercase (e.g., using `tolower()` from `<ctype.h>`) and increment the appropriate counter (e.g., `freq[c - 'a']++;`).
    *   After counting, loop from 0 to 25. If `freq[i] > 0`, print the corresponding character (`'a' + i`) and its count.

---

## Exercise 2: Insert into Sorted Array

*   **Task:** Write a function to insert a number into a sorted integer array while maintaining its sorted order.
*   **📝 Flowchart First:** Draw a flowchart for the insertion logic. It must show how to find the correct position and how to shift elements to make space.
*   **Function Signature:** `int insertIntoSorted(int arr[], int currentSize, int capacity, int key)`
    *   `arr`: The sorted array.
    *   `currentSize`: The number of elements currently in the array.
    *   `capacity`: The maximum size of the array.
    *   `key`: The integer to insert.
    *   **Return:** The new size of the array, or -1 if the array is full.
*   **Requirements:**
    1.  Find the position where `key` should be inserted.
    2.  Shift all elements from that position to the right by one.
    3.  Place `key` into its correct spot.
    4.  In `main`, start with a partially-filled sorted array and insert several new numbers, printing the array after each insertion.

---

## Exercise 3: Remove Redundant Blanks from String

*   **Task:** Write a function to remove unnecessary spaces from a string.
*   **📝 Flowchart First:** Draw a flowchart for the in-place string cleaning algorithm. Use two pointers/indices (a read pointer and a write pointer) to visualize the logic.
*   **Function Signature:** `void cleanString(char str[])`
*   **Requirements:**
    *   Modify the string in-place.
    *   Eliminate all leading and trailing spaces.
    *   Ensure that multiple spaces between words are reduced to a single space.
*   **Example:** `"   who   am   i.    "` should become `"who am i."`.
*   **Hint (In-place):** Use a "read" index `i` and a "write" index `j`. Iterate with `i` through the original string. Copy a character from `str[i]` to `str[j]` only if it's not a redundant space. Increment `j` only when you write a character.

---

## Exercise 4: Matrix Addition

*   **Task:** Write a function that performs matrix addition.
*   **Function Signature:** `void addMatrices(int A[][3], int B[][3], int C[][3], int rows, int cols)`
*   **Logic:** To add two matrices, you add their corresponding elements. `C[i][j] = A[i][j] + B[i][j]`.
*   **Requirements:**
    1.  Implement the `addMatrices` function. It will take two input matrices (`A`, `B`) and store the result in a third matrix (`C`).
    2.  Also create a `void printMatrix(int M[][3], int rows, int cols)` function.
    3.  In `main`, define and initialize two 2D arrays (e.g., 3x3).
    4.  Declare a third 2D array to hold the result.
    5.  Call `addMatrices`, then call `printMatrix` to display the resulting matrix.

---

## Exercise 5: Reverse a String In-Place

*   **Task:** Write a function that reverses a string in-place.
*   **Function Signature:** `void reverseString(char str[])`
*   **Algorithm:**
    1.  Use two pointers (or indices), one at the start of the string and one at the end.
    2.  Swap the characters at the start and end pointers.
    3.  Move the start pointer forward and the end pointer backward.
    4.  Repeat until the pointers meet or cross each other.
*   **Requirements:**
    1.  Implement the `reverseString` function. It must not create a new copy of the string.
    2.  In `main`, create a string, print it, call `reverseString`, and print the reversed result.
    3.  Example: `"hello"` should become `"olleh"`.

---

## Exercise 6: Find the Longest Word

*   **Task:** Write a function that finds and prints the longest word in a sentence.
*   **Function Signature:** `void findLongestWord(char sentence[])`
*   **Logic:**
    1.  Iterate through the sentence character by character.
    2.  Use a counter for the length of the current word. When you see a space or the end of the string, it marks the end of a word.
    3.  Keep track of the maximum length found so far and the starting position of that longest word.
    4.  After checking the whole sentence, print the longest word using the starting position and max length you recorded.
*   **Requirements:**
    1.  Implement the `findLongestWord` function.
    2.  If there are multiple words with the same max length, the first one found is sufficient.
    3.  In `main`, test with a sentence like `"The quick brown fox jumped over the lazy dog"`. The function should identify and print `"jumped"`.

---
src: ./assessment.md
---