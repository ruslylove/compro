---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 7 - Strings
class: lab
routeAlias: lab7
---

# Lab 7: Strings
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Objectives

*   **Master string manipulation within functions:**
    *   Pass strings to functions for in-place modification (e.g., Title Case, Reverse String).
    *   Pass arrays of strings (2D character arrays) to functions for searching.
*   **Implement common string processing algorithms:**
    *   Parse strings to count character frequencies or find the longest word.
    *   Clean and normalize string data by removing redundant whitespace.
*   **Develop efficient in-place modification techniques:**
    *   Modify strings directly in memory using two-pointer/index approaches.
*   **Utilize the C standard libraries for string operations:**
    *   Apply functions from `<string.h>` (like `strcmp`) and `<ctype.h>` (like `tolower`, `toupper`) to solve problems.

---

## Lab Outline

*   **Exercise 1: Character Frequency Count**
    *   Count character occurrences in a string.
*   **Exercise 2: Convert String to Title Case**
    *   Practice passing a string to a function for in-place modification.
*   **Exercise 3: Remove Redundant Blanks from String**
    *   Perform in-place string cleaning and normalization.
*   **Exercise 4: Search for a Name in a List**
    *   Practice passing an array of strings to a function.
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

## Exercise 2: Convert String to Title Case

*   **Task:** Write a function that converts a string to "title case," where the first letter of each word is capitalized and the rest are lowercase.
*   **📝 Flowchart First:** Draw a flowchart for the `toTitleCase` function. It should show the loop and the conditional logic for capitalizing or lowercasing each character.
*   **Function Signature:** `void toTitleCase(char str[])`
*   **Requirements:**
    1.  The function must modify the string **in-place**.
    2.  The first character of the string should always be capitalized.
    3.  Any character that follows a space should be capitalized.
    4.  All other alphabetic characters should be converted to lowercase.
    5.  Use `toupper()` and `tolower()` from `<ctype.h>`.
    6.  In `main`, create a test string like `"hELLo wORLd, how ARE yoU?"`,<br> print it, call `toTitleCase`, and print the modified string.

<div style="position:fixed;bottom:170px;right:40px;padding-bottom:30px">

*   **Example:**
    *   Input: `"a lIttLe tEa pOt"`
    *   Output: `"A Little Tea Pot"`
</div>
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
layout: two-cols-header
---

## Exercise 4: Search for a Name in a List

*   **Task:** Write a function that searches for a specific name within an array of strings.
:: left ::
*   **Function Signature:** `int findName(const char names[][50], int size, const char searchKey[])`
    *   `names`: The 2D character array (array of strings).
    *   `size`: The number of names in the array.
    *   `searchKey`: The string (name) to search for.
    *   **Return:** The index of the name if found; otherwise, return -1.
*   **Requirements:**
    1.  In `main`, define an array of strings, e.g., `char nameList[5][50] = {"Alice", "Bob", "Charlie", "David", "Eve"};`.
:: right ::
2.  Prompt the user to enter a name to search for.
3.  Implement the `findName` function. Inside, use a loop and `strcmp()` from `<string.h>` to compare the `searchKey` with each name in the `names` array.
4.  Call `findName` from `main`.
5.  Based on the return value, print a message indicating whether the name was found and at what index (e.g., `"Found 'Charlie' at index 2."` or `"'Frank' was not found."`).

---

## Exercise 5: Reverse a String In-Place

*   **Task:** Write a function that reverses a string in-place.
*   **Function Signature:** `void reverseString(char str[])`
*   **Algorithm:**
    1.  Use two indices, one at the start of the string and one at the end.
    2.  Swap the characters at the start and end indices.
    3.  increase the start index and decrease the end index.
    4.  Repeat until the indices are equal to each other.
*   **Requirements:**
    1.  Implement the `reverseString` function. It **must not create a new copy** of the string.
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


<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="assessment" title="Go to Assessment Rubric 📝"/>
</div>