---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lecture 11 - Bitwise Operations
---

# Lecture 10: Bitwise Operations
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Lecture Outline

1.  Overview of Bitwise Operations
2.  Applications of Bitwise Operations

---

## Why Bitwise Operations?

* As we know, data inside computers is stored in binary format (sequences of 0s and 1s), like `10101111`.
* Each binary representation corresponds to some data item (integer, float, character, etc.).
* In certain situations, particularly in system programming, embedded systems, or performance-critical code, we need to directly manipulate individual bits within these binary representations.
* For instance, how could we easily extract the lower 4 bits (`1111`) from the binary code `10101111`? Bitwise operations provide the tools for this.

---

## The Bitwise Operators in C

C provides six operators specifically designed for bit-level manipulation:

* `&` : Bitwise AND
* `|` : Bitwise OR
* `^` : Bitwise XOR (Exclusive OR)
* `~` : Bitwise NOT (One's Complement)
* `<<`: Left Shift
* `>>`: Right Shift

*These operators work directly on the binary representations of integer types (`int`, `char`, `short`, `long`, including unsigned variants).*

---

## Truth Tables for `&`, `|`, `^`

These operators compare corresponding bits of their operands:

**Bitwise AND (`&`)**
(Result is 1 only if *both* bits are 1)
| Bit 1 | Bit 2 | Bit 1 & Bit 2 |
| :---- | :---- | :------------ |
| 1     | 1     | 1             |
| 1     | 0     | 0             |
| 0     | 1     | 0             |
| 0     | 0     | 0             |

**Bitwise OR (`|`)**
(Result is 1 if *at least one* bit is 1)
| Bit 1 | Bit 2 | Bit 1 \| Bit 2 |
| :---- | :---- | :------------- |
| 1     | 1     | 1              |
| 1     | 0     | 1              |
| 0     | 1     | 1              |
| 0     | 0     | 0              |

---

## Truth Table for `^` (XOR)

**Bitwise XOR (`^`)**
(Result is 1 if the bits are *different*)
| Bit 1 | Bit 2 | Bit 1 ^ Bit 2 |
| :---- | :---- | :------------ |
| 1     | 1     | 0             |
| 1     | 0     | 1             |
| 0     | 1     | 1             |
| 0     | 0     | 0             |

---

## Bitwise Operator Examples (`&`, `|`, `^`)

Let's see how these work on integer values, considering their binary forms. Assume `int` is 8 bits for simplicity here.

* `a = 60;` (Binary: `0011 1100`)
* `b = 13;` (Binary: `0000 1101`)

**`a & b` (Bitwise AND):**
```
  0011 1100  (60)
& 0000 1101  (13)
-----------
  0000 1100  (12)  <-- Result
```

**`a | b` (Bitwise OR):**
```
  0011 1100  (60)
| 0000 1101  (13)
-----------
  0011 1101  (61)  <-- Result
```

**`a ^ b` (Bitwise XOR):**
```
  0011 1100  (60)
^ 0000 1101  (13)
-----------
  0011 0001  (49)  <-- Result
```

---

## Code Example (`&`, `|`, `^`)

```c
#include <stdio.h>

int main() {
    unsigned char a = 60;  // 0011 1100
    unsigned char b = 13;  // 0000 1101
    unsigned char result;

    // Bitwise AND
    result = a & b; // 0000 1100
    printf("%d & %d = %d\n", a, b, result); // Output: 60 & 13 = 12

    // Bitwise OR
    result = a | b; // 0011 1101
    printf("%d | %d = %d\n", a, b, result); // Output: 60 | 13 = 61

    // Bitwise XOR
    result = a ^ b; // 0011 0001
    printf("%d ^ %d = %d\n", a, b, result); // Output: 60 ^ 13 = 49

    return 0;
}
```
*(Using `unsigned char` for clearer 8-bit examples)*

---

## Bitwise NOT (`~`) Operator

* This is a **unary** operator (takes only one operand).
* It performs the **one's complement**, flipping each bit of its operand (0 becomes 1, 1 becomes 0).

* `a = 60;` (Binary: `0011 1100`)

**`~a` (Bitwise NOT):**
```
~ 0011 1100  (60)
-----------
  1100 0011  (Decimal value depends on interpretation:
             - Unsigned: 195
             - Signed (Two's Complement): -61)
```

---

## Code Example (`~`)

```c
#include <stdio.h>

int main() {
    unsigned char a = 60;  // 0011 1100
    unsigned char result;

    result = ~a; // 1100 0011
    printf("~%d = %u\n", a, result); // Output: ~60 = 195 (using %u for unsigned)

    // Example with signed int (behavior depends on system's int size and two's complement)
    int signed_a = 60;
    int signed_result = ~signed_a;
    printf("~%d (signed) = %d\n", signed_a, signed_result); // Likely outputs -61

    return 0;
}
```

---

## Left Shift (`<<`) Operator

* Shifts the bits of the left operand to the **left** by the number of positions specified by the right operand.
* Vacated bits on the right are filled with **zeros**.
* Bits shifted off the left end are discarded.
* **Effect:** Equivalent to multiplying the left operand by $2^{\text{right operand}}$ (if the result doesn't overflow).

* `a = 60;` (Binary: `0011 1100`)

**`a << 2` (Left Shift by 2):**
```
  0011 1100  (60) << 2
-----------
  1111 0000  (240) <-- Result (Shifted left twice, right filled with 0s)
             (60 * 2^2 = 60 * 4 = 240)
```

---

## Code Example (`<<`)

```c
#include <stdio.h>

int main() {
    unsigned char a = 60;  // 0011 1100
    unsigned char result;
    int shift_amount = 2;

    result = a << shift_amount; // 1111 0000
    printf("%d << %d = %u\n", a, shift_amount, result); // Output: 60 << 2 = 240

    // Equivalent to multiplication by power of 2
    printf("%d * (2^%d) = %d\n", a, shift_amount, a * (1 << shift_amount));

    return 0;
}
```

---

## Right Shift (`>>`) Operator

* Shifts the bits of the left operand to the **right** by the number of positions specified by the right operand.
* Bits shifted off the right end are discarded.
* **Filling Vacated Bits (Left Side):**
    * For **unsigned** types: Always filled with **zeros** (Logical Shift).
    * For **signed** types: Behavior is **implementation-defined**. It might be filled with zeros (Logical Shift) OR filled with copies of the original sign bit (Arithmetic Shift). Assume logical shift for unsigned, be cautious with signed.
* **Effect (Logical Shift):** Equivalent to dividing the left operand by $2^{\text{right operand}}$ (integer division).

* `a = 60;` (Binary: `0011 1100`)

**`a >> 2` (Right Shift by 2):**
```
  0011 1100  (60) >> 2
-----------
  0000 1111  (15)  <-- Result (Shifted right twice, left filled with 0s for unsigned)
             (60 / 2^2 = 60 / 4 = 15)
```

---

## Code Example (`>>`)

```c
#include <stdio.h>

int main() {
    unsigned char a = 60;  // 0011 1100
    unsigned char result;
    int shift_amount = 2;

    result = a >> shift_amount; // 0000 1111
    printf("%u >> %d = %u\n", a, shift_amount, result); // Output: 60 >> 2 = 15

    // Equivalent to division by power of 2
    printf("%u / (2^%d) = %d\n", a, shift_amount, a / (1 << shift_amount));

    // Example with signed (might be arithmetic shift)
    signed char signed_a = -60; // Example signed value
    signed char signed_result = signed_a >> shift_amount;
    printf("%d >> %d = %d\n", signed_a, shift_amount, signed_result); // Output depends on implementation

    return 0;
}
```

---

## Lecture Outline

1.  Overview of Bitwise Operations
2.  **Applications of Bitwise Operations**

---

## Common Applications of Bitwise Ops

Bitwise operators are fundamental for tasks like:

1.  **Checking Even/Odd:** `(number & 1)` is `0` if even, `1` if odd (checks the least significant bit).
2.  **Masking:** Extracting specific bits using `&` with a mask (a value with 1s at desired positions). E.g., `value & 0x0F` extracts the lower 4 bits.
3.  **Setting Bits:** Turning specific bits ON using `|` with a mask. E.g., `value | (1 << k)` sets the k-th bit to 1.
4.  **Clearing Bits:** Turning specific bits OFF using `&` with an inverted mask. E.g., `value & ~(1 << k)` clears the k-th bit.
5.  **Toggling Bits:** Flipping specific bits using `^` with a mask. E.g., `value ^ (1 << k)` toggles the k-th bit.
6.  **Efficient Multiplication/Division:** Using `<<` and `>>` for powers of 2.
7.  **Swapping Numbers:** `a ^= b; b ^= a; a ^= b;` swaps `a` and `b` without a temporary variable (using XOR properties).
8.  Representing sets or flags efficiently (each bit corresponds to an item/flag).

---

## Application Example: Counting Set Bits (1s)

* **Problem:** Given an integer `n`, count how many bits in its binary representation are set to `1`.
* **Algorithm:**
    1. Initialize `count = 0`.
    2. While `n` is greater than 0:
        a. Check the last bit of `n`: If `(n & 1)` is `1`, increment `count`.
        b. Right shift `n` by one position (`n = n >> 1;`) to examine the next bit.
    3. Return `count`.

---

## Code: Counting Set Bits

```c
#include <stdio.h>

int main() {
    int a = 11; // Binary: ...0000 1011
    int count = 0;
    int bit_check;

    printf("Enter an integer: ");
    scanf("%d", &a);

    int temp_a = a; // Use a temporary variable to preserve original 'a'

    while (temp_a > 0) {
        // Check the least significant bit
        bit_check = temp_a & 1;
        if (bit_check == 1) {
            count++;
        }
        // Shift right to process the next bit
        temp_a = temp_a >> 1;
    }

    printf("Number of set bits (1s) in %d is: %d\n", a, count);
    return 0;
}
// Example Input: 11 (1011) -> Output: 3
// Example Input: 60 (00111100) -> Output: 4
```

---

## Application Example: Setting the k-th Bit

* **Problem:** Given a number `n` and a bit position `k` (where k=0 is the least significant bit), set the k-th bit of `n` to `1`, leaving other bits unchanged.
* **Algorithm:**
    1. Create a **mask** with only the k-th bit set to 1. This is done using left shift: `mask = 1 << k;`.
    2. Perform a **bitwise OR** between the original number `n` and the `mask`. The OR operation will set the k-th bit if it wasn't already set, and leave other bits as they were. `n = n | mask;` or `n |= mask;`.

---

## Code: Setting the k-th Bit

```c
#include <stdio.h>

int main() {
    int n = 10; // Binary: ...0000 1010
    int k = 2;  // Set the 2nd bit (0-indexed, value 4)
    int mask;

    printf("Original number n = %d (Binary: ...1010)\n", n);
    printf("Setting bit at position k = %d\n", k);

    // Create the mask with the k-th bit set
    mask = 1 << k; // mask = 1 << 2 = ...0000 0100

    // Perform bitwise OR to set the bit
    n = n | mask;
    //   ...0000 1010 (10)
    // | ...0000 0100 (4)
    // --------------
    //   ...0000 1110 (14)

    printf("Resulting number n = %d (Binary: ...1110)\n", n); // Output: 14

    return 0;
}
```
