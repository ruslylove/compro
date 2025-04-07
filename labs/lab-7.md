---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 7 - Functions and Array (2)
class: lab
---

# Computer Programming
## Lab 7: Functions and Arrays (2)

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Exercise 1: Character Frequency Count

* **Task:** Write a C program to count the frequency of each character within a given string.
* **Input String Example:** `char s[] = "aa56231332bbAcc11"`
* **Requirements:**
    * Count occurrences of all characters (digits, letters - case-sensitive for counting, etc.).
    * Print the frequency counts for only those characters that appear one or more times in the string.
* **Example Output Format (based on input string):**
    ```
    a: -> 2
    b: -> 2
    c: -> 2  // (Assuming 'C' and 'c' are distinct or converted)
    C: -> ??  // (Depends on case sensitivity handling)
    1: -> 3
    2: -> 2
    3: -> 3
    5: -> 1
    6: -> 1
    ```
    *(Note: The exact output depends on whether you treat uppercase and lowercase as the same or different characters for counting purposes. The example in the PDF suggests 'a' and 'A' might be counted together as 'a', and 'c' and 'C' counted together as 'C', requiring case conversion before counting.)*
* **Hints:**
    * Use an integer array, possibly `int freq[128];` (to cover ASCII values), initialized to all zeros.
    * Iterate through the input string character by character.
    * For each character, increment the corresponding counter in the `freq` array (e.g., `freq[(int)s[i]]++;` or handle case conversion first: `freq[tolower(s[i]) - 'a']++;` for letters if case-insensitive).
    * After processing the string, loop through the `freq` array (e.g., indices 0 to 127) and print the character and its count `if (freq[i] > 0)`.

---

## Exercise 2: Insert into Sorted Array

* **Task:** Write a C program to insert elements from one array (`b`) into a sorted array (`a`) while maintaining the sorted order of `a`. Assume array `a` has enough allocated space to accommodate the new elements.
* **Given Arrays:**
    * Sorted array `a`: `a[13] = {10, 14, 15, 18, 19, 21, 22, 31, 32, 35, 0, 0, 0}` (Note: Trailing zeros indicate available space; initial actual size is 10).
    * Array `b` containing elements to insert: `b[3] = {55, 17, 32}`.
* **Requirements:**
    * Insert each element from `b` into `a` one by one.
    * For each insertion, find the correct position in `a` to maintain ascending order.
    * Shift existing elements in `a` to the right to make space for the new element.
    * Update the count of valid elements in `a`.
    * After inserting all elements from `b`, print the final contents of array `a`.
* **Expected Final `a` (after inserting 55, 17, 32):** `{10, 14, 15, 17, 18, 19, 21, 22, 31, 32, 32, 35, 55}`

---

## Exercise 3: Remove Redundant Blanks from String

* **Task:** Write a C program to remove unnecessary spaces from a string, ensuring only single spaces remain between words and no leading/trailing spaces (unless the original string is just spaces).
* **Input String Example:** `char str[] = "   who   am   i.    To  be or  not to be  "`
* **Requirements:**
    * Process the input string to eliminate consecutive spaces.
    * Remove leading and trailing spaces (if any).
    * The resulting string should have words separated by exactly one space.
* **Expected Output String (based on input example):** `"who am i. To be or not to be"`
* **Hints:**
    * You can create a new character array to store the result, copying characters selectively from the original.
    * Iterate through the original string. Keep track of whether the previous character was also a space. Only copy a space to the result if the previous character was not a space (and avoid leading spaces). Copy non-space characters directly.
    * Alternatively, modify the string in-place using two index pointers (one for reading, one for writing).