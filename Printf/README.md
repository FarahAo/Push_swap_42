*This activity has been created as part of the 42 curriculum by tkhaleel.*

# ft_printf

## Description

`ft_printf` is a 42 project whose goal is to recode the standard C `printf()` function.

The main purpose of this project is to understand and use **variadic functions** in C, which allow a function to accept a variable number of arguments.

The project implements the following conversions:

* `%c` — prints a single character
* `%s` — prints a string
* `%p` — prints a pointer address in hexadecimal
* `%d` — prints a decimal integer
* `%i` — prints an integer in base 10
* `%u` — prints an unsigned decimal integer
* `%x` — prints an unsigned hexadecimal number in lowercase
* `%X` — prints an unsigned hexadecimal number in uppercase
* `%%` — prints a percent sign

The function prototype is:

```c
int ft_printf(const char *format, ...);
```

The implementation does not reproduce the buffer management of the original `printf()`.

## Instructions

### Compilation

The project produces the static library:

```text
libftprintf.a
```

To compile the project:

```bash
make
```

Other available Makefile commands:

```bash
make all
make clean
make fclean
make re
```

The Makefile uses:

```text
cc
-Wall
-Wextra
-Werror
```

and uses `ar` to create the static library.

### Using ft_printf

Include the header in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

## Algorithm

The main algorithm is based on scanning the format string from left to right.

1. Start at the first character of the format string.
2. If the current character is not `%`, print it directly.
3. If `%` is found, examine the following character to determine the requested conversion.
4. Retrieve the corresponding argument using `va_arg`.
5. Send the argument to the appropriate conversion function.
6. Each printing function returns the number of characters it printed.
7. Add this value to the total character counter.
8. Continue until the end of the format string.
9. Call `va_end` before returning the final character count.

The main loop therefore separates two cases:

```text
normal character
        |
        v
   print it
        |
        v
    continue

       OR

      '%'
       |
       v
identify conversion
       |
       v
retrieve argument
       |
       v
print argument
       |
       v
continue
```

### Variadic arguments

`ft_printf` uses the C `<stdarg.h>` functionality to handle a variable number of arguments.

The following macros are used:

* `va_start` — initializes the `va_list`
* `va_arg` — retrieves the next argument
* `va_end` — cleans up the `va_list`

The type passed to `va_arg` depends on the conversion being processed.

For example:

```c
va_arg(args, int);
```

is used for `%d`, `%i`, and `%c`, while:

```c
va_arg(args, char *);
```

is used for `%s`.

For `%p`, the argument is retrieved as:

```c
va_arg(args, void *);
```

and then converted to an unsigned integer type for hexadecimal printing.

## Data Structure

The project does not require a complex data structure such as a linked list or tree.

The main structure used is the **`va_list`** provided by the C standard library.

The format string acts as the input sequence, while the `va_list` keeps track of the variable arguments supplied to `ft_printf`.

The conversion character determines how the next argument should be interpreted.

For example:

```text
ft_printf("Number: %d", 42);

format:
"Number: %d"
          ^
          conversion

argument list:
42
```

When `%d` is encountered, the next argument is retrieved as an `int`.

### Character counting

`ft_printf` returns the number of characters printed.

Each printing function therefore returns its own character count, which is added to the total counter in `ft_printf`.

For example:

```text
print "Hello"
returns 5
```

The total counter can then be updated with:

```c
counter += print_string(...);
```

### Number printing

Decimal and hexadecimal numbers are printed by repeatedly extracting digits from the number and converting them into their corresponding characters.

For hexadecimal:

```text
0 1 2 3 4 5 6 7 8 9 A B C D E F
```

or:

```text
0 1 2 3 4 5 6 7 8 9 a b c d e f
```

depending on whether `%X` or `%x` is used.

Pointers are printed in hexadecimal with the `0x` prefix, following the expected `printf` representation.

## Supported Features

| Conversion | Description              |
| ---------- | ------------------------ |
| `%c`       | Character                |
| `%s`       | String                   |
| `%p`       | Pointer address          |
| `%d`       | Decimal integer          |
| `%i`       | Integer                  |
| `%u`       | Unsigned decimal integer |
| `%x`       | Lowercase hexadecimal    |
| `%X`       | Uppercase hexadecimal    |
| `%%`       | Percent sign             |

## Testing

The implementation can be tested by comparing its output with the original `printf()`.

Example:

```c
printf("Value: %d\n", 42);
ft_printf("Value: %d\n", 42);
```

Tests should cover:

* normal characters
* empty strings
* `%c`
* `%s`
* `%p`
* `%d`
* `%i`
* `%u`
* `%x`
* `%X`
* `%%`
* `NULL` strings
* `0`
* positive and negative integers
* integer limits
* unsigned integer limits
* pointer addresses

The project also encourages creating test programs even though they are not submitted.

## Resources

### Documentation

* `man printf`
* `man write`
* `man stdarg`

### C Documentation and Tutorials

* C standard library documentation
* `cppreference`
* GeeksforGeeks — C programming and variadic functions
* W3Schools — C programming basics
* 42 documentation and subject PDF

### AI Usage

AI was used as a learning and support tool during the development of this project.

It was used for:

* explaining variadic functions and `va_list`
* explaining how `va_start`, `va_arg`, `va_copy`, and `va_end` work
* clarifying C pointers and type conversions
* discussing possible algorithms and implementation approaches
* helping understand compiler errors and debugging issues
* reviewing code and suggesting areas to test
* explaining the project requirements and helping structure the README

The code was studied, tested, and adapted as part of the learning process rather than being blindly copied. Understanding the implementation and being able to explain it during peer evaluation remains the responsibility of the student.

## Project Requirements

The project follows the requirements of the 42 `ft_printf` subject:

* The library must be named `libftprintf.a`.
* The project must provide `ft_printf()`.
* The required conversions are `cspdiuxX%`.
* `ar` must be used to create the library.
* `libtool` is forbidden.
* The library must be located at the root of the repository.
* The header must be named `ft_printf.h`.
* The project must follow the 42 Norm.
* Heap-allocated memory must be properly managed.
* The Makefile must contain `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

