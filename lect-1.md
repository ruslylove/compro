---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
---

# Computer Programming
## Lecture 1: Introduction and Overview

Presented by: Dr. Ruslee Sutthaweekul

Semester 1/2025

---

## Lecture Outline

1.  **Course Syllabus**
2.  Fundamentals of Computers
3.  Introduction to Programming
4.  C Programming Basics

---
layout: two-cols
---

## Syllabus Overview

* **Core Topics Covered:**
    * Primitive Data Types and Operations
    * Sequential Program Flow
    * Conditional Logic: `if-else`, `switch`
    * Looping Constructs: `while`, `do-while`, `for`
    * Functions: Declaration, Definition, Calling
    * Preprocessor Directives & Macros (`#ifdef`, etc.)
    * Arrays: Declaration, Definition, Usage
    * Structures: `struct`, `union`
    * Pointers
    * File Input/Output Operations
    * Bitwise Operations
    * Build Tools: `make`, MakeFile, `cmake`, CMakeLists.txt

::right::

* **Performance Evaluation Concepts**
  * **Grading Breakdown:**
    * Project Assignment: 10%
    * Lab Exercises: 20%
    * Attendance: 10%
    * Exam: 60%

---

## Course Structure

* **Lectures:** 12 weeks, 2 hours per week.
* **Labs:** 10 weeks, 2 hours per session.
* **Support:** TA and instructor available during labs.
* **Exams:** Mid-term and Final exams conducted in the exam room (no computer).
    * Format includes 30 multiple-choice questions.
    * Includes 3 coding problems.
* **Policies:** Academic integrity is strictly enforced (no cheating or grade negotiation).
* **Commitment:** Attending all classes is encouraged for maximizing learning.

---

## Lecture Outline

1.  Course Syllabus
2.  **Fundamentals of Computers**
3.  Introduction to Programming
4.  C Programming Basics

---
layout: image-right
image: https://cdn.britannica.com/10/23610-050-6E34CF6B/portion-Difference-Engine-Charles-Babbage-logarithm-tables-1832.jpg
---

## What is a Computer?

* Essentially, a computer is a machine designed for computation.
* Conceptually, it's not vastly different from older calculating tools like the abacus.
* Throughout history, various machines have been used for calculation:
    * Abacus
    * Difference Engine (Babbage)
    * Tide-predicting machines

---
layout: image-right
image: https://miro.medium.com/v2/resize:fit:720/format:webp/0*W_QPS0HHrjyU9l9p
---

## The Computing Model

* **What defines computing?**
    * Taking input data.
    * Performing necessary operations on that data.
    * Producing an output or answer.
* This fundamental model aligns with concepts proposed by pioneers like Alan Turing and John Von Neumann.

---
layout: two-cols
---

## Computer Architecture Framework

* Let's identify the primary components of a typical computer system:
    * **CPU (Central Processing Unit):** The "brain" performing calculations.
    * **Memory (RAM):** Temporary storage for active data and programs.
    * **Hard Disk/SSD:** Long-term storage.
    * **Input Devices:** Keyboard, Mouse.
    * **Output Devices:** Graphics Card + Monitor/Screen, Sound Card + Speakers.
    * **Communication Paths (Buses):** Address Bus, Data Bus, Instruction Bus connecting components.

::right::
<img src="https://images.tpointtech.com/computer/images/computer-components.png">

---

## Identifying Computer Components

* Can you recognize the various internal parts of a computer?

<img src="https://quizizz.com/media/resource/gs/quizizz-media/quizzes/e6088b45-4eb9-4ac3-b556-810995d8ddd5">

---
layout: image-right
image: https://www.electronics-lab.com/wp-content/uploads/2021/02/1280px-Three_IC_circuit_chips-1024x832.jpg
---

## Fundamental Chip Elements

* Modern computer chips (Very Large Scale Integrated Circuits - VLSIC) are incredibly complex.
* However, they are built upon two fundamental types of electronic elements:
    * **Gates (e.g., AND, OR, NOT):** Responsible for performing logical operations; the core building blocks of the CPU.
    * **Latches (or Flip-Flops):** Responsible for storing bits of information (memory); the core building blocks of memory components.

---

## Lecture Outline

1.  Course Syllabus
2.  Fundamentals of Computers
3.  **Introduction to Programming**
4.  C Programming Basics

---

## Why Do We Program? (Part 1)

* Programming allows us to instruct computers.
* Early computing pioneers:
    * **Charles Babbage:** Designed early mechanical computers like the Difference Engine.
    * **Ada Lovelace:** Collaborated with Babbage and is widely regarded as the first computer programmer, developing algorithms for his machines. The Ada programming language is named in her honor.

<img src="https://competitions.amt.edu.au/question_files//b/6/c/image-1561289354.png" style="height:300px">

---

## Why Do We Program? (Part 2)

* Fundamentally, programming provides the **instructions** that tell the CPU what to do.
* The CPU fetches both instructions and the necessary **data** from memory.
* After processing, the results are typically sent back to memory.

<img src="https://math.hws.edu/javanotes/c1/overview-fig1.png">

---
layout: image-right
image: https://cdn.educba.com/academy/wp-content/uploads/2023/12/Machine-Language.jpg
---

## Need for High-Level Languages?

* Humans communicate using natural languages (English, Chinese, etc.).
* To communicate with computers, we need a language they understand, or a way to translate our instructions.
* Computer languages act as the medium for this communication.
* We need either a language the computer directly understands (machine code) or an interpreter/translator for a more human-readable language.

---
layout: two-cols-header
---

## Need for High-Level Languages? 
::left::
* At the lowest level, computer instructions are just sequences of binary digits (0s and 1s) - **machine code**.
* The hardware (CPU) can only directly execute these binary instructions.

::right::
<img src="https://miro.medium.com/v2/resize:fit:720/format:webp/1*bXbjWyhMLUXZGxJNP__WJQ.png">

---

## From Binary to High-Level Code

* Imagine trying to write complex programs directly in binary:
    ```
    1 010101 0000 0011
    2 010101 0001 0101
    3 101010 0000 0001
    4 010101 0000 1011
    ...
    ```
* This is extremely difficult and error-prone for humans.

---

## From Binary to High-Level Code

* **Assembly Language:** A step up from binary, using human-readable symbols (mnemonics) to represent machine instructions.
    * Binary:
        ```
        1 010101 0000 0011
        2 010101 0001 0101
        3 101010 0000 0001
        4 010101 0000 1011
        ```
    * Assembly Equivalent (Example):

        ```asm {*}
        1 MOV D1 0011  ; Move value 3 to register D1
        2 MOV D2 0101  ; Move value 5 to register D2
        3 ADD D1 D2    ; Add D2 to D1, store result in D1
        4 MOV D1 A1    ; Move result from D1 to memory address A1
        ```
* This is easier than binary but still very low-level and tied to specific hardware.

---

## From Binary to High-Level Code

* **High-Level Languages (like C):** Provide a much more abstract and human-friendly way to write instructions, closer to mathematical notation or natural language logic.
    * Machine Code: `010101...`
    * Assembly: `MOV D1, ...`
    * High-Level (C example): `a = 3 + 5;`
* A single high-level statement often translates to multiple machine instructions.

---

## Role of Translators/Compilers

* How does high-level code run on hardware that only understands binary?
    * We write our program as text in a file, following the rules (syntax/grammar) of the high-level language (e.g., C).
    * A special program called a **translator** or **compiler** reads this text file.
    * The compiler converts the human-readable instructions into the equivalent binary machine code.
    * The resulting machine code can then be executed directly by the computer's CPU.
* Different programming languages (C, Java, Python, etc.) have different grammars and require different translators/compilers.

```
 High-Level Code ----> Compiler ----> Machine Code
 (e.g., C code)      (Translator)    (Binary for CPU)

 a = 3+5;                            010101 0000 0011
 b = a*2;                            010101 0001 0101
 printf(...);                        101010 0000 0001
                                     ...
```

---

## Program Lifecycle

1.  **Editing:** Write C code in a text file (e.g., `Prog1.c`).
2.  **Compiling & Linking:** Use a C compiler to translate `Prog1.c` into machine code and link it with necessary libraries, creating an executable file (e.g., `Prog1.exe` on Windows, `Prog1` on Linux/macOS). This executable is stored on the hard disk.
3.  **Loading:** When you run the program, the operating system loads the executable file from the hard disk into memory (RAM).
4.  **Executing:** The CPU fetches instructions from memory and executes them one by one, interacting with peripherals (like the screen via `printf`) as needed.

---

## Lecture Outline

1.  Course Syllabus
2.  Fundamentals of Computers
3.  Introduction to Programming
4.  **C Programming Basics**

---
layout: two-cols
---

## A Brief History of C

* **Origins:** C was developed at AT&T Bell Labs in the early 1970s, primarily by **Dennis Ritchie**, alongside the development of the **UNIX** operating system (with significant contributions from **Ken Thompson**).
* **Recognition:** Ritchie and Thompson were later awarded the Turing Award for their work on UNIX and C.
* **Characteristics of C:**
    * Relatively simple language structure.
    * Versatile: Used for system programming, applications, embedded systems, etc.
    * Highly efficient: Programs often run nearly as fast as equivalent assembly language code (historically cited around 70-80% efficiency).

:: right ::
* **Legacy:** C heavily influenced many later languages (C++, Java, C#, Objective-C). UNIX became a highly influential and stable operating system.
<img src="https://miro.medium.com/v2/resize:fit:640/format:webp/1*4AApxPkF4yXzY0jF0yHgkA.jpeg">

---
layout: two-cols
---

## Your First C Program Example (Part 1)

```c {*|2|5|10|13|*}{lines:true}
// 1. Include Header File for Standard Input/Output
#include <stdio.h>

// 2. Define the main function (entry point of the program)
int main() { // The program starts executing here
    // 3. Start of a code block

    // 4. Call the printf function to print text to the screen
    //    "\n" represents a newline character
    printf("Hello world!\n");

    // 5. Return 0 to the operating system (indicates successful execution)
    return 0;

    // 6. End of the code block
}
```

* **`#include <stdio.h>`:** Tells the compiler to include information about standard input/output functions (like `printf`) found in the `stdio.h` header file.

:: right ::

* **`int main() { ... }`:** Defines the mandatory `main` function where program execution begins. `int` indicates it returns an integer value. `{` and `}` define the function's body (a block of code).
* **`printf(...)`:** A function from `stdio.h` used to display output.
* **`return 0;`:** Exits the `main` function and signals successful completion to the OS.
* **Keywords:** `include`, `int`, `return` are reserved words in C with special meanings.
* **Comments:** Text between `/*` and `*/` (or after `//` on a line) is ignored by the compiler and used for explanations.

---

## Your First C Program Example (Part 2)

```c
#include <stdio.h>

int main() {
    printf("Hello world 1!\n"); // First statement executed
    printf("Hello world 2!\n"); // Second statement executed
    printf("Hello world 3!\n"); // Third statement executed
    return 0;
}
```

**Expected Output:**
```text
Hello world 1!
Hello world 2!
Hello world 3!
```

* Statements within the `main` function are typically executed sequentially from top to bottom.

---
layout: iframe-right
url: https://www.tiobe.com/tiobe-index/
---

## C Language Popularity (Trends)

* C has consistently remained one of the most widely used programming languages for decades due to its efficiency, flexibility, and foundational role in systems programming.

---
layout: image-right
image: https://asset-cdn.tecky.io/2021/10/20/programming_languages_family_trees_uid_616fd206b9de0.png
---

## C Language Popularity (Evolution)

* C's influence is evident in many subsequent languages:
    * **C++:** Added object-oriented features to C.
    * **Objective-C:** Another object-oriented variant, heavily used by Apple.
    * **Java:** Borrowed syntax from C/C++ but uses a virtual machine.
    * **C#:** Microsoft's language similar to Java, also C-inspired syntax.
    * **Python:** While syntactically different, its standard interpreter is written in C, and it interfaces well with C libraries.

