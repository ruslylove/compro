---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 7 - struct and union
class: lab
---

# Computer Programming
## Lab 8: struct and union

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Lab Outline

1.  `struct` Exercises
2.  `union` Exercise

---

## Exercise 1: Complex Number Struct

* **Task:** Perform operations on complex numbers using structures.
* **Requirements:**
    1.  Define a structure named `Compx` to represent a complex number, containing two `float` members: `rl` for the real part and `vt` for the imaginary part.
    2.  Implement a function `struct Compx multComp(struct Compx d1, struct Compx d2)` that takes two complex numbers (`d1`, `d2`) and returns their product (another `struct Compx`).
        * Complex Multiplication Formula:
          If $d1 = a + bi$ and $d2 = c + di$, then $d1 \times d2 = (ac - bd) + (ad + bc)i$.
          So, `result.rl = d1.rl * d2.rl - d1.vt * d2.vt;`
          And, `result.vt = d1.rl * d2.vt + d1.vt * d2.rl;`
    3.  Implement a function `void printCompx(struct Compx a)` that prints a complex number in the format `real_part + imaginary_part i` (e.g., `0.3 + 0.5i`). Handle positive and negative imaginary parts appropriately (e.g., `0.3 - 0.5i`).

---

## Exercise 1: Complex Number - Implementation Sketch

```c
#include <stdio.h>

// Define the complex number structure
struct Compx {
    float rl; // Real part
    float vt; // Imaginary part
};

// Function to multiply two complex numbers
struct Compx multComp(struct Compx d1, struct Compx d2) {
    struct Compx result;
    // --- Your multiplication logic here ---
    result.rl = d1.rl * d2.rl - d1.vt * d2.vt;
    result.vt = d1.rl * d2.vt + d1.vt * d2.rl;
    return result;
}

// Function to print a complex number
void printCompx(struct Compx a) {
    // --- Your printing logic here ---
    // Handle positive/negative imaginary part for correct sign display
    printf("%.2f %c %.2fi", a.rl, (a.vt >= 0 ? '+' : '-'), (a.vt >= 0 ? a.vt : -a.vt));
}

// main function (see next slide)
```

---

## Exercise 1: Complex Number - Main Function Example

```c
int main() {
    // Declare and initialize two complex numbers
    struct Compx num1 = {0.3, 0.5}; // 0.3 + 0.5i
    struct Compx num2 = {1.2, -0.8}; // 1.2 - 0.8i
    struct Compx product;

    // Multiply them using the function
    product = multComp(num1, num2);

    // Print the result using the printing function
    printf("Result of multiplication: ");
    printCompx(product);
    printf("\n");

    return 0;
}
```

---

## Exercise 2: Struct Array for QQ Book

* **Task:** Create a simple "QQ Book" using an array of structures to store contact information.
* **Requirements:**
    1.  Define a structure `struct NoteBook` containing two members:
        * `name` (character array, e.g., `char name[30];`)
        * `qq` (integer, e.g., `int qq;`)
    2.  Declare a global array of 4 `struct NoteBook` elements (e.g., `struct NoteBook persons[4];`).
    3.  Implement a function `void readQQbook()` that prompts the user to enter the name and QQ number for each of the 4 persons and stores the input in the global array.
    4.  Implement a function `void printQQbook()` that prints the stored name and QQ number for all 4 persons.
    5.  Call `readQQbook()` and then `printQQbook()` from the `main()` function.

---

## Exercise 2: QQ Book - Implementation Sketch

```c
#include <stdio.h>

// Define the structure
struct NoteBook {
    char name[30];
    int qq;
};

// Declare global array (can hold 4 records)
struct NoteBook persons[4];

// Function to read data into the global array
void readQQbook() {
    printf("Enter data for 4 persons:\n");
    for (int i = 0; i < 4; i++) {
        printf("Person %d\n", i + 1);
        printf("  Name: ");
        scanf("%29s", persons[i].name); // Read name (use width limit)
        printf("  QQ Number: ");
        scanf("%d", &persons[i].qq);   // Read QQ number
    }
}

// Function to print data from the global array
void printQQbook() {
    printf("\n--- QQ Book Contents ---\n");
    for (int i = 0; i < 4; i++) {
        printf("Person %d:\n", i + 1);
        printf("  Name: %s\n", persons[i].name);
        printf("  QQ: %d\n", persons[i].qq);
    }
}

int main() {
    readQQbook();  // Fill the array with user input
    printQQbook(); // Display the contents
    return 0;
}
```

---

## Lab Outline

1.  `struct` Exercises
2.  **`union` Exercise**

---

## Exercise 3: Defining and Using a Union

* **Task:** Define and experiment with a `union`.
* **Requirements:**
    1.  Define a `union` named `Data` that can hold:
        * A `float` member (`f`).
        * A `short` integer member (`i`).
        * A `char` member (`c`).
    2.  Use `typedef` to create an alias `DATA` for `union Data`.
    3.  In `main()`, declare a variable `d1` of type `DATA`.
    4.  Assign a value to one member (e.g., `d1.f = 123.45f;`) and print it.
    5.  Assign a value to a *different* member (e.g., `d1.i = 100;`) and print it.
    6.  Observe the size of the union using `sizeof(DATA)`.

---

## Exercise 3: Union - Implementation Sketch

```c
#include <stdio.h>

// Define the union
union Data {
    float f;
    short i;
    char c;
};

// Use typedef to create an alias
typedef union Data DATA;

int main() {
    // Declare a variable of the union type
    DATA d1;

    printf("Size of union DATA: %zu bytes\n", sizeof(DATA));
    // Should be the size of the largest member (likely float, e.g., 4 bytes)

    // Assign and print float member
    d1.f = 123.45f;
    printf("\nAssigned float: d1.f = %f\n", d1.f);
    // Accessing other members now is undefined/yields garbage interpretation
    // printf("Accessed as short after float assignment: d1.i = %d\n", d1.i);

    // Assign and print short member (overwrites float)
    d1.i = 100;
    printf("\nAssigned short: d1.i = %d\n", d1.i);
    // Accessing other members now is undefined/yields garbage interpretation
    // printf("Accessed as float after short assignment: d1.f = %f\n", d1.f);

    // Assign and print char member (overwrites short)
    d1.c = 'X';
    printf("\nAssigned char: d1.c = %c\n", d1.c);
    // Accessing other members now is undefined/yields garbage interpretation
    // printf("Accessed as short after char assignment: d1.i = %d\n", d1.i);

    return 0;
}
```
