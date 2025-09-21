---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 9 - Pointers
class: lab
routeAlias: lab9
---

# Lab 9: Pointers
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Objectives

*   **Master pointer fundamentals and arithmetic**
    *   Declare, initialize, and dereference pointers using `&` and `*`.
    *   Use pointer arithmetic to navigate arrays.
*   **Use pointers to simulate call-by-reference**
    *   Pass pointers to functions to allow direct modification of caller data.
*   **Manage memory dynamically**
    *   Allocate and free memory on the heap using `malloc` and `free`.
*   **Implement a basic Linked List**
    *   Define a node structure.
    *   Dynamically add nodes and link them together.
*   **Use Function Pointers for callbacks**
    *   Declare function pointers.
    *   Pass functions as arguments to other functions to create generic algorithms.

---

## Lab Outline

*   **Exercise 1: Pointer Arithmetic Predictions**
    *   Predict the output of pointer operations.
*   **Exercise 2: Flip Array Elements using Pointers**
    *   Modify an array in-place using pointer arithmetic.
*   **Exercise 3: Calculate Dot Product using Pointers**
    *   Access multiple arrays in parallel using pointers.
*   **Exercise 4: Dynamic Array with `malloc`**
    *   Learn to allocate memory at runtime.
*   **Exercise 5: Build a Simple Linked List**
    *   Practice dynamic allocation with `struct`s to create a list.
*   **Exercise 6: Array Processing with Function Pointers**
    *   Create a generic `map` function for arrays.

---

## Exercise 1: Pointer Arithmetic Predictions

*   **Task:** Analyze the following code snippet *without running it*. Predict the output for each `printf` statement.
*   **Concept:** This exercise tests your understanding of how pointer arithmetic is scaled by the size of the data type it points to.
*   **Code:** 

```c {*}{maxHeight:'150px'}
    #include <stdio.h>

    int main() {
        int arr[] = {100, 200, 300, 400, 500};
        int *p = arr;
        printf("1. Value: %d, Address: %p\n", *p, (void*)p);
        p++;
        printf("2. Value: %d, Address: %p\n", *p, (void*)p);
        p = p + 2;
        printf("3. Value: %d, Address: %p\n", *(p), (void*)p);
        p--;
        printf("4. Value: %d, Address: %p\n", *p, (void*)p);
        printf("5. Value: %d\n", *(arr + 3));
        return 0;
    }
```

*   **Your Task:**
    1.  Write down what you think each of the five `printf` lines will output. Assume an `int` is 4 bytes and the starting address of `arr` is `0x7ffc...1000`.
    2.  After making your predictions, compile and run the code to verify your answers.
    3.  Explain any differences between your prediction and the actual output.

---

## Exercise 2: Flip Array Elements using Pointers

*   **Task:** Create a function `void flip(int *a, int sz)` that reverses an integer array *in place*.
*   **📝 Flowchart First:** Draw a flowchart for the `flip` function. It should visualize the two-pointer swapping logic.
*   **Requirements:**
    1.  The function must use pointer arithmetic (e.g., `*p`, `p++`), not array indexing (`a[i]`).
    2.  Use two pointers, one at the start and one at the end, moving towards the center and swapping elements.
    3.  In `main`, declare an array, print it, call `flip`, and print it again.
*   **Example:** `{11, 4, 31, 2, 5}` becomes `{5, 2, 31, 4, 11}`.

---

## Exercise 3: Calculate Dot Product using Pointers

*   **Task:** Define a function `float dotprod(float *a, float *b, int sz)` that calculates the dot product of two float arrays.
*   **📝 Flowchart First:** Draw a flowchart for the `dotprod` function, showing the loop that accumulates the sum using pointers.
*   **Dot Product:** $result = \sum_{i=0}^{sz-1} a_i \times b_i$
*   **Requirements:**
    1.  Use pointers, not array indexing, to iterate through the arrays.
    2.  Return the resulting `float` dot product.
    3.  In `main`, create two float arrays, call `dotprod`, and print the result.

---

## Exercise 4: Dynamic Array with `malloc`

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

## Exercise 5: Build a Simple Linked List

*   **Task:** Create a program to build a linked list of integers (`10 -> 20 -> 30`).
*   **📝 Flowchart First:** Draw a flowchart illustrating the steps to create the head node, then create and link the second and third nodes.
*   **Requirements:**
    1.  Define a `Node` struct with `int data;` and `struct Node *next;`.
    2.  In `main`, dynamically allocate three nodes using `malloc`. Check for allocation failures.
    3.  Assign data (`10`, `20`, `30`) and link them together: `head->next = second;`, `second->next = third;`, `third->next = NULL;`.
    4.  Write a `print_list(Node *head)` function that traverses the list from the head and prints each node's data.
    5.  Call `print_list` to display your list.
    6.  Write a `free_list(Node *head)` function that iterates through the list and frees each node to prevent memory leaks. Call it before `main` exits.

---

## Exercise 6: Array Processing with Function Pointers

*   **Task:** Create a `map` function that applies a given operation to each element of an integer array.
*   **Concept:** A function pointer allows you to pass a function as an argument, making your code more flexible.
*   **📝 Flowchart First:** Draw a flowchart for the `map` function. It should show a loop that calls the function pointer for each array element.
*   **Requirements:**
    1.  Define the `map` function: `void map(int *arr, int sz, int (*f)(int))`. It takes an array, its size, and a function pointer `f`. The function `f` should take an `int` and return an `int`.
    2.  Inside `map`, iterate through the array and update each element with the result of calling the function pointer on it: `arr[i] = f(arr[i]);`.
    3.  Create two simple functions with a matching signature, e.g., `int square(int x)` and `int double_val(int x)`.
    4.  In `main`, create an array. Call `map` with the `square` function and print the result.
    5.  Reset the array. Call `map` with the `double_val` function and print the result.


<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="assessment" title="Go to Assessment Rubric 📝"/>
</div>