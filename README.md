### **ft_printf** - Custom Implementation

This repository contains my implementation of the **ft_printf** function, 
a core project in the **42 School** curriculum. 

The goal of this project is to recreate the standard C `printf` function 
while meeting specific requirements and constraints, 
deepening the understanding of **variadic functions**, **formatted output**, 
and **memory management**.

#### **About ft_printf**

`ft_printf` is a variadic function, meaning it accepts a variable number of arguments. 
The first argument is a format string that defines how the subsequent arguments are formatted and displayed. 
The function processes the format string, parsing specifiers like `%d`, `%s`, `%c`, etc., and outputs the corresponding formatted values.

#### **Key Concepts**

- **Variadic Functions**: 
  - The `<stdarg.h>` library is used to handle variadic functions, enabling the processing of a variable number of arguments.
  - Key macros:
    - `va_start`: Initializes the `va_list` for use.
    - `va_arg`: Retrieves the next argument from the list.
    - `va_end`: Cleans up the `va_list` after processing.

- **Return Type**: 
  - The function returns the total number of characters printed.
  - If an error occurs, `ft_printf` returns `-1`.

---

### **Function Overview**

| **Function** | **Description** |
|--------------|-----------------|
| `ft_printf(const char *str, ...)` | The main function that processes the format string and handles the variadic arguments. It returns the total number of characters printed. |
| `ft_printf_format(char specifier, va_list arg_ptr)` | A helper function that processes individual format specifiers (e.g., `%c`, `%d`, `%s`). |

#### **File: ft_printf_words.c**

| **Function** | **Description** |
|--------------|-----------------|
| `ft_printf_c(int c)` | Handles the `%c` format specifier and prints a character. |
| `ft_printf_s(char *s)` | Handles the `%s` format specifier and prints a string. |

#### **File: ft_printf__digits.c**

| **Function** | **Description** |
|--------------|-----------------|
| `ft_printf_d(int n)` | Handles the `%d` format specifier and prints a signed integer. |
| `ft_printf_u(unsigned int n)` | Handles the `%u` format specifier and prints an unsigned integer. |

#### **File: ft_printf_hex.c**

| **Function** | **Description** |
|--------------|-----------------|
| `ft_printf_p(void *ptr)` | Handles the `%p` format specifier and prints a pointer address. |
| `ft_printf_x(unsigned int n, char specifier)` | Handles the `%x` and `%X` format specifiers to print a hexadecimal value (lowercase/uppercase). |
| `ft_printf_hex(unsigned long n)` | Prints a hexadecimal value (lowercase) of the given unsigned long integer. |
| `ft_printf_hex_upper(unsigned long n)` | Prints a hexadecimal value (uppercase) of the given unsigned long integer. |
