---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lecture 7 - struct, union, and enum
---

# Computer Programming
## Lecture 7: struct, union, and enum

Presented by: Dr. Ruslee Sutthaweekul

Semester 1/2025

---

## Motivating Example: Complex Student Records

* **Problem:** Imagine needing to store detailed information for 40 students, including:
    1.  Student number (string/char array)
    2.  Name (string/char array)
    3.  Age (integer)
    4.  Gender (string/char array or char)
    5.  Height (float)
    6.  GPA (float)
* **Approach Using Only Arrays/Simple Variables:** We could use parallel arrays: one for names, one for numbers, one for ages, etc.
    ```c
    char std_names[40][64];
    char std_numbers[40][11];
    int std_ages[40];
    char std_genders[40][5];
    // ... etc.
    ```
* **Challenge:** Managing these parallel arrays becomes very complex. Keeping track of which index corresponds to which student across all arrays is error-prone. There's no single entity representing *a student*. We need a way to group related data of different types together.

---

## Lecture Outline

1.  **`struct` (Structures)**
2.  `union` (Unions)
3.  `enum` (Enumerations)

---

## Composite Data Types: `struct` (Part 1)

* While using parallel arrays is possible, it's inconvenient for managing records with different data types.
* C allows us to define **composite data types** using the `struct` keyword.
* A `struct` (structure) groups together variables (called **members** or **fields**) of potentially different data types under a single name.
* This creates a new, custom data type template.

---

## Defining a `struct` (Part 2)

* **Syntax:**
    ```c
    struct StructureTagName {
        data_type member1_name;
        data_type member2_name;
        // ... other members ...
    }; // Note the semicolon at the end!
    ```
* `struct`: Keyword to declare a structure.
* `StructureTagName`: An optional name (tag) for this structure template.
* `memberX_name`: Name of a variable within the structure.
* `data_type`: The type of that member (can be primitive types, arrays, other structs, pointers, etc.).

**Example: Student Record Structure**
```c
struct Student {
    char student_name[64];
    char student_number[11];
    int age;
    char gender[7]; // e.g., "Male", "Female"
    float height;
    float gpa;
}; // Semicolon is mandatory here
```
* This defines a *template* called `Student`. It doesn't create any variables yet.

---

## Lecture Outline

1.  **`struct` (Structures)**
    * Declaration, Definition, Member Access
    * Pointers to Structs
    * Nested Structs
    * `typedef` with Structs
    * Memory Allocation & Padding
2.  `union` (Unions)
3.  `enum` (Enumerations)

---

## Using `struct`: Declaring Variables

* Once a `struct` template is defined, you can declare variables of that structure type.
* **Syntax:** `struct StructureTagName variable_name;`

```c
// Define the template
struct Student {
    char student_name[64];
    char student_number[11];
    int age;
    float gpa;
};

int main() {
    // Declare a variable 's1' of type 'struct Student'
    struct Student s1;

    // Declare another variable 's2'
    struct Student s2;

    // We can also declare an array of structures
    struct Student class_list[40]; // An array to hold 40 student records

    // ... code to work with s1, s2, class_list ...
    return 0;
}
```

---

## Accessing `struct` Members: The Dot Operator (`.`)

* To access or modify individual members within a `struct` variable, use the **dot operator (`.`)**.
* **Syntax:** `structure_variable_name.member_name`

```c
#include <stdio.h>
#include <string.h> // For strcpy

struct Student {
    char student_name[64];
    int age;
    float gpa;
};

int main() {
    struct Student s1;

    // Assign values to members using the dot operator
    strcpy(s1.student_name, "Alice"); // Use strcpy for strings
    s1.age = 20;
    s1.gpa = 3.8;

    // Access and print member values
    printf("Student Name: %s\n", s1.student_name);
    printf("Age: %d\n", s1.age);
    printf("GPA: %.2f\n", s1.gpa);

    // Access element in an array of structs
    struct Student class_list[5];
    strcpy(class_list[0].student_name, "Bob");
    class_list[0].age = 21;
    printf("\nFirst student in list: %s\n", class_list[0].student_name);

    return 0;
}
```

---

## Initializing `struct` Variables

* Similar to arrays, you can initialize `struct` variables upon declaration using curly braces `{}`.
* Values must be provided in the order the members are declared in the `struct` definition.

```c
struct Student {
    char student_name[64];
    int age;
    float gpa;
};

int main() {
    // Initialize s1 using aggregate initializer
    struct Student s1 = {"Carol", 19, 3.5};

    // Designated initializers (C99+) - more robust
    struct Student s2 = {.gpa = 3.9, .student_name = "David", .age = 22};

    printf("s1: Name=%s, Age=%d, GPA=%.1f\n", s1.student_name, s1.age, s1.gpa);
    printf("s2: Name=%s, Age=%d, GPA=%.1f\n", s2.student_name, s2.age, s2.gpa);

    return 0;
}
```

---

## Pointers to `struct`s

* You can declare pointers that hold the memory address of a `struct` variable.
* **Syntax:** `struct StructureTagName *pointer_name;`

```c
struct Student {
    char student_name[64];
    int age;
    float gpa;
};

int main() {
    struct Student s1 = {"Eve", 20, 3.7};
    struct Student *ptr_s1; // Declare a pointer to a Student struct

    // Assign the address of s1 to the pointer
    ptr_s1 = &s1;

    // ... access members using the pointer ...
    return 0;
}
```

---

## Accessing Members via Pointers: Arrow Operator (`->`)

* When you have a pointer to a `struct`, you **cannot** use the dot (`.`) operator directly on the pointer itself.
* You need to use the **arrow operator (`->`)** to access members through a pointer.
* **Syntax:** `structure_pointer_name->member_name`
* This is equivalent to first dereferencing the pointer (`*pointer_name`) and then using the dot operator (`(*pointer_name).member_name`), but the arrow operator is much more common and readable.

```c
#include <stdio.h>
#include <string.h>

struct Student {
    char student_name[64];
    int age;
    float gpa;
};

int main() {
    struct Student s1 = {"Frank", 21, 3.2};
    struct Student *ptr_s1 = &s1; // Pointer holds address of s1

    // Access members using the arrow operator ->
    printf("Name (via ptr): %s\n", ptr_s1->student_name);
    printf("Age (via ptr): %d\n", ptr_s1->age);

    // Modify member using the arrow operator
    ptr_s1->gpa = 3.3;
    printf("New GPA (via original): %.1f\n", s1.gpa); // Change reflected in original

    // Equivalent access using dereference and dot (less common)
    printf("Age (via *ptr.): %d\n", (*ptr_s1).age);

    return 0;
}
```

---

## Nested `struct`s

* A `struct` can contain members that are themselves other `struct`s.

```c
#include <stdio.h>
#include <string.h>

// Define a Date structure
struct Date {
    int day;
    int month;
    int year;
};

// Define a Student structure that includes a Date structure
struct Student {
    char student_name[64];
    struct Date birthday; // Nested structure
    float gpa;
};

int main() {
    struct Student s1;

    // Access nested members using multiple dot operators
    strcpy(s1.student_name, "Grace");
    s1.birthday.day = 15;
    s1.birthday.month = 6;
    s1.birthday.year = 2003;
    s1.gpa = 3.9;

    printf("Name: %s\n", s1.student_name);
    printf("Birthday: %d/%d/%d\n", s1.birthday.day, s1.birthday.month, s1.birthday.year);

    // Using pointers
    struct Student *ptr_s1 = &s1;
    printf("Birthday Year (via ptr): %d\n", ptr_s1->birthday.year);

    return 0;
}
```

---

## The `typedef` Keyword

* `typedef` allows you to create an **alias** (a synonym) for an existing data type.
* It doesn't create a new type, just another name for an existing one.
* Commonly used with `struct` definitions to make declaring variables less verbose (avoiding repeating `struct StructureTagName`).
* **Syntax:** `typedef existing_type_definition NewTypeName;`

```c
// Original struct definition
struct ComplexNumber {
    double real;
    double imag;
};

// Using typedef to create an alias 'Complex'
typedef struct ComplexNumber Complex;

// Can also combine definition and typedef
typedef struct PointTag {
    int x;
    int y;
} Point; // 'Point' is now an alias for 'struct PointTag'

int main() {
    // Declare using the original name
    struct ComplexNumber c1;
    // Declare using the typedef'd alias 'Complex'
    Complex c2;

    // Declare using the typedef'd alias 'Point'
    Point p1 = {10, 20};

    c2.real = 1.0;
    c2.imag = -2.5;
    printf("Point p1: (%d, %d)\n", p1.x, p1.y);
    printf("Complex c2: %.1f + %.1fi\n", c2.real, c2.imag);

    return 0;
}
```
* Using `typedef` (like `Point` or `Complex` above) makes variable declarations cleaner than using `struct PointTag` or `struct ComplexNumber`.

---

## Memory Allocation for `struct`s & Padding

* Members of a `struct` are typically allocated in memory in the order they are declared.
* However, compilers often insert unused bytes (**padding**) between members or after the last member.
* **Why padding?** To ensure that each member is aligned on a memory address that is efficient for the CPU to access (e.g., ensuring an `int` starts on an address divisible by 4, or a `double` on an address divisible by 8).
* **Consequence:** The total size of a `struct` (`sizeof(struct StructureTagName)`) might be **larger** than the sum of the sizes of its individual members due to this padding. The exact padding rules depend on the compiler and system architecture.

```c
#include <stdio.h>

typedef struct Example {
    char c1;   // 1 byte
    // Potential padding here (e.g., 3 bytes)
    int i;     // 4 bytes
    char c2;   // 1 byte
    // Potential padding here (e.g., 3 bytes to align next struct or end on boundary)
} ExampleStruct;

int main() {
    printf("Size of char: %zu\n", sizeof(char)); // Usually 1
    printf("Size of int: %zu\n", sizeof(int));   // Usually 4
    printf("Size of ExampleStruct: %zu\n", sizeof(ExampleStruct)); // Might be 12 or 16, not 1+4+1=6

    return 0;
}
```
* Don't assume the size of a struct is just the sum of its parts. Use `sizeof()` to get the actual size.

---

## Lecture Outline

1.  `struct` (Structures)
2.  **`union` (Unions)**
3.  `enum` (Enumerations)

---

## `union` Overview

* A `union` is another user-defined data type, similar in declaration syntax to `struct`.
* **Key Difference:** Whereas `struct` members occupy *separate* memory locations, `union` members **share the same memory location**.
* Only **one** member of the `union` can hold a valid value at any given time. Assigning a value to one member overwrites the memory used by other members.
* Useful for saving memory when you know only one of several possible data types will be needed at a time, or for interpreting the same raw memory bytes as different data types.
* **Syntax:**
    ```c
    union UnionTagName {
        data_type member1;
        data_type member2;
        // ...
    };
    ```

---

## `union` Example

```c
#include <stdio.h>

// Define a union to hold either an integer or a float
union DataValue {
    int i;
    float f;
    char str[20]; // Can also include arrays, etc.
};

int main() {
    union DataValue data;

    // Store an integer
    data.i = 10;
    printf("Data as int: %d\n", data.i);

    // Now store a float (overwrites the integer)
    data.f = 220.5;
    printf("Data as float: %.1f\n", data.f);
    // printf("Data as int (after float assignment): %d\n", data.i); // Reading data.i now is invalid!

    // Store a string (overwrites the float)
    strcpy(data.str, "Hello");
    printf("Data as string: %s\n", data.str);
    // printf("Data as float (after string assignment): %.1f\n", data.f); // Reading data.f now is invalid!

    return 0;
}
```
* It's the programmer's responsibility to keep track of which member currently holds the valid data.

---

## `union` Memory Allocation & Size

* The amount of memory allocated for a `union` is determined by the size of its **largest member**.
* All members start at the same memory address.

```c
#include <stdio.h>

union ExampleUnion {
    int i;     // Typically 4 bytes
    double d;  // Typically 8 bytes
    char c;    // Typically 1 byte
};

int main() {
    printf("Size of int: %zu\n", sizeof(int));
    printf("Size of double: %zu\n", sizeof(double));
    printf("Size of char: %zu\n", sizeof(char));
    // Size of union will be size of the largest member (double)
    printf("Size of ExampleUnion: %zu\n", sizeof(union ExampleUnion)); // Usually 8

    return 0;
}
```

---

## Lecture Outline

1.  `struct` (Structures)
2.  `union` (Unions)
3.  **`enum` (Enumerations)**

---

## `enum` Overview (Enumerated Types)

* An `enum` allows you to define a set of named **integer constants**, called **enumerators**.
* Primarily used to improve code readability and maintainability by giving meaningful names to integer values that represent specific states, types, or options.
* **Syntax:**
    ```c
    enum EnumTagName {
        ENUMERATOR_1, // Assigned 0 by default
        ENUMERATOR_2, // Assigned 1 by default
        ENUMERATOR_3, // Assigned 2 by default
        // ...
    };
    ```
    OR assigning specific values:
    ```c
    enum EnumTagName {
        ENUMERATOR_A = 1,
        ENUMERATOR_B = 5,
        ENUMERATOR_C, // Assigned 6 (previous + 1)
        ENUMERATOR_D = 10
    };
    ```
* Underneath, enumerators are simply `int` values.

---

## Using `enum`

* Improves readability compared to using raw numbers or `#define` macros for related constants.

```c
#include <stdio.h>

// Define an enumeration for days of the week
enum Day {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
}; // SUNDAY=0, MONDAY=1, ..., SATURDAY=6

// Define enumeration for basic colors with specific values
enum Color {
    RED = 1,
    GREEN = 2,
    BLUE = 4
};

int main() {
    // Declare a variable of the enum type
    enum Day today = WEDNESDAY; // More readable than 'int today = 3;'

    if (today == WEDNESDAY || today == TUESDAY) {
        printf("It's a weekday.\n");
    } else {
        printf("It's the weekend or Monday/Thursday/Friday.\n");
    }

    // Use the named constant
    enum Color my_color = BLUE;
    printf("Color value: %d\n", my_color); // Output: 4

    return 0;
}
```

---

## `enum` Value Assignment Details

* If no values are explicitly assigned, the first enumerator gets `0`, and subsequent enumerators get the value of the previous one plus `1`.
* If a value is assigned, subsequent unassigned enumerators continue incrementing from the last assigned value.
* Multiple enumerators can have the same integer value (though this might reduce clarity).

```c
#include <stdio.h>

// Example with mixed assignment
enum Status {
    PENDING,         // 0
    PROCESSING,      // 1
    COMPLETE = 10,
    FAILED,          // 11
    CANCELLED = 10,  // Same value as COMPLETE
    RETRY = 20
};

int main() {
    printf("PENDING = %d\n", PENDING);       // Output: 0
    printf("PROCESSING = %d\n", PROCESSING);   // Output: 1
    printf("COMPLETE = %d\n", COMPLETE);     // Output: 10
    printf("FAILED = %d\n", FAILED);         // Output: 11
    printf("CANCELLED = %d\n", CANCELLED);   // Output: 10
    printf("RETRY = %d\n", RETRY);           // Output: 20
    return 0;
}
```
* Be mindful of implicit assignments when explicitly setting values.
