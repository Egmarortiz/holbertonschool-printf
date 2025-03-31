Holberton School _printf Project
Overview
This project is a custom implementation of the standard C library function printf. The goal is to reproduce basic formatted output functionality while deepening our understanding of variadic functions, function pointers, and modular C programming.

The custom _printf function supports a subset of conversion specifiers:

%c – Print a character.

%s – Print a string (if the string is NULL, print (null)).

%d and %i – Print a signed integer in base 10.

%% – Print a literal percent sign.

This implementation does not support:

Flag characters (e.g., -, +, 0)

Field width and precision

Length modifiers

Advanced buffering (the standard library printf buffer handling is not reproduced)

File Structure
The project is organized into multiple files for modularity:

main.h
Contains all function prototypes, macro definitions, and necessary type declarations used throughout the project.

_printf.c
Implements the _printf function. It parses the format string, dispatches conversion specifiers to the proper conversion functions, and handles output to stdout.

conversion.c
Contains functions that handle conversion specifiers:

print_char – Prints a single character.

print_string – Prints a string, handling NULL pointers.

print_int – Prints an integer (handling both %d and %i).

print_percent – Prints a literal %.

_putchar.c
Implements the _putchar function which writes a single character to stdout. This function is used by _printf and the conversion functions.

main.c (optional, for testing)
A driver file containing test cases for _printf.

How to Compile
Use the following command to compile the project (all .c files must be in the same directory):

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o _printf
-Wall -Werror -Wextra -pedantic: Enable and enforce strict compiler warnings.

-std=gnu89: Use the GNU89 standard.

-Wno-format: Suppress warnings related to format strings.

-o _printf: Create an executable named _printf.

Usage
After compiling, run your custom printf as follows:

./_printf "Hello, %s! Your score is %d%%.\n" "Alice" 95
Expected output:

Hello, Alice! Your score is 95%.
The function returns the total number of characters printed (excluding the terminating null byte).

How It Works
Parsing the Format String
The _printf function processes the format string character by character:

Literal Characters:
Printed directly using _putchar, and the character count is updated.

Conversion Directives:
When a % is encountered, the next character determines the conversion specifier.

For %c, %s, %d/%i, and %%, the function calls the corresponding conversion function.

If an unsupported specifier is found, the % and the following character are printed literally.

Variadic Functions
The function uses variadic arguments to handle an indefinite number of parameters:

va_list, va_start, va_arg, va_end:
These macros (declared in <stdarg.h>) are used to access the additional arguments passed to _printf.

Conversion Functions
Each conversion function is responsible for:

Retrieving the correct type from the va_list.

Converting it to a character representation.

Printing the result using _putchar.

Returning the number of characters printed.

For example, the integer conversion function (print_int) handles both %d and %i specifiers, taking care of negative numbers and printing each digit individually.

Example Code Snippet
Here’s an example demonstrating the usage of _printf:

#include "_printf.h"

int main(void)
{
    int printed;

    printed = _printf("Hello, %s! Your score is %d%%.\n", "Alice", 95);
    _printf("Printed %d characters.\n", printed);
    return (0);
}

Contribution Guidelines
Coding Style:
All code should follow the Betty coding style guidelines.

Testing:
Write and run comprehensive tests to ensure that each conversion specifier is handled correctly.

Documentation:
Ensure that each file and function is properly documented in accordance with project requirements.

License
(Include any applicable license information here.)

Authors
[Egmar Ortiz, Victor Diaz]
