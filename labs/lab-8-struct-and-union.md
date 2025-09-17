---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 8 - struct, union and enum
class: lab
routeAlias: lab8
---

# Lab 8: struct, union and enum
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Objectives

*   **Define and use `struct` to group related data**
    *   Create custom data types that aggregate variables of different types.
    *   Declare `struct` variables and access their members using the dot (`.`) operator.
*   **Use `enum` to create named constants for better readability**
    *   Define enumerations and use them to represent states or categories.
*   **Work with structs and functions**
    *   Pass structs to functions by value.
    *   Return structs from functions.
*   **Manage collections of data with arrays of structs**
    *   Declare and manipulate arrays where each element is a complex `struct`.
*   **Understand and use `union` for memory optimization**
    *   Define unions to store different data types in the same memory location.
*   **Explore advanced struct features like nesting and bit-fields**

---

## Lab Outline

*   **Exercise 1: Complex Number Struct**
    *   Use a struct to represent a mathematical object and perform operations.
*   **Exercise 2: QQ Book (Array of Structs)**
    *   Use an array of structs to create a simple database.
*   **Exercise 3: Defining and Using a Union**
    *   Explore how unions store data and their memory footprint.
*   **Exercise 4: Product Catalog with Enum**
    *   Use `enum` to represent categories within a `struct`.
*   **Exercise 5: Nested Structs**
    *   Create structs that contain other structs as members.
*   **Exercise 6: Data Packing with Bit-Fields**
    *   Use bit-fields within a struct to save memory.

---

## Exercise 1: Complex Number Struct

*   **Task:** Perform operations on complex numbers using structures.
*   **📝 Flowchart First:** Draw a flowchart for the `multComp` function, detailing the steps of the complex multiplication formula.
*   **Requirements:**
    1.  Define a `struct Compx` with `float` members `real` and `imag`.
    2.  Implement `struct Compx multComp(struct Compx d1, struct Compx d2)` that returns the product of two complex numbers.
        *   Formula: $(a + bi) \times (c + di) = (ac - bd) + (ad + bc)i$.
    3.  Implement `void printCompx(struct Compx a)` that prints a complex number in the format `a + bi` (e.g., `0.30 + 0.50i` or `1.20 - 0.80i`).
    4.  In `main`, create two `Compx` variables, multiply them, and print the result.

---

## Exercise 2: QQ Book (Array of Structs)

*   **Task:** Create a simple "QQ Book" using an array of structures.
*   **📝 Flowchart First:** Draw a flowchart for the `readQQbook` function, showing the loop for entering data for multiple people.
*   **Requirements:**
    1.  Define a `struct NoteBook` with `char name[30]` and `int qq`.
    2.  In `main`, declare an array of 4 `struct NoteBook` elements.
    3.  Implement `void readQQbook(struct NoteBook book[], int size)` that prompts the user to fill the array.
    4.  Implement `void printQQbook(struct NoteBook book[], int size)` that prints the contents of the array.
    5.  Call these functions from `main`.

---

## Exercise 3: Defining and Using a Union

*   **Task:** Define and experiment with a `union` to understand how it stores data.
*   **Requirements:**
    1.  Define a `union Data` that can hold a `float f`, an `int i`, and a `char c`.
    2.  In `main`, declare a `union Data` variable `d1`.
    3.  Print the size of the union using `sizeof(d1)`. Observe that it's the size of its largest member (the `float`).
    4.  Assign a value to `d1.f` and print it. Then, immediately print `d1.i` and `d1.c` to see how the memory is reinterpreted (garbage values).
    5.  Assign a value to `d1.i` and print it. Observe how this overwrites the previous float value.

---

## Exercise 4: Product Catalog with Enum

*   **Task:** Create a product catalog where each product has a category defined by an `enum`.
*   **Concept:** `enum` makes code more readable and less error-prone by using named constants instead of arbitrary numbers (e.g., `CATEGORY_ELECTRONICS` is clearer than `1`).
*   **Requirements:**
    1.  Define an `enum ProductCategory` with values like `ELECTRONICS`, `BOOKS`, `CLOTHING`, `GROCERIES`.
    2.  Define a `struct Product` with members: `char name[50]`, `float price`, and `enum ProductCategory category`.
    3.  Implement a function `void printProduct(struct Product p)`. Inside this function, use a `switch` statement on `p.category` to print the category as a string (e.g., if `p.category` is `ELECTRONICS`, print "Category: Electronics").
    4.  In `main`, create an array of `Product` structs.
    5.  Initialize the array with a few different products of various categories.
    6.  Loop through the array and call `printProduct` for each product.

---

## Exercise 5: Nested Structs

*   **Task:** Model more complex data by nesting one struct inside another.
*   **Requirements:**
    1.  Define a `struct Date` with `int day`, `int month`, `int year`.
    2.  Define a `struct Employee` with `char name[50]`, `int id`, and a member `struct Date hireDate`.
    3.  In `main`, create an `Employee` variable.
    4.  Initialize all its members, including the nested `hireDate` members (e.g., `emp1.hireDate.day = 10;`).
    5.  Write a function `void printEmployee(struct Employee e)` that prints all the employee's details in a readable format, including the full hire date.
    6.  Call this function from `main`.

---

## Exercise 6: Data Packing with Bit-Fields

*   **Task:** Use bit-fields to pack several boolean flags into a single byte.
*   **Concept:** Bit-fields allow you to specify the width (in bits) of struct members. This is useful for saving memory when you have members that don't need a full byte.
*   **Requirements:**
    1.  Define a `struct Status` with several bit-field members:
        ```c
        struct Status {
            unsigned int isActive : 1;
            unsigned int isConnected : 1;
            unsigned int hasError : 1;
            unsigned int permissionLevel : 2; // Can hold 0,1,2,3
        };
        ```
    2.  In `main`, declare a `struct Status` variable `s`.
    3.  Print the size of the struct. Notice it's much smaller than a struct with regular `int` members.
    4.  Assign values to the bit-fields (e.g., `s.isActive = 1; s.permissionLevel = 2;`).
    5.  Print the values to verify they are stored correctly.


<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="assessment" title="Go to Assessment Rubric 📝"/>
</div>
