---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 6 - Functions and Arrays
class: lab
routeAlias: lab6
---

# Computer Programming
## Lab 6: Functions and Arrays

Presented by {{ $slidev.configs.presenter }}

Semester {{ $slidev.configs.semester }}

---

## Objectives

*   **Pass arrays to functions**
    *   Understand how to declare function parameters that accept arrays.
    *   Learn that arrays are passed by reference (i.e., the function receives a pointer to the original array).
*   **Modify arrays within functions**
    *   Write functions that directly alter the contents of an array passed from the caller.
*   **Process strings (character arrays) with functions**
    *   Develop functions to perform common string manipulations and conversions.
*   **Implement algorithms using functions and arrays**
    *   Encapsulate logic for searching, sorting, and number analysis within separate, reusable functions.
*   **Return information about array processing**
    *   Design functions that return status codes, calculated values, or boolean flags based on array data.

---

## Lab Outline

*   **Exercise 1: Narcissistic Numbers**
    *   Use a function to check a number's property.
*   **Exercise 2: Palindrome Square Numbers**
    *   Combine multiple helper functions to find numbers with two properties.
*   **Exercise 3: Convert Number String to Integer**
    *   Process a character array to produce a numerical result.
*   **Exercise 4: Convert Decimal to Hexadecimal String**
    *   Use a function to handle numerical base conversion and output.
*   **Exercise 5: Bubble Sort in a Function**
    *   Implement a sorting algorithm that modifies an array in-place.
*   **Exercise 6: Linear Search in a Function**
    *   Write a function to find an element within an array.

---

## Exercise 1: Narcissistic Numbers

*   **Task:** Find and print all three-digit "Narcissistic" numbers (also known as Armstrong numbers).
*   **📝 Flowchart First:** Draw a flowchart for the `isNarcNum` function, showing how to extract digits and check the property.
*   **Definition:** A three-digit number is Narcissistic if the sum of the cubes of its digits equals the number itself. Example: $153 = 1^3 + 5^3 + 3^3$.
*   **Requirements:**
    1.  Implement a function `int isNarcNum(int n)` that returns `1` if `n` is a three-digit Narcissistic number, and `0` otherwise.
    2.  In `main()`, loop through numbers from 100 to 999.
    3.  Call `isNarcNum()` for each number and print the ones that are Narcissistic.
    4.  Format the output to display two Narcissistic numbers per line.
*   **Hint:** To get digits of `n`, use `/` and `%`. `d1 = n / 100; d2 = (n / 10) % 10; d3 = n % 10;`

---

## Exercise 2: Palindrome Square Numbers

*   **Task:** Find and print all numbers within a user-defined range `[a, b]` that are both **palindromes** and **perfect squares**.
*   **📝 Flowchart First:** Draw flowcharts for both the `isPalindrome` and `isPerfectSquare` functions.
*   **Definitions:**
    *   **Palindrome:** Reads the same forwards and backwards (e.g., 121).
    *   **Perfect Square:** Is the square of an integer (e.g., 121 = 11²).
*   **Requirements:**
    1.  Define `int isPalindrome(int n)` which returns `1` if `n` is a palindrome.
    2.  Define `int isPerfectSquare(int n)` which returns `1` if `n` is a perfect square.
    3.  In `main()`, get the range `a` and `b` from the user.
    4.  Loop from `a` to `b`, and if a number satisfies both conditions, print it.
*   **Hints:**
    *   `isPalindrome`: Reverse the number and check if it equals the original.
    *   `isPerfectSquare`: Calculate `sqrt(n)`, cast to `int`, square it, and see if it equals `n`.

---

## Exercise 3: Convert Number String to Integer

*   **Task:** Write a function that converts a string of digits (e.g., `"312"`) into its integer value.
*   **📝 Flowchart First:** Draw a flowchart for the `str2num` function's conversion logic.
*   **Function Signature:** `int str2num(char s[])`
*   **Requirements:**
    1.  Iterate through the string character by character.
    2.  For each character, update the total number. `num = num * 10 + (s[i] - '0');`
    3.  Return the final integer.
    4.  In `main`, test your function with a sample string like `"215"` and print the result.

---

## Exercise 4: Convert Decimal to Hexadecimal String

*   **Task:** Write a function that takes an integer `n` and prints its hexadecimal (base-16) representation.
*   **📝 Flowchart First:** Draw a flowchart for the `dec2hexa` function. An iterative approach using an array to store digits is recommended.
*   **Function Signature:** `void dec2hexa(int n)`
*   **Requirements:**
    1.  Handle the conversion by repeatedly dividing `n` by 16 and storing the remainders.
    2.  Map remainders 10-15 to characters 'A'-'F'.
    3.  Since remainders are generated in reverse order, store them in a temporary array and then print the array backwards.
    4.  Prefix the output with "0x".
    5.  In `main`, test with a number like `361005` and show the output.

---

## Exercise 5: Bubble Sort in a Function

*   **Task:** Implement the Bubble Sort algorithm within a function to sort an integer array in ascending order.
*   **Function Signature:** `void bubbleSort(int arr[], int size)`
*   **Algorithm:**
    1.  Use a nested loop. The outer loop iterates from the end of the array towards the beginning.
    2.  The inner loop "bubbles up" the largest element to its correct position in each pass.
    3.  It does this by comparing adjacent elements (`arr[j]` and `arr[j+1]`) and swapping them if they are in the wrong order.
*   **Requirements:**
    1.  Implement the `bubbleSort` function. It should modify the array directly (in-place).
    2.  Create a helper function `void printArray(int arr[], int size)` to display array contents.
    3.  In `main`, create an unsorted array, print it, call `bubbleSort`, and print the sorted array.

---

## Exercise 6: Linear Search in a Function

*   **Task:** Write a function to search for a specific value (the "key") within an array.
*   **Function Signature:** `int linearSearch(int arr[], int size, int key)`
*   **Algorithm:**
    1.  Iterate through the array from the first element to the last.
    2.  In each iteration, compare the current element with the `key`.
    3.  If a match is found, return the index of that element.
*   **Requirements:**
    1.  Implement the `linearSearch` function.
    2.  If the `key` is found, the function should return its index.
    3.  If the `key` is not found after checking all elements, the function should return `-1`.
    4.  In `main`, create an array, ask the user for a number to search for, call `linearSearch`, and report whether the number was found and at what index.


<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="/labs/lab-1#assessment-criteria" title="Go to Assessment Rubric 📝"/>
</div>