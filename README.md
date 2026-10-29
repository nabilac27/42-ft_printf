# ft_printf

## Overview

`ft_printf` is a recreation of the standard C `printf` function. It focuses on **variadic functions**, **formatted output** and **memory management**.

| Specifier | Description | Type |
|-----------|-------------|------|
| `%c` | Prints a single character | `int` |
| `%s` | Prints a string | `char *` |
| `%p` | Prints a pointer address in hexadecimal | `void *` |
| `%d` `%i` | Prints a signed integer | `int` |
| `%u` | Prints an unsigned integer | `unsigned int` |
| `%x` `%X` | Prints a hexadecimal number (lower / upper) | `unsigned int` |
| `%%` | Prints a percent sign | none |

The function returns the number of characters printed, or `-1` on error.

## Concepts Learned

- Variadic functions with `<stdarg.h>`
  - `va_start` initializes the argument list
  - `va_arg` fetches the next argument
  - `va_end` cleans up the list
- Format string parsing
- Number base conversion (decimal to hexadecimal)
- Static libraries with `ar` and `make`

## Structure

| File | Role |
|------|------|
| `ft_printf.c` | Main function and format parsing |
| `ft_printf_digits.c` | `%d` `%i` `%u` |
| `ft_printf_hex.c` | `%x` `%X` `%p` |
| `ft_printf_words.c` | `%c` `%s` |
| `ft_printf.h` | Prototypes and includes |

## Usage

```sh
git clone https://github.com/nabilac27/ft_printf.git
cd ft_printf
make                     # builds libftprintf.a
cc main.c libftprintf.a
./a.out
```

## Example

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s!\n", "World");
    ft_printf("Printed %d characters\n", len);
    ft_printf("Hex: %x / %X\n", 255, 255);
    return (0);
}
```