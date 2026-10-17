*This activity has been created as part of the 42 curriculum by tkhaleel.*

# Libft

## Description

**Libft** is a C library developed as part of the 42 curriculum. The purpose of this project is to recreate a collection of standard C library functions and to implement additional utility functions that can be reused in future 42 projects.

The project focuses on understanding how common C functions work internally instead of simply using the functions provided by the standard library. It requires working with strings, memory, characters, dynamic allocation, function pointers, file descriptors, and linked lists.

The final result is a static library called **`libft.a`**, which can be linked to other C programs.

The project is divided into three main parts:

* **Libc functions:** Reimplementation of functions related to characters, strings, memory, and conversions.
* **Additional functions:** Utility functions for string manipulation, dynamic memory, integer conversion, iteration, and output.
* **Linked-list functions:** Functions for creating, adding, traversing, modifying, and deleting nodes in a singly linked list.

The project also introduces the use of a **Makefile** to automate compilation and the creation of the static library.

## Library Description

### Character and Conversion Functions

These functions operate on characters or convert strings into other representations.

* `ft_isalpha` — checks whether a character is an alphabetic character.
* `ft_isdigit` — checks whether a character is a digit.
* `ft_isalnum` — checks whether a character is alphanumeric.
* `ft_isascii` — checks whether a character belongs to the ASCII range.
* `ft_isprint` — checks whether a character is printable.
* `ft_toupper` — converts a lowercase letter to uppercase.
* `ft_tolower` — converts an uppercase letter to lowercase.
* `ft_atoi` — converts a numeric string into an integer.

### Memory Functions

These functions work directly with blocks of memory and are useful for understanding how data is stored and manipulated at the byte level.

* `ft_memset` — fills a block of memory with a specified byte.
* `ft_bzero` — sets a block of memory to zero.
* `ft_memcpy` — copies a block of memory from one location to another.
* `ft_memmove` — copies memory while correctly handling overlapping memory areas.
* `ft_memchr` — searches for a byte inside a memory block.
* `ft_memcmp` — compares two blocks of memory byte by byte.
* `ft_calloc` — allocates memory for multiple elements and initializes it to zero.

### String Functions

These functions provide operations for finding, copying, comparing, creating, and modifying strings.

* `ft_strlen` — calculates the length of a string.
* `ft_strchr` — searches for the first occurrence of a character.
* `ft_strrchr` — searches for the last occurrence of a character.
* `ft_strncmp` — compares two strings up to a specified number of characters.
* `ft_strnstr` — searches for one string inside another within a specified length.
* `ft_strlcpy` — copies a string into a destination buffer with size protection.
* `ft_strlcat` — appends one string to another with size protection.
* `ft_strdup` — creates a dynamically allocated copy of a string.
* `ft_substr` — creates a substring from a given string.
* `ft_strjoin` — concatenates two strings into a newly allocated string.
* `ft_strtrim` — removes specified characters from the beginning and end of a string.
* `ft_split` — splits a string into an array of strings using a delimiter.
* `ft_itoa` — converts an integer into a dynamically allocated string.

### Additional Utility Functions

These functions use function pointers or file descriptors to provide more flexible operations.

* `ft_strmapi` — applies a function to every character of a string and creates a new string with the results.
* `ft_striteri` — applies a function to every character while allowing the original string to be modified.
* `ft_putchar_fd` — writes a character to a file descriptor.
* `ft_putstr_fd` — writes a string to a file descriptor.
* `ft_putendl_fd` — writes a string followed by a newline to a file descriptor.
* `ft_putnbr_fd` — writes an integer to a file descriptor.

### Linked-List Functions

This part of Libft introduces singly linked lists using the `t_list` structure defined in `libft.h`.

Each node contains:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

The linked-list functions are:

* `ft_lstnew` — creates a new list node.
* `ft_lstadd_front` — adds a node to the beginning of a list.
* `ft_lstsize` — counts the number of nodes in a list.
* `ft_lstlast` — returns the last node of a list.
* `ft_lstadd_back` — adds a node to the end of a list.
* `ft_lstdelone` — deletes one node and frees its content.
* `ft_lstclear` — deletes and frees an entire list.
* `ft_lstiter` — applies a function to every node's content.
* `ft_lstmap` — creates a new list by applying a function to every node.

These functions provide practice with structures, pointers, dynamic memory allocation, and pointer-to-pointer manipulation.

## Compilation and Instructions

The project includes a `Makefile` that automates the compilation process.

### Compile the library

From the root of the repository:

```bash
make
```

This compiles the source files into object files and creates:

```text
libft.a
```

### Remove object files

```bash
make clean
```

### Remove object files and the library

```bash
make fclean
```

### Recompile the entire library

```bash
make re
```

### Using Libft in another program

Create a C file and include the library header:

```c
#include "libft.h"

int main(void)
{
    ft_putstr_fd("Hello from Libft!\n", 1);
    return (0);
}
```

Compile it together with the library:

```bash
cc -Wall -Wextra -Werror main.c libft.a
```

Then run the resulting program:

```bash
./a.out
```

The library can therefore be reused by including `libft.h` and linking `libft.a` during compilation.

## Makefile

The Makefile is used to automate the compilation of the project.

The main targets are:

* `all` — builds the library.
* `clean` — removes object files.
* `fclean` — removes object files and `libft.a`.
* `re` — performs a complete rebuild.

The project uses:

```text
cc
-Wall -Wextra -Werror
ar rcs
```

The source files are first compiled into `.o` object files. These object files are then archived into the static library `libft.a`.

## Requirements and Constraints

The implementation follows the requirements of the 42 Libft subject.

The project follows the 42 coding standard and is intended to compile with:

```bash
-Wall -Wextra -Werror
```

The library is created as a static archive using `ar`.

The implementation does not rely on the corresponding standard library functions for the functions being reimplemented.

## Resources

The following resources were used to understand the C language, standard library behavior, memory management, linked lists, and Makefiles:

* **42 Libft Subject** — project requirements, function descriptions, and constraints.
* **C manual pages (`man`)** — used to check the behavior and expected return values of standard functions.
* **W3Schools C tutorials** — used as a beginner-friendly reference for C concepts.
* **GeeksforGeeks** — used for additional explanations and examples of C concepts, pointers, memory, and data structures.
* **YouTube tutorials** — used to reinforce concepts through practical explanations and examples.
* **Compiler and Makefile documentation** — used to understand compilation commands, object files, static libraries, and Makefile rules.

### AI Usage

AI was used as a **learning and debugging support tool** during the development of this project.

It was mainly used for:

* Explaining C concepts such as pointers, memory addresses, `void *`, `unsigned char`, structures, and function pointers.
* Understanding how standard functions such as `memcpy`, `memmove`, `memcmp`, `strlcat`, and `calloc` behave.
* Helping identify and understand bugs found during testing.
* Creating small test programs to compare the implemented functions with their standard-library behavior.
* Explaining compiler and linker errors.
* Understanding Makefile syntax, compilation rules, object files, and static libraries.
* Reviewing code and suggesting areas that required further testing or correction.

AI was used as a support tool rather than as a replacement for understanding the implementation. The code was studied, tested, debugged, and modified during the development process with the goal of being able to explain the functions and their behavior during evaluation.

## Conclusion

Libft is a foundational C programming project that results in a reusable personal library.

Through this project, the implementation covers several important concepts in C, including:

* Character and string manipulation
* Byte-level memory operations
* Dynamic memory allocation
* Pointers and pointer arithmetic
* Structures and linked lists
* Function pointers
* File descriptors
* Static libraries
* Makefiles and compilation

The resulting `libft.a` can be linked with future 42 projects and reused as a foundation for more advanced C programming.

