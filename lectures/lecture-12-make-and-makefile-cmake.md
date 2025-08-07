---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lecture 12 - make & Makefile / CMake
---

# Lecture 11: make & Makefile / CMake
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Lecture Outline

1.  Building Projects with `make` and Makefiles
2.  Building Projects with CMake

---

## Why Automate Building? (Part 1)

* Consider a simple project split into multiple files:
    * `mylib.h`: Header file declaring functions.
    * `mylib.c`: Source file defining functions declared in `mylib.h`.
    * `main.c`: Main program file using functions from `mylib.h`.

```c
// mylib.h
#ifndef MYLIB_H
#define MYLIB_H
int isodd(int x);
float square(float x);
#endif

// mylib.c
#include "mylib.h"
float square(float x) { return x * x; }
int isodd(int x) { return (x % 2 != 0); }

// main.c
#include "mylib.h"
#include <stdio.h>
int main() {
    float x = 3.4; int a = 5;
    float y = square(x);
    if (isodd(a)) { printf("%d is odd\n", a); }
    return 0;
}
```

---

## Why Automate Building? (Part 2)

* **Manual Compilation Steps:** To build an executable from these files, you would typically:
    1.  Compile `main.c` into an object file (`main.o`):
        `gcc main.c -o main.o -c`
    2.  Compile `mylib.c` into an object file (`mylib.o`):
        `gcc mylib.c -o mylib.o -c`
    3.  Link the object files together to create the executable (`myproj`):
        `gcc -o myproj main.o mylib.o`
* **Challenge:** Manually typing these commands is feasible for small projects but becomes tedious and error-prone for larger projects with many files. Furthermore, if only one source file changes, we ideally want to recompile only that file and then re-link, not recompile everything. This is where build automation tools like `make` come in.

---

## What is `make`?

* `make` is a build automation tool that reads instructions from a file, typically named `Makefile` (or `makefile`).
* It automatically determines which parts of a program need to be recompiled and issues the necessary commands.
* `make` works based on **rules** defined in the `Makefile`.

---

## Basic `Makefile` Rule Syntax

* A rule tells `make` how to create a target file from its prerequisites (dependencies).
* **General Form:**
    ```makefile
    target: prerequisite1 prerequisite2 ...
    <TAB>recipe_command1
    <TAB>recipe_command2
    ...
    ```
    * `target`: The file to be built (e.g., an executable or an object file).
    * `prerequisites`: Files that the target depends on (e.g., source files, object files, headers). If any prerequisite is newer than the target, the recipe is executed.
    * `recipe`: One or more commands (like `gcc`) needed to build the target from the prerequisites. **Crucially, recipe lines MUST start with a TAB character, not spaces.**

---

## Example `Makefile`

* For the project on slides 3/4:

```makefile
# This is a comment

# Rule to build the final executable 'myproj'
# Depends on main.o and mylib.o
myproj: main.o mylib.o
	gcc -o myproj main.o mylib.o

# Rule to build main.o
# Depends on main.c and mylib.h
main.o: main.c mylib.h
	gcc -c main.c -o main.o

# Rule to build mylib.o
# Depends on mylib.c and mylib.h
mylib.o: mylib.c mylib.h
	gcc -c mylib.c -o mylib.o

# Rule for cleaning up generated files (optional but common)
# '.PHONY' indicates 'clean' is not a file dependency
.PHONY: clean
clean:
	rm -f myproj main.o mylib.o
```
* **How it works:**
    * Typing `make` (or `make myproj`) tells `make` to build the `myproj` target.
    * It sees `myproj` depends on `main.o` and `mylib.o`.
    * It checks the rules for `main.o` and `mylib.o`, building them if necessary (if their prerequisites `.c` or `.h` files are newer).
    * Finally, it runs the `gcc` linking command for `myproj`.
    * Typing `make clean` removes the generated files.

---

## Using Variables in Makefiles

* Makefiles often use variables to make them more readable and easier to modify.
* **Syntax:**
    * Define: `VARIABLE_NAME = value` (or `:=` for simpler expansion)
    * Use: `$(VARIABLE_NAME)` or `${VARIABLE_NAME}`
* **Common Variables:**
    * `CC`: C compiler (e.g., `gcc`)
    * `CFLAGS`: Compiler flags (e.g., `-Wall -g`)
    * `LDFLAGS`: Linker flags
    * `SOURCES`: List of source files
    * `OBJECTS`: List of object files derived from sources

---

## Example `Makefile` with Variables

```makefile
# Define Variables
CC = gcc
CFLAGS = -Wall -g -std=c11 # Compiler flags: warnings, debug info, C11 standard
LDFLAGS = # Linker flags (none needed here)

SOURCES = main.c mylib.c
# Automatically generate object file names from source names
OBJECTS = $(SOURCES:.c=.o) # Replaces .c suffix with .o

# Default target (often the executable name)
TARGET = myproj

# Build the target executable
# '$@' means the target name ('myproj')
# '$^' means all prerequisites ('main.o mylib.o')
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# Generic rule to build any .o file from its corresponding .c file
# '$<' means the first prerequisite ('main.c' or 'mylib.c')
%.o: %.c mylib.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)
```
* This version is more flexible. Changing the compiler or flags only requires editing the variable definitions.

---

## Lecture Outline

1.  Building Projects with `make` and Makefiles
2.  **Building Projects with CMake**

---

## Why CMake? Limitations of `make`

* While `make` is powerful, traditional Makefiles have limitations:
    * **Platform Dependency:** Makefiles often contain commands specific to one operating system (like `rm` on Unix vs. `del` on Windows) or compiler.
    * **Finding Dependencies:** Doesn't automatically find installed libraries or required tools.
    * **Complexity:** Can become very complex for large projects with many options and configurations.
* **CMake** addresses these issues by being a **cross-platform build system generator**.

---

## What is CMake?

* CMake doesn't build the project directly. Instead, it reads configuration files (typically `CMakeLists.txt`) and **generates native build files** appropriate for the target platform and build tool (e.g., Makefiles for Linux/macOS, Visual Studio projects for Windows, Ninja files, etc.).
* **Workflow:**
    1. Write `CMakeLists.txt` file(s) describing your project structure, source files, libraries, dependencies, and build options.
    2. Run `cmake` in a build directory, pointing it to your source directory containing `CMakeLists.txt`. CMake configures the project and generates the native build files (e.g., `Makefile`).
    3. Use the native build tool (e.g., `make`, `ninja`, Visual Studio) in the build directory to compile and link your project.
* **Advantages:** Provides platform independence, better dependency handling, and integration with testing (CTest) and packaging (CPack).

---

## Basic `CMakeLists.txt` Structure

* The primary configuration file for CMake. Uses its own simple scripting language.
* **Common Commands:**
    * `cmake_minimum_required(VERSION x.y)`: Specifies the minimum CMake version needed. **Required.**
    * `project(ProjectName [LANGUAGES C CXX ...])`: Defines the project name and languages used (e.g., C, C++). **Required.**
    * `add_executable(TargetName source1.c source2.c ...)`: Defines an executable target and lists its source files.
    * `add_library(TargetName [STATIC|SHARED|MODULE] source1.c ...)`: Defines a library target.
    * `target_link_libraries(TargetName library1 library2 ...)`: Links libraries to an executable or another library.
    * `set(VARIABLE_NAME value)`: Sets a CMake variable.
    * `include_directories(path1 path2 ...)`: Specifies directories to search for header files.
    * `find_package(PackageName REQUIRED)`: Finds external libraries/packages.

---

## Simple `CMakeLists.txt` Example

* For the project on slides 3/4:

```cmake
# Specify minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Define the project name and language
project(MyProject LANGUAGES C)

# Define the executable target and its source files
add_executable(myproj main.c mylib.c)

# Note: Unlike Makefiles, CMake automatically figures out
# the dependencies between .c and .h files if they are
# included correctly (#include "mylib.h" in main.c/mylib.c).
```

---

## Setting Variables and Flags in CMake

* Use the `set()` command to define variables.
* Standard CMake variables control build settings (e.g., `CMAKE_C_FLAGS` for C compiler flags).

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES C)

# Set compiler flags (e.g., warnings, debug info, standard)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -std=c11")

# Add the executable
add_executable(myproj main.c mylib.c)
```
* Flags can also be set via the command line when running `cmake` (e.g., `cmake -DCMAKE_C_FLAGS="-O3" ..`).

---

## Out-of-Source Builds with CMake

* It's highly recommended to perform builds in a separate directory (e.g., `build`) outside your source tree. This keeps generated files separate from your source code.
* **Typical Commands:**
    ```bash
    # Navigate to your project's root directory (where CMakeLists.txt is)
    cd /path/to/MyProject

    # Create a build directory (if it doesn't exist)
    mkdir build

    # Change into the build directory
    cd build

    # Run cmake, telling it where the source CMakeLists.txt is ('..' means parent directory)
    # This generates the native build files (e.g., Makefile) in the 'build' directory
    cmake ..

    # Run the native build tool (e.g., make)
    make

    # The executable ('myproj') will be created inside the 'build' directory
    ./myproj
    ```

---

## Building Libraries with CMake

* Use `add_library()` to define a library target.
* Specify `STATIC` or `SHARED` (default depends on `BUILD_SHARED_LIBS` variable).

**Example `CMakeLists.txt` for Building a Library (`mylib`)**
```cmake
# CMakeLists.txt (in a 'lib' subdirectory perhaps)
cmake_minimum_required(VERSION 3.10)
project(MyLibrary LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -std=c11")

# Define the library target 'mylib' from mylib.c
# Build it as a STATIC library (.a file)
add_library(mylib STATIC mylib.c)

# Optional: Specify public include directories if needed by users of the library
# target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

---

## Linking Libraries with CMake

* Use `target_link_libraries()` to link a library (created with `add_library` or found with `find_package`) to an executable or another library.

**Example `CMakeLists.txt` for Executable Linking to `mylib`**
```cmake
# CMakeLists.txt (in the main project directory)
cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -std=c11")

# Add the subdirectory containing the library's CMakeLists.txt
# This ensures the 'mylib' target is defined before we use it.
# Assumes the library source is in a 'lib' subdirectory.
add_subdirectory(lib) # Processes lib/CMakeLists.txt

# Define the executable target using main.c
add_executable(myproj main.c)

# Link the 'mylib' library target to the 'myproj' executable target
target_link_libraries(myproj PRIVATE mylib)
# 'PRIVATE' means mylib is needed to build myproj, but not needed
# by things that link to myproj itself (PUBLIC/INTERFACE are other options)
```
* When you run `cmake ..` and `make` in the build directory, CMake handles building the library first (if needed) and then linking it correctly when building the executable.
