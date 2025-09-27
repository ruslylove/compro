---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lecture 10 - File Operations
---

# Lecture 10: File Operations
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Lecture Outline

1.  Computer Storage Concepts
2.  Performing File Operations in C

---

## Computer Memory vs. Storage

* When we run programs, two main components are involved:
    1.  **CPU:** Executes the program instructions.
    2.  **Memory (RAM):** Temporarily holds the program code and data during execution.
* **Problem:** Data stored in main memory (RAM) is **volatile** – it disappears when the computer is turned off.
* **Solution:** **External storage** devices (hard disks, SSDs, USB drives, etc.) provide **non-volatile** storage, allowing data to be kept permanently. Data on these devices is organized into **files**.

---

## Storage Device Basics

* Various storage technologies have existed throughout computing history.
* Common modern examples include Hard Disk Drives (HDDs), Solid-State Drives (SSDs), DVDs, and USB flash drives.
* Data is stored on these devices in units called **files**.
* Essential information (metadata) managed by the operating system for each file includes:
    1.  File name
    2.  File size
    3.  Physical location on the storage device (e.g., disk cylinder, track, sector details).
    4.  Timestamps: Creation time, last modification time, last access time.
    5.  Access permissions, file type, etc.

---

## Lecture Outline

1.  Computer Storage Concepts
2.  **Performing File Operations in C**

---

## File Operations in C: Overview

* C provides standard library functions (primarily from `<stdio.h>`) to interact with files.
* Key steps usually involve:
    1.  **Opening** a file to establish a connection.
    2.  **Reading from** or **Writing to** the file.
    3.  **Closing** the file to release resources.
* **File Pointer (`FILE *`):** When a file is opened, the system returns a pointer to a `FILE` structure (often called a file handle or stream pointer). This pointer is used in subsequent operations to identify the opened file.
* **Standard Streams:** Three file streams are automatically opened when a C program starts:
    * `stdin`: Standard input (usually the keyboard).
    * `stdout`: Standard output (usually the screen/console).
    * `stderr`: Standard error output (usually the screen/console, for error messages).

---

## Opening Files: `fopen()`

* Establishes a link between your program and a physical file on the storage device.
* **Syntax:** `FILE *fopen(const char *filename, const char *mode);`
* **Parameters:**
    * `filename`: A string containing the name (and potentially path) of the file.
    * `mode`: A string specifying how you intend to use the file (e.g., read, write, append).
* **Return Value:**
    * Returns a `FILE*` pointer (handle) to the opened file on success.
    * Returns `NULL` if the file cannot be opened (e.g., file not found, permissions issue).
* **Crucial:** **Always check if `fopen()` returned `NULL`** to handle potential errors gracefully.

---

## Common `fopen()` Modes

<Transform scale="0.85">

| **Mode String** | Meaning                                        | Behavior if File Exists | Behavior if File Doesn't Exist |
| :---------- | :--------------------------------------------- | :---------------------- | :----------------------------- |
| `"r"`       | **R**ead (text)                                | Read from start         | Error (`NULL` returned)        |
| `"w"`       | **W**rite (text)                               | **Destroy contents** | Create new file                |
| `"a"`       | **A**ppend (text)                              | Write at end            | Create new file                |
| `"r+"`      | Read and Write (text)                          | Read/Write from start   | Error (`NULL` returned)        |
| `"w+"`      | Read and Write (text)                          | **Destroy contents** | Create new file                |
| `"a+"`      | Read and Append (text)                         | Read start, Append end  | Create new file                |
| `"rb"`, `"wb"`, `"ab"`, `"rb+"`, `"wb+"`, `"ab+"` | Like above, but for **B**inary files |                         |                                |

</Transform>

---

## Closing Files: `fclose()`

* Breaks the link between the program and the physical file, flushing any buffered data to the disk and releasing system resources associated with the file handle.
* **Syntax:** `int fclose(FILE *fp);`
* **Parameter:** `fp` is the `FILE*` pointer obtained from `fopen()`.
* **Return Value:** Returns `0` on success, `EOF` (a special constant, usually -1) on error.
* **Crucial:** **Always `fclose()` files when you are finished with them.** Failure to do so can lead to data loss (if buffers aren't flushed) and resource leaks. Closing happens automatically when a program exits normally, but explicitly closing is good practice.

---

## Reading from Files: `fscanf()` and `fgets()`

* **`fscanf(FILE *fp, const char *format, ...)`:**
    * Reads formatted input from the file stream `fp`, similar to how `scanf` reads from `stdin`.
    * Reads data according to the `format` string and stores it in the provided variable addresses.
    * Returns the number of items successfully read, or `EOF` if the end of the file is reached or an error occurs. **Checking against `EOF` is essential for loops reading until the end.**
* **`fgets(char *str, int size, FILE *fp)`:**
    * Reads a line of text (up to `size - 1` characters) from the file stream `fp` and stores it into the character array `str`.
    * Stops reading after encountering a newline (`\n`) or `EOF`, or when `size - 1` characters have been read.
    * **Safer than `gets` or `fscanf("%s", ...)`** because it includes a size limit, preventing buffer overflows.
    * Automatically adds a null terminator `\0`.
    * Returns `str` on success, `NULL` on end-of-file or error.

---

## Reading Example (`fscanf`)

```c {*}{maxHeight:'420px',lines:true}
#include <stdio.h>

int main() {
    FILE *fp = NULL;
    char name[50];
    int score;
    int items_read;

    // Open file for reading
    fp = fopen("scores.txt", "r"); // Assume scores.txt contains "Alice 95\nBob 88\n"

    // Check if file opened successfully
    if (fp == NULL) {
        perror("Error opening file"); // Print system error message
        return 1;
    }

    printf("Reading scores:\n");
    // Read name (string) and score (int) repeatedly
    // Check if fscanf successfully reads 2 items each time
    while ((items_read = fscanf(fp, "%s %d", name, &score)) == 2) {
        printf("Name: %s, Score: %d\n", name, score);
    }

    // Check why the loop ended (EOF or read error)
    if (feof(fp)) {
        printf("End of file reached.\n");
    } else if (ferror(fp)) {
        perror("Error reading from file");
    }

    // Close the file
    fclose(fp);
    return 0;
}
```

---

## Reading Example (`fgets`)

```c {*}{maxHeight:'420px',lines:true}
#include <stdio.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *fp = NULL;
    char line_buffer[MAX_LINE_LENGTH];

    fp = fopen("input.txt", "r"); // Assume input.txt has lines of text

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("File contents:\n");
    // Read lines until fgets returns NULL (EOF or error)
    while (fgets(line_buffer, MAX_LINE_LENGTH, fp) != NULL) {
        // Print the line read (fgets includes the newline if it fits)
        printf("%s", line_buffer);
    }

    fclose(fp);
    return 0;
}
```

---

## Writing to Files: `fprintf()` and `fputs()`

* **`fprintf(FILE *fp, const char *format, ...)`:**
    * Writes formatted output to the file stream `fp`, similar to how `printf` writes to `stdout`.
    * Converts data to text based on the `format` string and writes it to the file.
    * Returns the number of characters written, or a negative value on error.
* **`fputs(const char *str, FILE *fp)`:**
    * Writes the string `str` (up to, but not including, the null terminator) to the file stream `fp`.
    * Does **not** automatically add a newline (`\n`) like `puts`.
    * Returns a non-negative value on success, or `EOF` on error.

---

## Writing Example (`fprintf`, Mode "w")

```c {*}{maxHeight:'400px',lines:true}
#include <stdio.h>

int main() {
    FILE *fp = NULL;
    char name[] = "Charlie";
    int score = 92;

    // Open file for writing (creates new or overwrites existing)
    fp = fopen("output.txt", "w");

    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write formatted data to the file
    fprintf(fp, "Student Record\n");
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Score: %d\n", score);
    fprintf(fp, "-----------\n");

    printf("Data written to output.txt\n");

    // Close the file (flushes buffers)
    fclose(fp);
    return 0;
}
```

*Running this will create `output.txt` (or overwrite it) with the specified lines.*

---

## Appending Example (`fprintf`, Mode "a")

```c {*}{maxHeight:'400px',lines:true}
#include <stdio.h>

int main() {
    FILE *fp = NULL;
    char name[] = "David";
    int score = 85;

    // Open file for appending (creates if doesn't exist, adds to end if exists)
    fp = fopen("output.txt", "a"); // Use "a" for append

    if (fp == NULL) {
        perror("Error opening file for appending");
        return 1;
    }

    // Append formatted data to the end of the file
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Score: %d\n", score);
    fprintf(fp, "-----------\n");

    printf("Data appended to output.txt\n");

    // Close the file
    fclose(fp);
    return 0;
}
```

*Running this after the previous example will add David's record to the end of `output.txt`.*

---

## Binary File Operations

* For reading/writing non-text data (like raw bytes of structs, images, etc.), use **binary modes** (`"rb"`, `"wb"`, `"ab"`, etc.).
* Text mode (`"r"`, `"w"`, `"a"`) might perform character translations (e.g., newline conversions) which can corrupt binary data.
* Use functions like `fread()` and `fwrite()` for binary I/O.
    * `fread(void *ptr, size_t size, size_t count, FILE *fp)`: Reads `count` items, each of `size` bytes, from `fp` into the buffer pointed to by `ptr`.
    * `fwrite(const void *ptr, size_t size, size_t count, FILE *fp)`: Writes `count` items, each of `size` bytes, from the buffer `ptr` to `fp`.
* Detailed usage of binary I/O is often covered in more advanced topics (e.g., Microprocessor and Embedded Systems).

---
layout: default
---

## Summary
<Transform scale="0.85">

*   **File I/O:** C programs use functions from `<stdio.h>` to interact with files for persistent storage.
*   **`FILE*` Pointer:** A special pointer (or handle) returned by `fopen()` that represents the connection to a file.
*   **Core Operations:**
    1.  **Open:** Use `fopen("filename", "mode")`. Common modes are `"r"` (read), `"w"` (write, overwrites), and `"a"` (append). **Always check the return value for `NULL`**.
    2.  **Process:**
        *   **Read:** `fscanf()` (formatted), `fgets()` (line-based, safer).
        *   **Write:** `fprintf()` (formatted), `fputs()` (string).
    3.  **Close:** Use `fclose(file_pointer)` to save changes and release system resources. **This is crucial.**
*   **Text vs. Binary:** Use text modes (`r`, `w`) for human-readable files and binary modes (`rb`, `wb`) for non-text data to prevent character translation issues.
*   **Standard Streams:** `stdin` (keyboard), `stdout` (screen), and `stderr` (screen for errors) are automatically available `FILE*` streams.

</Transform>

<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="lab10" title="Go to Lab10 👩‍🔬"/>
</div>

* Files provide persistent storage.
* Use `<stdio.h>` functions for file I/O.
* **`fopen()`:** Open a file with a specific mode (`"r"`, `"w"`, `"a"`, etc.). **Always check for `NULL` return.**
* **`FILE*`:** Use the returned file pointer (handle) for subsequent operations.
* **Reading:** Use `fscanf()` (formatted), `fgets()` (line-based, safer). Check return values for `EOF` or `NULL`.
* **Writing:** Use `fprintf()` (formatted), `fputs()` (string).
* **`fclose()`:** **Always close files** when finished to save data and release resources.
* Remember standard streams: `stdin`, `stdout`, `stderr`.
