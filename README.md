42 Projects: ft_printf
This repository contains my implementation of the ft_printf function, a fundamental part of the 42 School curriculum.
The goal is to recreate the standard C printf function with specified features and constraints while deepening 
understanding of variadic functions, memory management, and formatted output.

About ft_printf
printf is a variadic function, meaning it accepts a variable number of arguments. 
The first argument is a format string that defines how the subsequent arguments are formatted and displayed.

Key Concepts
Variadic Functions:
The <stdarg.h> library provides macros for working with variadic functions:

va_start: Initializes a va_list for use.
va_arg: Retrieves the next argument in the list.
va_end: Cleans up the va_list when done.

Return Type:
Returns the total length of characters printed.
If an error occurs, ft_printf returns -1.
