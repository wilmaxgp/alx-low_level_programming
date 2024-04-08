# 0x18. C - Dynamic libraries

## Table of Contents
* [Description](#description)
* [Project Requirements](#project-requirements)
* [Tasks](#tasks)
  * [Task 0: A library is not a luxury but one of the necessities of life](#task-0-a-library-is-not-a-luxury-but-one-of-the-necessities-of-life)
  * [Task 1: Without libraries what have we? We have no past and no future](#task-1-without-libraries-what-have-we-we-have-no-past-and-no-future)
  * [Task 2: Let's call C functions from Python](#task-2-lets-call-c-functions-from-python)
  * [Task 3: Code injection: Win the Giga Millions!](#task-3-code-injection-win-the-giga-millions)

## Description
This project focuses on dynamic libraries in C programming. It includes tasks that involve creating dynamic libraries, using them in C programs, calling C functions from Python, and exploring code injection techniques.

## Project Requirements
* The project uses C programming language.
* Compilation is done using `gcc` with specific options.
* All files must comply with the Betty style.
* No use of global variables.
* Limited number of functions per file.
* Restrictions on using standard library functions.
* Scripts are written in Bash.
* Scripts must be executable.
* A `README.md` file is mandatory for each task.

## Tasks

### Task 0: A library is not a luxury but one of the necessities of life
* Create a dynamic library (`libdynamic.so`) containing several C functions.
* Functions include `_putchar`, `_islower`, `_isalpha`, `_abs`, `_isupper`, `_isdigit`, `_strlen`, `_puts`, `_strcpy`, `_atoi`, `_strcat`, `_strncat`, `_strncpy`, `_strcmp`, `_memset`, `_memcpy`, `_strchr`, `_strspn`, `_strpbrk`, `_strstr`.
* Include prototypes in `main.h`.

### Task 1: Without libraries what have we? We have no past and no future
* Write a script (`1-create_dynamic_lib.sh`) that creates a dynamic library (`liball.so`) from all `.c` files in the current directory.

### Task 2: Let's call C functions from Python
* Create a dynamic library (`100-operations.so`) containing C functions that can be called from Python.
* Demonstrate calling these functions from Python using a test script (`100-tests.py`).

### Task 3: Code injection: Win the Giga Millions!
* Implement a code injection technique to win the Giga Millions lottery jackpot by manipulating the program execution environment without modifying the main program.
* Write a shell script (`101-make_me_win.sh`) that achieves this goal using the `LD_PRELOAD` trick.

For detailed instructions and code snippets, please refer to the specific task files in the repository.
