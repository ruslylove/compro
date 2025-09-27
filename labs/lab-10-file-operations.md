---
theme: seriph
background: https://cover.sli.dev
transition: slide-left
layout: cover
title: Lab 10 - File Operations
class: lab
routeAlias: lab10
---

# Lab 10: File Operations
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}

---

## Objectives

*   **Perform fundamental file I/O operations**
    *   Open files in various modes (`"r"`, `"w"`, `"a"`).
    *   Read from files using different functions (`fscanf`, `fgets`, `fgetc`).
    *   Write to files using `fprintf` and `fputc`.
    *   Handle file-related errors, such as a failure to open a file.
*   **Apply file operations to solve practical problems**
    *   Parse formatted data from a file.
    *   Process a file line by line.
    *   Aggregate data from a file.
    *   Copy file contents.

---

## Lab Outline

*   **Exercise 1: Read and Process Student Scores**
    *   Read formatted data from a file using `fscanf` and perform calculations.
*   **Exercise 2: Number Lines in a File**
    *   Read a file line-by-line with `fgets` and write to a new file with `fprintf`.
*   **Exercise 3: Alphabet Frequency from File**
    *   Combine file reading with array manipulation.
*   **Exercise 4: Simple File Writing**
    *   Practice creating and writing to a new file.
*   **Exercise 5: Append a Log Entry**
    *   Practice opening a file in append mode (`"a"`) to add content without overwriting.
*   **Exercise 6: Copy a File**
    *   Read from one file and write the contents to another.

---

## Exercise 1: Read and Process Student Scores

*   **Task:** Read student names and scores from a file named `scores.txt`. Calculate the average score and find the student with the highest score.
*   **📝 Flowchart First:** Draw a flowchart for the main logic. It should show opening the file, a loop to read and process data, closing the file, and printing the final results.
*   **Requirements:**
    1.  Create a `scores.txt` file with a few lines, each containing a name and a score (e.g., `Alice 95`).
    2.  Open `scores.txt` in read mode (`"r"`). Handle potential file opening errors.
    3.  Use a `while` loop with `fscanf` to read the name and score from each line. The loop should continue as long as `fscanf` successfully reads 2 items.
    4.  Inside the loop, accumulate the total score and keep track of the highest score seen so far and the name of the student who achieved it.
    5.  After the loop, calculate the average.
    6.  Print the average score, the highest score, and the name of the top-scoring student.
    7.  Remember to `fclose()` the file.

---

## Exercise 2: Number Lines in a File

*   **Task:** Read a text file named `lyrics.txt` and write its contents to a new file, `numbered_lyrics.txt`, with each line prefixed by a line number.
*   **📝 Flowchart First:** Draw a flowchart that shows opening both files, the loop for reading a line and writing the numbered line, and closing both files.
*   **Requirements:**
    1.  Create a `lyrics.txt` file with some sample text (e.g., a few lines of a song).
    2.  Open `lyrics.txt` for reading and `numbered_lyrics.txt` for writing. Handle any file opening errors.
    3.  Use a `while` loop with `fgets` to read the source file line by line.
    4.  Inside the loop, use `fprintf` to write the line number, a colon, a space, and the line content to the destination file.
    5.  Keep a counter for the line numbers.
    6.  Close both files.

---

## Exercise 3: Alphabet Frequency from File

*   **Task:** Read text from `input.txt` and count the frequency of each letter (case-insensitive).
*   **📝 Flowchart First:** Draw a high-level flowchart showing the main steps: Open File -> Loop (Read Char -> Process Char) -> Close File -> Print Results.
*   **Requirements:**
    1.  Open `input.txt` in read mode (`"r"`). Handle file opening errors.
    2.  Read the file character by character until `EOF`.
    3.  Use an integer array `counts[26]` to store frequencies.
    4.  For each character, if it's a letter, convert it to lowercase and increment the corresponding counter in your array.
    5.  After reading, print the counts for letters that appeared at least once.
    6.  Remember to `fclose()` the file.

---

## Exercise 4: Simple File Writing

*   **Task:** Write a program that creates a file named `hi.txt` and writes a single line of text to it.
*   **Requirements:**
    1.  Open `hi.txt` in write mode (`"w"`). Check if the `FILE*` is `NULL`.
    2.  Use `fprintf()` to write a string like `"Hello, this is [Your Name]"` into the file.
    3.  Close the file using `fclose()`.
    4.  Print a confirmation message to the console.

---

## Exercise 5: Append a Log Entry

*   **Task:** Write a program that appends a new log message to a file named `events.log` each time it is run.
*   **Concept:** Opening a file in append mode (`"a"`) places the file pointer at the end of the file, so any new writes are added without deleting existing content. If the file doesn't exist, it will be created.
*   **Requirements:**
    1.  Open `events.log` in append mode (`"a"`). Handle file opening errors.
    2.  Use `fprintf` to write a new line to the file, for example: `"Event: System startup.\n"`.
    3.  Close the file.
    4.  Run the program multiple times and check the contents of `events.log` to verify that each run adds a new line to the end of the file.

---

## Exercise 6: Copy a File

*   **Task:** Write a program that copies the content of a source file (`source.txt`) to a destination file (`destination.txt`).
*   **📝 Flowchart First:** Draw a flowchart for the file copy logic. It should include opening both files, the main read/write loop, and closing both files.
*   **Requirements:**
    1.  Open `source.txt` in read mode and `destination.txt` in write mode.
    2.  Handle errors for both file openings.
    3.  Read the source file character by character in a loop (`while ((c = fgetc(source_fp)) != EOF)`).
    4.  Write each character to the destination file using `fputc(c, dest_fp)`.
    5.  Close both files.
    6.  Before running, create a `source.txt` file with some sample text. After running, verify that `destination.txt` was created and contains the same text.


<div style="position:fixed;bottom:0;right:20px;padding-bottom:30px">
<Link to="assessment" title="Go to Assessment Rubric 📝"/>
</div>