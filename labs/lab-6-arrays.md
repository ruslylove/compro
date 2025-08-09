---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 6 - Arrays
class: lab
routeAlias: lab6
---

# Lab 6: Arrays
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Objectives

*   **Understand array memory layout and indexing** for both 1D and 2D arrays.
*   **Declare, initialize, and access 1D and 2D arrays.**
*   **Pass arrays to functions** to perform calculations and modifications.
*   **Implement fundamental array algorithms:**
    *   Statistical analysis (mean, median, mode).
    *   Sorting (Bubble Sort).
    *   Matrix manipulation (diagonal summation).
*   **Use 2D arrays to represent and manipulate grid-based data** like interactive dice faces and matrices.

<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="lecture6" title="Go to Lecture 6 🧑‍🏫"/>
</div>

---

## Lab Outline

*   **Exercise 1: Array Memory & Indexing**
    *   Explore how arrays are stored in memory.
*   **Exercise 2: Student Scores Analysis**
    *   Perform calculations on a 1D array using functions.
*   **Exercise 3: Statistical Analysis: Mean, Mode, and Median**
    *   Perform data analysis on a 1D array, including sorting via counting.
*   **Exercise 4: Print a Dice Face 🎲**
    *   Use a 2D array and a selection statement to create an interactive grid.
*   **Exercise 5: Bubble Sort in a Function**
    *   Implement a classic sorting algorithm that modifies an array in-place.
*   **Exercise 6: Sum of Matrix Diagonals**
    *   Perform specific calculations on a square 2D array.

---
layout: two-cols-header
---

## Exercise 1: Array Memory & Indexing

*   **Task:** Write a program to explore the memory layout of 1D and 2D arrays.
:: left ::
*   **Part A: 1D Array**
    1.  Declare an integer array, e.g., `int data[5] = {10, 20, 30, 40, 50};`.
    2.  Print the size of the entire array in bytes using `sizeof(data)`.
    3.  Print the size of a single element in bytes using `sizeof(data[0])`.
    4.  Use a `for` loop to print the `index`, `value`, and memory `address` (`&data[i]`) of each element. Use the `%p` format specifier to print addresses.
    5.  **Question:** What is the difference in the memory address between `data[0]` and `data[3]`?
:: right ::
*   **Part B: 2D Array**
    1.  Declare a 2D integer array, e.g., `int matrix[2][3] = {{11, 22, 33}, {44, 55, 66}};`.
    2.  Print the total size of the matrix in bytes using `sizeof(matrix)`.
    3.  Use nested `for` loops to print the `index (r, c)`, `value`, and memory `address` (`&matrix[r][c]`) of each element.
    4.  **Question:** Observe the memory addresses. Are the elements of the first row (`matrix[0]`) stored right before the elements of the second row (`matrix[1]`)?

---
layout: two-cols-header
---

## Exercise 2: Student Scores Analysis

*   **Task:** Write a program with functions to analyze an array of student scores.
:: left ::
*   **📝 Flowchart First:** Draw a flowchart for the `findMax` function.
*   **Requirements:**
    1.  In `main`, create a `float` array and initialize it with some scores (e.g., `float scores[] = {88.5, 92.0, 76.5, 95.0, 83.0};`).
    2.  Implement a function `float findSum(float arr[], int size)` that returns the sum of all scores.
    3.  Implement a function `float findMax(float arr[], int size)` that returns the highest score.
:: right ::

4.  Implement a function `float findMin(float arr[], int size)` that returns the lowest score.
5.  In `main`, call these functions and use their results to print the `sum`, `average`, `maximum`, and `minimum` scores.
<br>
<img src="/student_scores.png" style="height:200px;width:200px;margin:auto" alt="Student Scores Analysis" title="Student Scores Analysis"/>


---

## Exercise 3: Statistical Analysis: Mean, Mode, and Median

*   **Task:** Write a program to calculate the mean, mode, and median of a dataset. This is a very common task in data analysis.
*   **📝 Flowchart First:** Draw a flowchart for the logic to find the **mode**.
*   **Requirements:**
    1.  In `main`, create an integer array, e.g., `int data[] = {7, 2, 8, 2, 9, 2, 7, 4, 5};`.
    2.  **Mean:** Calculate the sum of all elements and divide by the number of elements. Print this value as a `float`.
    3.  **Mode:** The value that appears most frequently.
        *   Use a second array, `frequency[10]`, to count the occurrences of each number (assuming numbers are 0-9).
    4.  **Median:** The middle value of a *sorted* dataset.
        *   To find the median, you must first sort the `data` array, you may apply the frequency counting concept for sorting.
    5.  Print the calculated `mean`, `median`, and `mode`.

---
layout: two-cols-header
---

## Exercise 4: Print a Dice Face 🎲

:: left ::

*   **Task:** Write a program that asks the user for a number from 1 to 6 and prints the corresponding face of a die using a 2D array.
*   **📝 Flowchart First:** Draw a flowchart that shows how the program gets user input and uses a selection structure (e.g., `switch`) to determine which dice face to print.

**Requirements:**
1.  In `main`, prompt the user to enter an integer from 1 to 6.
2.  Define a 2D array, `int diceFace[3][3]`.
3.  Based on the user's input, populate the `diceFace` array with the correct pattern of 1s and 0s.

:: right ::
 
4.  Write a function `void printGrid(int grid[][3], int rows)` that takes the 2D array and prints it.
5.  The function should use nested loops to iterate through the grid. It should print a `* ` (star and space) for a `1` and ` ` ` ` (two spaces) for a `0`.
6.  Call `printGrid` from `main` to display the chosen dice face.
7.  Your program should handle invalid input (numbers not between 1 and 6).
*   **Example Output (for input 5):**
    ```text
    *   * 
      *   
    *   * 
    ```

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
layout: two-cols-header
---

## Exercise 6: Sum of Matrix Diagonals

*   **Task:** Write functions to calculate the sum of the main and anti-diagonals of a square matrix.

:: left ::

*   **Concept:**
    *   The **main diagonal** consists of elements where the row index equals the column index (e.g., `M[0][0]`, `M[1][1]`).
    *   The **anti-diagonal** consists of elements where the sum of row and column indices equals `size - 1`.
*   **Requirements:**
    1.  Use `#define` to create a square matrix size <br> (e.g., `#define SIZE 4`).
    2.  In `main`, define and initialize a square 2D integer array.
:: right ::

3.  Implement a function `int sumMainDiagonal(int M[][SIZE], int size)` that returns the sum of the main diagonal elements.
4.  Implement a function `int sumAntiDiagonal(int M[][SIZE], int size)` that returns the sum of the anti-diagonal elements.
5.  Create a helper function `void printMatrix(int M[][SIZE], int size)` to display the matrix.
6.  In `main`, call `printMatrix` to show the matrix, then call the two sum functions and print their results.


<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="assessment" title="Go to Assessment Rubric 📝"/>
</div>