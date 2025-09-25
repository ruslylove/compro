---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lecture 9 - Pointers
---

# Lecture 9: Pointers
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Lecture Outline

1.  **Pointer Fundamentals** (Primitives, `&`, `*`)
2.  Pointer Arithmetic and Arrays
3.  Pointers with Structs and Pointers-to-Pointers
4.  Passing Pointers to Functions
5.  Dynamic Memory Allocation
6.  Application: Linked Lists
7.  Function Pointers

---
layout: two-cols-header
---

## Pointer Fundamentals

::left::

*   We've seen various data types: `int`, `char`, `float`, `array`, `enum`, `union`, `struct`.
*   **Pointer:** A special type of variable whose value is the **memory address** of another variable.
*   Every variable, regardless of its type, resides at a specific memory address.
*   Pointers "point to" the location where data is stored.

```c
int age = 30;
int *ptr_age = &age;
```

::right::
<div style="left:100px;position:relative">
```mermaid {scale: 0.9}
graph TD
    subgraph "Memory"
        A["
            <b>age</b> (int)<br>
            Value: 30<br>
            Address: 0x7ffc1234
        "]
        B["
            <b>ptr_age</b> (int *)<br>
            Value: 0x7ffc1234<br>
            Address: 0x7ffc5678
        "]
    end

    B -- "points to" --> A
```
</div>

---

## Pointer Definition Syntax

* Declaring a pointer variable involves specifying the data type it will point to, followed by an asterisk (`*`), and then the pointer variable name.
* **Syntax:** `data_type *pointer_variable_name;`
* The `*` indicates that `pointer_variable_name` is a pointer.
* `data_type` specifies the type of the variable whose address the pointer will store. This is crucial for pointer arithmetic and dereferencing.

```c
int main() {
    int *ptr_to_int;   // Declares a pointer named 'ptr_to_int'
                       // that can hold the address of an integer variable.

    float *ptr_to_float; // Declares a pointer to a float.

    char *ptr_to_char;   // Declares a pointer to a char.

    // ... pointer initialization and usage ...
    return 0;
}
```

---

## Pointer Initialization

* Like regular variables, pointers should be initialized before use.
* **Initialization Methods:**
    1.  **Using the Address-Of Operator (`&`):** Get the memory address of an existing variable and assign it to the pointer.
        ```c
        int my_var = 10;
        int *ptr = &my_var; // 'ptr' now holds the address of 'my_var'
        ```
    2.  **Assigning `NULL`:** Initialize the pointer to `NULL` (often defined as `(void*)0`) to indicate it doesn't point to a valid memory location yet. This is a safe practice.
        ```c
        float *fptr = NULL;
        ```
    3.  **Assigning Another Pointer:** Copy the address stored in another pointer of the compatible type.
        ```c
        int *ptr1 = &my_var;
        int *ptr2 = ptr1; // ptr2 now also points to my_var
        ```
* **Important:** The pointer type must match the variable type (e.g., `int *` points to `int`, `float *` points to `float`).

---

## The Dereference Operator (`*`)

* Used to access or modify the **value stored at the memory address** held by a pointer.
* When `*` is used in front of an initialized pointer variable (not in a declaration), it means "the value pointed to by".
* **Syntax:** `*pointer_variable`
* **Contrast:**
    * `&variable_name`: Gives the *address* of the variable.
    * `*pointer_variable`: Gives the *value* at the address stored in the pointer.

---

## Dereferencing Examples

```c
#include <stdio.h>

int main() {
    int age = 30;
    int *ptr_age = &age; // ptr_age holds the address of age

    // Accessing the value using dereference
    printf("Value of age (direct): %d\n", age);
    printf("Value of age (via pointer): %d\n", *ptr_age); // *ptr_age reads the value at the address

    // Modifying the value using dereference
    *ptr_age = 31; // Changes the value stored at the address ptr_age points to
    printf("New value of age (direct): %d\n", age); // age is now 31

    // Example with another variable
    int value_read;
    value_read = *ptr_age; // Read the value pointed to by ptr_age into value_read
    printf("Value read via pointer: %d\n", value_read); // Output: 31

    return 0;
}
```



---

## Lecture Outline

1.  Pointer Fundamentals (Primitives, `&`, `*`)
2.  **Pointer Arithmetic and Arrays**
3.  Pointers with Structs and Pointers-to-Pointers
4.  Passing Pointers to Functions
5.  Dynamic Memory Allocation
6.  Application: Linked Lists
7.  Function Pointers

---

## Pointer Arithmetic

* You can perform arithmetic operations (like `+`, `-`, `++`, `--`) on pointers.
* **Key Concept:** Pointer arithmetic is automatically scaled by the **size of the data type** the pointer points to.
* `pointer + 1`: Does *not* add 1 byte to the address. It adds `1 * sizeof(data_type)` bytes, effectively moving the pointer to the **next element** of that type in memory.
* `pointer - 1`: Subtracts `1 * sizeof(data_type)` bytes.
* This makes pointer arithmetic useful for navigating arrays.

---

## Example: Pointer Arithmetic

```c {*}{maxHeight:'420px'}
#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40};
    int *ptr_int = numbers; // Points to numbers[0]

    char letters[] = {'A', 'B', 'C', 'D'};
    char *ptr_char = letters; // Points to letters[0]

    double values[] = {1.1, 2.2, 3.3, 4.4};
    double *ptr_double = values; // Points to values[0]

    printf("Initial addresses:\n");
    printf("ptr_int points to address: %p\n", (void*)ptr_int);
    printf("ptr_char points to address: %p\n", (void*)ptr_char);
    printf("ptr_double points to address: %p\n", (void*)ptr_double);

    // Increment each pointer by 1 element
    ptr_int++;    // Moves forward by sizeof(int) bytes (e.g., 4 bytes)
    ptr_char++;   // Moves forward by sizeof(char) bytes (e.g., 1 byte)
    ptr_double++; // Moves forward by sizeof(double) bytes (e.g., 8 bytes)

    printf("\nAddresses after ptr++:\n");
    printf("ptr_int now points to address: %p (value %d)\n", (void*)ptr_int, *ptr_int);
    printf("ptr_char now points to address: %p (value %c)\n", (void*)ptr_char, *ptr_char);
    printf("ptr_double now points to address: %p (value %.1f)\n", (void*)ptr_double, *ptr_double);

    return 0;
}
// Note: %p is used to print addresses (pointers). Casting to (void*) is good practice.
```

---

## Pointers and Arrays Relationship

* In C, there's a very close relationship between pointers and arrays.
* When an array name is used in most expressions (e.g., assigned to a pointer, passed to a function), it **decays** into a pointer to its first element.
* `int arr[10]; int *ptr = arr;` is equivalent to `int *ptr = &arr[0];`
* This allows accessing array elements using pointer notation and arithmetic.
* **Equivalences:**
    * `arr[i]` is equivalent to `*(arr + i)`
    * `&arr[i]` is equivalent to `arr + i`

---

## Accessing Array Elements Using Pointers

```c {*}{maxHeight:'420px'}
#include <stdio.h>

int main() {
    int numbers[] = {100, 200, 300, 400, 500};
    int *ptr = numbers; // ptr points to numbers[0]
    int i;

    printf("Accessing using array notation (numbers[i]):\n");
    for (i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    printf("\nAccessing using pointer notation (*(ptr + i)):\n");
    ptr = numbers; // Reset pointer to the beginning
    for (i = 0; i < 5; i++) {
        // *(ptr + i) accesses element at index i via pointer arithmetic
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }

    printf("\nAccessing using pointer notation (incrementing ptr):\n");
    ptr = numbers; // Reset pointer
    for (i = 0; i < 5; i++) {
        // *ptr accesses current element, then ptr++ moves to the next
        printf("Value: %d at address %p\n", *ptr, (void*)ptr);
        ptr++;
    }

    return 0;
}
```

---

## Lecture Outline

1.  Pointer Fundamentals (Primitives, `&`, `*`)
2.  Pointer Arithmetic and Arrays
3.  **Pointers with Structs and Pointers-to-Pointers**
4.  Passing Pointers to Functions
5.  Dynamic Memory Allocation
6.  Application: Linked Lists
7.  Function Pointers

---

## Pointers to `struct` Variables (Recap)

* We covered this briefly in the `struct` lecture.
* Declare a pointer of the struct type: `struct MyStruct *ptr;`
* Assign the address of a struct variable: `ptr = &my_struct_var;`
* Access members using the **arrow operator (`->`)**: `ptr->member_name`

```c {*}{maxHeight:'300px'}
#include <stdio.h>

typedef struct { // Using typedef for cleaner syntax
    int id;
    float value;
} Record;

int main() {
    Record r1 = {101, 99.5};
    Record *ptr_r1 = &r1; // Pointer to the Record struct

    // Access using arrow operator
    printf("ID: %d\n", ptr_r1->id);
    printf("Value: %.1f\n", ptr_r1->value);

    // Modify using arrow operator
    ptr_r1->id = 102;
    printf("New ID: %d\n", r1.id); // Change reflected in original

    return 0;
}
```


---
layout: two-cols-header
---

## Pointer to Pointer (Double Pointers)

::left::

*   A pointer can point to another pointer. This is called a **pointer to a pointer** or a **double pointer**.
*   It's a variable that holds the memory address of another pointer variable.
*   **Declaration:** `data_type **pptr;`
*   **Dereferencing:**
    *   `*pptr`: Accesses the pointer it points to (giving you an address).
    *   `**pptr`: Accesses the final value (dereferences twice).

```c
int var = 789;
// Pointer to an int
int *ptr = &var;
// Pointer to a pointer to an int
int **pptr = &ptr;
```

::right::

<div style="left:50px;position:relative">
```mermaid {scale: 0.6}
graph TD
    subgraph "Memory"
        C["<b>var</b> (int)<br>Value: 789<br>Address: 0x7ffc1111"]
        B["<b>ptr</b> (int *)<br>Value: 0x7ffc1111<br>Address: 0x7ffc2222"]
        A["<b>pptr</b> (int **)<br>Value: 0x7ffc2222<br>Address: 0x7ffc3333"]
    end

    A -- "points to address of ptr" --> B
    B -- "points to address of var" --> C
```


`*pptr` evaluates to `0x7ffc1111` (the value of `ptr`).
`**pptr` evaluates to `789` (the value of `var`).

</div>




---
layout: two-cols-header
---

## Passing Pointers to Functions

::left::

### 1. To Modify a Variable's Value (Pass-by-Reference)

*   To allow a function to modify a variable passed to it, you must pass a **pointer** to that variable.
*   The function can then dereference the pointer to change the original variable's value.

```c
void add_five(int *num_ptr) {
    *num_ptr = *num_ptr + 5; // Modifies original
}

int main() {
    int x = 10;
    add_five(&x); // Pass address of x
    // Now, x is 15
}
```
::right::

```mermaid
graph TD
    subgraph "main()"
        X["<b>x</b><br>Value: 10<br>Address: 0xAAA"]
    end
    subgraph "add_five(int *num_ptr)"
        NP["<b>num_ptr</b><br>Value: 0xAAA"]
    end
    NP -- "points to" --> X
```

`*num_ptr` accesses `x`.

---
layout: two-cols-header
---


### 2. To Modify the Pointer Itself
:: left ::
*   To change where a pointer points from within a function (e.g., for memory allocation or linked list manipulation), you must pass a **pointer to that pointer** (`**`).



```c
void allocate_memory(int **ptr_ref) {
    *ptr_ref = (int*)malloc(sizeof(int));
}

int main() {
    int *my_ptr = NULL;
    allocate_memory(&my_ptr); // Pass address of my_ptr
    // my_ptr now points to allocated memory
    free(*my_ptr);
}
```
:: right ::

```mermaid
graph TD
    subgraph "main()"
        MP["<b>my_ptr</b> (int*)<br>Value: NULL<br>Address: 0xBBB"]
    end
    subgraph "allocate_memory(int **ptr_ref)"
        PR["<b>ptr_ref</b> (int**)<br>Value: 0xBBB"]
    end
    PR -- "points to" --> MP
```
`*ptr_ref` accesses `my_ptr`, allowing the function to change it.

---

## Lecture Outline

1.  Pointer Fundamentals (Primitives, `&`, `*`)
2.  Pointer Arithmetic and Arrays
3.  Pointers with Structs and Pointers-to-Pointers
4.  Passing Pointers to Functions
5.  **Dynamic Memory Allocation**
6.  Application: Linked Lists
7.  Function Pointers

---

## Static vs. Dynamic Memory Allocation

* **Static Allocation:** Memory for global variables, static variables, and (conceptually) local variables is allocated by the compiler/loader either at compile time or when a function is called (on the **stack**). The size and lifetime are fixed.
* **Dynamic Allocation:** Allows programs to request blocks of memory of variable size *during runtime* from a memory pool called the **heap**. This memory persists until explicitly deallocated. Essential for data structures that grow or shrink (like linked lists, trees) or when memory needs are unknown until runtime.
* Managed using pointers and library functions from `<stdlib.h>`.

---

## Dynamic Allocation Functions (`<stdlib.h>`)

1.  **`malloc(size_t size)`:** (Memory Allocation)
    * Allocates a block of memory of at least `size` bytes on the heap.
    * Returns a `void*` (generic pointer) to the beginning of the allocated block.
    * Returns `NULL` if allocation fails (e.g., heap is full).
    * The allocated memory is **uninitialized** (contains garbage values).
    * **Usage:** `ptr = (data_type *)malloc(num_elements * sizeof(data_type));`
        * Cast the `void*` result to the desired pointer type.
        * Calculate size using `sizeof()`.
        * **Always check if the returned pointer is `NULL`**.
2.  **`calloc(size_t num, size_t size)`:** (Contiguous Allocation)
    * Allocates memory for an array of `num` elements, each of `size` bytes.
    * Initializes the allocated memory to **zero**.
    * Returns `void*` or `NULL`.

---

## Dynamic Allocation Functions (`<stdlib.h>`) (Cont.)

3.  **`realloc(void *ptr, size_t new_size)`:**
    * Resizes a previously allocated memory block (pointed to by `ptr`) to `new_size`.
    * May move the memory block; returns the new address (or `NULL` on failure).
    * Preserves existing content up to the minimum of the old and new sizes.
4.  **`free(void *ptr)`:**
    * Deallocates a block of memory previously allocated by `malloc`, `calloc`, or `realloc`.
    * The pointer `ptr` must point to the *start* of a dynamically allocated block.
    * **Crucial:** Failure to `free` memory leads to **memory leaks**. Freeing already freed memory or invalid pointers causes undefined behavior.

---

## `malloc` Example: Allocating a Single Integer

```c {*}{maxHeight:'430px'}
#include <stdio.h>
#include <stdlib.h> // Required for malloc, free

int main() {
    int *ptr_int = NULL; // Initialize pointer to NULL

    // Allocate memory for one integer on the heap
    ptr_int = (int *)malloc(sizeof(int));

    // ALWAYS check if malloc succeeded
    if (ptr_int == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Indicate error
    }

    // Use the allocated memory via the pointer
    *ptr_int = 123;
    printf("Value stored in dynamic memory: %d\n", *ptr_int);

    // Deallocate the memory when done
    free(ptr_int);
    ptr_int = NULL; // Good practice: set pointer to NULL after freeing

    return 0;
}
```

---

## `malloc` Example: Allocating an Array Dynamically

```c {*}{maxHeight:'430px'}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_elements = 5;
    int *dyn_array = NULL; // Pointer for the dynamic array
    int i;

    // Allocate memory for 'num_elements' integers
    dyn_array = (int *)malloc(num_elements * sizeof(int));

    // Check allocation result
    if (dyn_array == NULL) {
        printf("Failed to allocate memory for the array.\n");
        return 1;
    }

    // Use the dynamic array like a regular array
    printf("Enter %d integers:\n", num_elements);
    for (i = 0; i < num_elements; i++) {
        // dyn_array[i] is equivalent to *(dyn_array + i)
        scanf("%d", &dyn_array[i]);
    }

    printf("You entered:\n");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", dyn_array[i]);
    }
    printf("\n");

    // IMPORTANT: Free the allocated array memory
    free(dyn_array);
    dyn_array = NULL; // Set pointer to NULL

    return 0;
}
```

---

## Importance of `free()` - Memory Leaks

* Dynamically allocated memory (from the heap) is **not automatically reclaimed** when pointers go out of scope (unlike stack variables).
* If you allocate memory with `malloc`/`calloc` and lose all pointers to that memory block *without* calling `free()`, that memory becomes inaccessible for the rest of the program's execution. This is a **memory leak**.
* Accumulating memory leaks can exhaust available heap memory, causing future allocations to fail or the program to crash.
* **Rule:** For every successful `malloc`/`calloc`/`realloc`, there should eventually be a corresponding `free()` call when the memory is no longer needed.

---

## Lecture Outline

1.  Pointer Fundamentals (Primitives, `&`, `*`)
2.  Pointer Arithmetic and Arrays
3.  Pointers with Structs and Pointers-to-Pointers
4.  Passing Pointers to Functions
5.  Dynamic Memory Allocation
6.  **Application: Linked Lists**
7.  Function Pointers

---

## Why Not Just Use Arrays?

Arrays are great for storing collections of data, but they have some significant limitations, especially when the data size changes frequently.
*   **Fixed Size:**
    *   The size of an array is fixed when it is created (either at compile-time or with a single `malloc` call).
    *   If the array fills up, you must allocate a new, larger array and copy all the old elements over. This is a slow operation.
*   **Inefficient Insertions & Deletions:**
    *   To insert or delete an element in the middle of an array, you must shift all subsequent elements.
    *   For an array with `N` elements, this can take up to $O(N)$ time, which is very inefficient for large collections.
*   **Wasted Memory:**
    *   If you allocate a large array to anticipate future needs but only use a small portion of it, the unused memory is wasted.
**So, we need a data structure that can grow and shrink easily. This is where Linked Lists come in.**

---

## Introduction to Linked Lists

*   A **Linked List** is a dynamic data structure that solves these problems. It's a sequence of elements (**nodes**) where each node is linked to the next one using pointers.
*   It can easily grow or shrink at runtime without needing to reallocate and copy the entire structure.
* Each node typically contains:
    1.  **Data:** The actual value stored in the node.
    2.  **Pointer(s):** One or more pointers linking to the next (and possibly previous) node in the sequence.
* The list is accessed starting from a **head** pointer, which points to the first node. The last node's "next" pointer is typically `NULL`.




---
layout: default
---

## Linked List Node Structure

*   A node is defined using a `struct`.
*   A common pattern is a **self-referential structure**, where the `struct` contains a pointer to its own type.
*   This `next` pointer is the "link" that connects one node to the next one in the chain.
```c
// Define the structure for a node in a singly linked list
typedef struct NodeTag {
    int data;             // Data stored in the node (e.g., an integer)
    struct NodeTag *next; // Pointer to the next node in the list
} Node;
```

* A single node in memory consists of its data and a pointer to the next node.

```mermaid
graph LR
    A["<b>Node</b><br>Address: 0x7ffc1234<br><b>data</b>(int): 10<br><b>next</b>(Node*) :0x7ffc5678<hr>"]
    B["<b>Node</b><br>Address: 0x7ffc5678<br><b>data</b>(int): 20<br><b>next</b>(Node*) :NULL<hr>"]
    A --> B
```

---

## Basic Linked List Operations

* **Traversal:** Iterating through the list from head to tail, usually following the `next` pointers.
* **Insertion:** Adding a new node (e.g., at the beginning, end, or middle). Requires updating `next` pointers.
* **Deletion:** Removing a node. Requires updating the `next` pointer of the *previous* node to bypass the deleted node, then `free`ing the deleted node's memory.
* **Searching:** Finding a node with a specific data value.

*Implementing these operations requires careful pointer manipulation.*

---

## Visualizing a Linked List

A linked list is a chain of nodes, starting from a `head` pointer. The last node points to `NULL`.



**Concept:**
- The `head` is your entry point.
- Each `Node` contains data and a `next` pointer.
- You follow the `next` pointers to traverse the list.
- The chain ends when a `next` pointer is `NULL`.

<br>

```mermaid
graph LR
    
        Head(Head) --> Node1["data |  next"]
        Node1 -- "addr_of_node2" --> Node2["data |  next"]
        Node2 -- "addr_of_node3" --> Node3["data |  next"]
        Node3 -- "NULL" --> End(( ))
    
    style End fill:#000,stroke:#333,stroke-width:4px
```



---
layout: two-cols-header
---

## Operation: Add to Front (Prepend)

Adding a node to the beginning of the list is efficient.

:: left ::

**Steps:**
1.  Allocate memory for the `newNode`.
2.  Set the `newNode`'s data.
3.  Point `newNode->next` to the current `head` of the list.
4.  Update `head` to point to the `newNode`.

:: right ::

```c
void addFirst(Node **head_ref, int new_data) {
    // 1. Allocate new node
    Node* new_node = (Node*)malloc(sizeof(Node));

    // 2. Put in the data
    new_node->data = new_data;

    // 3. Make next of new node as head
    new_node->next = (*head_ref);

    // 4. Move the head to point to the new node
    (*head_ref) = new_node;
}

// To call:
// Node *head = NULL;
// addFirst(&head, 10);
// addFirst(&head, 5); // List is now 5 -> 10 -> NULL
```

---

## Visualization: Add to Front
**Visualization: `addFirst(&head, 5)`**

```mermaid
graph LR
    subgraph "Before"
        H1[head] --> N1(10)
        N1 --> N2(20)
        N2 --> NUL1((NULL))
    end

    subgraph "After"
        NewNode("5<br>(new_node)")
        H2[head] --> NewNode
        NewNode -. "new_node.next = head" .-> N1
    end

    H1 -. "head.next = new_node" .-> H2
```



---
layout: two-cols-header
---

## Operation: Remove from Front

Removing the first node is also very fast.
:: left ::
**Steps:**
1.  Check if the list is empty (`head` is `NULL`). If so, do nothing.
2.  Create a temporary pointer `temp` to store the current `head`.
3.  Move `head` to the next node (`head = head->next`).
4.  `free` the memory of the old head using the `temp` pointer.

<br><br>

:: right ::

```c
void removeFirst(Node **head_ref) {
    // 1. Check if list is empty
    if (*head_ref == NULL) {
        return;
    }

    // 2. Store old head
    Node *temp = *head_ref;

    // 3. Move head to next node
    *head_ref = temp->next;

    // 4. Free old head
    free(temp);
}

// To call:
// removeFirst(&head);
```

---

## Visualization: Remove from Front

**Visualization: `removeFirst(&head)`**

```mermaid {scale: 0.9}
graph LR
    subgraph "Before"
        H1[head] --> N1(10)
        N1 --> N2(20)
        N2 --> NUL1((NULL))
    end

    subgraph "After"
        H2[head] --> N2
    end

    subgraph "Freed"
      F(10)
    end

    H1 -. "head = head.next" .-> H2
    N1 --> F
```

---
layout: two-cols-header
---

## Operation: Add to End (Append)

Adding a node to the end requires traversing the list.
::left::
**Steps:**
1.  Allocate memory for the `newNode`.
2.  Set its data and set `newNode->next` to `NULL`.
3.  **If the list is empty:** set `head` to `newNode`.
4.  **Otherwise:** Traverse the list until you find the last node (where `current->next` is `NULL`).
5.  Point the `next` of that last node to `newNode`.

::right::

```c
void addLast(Node **head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;

    // If list is empty, new node is the head
    if (*head_ref == NULL) {
       *head_ref = new_node;
       return;
    }

    // Else, traverse till the last node
    Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new_node;
}
```

---

## Visualization: Add to End (Append)

**Visualization: `addLast(&head, 30)`**

```mermaid
graph LR
    subgraph "Before"
        H1[head] --> N1(10)
        N1 --> N2(20)
        N2 -.-> NUL1((NULL))
    end

    subgraph "After"
        N2 --"(last_node).next = new_node"--> NewNode(30)
        NewNode -- "new_node.next = NULL"--> NUL2((NULL))
    end

    
    
```



---

## Linked List Example: Creating a Simple List

```c {*}{maxHeight:'430px'}
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTag {
    int data;
    struct NodeTag *next;
} Node;

int main() {
    Node *head = NULL; // Start with an empty list
    Node *second = NULL;
    Node *third = NULL;

    // Allocate three nodes dynamically
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    // Check allocation
    if (!head || !second || !third) {
        printf("Memory allocation failed\n"); return 1;
    }

    // Assign data and link them: head -> second -> third -> NULL
    head->data = 1;
    head->next = second; // Link first to second

    second->data = 2;
    second->next = third; // Link second to third

    third->data = 3;
    third->next = NULL; // Mark end of the list

    // Traverse and print the list
    Node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");

    // Free the allocated memory (important!)
    free(head);
    free(second);
    free(third); // In a real scenario, free nodes during traversal or deletion

    return 0;
}
```

---

## Lecture Outline

1.  Pointer Fundamentals (Primitives, `&`, `*`)
2.  Pointer Arithmetic and Arrays
3.  Pointers with Structs and Pointers-to-Pointers
4.  Passing Pointers to Functions
5.  Dynamic Memory Allocation
6.  Application: Linked Lists
7.  **Function Pointers**

---

## Function Pointers

* Just like variables, functions also reside in memory and therefore have addresses.
* A **function pointer** is a pointer variable that stores the memory address of a function.
* Allows functions to be treated like data: stored, passed as arguments to other functions, returned from functions.
* Useful for implementing callbacks, creating dispatch tables (like virtual functions in OOP), and generic algorithms.

---

## Function Pointer Declaration Syntax

* The declaration must match the **signature** (return type and parameter types) of the functions it can point to.
* **Syntax:** `return_type (*pointer_name)(parameter_type_list);`
* **Key elements:**
    * `return_type`: The return type of the function being pointed to.
    * `(*pointer_name)`: The name of the pointer variable, enclosed in parentheses and preceded by `*`. The parentheses are crucial to distinguish it from a function declaration returning a pointer.
    * `(parameter_type_list)`: The list of parameter types the function takes.

```c
// Example: Declare a pointer 'pFunc' that can point to functions
// which take two integers as input and return an integer.
int (*pFunc)(int, int);

// Example: Pointer to a function taking no args, returning void
void (*callback_ptr)(void);

// Example: Pointer to a function taking float*, returning double
double (*process_data_ptr)(float *);
```

---

## Assigning and Using Function Pointers

* **Assignment:** Assign the address of a compatible function using the function name (which decays into a pointer, similar to arrays) or explicitly using the address-of operator `&`.
    ```c
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }

    int (*operation_ptr)(int, int); // Declare function pointer

    operation_ptr = add;      // Assign address of add function
    // OR
    operation_ptr = &subtract; // Assign address of subtract function
    ```
* **Calling:** Call the function through the pointer using syntax similar to a regular function call, or by explicitly dereferencing the pointer first (less common).
    ```c
    int result1 = operation_ptr(10, 5); // Call function via pointer (preferred)
    int result2 = (*operation_ptr)(20, 8); // Explicit dereference also works
    ```

---

## Example: Using Function Pointers

```c {*}{maxHeight:'430px'}
#include <stdio.h>

// Functions with matching signatures
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

// Function that takes a function pointer as an argument
void perform_operation(int x, int y, int (*op_func)(int, int)) {
    int result = op_func(x, y); // Call the passed function via pointer
    printf("Operation result: %d\n", result);
}

int main() {
    // Declare a function pointer
    int (*calculator_ptr)(int, int);

    // Assign 'add' to the pointer
    calculator_ptr = add;
    printf("Calling via pointer (add): %d\n", calculator_ptr(5, 3)); // Output: 8

    // Assign 'multiply' to the pointer
    calculator_ptr = multiply;
    printf("Calling via pointer (multiply): %d\n", calculator_ptr(5, 3)); // Output: 15

    // Pass function pointers as arguments (Callbacks)
    printf("\nUsing perform_operation:\n");
    perform_operation(10, 2, add);      // Pass 'add' function
    perform_operation(10, 2, multiply); // Pass 'multiply' function

    return 0;
}
```


---
layout: default
---

## Summary
<Transform scale="0.85">

*   **Pointers:** Variables that store memory addresses of other variables.
*   **Operators:**
    *   `&` (Address-Of): Gets the memory address of a variable.
    *   `*` (Dereference): Accesses the value at the address a pointer holds.
*   **Pointers and Arrays:** An array name decays into a pointer to its first element. `arr[i]` is equivalent to `*(arr + i)`.
*   **Dynamic Memory Allocation (`<stdlib.h>`):**
    *   `malloc()`: Allocates a block of memory on the heap. Returns a pointer or `NULL` on failure.
    *   `free()`: Deallocates memory to prevent memory leaks. Every `malloc` needs a corresponding `free`.
*   **Linked Lists:** A dynamic data structure where nodes containing data are linked via pointers. They can grow and shrink at runtime.
*   **Function Pointers:** Pointers that store the address of a function, allowing functions to be passed as arguments (callbacks).

</Transform>

<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="lab9" title="Go to Lab9 👩‍🔬"/>
</div>
