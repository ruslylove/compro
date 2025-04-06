---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 1 - IDE for C coding
class: lab
---

# Computer Programming
## Lab 1: IDE for C coding

Presented by: Dr. Ruslee Sutthaweekul

Semester: 1/2025

---

## Lab Outline

1.  Setting up the Code::Blocks IDE
2.  Setting up Visual Studio Code (VS Code)
3.  Exercises on Variables and Output Formatting

---

## Code::Blocks IDE

* Code::Blocks is a free, open-source Integrated Development Environment.
* It's known for being lightweight and stable.
* It supports multiple platforms: Linux, Windows, and macOS.
* You can typically find downloads on the official Code::Blocks website (look for the version including the MinGW compiler setup for Windows if needed).

---

## Compiler Setup in Code::Blocks

* After installation, you may need to ensure the compiler is correctly configured.
* Go to `Settings` -> `Compiler`.
* Under `Global compiler settings`, select `GNU GCC Compiler` (or the appropriate compiler you installed, like MinGW).
* Go to the `Toolchain executables` tab.
* Ensure the `Compiler's installation directory` points to the correct location (e.g., `C:\Program Files (x86)\CodeBlocks\MinGW` for a standard Windows install with MinGW). The `C compiler`, `C++ compiler`, and `Linker` fields should automatically point to the executables (`mingw32-gcc.exe`, `mingw32-g++.exe`, `ar.exe`, etc.) within that directory's `bin` subfolder. You can use `Auto-detect` if needed.

---

## Creating a New Project in Code::Blocks

1.  Go to `File` -> `New` -> `Project...`
2.  Select `Console application` and click `Go`.
3.  Choose `C` as the language.

---

## Setting Project Details in Code::Blocks

1.  **Project title:** Give your project a name (e.g., `Lab1_HelloWorld`).
2.  **Folder to create project in:** Choose a location on your computer to save the project files.
3.  Code::Blocks will generate the necessary file names based on the title. Click `Next`.

---

## Build Configuration in Code::Blocks

1.  **Compiler:** Ensure the correct compiler (e.g., `GNU GCC Compiler`) is selected.
2.  **Build configurations:** You typically have `Debug` and `Release` options.
    * `Debug`: Includes extra information useful for debugging (recommended while developing).
    * `Release`: Optimized for performance, smaller executable size (used for final versions).
3.  Leave the defaults checked for now and click `Finish`.

---

## Navigating the Code::Blocks Workspace

* After creating the project, the main window appears.
* On the left side (usually), you'll see the `Management` pane with the `Projects` tab.
* Expand your project (e.g., `Lab1_HelloWorld`).
* Expand the `Sources` folder.
* Double-click on `main.c` to open the default C source file in the editor.

---

## Building and Running in Code::Blocks

* **Build:** Compiles your source code (`.c` files) into object files (`.o`) and links them into an executable.
    * Use the "Build" button (often looks like a gear) or `Build` -> `Build` menu.
* **Run:** Executes the compiled program.
    * Use the "Run" button (often looks like a play triangle) or `Build` -> `Run` menu.
* **Build and Run:** Performs both steps sequentially.
    * Use the "Build and run" button (gear + play triangle) or `Build` -> `Build and run`.
* Output from `printf` will appear in the console window that pops up when you run the program.

---

## Lab Outline

1.  Setting up the Code::Blocks IDE
2.  **Setting up Visual Studio Code (VS Code)**
3.  Exercises on Variables and Output Formatting

---

## Visual Studio Code (VS Code)

* Developed by Microsoft.
* A free, powerful, and highly popular source code editor (not a full IDE out-of-the-box, but extensible).
* Runs on Windows, macOS, and Linux.
* Relies heavily on **extensions** for language support, debugging, and other features.

---

## VS Code: Essential C/C++ Extension

* To effectively work with C/C++ in VS Code, you need to install the appropriate extension.
* Go to the `Extensions` view (usually the icon with squares on the left sidebar).
* Search for `C/C++`.
* Install the official **C/C++ extension from Microsoft**. This provides features like code completion (IntelliSense), debugging support, and code navigation.

---

## VS Code: Project and File Setup

* VS Code works primarily with folders.
    1.  Create a new folder for your project on your computer (e.g., `Lab1_VSCode`).
    2.  Open VS Code.
    3.  Go to `File` -> `Open Folder...` and select the folder you just created.
    4.  Create your C source file within that folder: `File` -> `New File`, save it as `main.c` (or another `.c` name).
    5.  Write your C code in `main.c`.

---

## Building C Code in VS Code (Terminal)

* VS Code has an integrated terminal. Open it using `Terminal` -> `New Terminal` or the shortcut (often `Ctrl+``).
* You need a C compiler installed separately (like GCC/MinGW on Windows, GCC/Clang on Linux/macOS).
* To compile your `main.c` file, type the `gcc` command in the terminal:
    ```bash
    gcc main.c -o main
    ```
    * `gcc`: The command to invoke the GCC compiler.
    * `main.c`: Your input source file.
    * `-o main`: Specifies the name of the output executable file (e.g., `main.exe` on Windows, `main` on Linux/macOS).

---

## Running C Code in VS Code (Terminal)

* After successfully compiling (no errors shown in the terminal), you can run the generated executable from the same terminal.
* **Command:**
    * On Linux/macOS: `./main`
    * On Windows (Command Prompt/PowerShell): `.\main.exe` or sometimes just `main.exe`
* The program will execute, and any `printf` output will appear in the terminal.

---

## Lab Outline

1.  Setting up the Code::Blocks IDE
2.  Setting up Visual Studio Code (VS Code)
3.  **Exercises on Variables and Output Formatting**

---

## Exercise: Variables and Basic Output

* Declare variables of different fundamental types (`int`, `float`, `double`, `char`).
* Assign appropriate literal values to them.
* Print the value of each variable to the screen using `printf` and the correct format specifier (`%d`, `%f`, `%lf`, `%c`).

```c
#include <stdio.h>

int main() {
    // Declare and initialize variables
    int integer_var = 10;
    float float_var = 3.14f; // Use 'f' suffix for float literals
    double double_var = 2.71828;
    char char_var = 'A';
    int another_int = -55;

    // Print the values
    printf("Integer: %d\n", integer_var);
    printf("Float: %f\n", float_var);
    printf("Double: %lf\n", double_var); // Use %lf for printing doubles
    printf("Character: %c\n", char_var);
    printf("Another Integer: %d\n", another_int);

    return 0;
}
```
* Compile and run this code in your chosen IDE (Code::Blocks or VS Code).

---

## Exercise: Floating-Point Precision (`float` vs `double`)

* Observe the precision differences between `float` and `double`.
* Use `printf` formatting options to control the number of decimal places displayed.
    * `%.Nf` or `%.Nlf` prints the number with exactly N digits after the decimal point.

```c
#include <stdio.h>

int main() {
    double pi_double = 3.141592653589793;
    float pi_float = 3.141592653589793f; // Precision might be lost here

    printf("Double (default): %lf\n", pi_double);
    printf("Float (default): %f\n", pi_float); // May show fewer correct digits

    printf("\nFormatted Output:\n");
    printf("Double (4 decimal places): %.4lf\n", pi_double);
    printf("Double (8 decimal places): %.8lf\n", pi_double);
    printf("Float (4 decimal places): %.4f\n", pi_float);
    printf("Float (8 decimal places): %.8f\n", pi_float); // Digits beyond float's precision might be inaccurate

    return 0;
}
```
* Compile and run. Notice how `double` generally maintains more precision than `float`.

---

## Exercise: Formatted Integer Output

* **Goal:** Print integer values aligned in columns.
* Use the width specifier in `printf`:
    * `%Nd`: Prints the integer using at least N character positions. If the number has fewer than N digits, it will be padded with spaces (usually on the left, right-aligned by default).

* **Task:** Print `a=234`, `b=5`, `c=123`, `d=55`. Display two numbers per line, separated by a comma and space. Each number should occupy 6 spaces, right-aligned.

**Expected Output:**
```
   234,      5
   123,     55
```

*(Self-correction: The original PDF formatting _ _ _234,_ _ _ _ _5 implies padding might be slightly different or include the comma in the width. We'll aim for standard `%6d`.)*

---

## Code: Formatted Integer Output

```c
#include <stdio.h>

int main() {
    int a = 234;
    int b = 5;
    int c = 123;
    int d = 55;

    // Print first line: a and b, each in a field of width 6
    printf("%6d, %6d\n", a, b);

    // Print second line: c and d, each in a field of width 6
    printf("%6d, %6d\n", c, d);

    return 0;
}
```
* Compile and run this code to see the formatted output.
