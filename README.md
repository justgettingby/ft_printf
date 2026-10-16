*This project has been created as part of the 42 curriculum by ralkhrai.*

# ft_printf

## Description

`ft_printf` is a re-implementation of part of the C `printf` function, built as a static library (`libftprintf.a`). It writes to standard output with `write` only, and returns the number of characters printed, or `-1` if a `write` fails.

```c
int ft_printf(char *str, ...);
```

Supported conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`.
Flags, width and precision are not supported.

### Functions

| Function | Role |
|---|---|
| `ft_printf` | Walks the format string, adds up the characters written, returns `-1` on any write error. |
| `ft_step` | Handles one position of the format string: plain text or a `%` conversion. |
| `ft_literal` | Writes a run of plain text up to the next `%` with a single `write`. |
| `ft_format` | Reads the next argument with `va_arg` and calls the matching helper for the specifier. |
| `ft_putchar` | Writes one character (`%c`, `%%`). |
| `ft_putstr` | Writes a string, or `(null)` for a `NULL` pointer (`%s`). |
| `ft_putn` | Prints an unsigned number in any base from a digit list (`%u`, `%x`, `%X`). |
| `ft_putnbr_signed` | Prints a sign if needed, then the number in base 10 (`%d`, `%i`). |
| `ft_putptr` | Prints `0x` and the address in hexadecimal, or `(nil)` for `NULL` (`%p`). |

### Notes

- `%p` with `NULL` prints `(nil)` (Linux/glibc behavior).
- Arguments that do not match their specifier cause undefined behavior, as with the real `printf`.

## Instructions

```
make            # build libftprintf.a
make clean      # remove object files
make fclean     # remove object files and the library
make re         # rebuild everything
```

Use it in your own program:

```c
#include "libftprintf.h"

int main(void)
{
	ft_printf("Hello %s, number %d\n", "world", 42);
	return (0);
}
```

```
cc -Wall -Wextra -Werror main.c libftprintf.a
```

## Resources

- Linux manual pages: `man 3 printf`, `man 2 write`, `man 3 stdarg`.

### Use of AI

LLMs were used to explain concepts (variadic arguments, `va_list` passing, `uintptr_t`), to generate comparison test programs, and to assist with this README :)
