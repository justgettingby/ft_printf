*This project has been created as part of the 42 curriculum by ralkhrai.*

# ft_printf

## Description

The goal of this project is to learn variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`) by recoding part of `printf` as a static library, `libftprintf.a`.

```c
int ft_printf(const char *str, ...);
```

It writes to standard output with `write` only and returns the number of characters printed, or `-1` if a `write` fails.

Supported conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`.
Flags, width and precision are not supported.

### Functions

| Function | Role |
|---|---|
| `ft_printf` | Walks the format string, adds up the characters written, returns `-1` on any write error. |
| `ft_step` | Handles one position of the format string: plain text or a `%` conversion. |
| `ft_literal` | Writes a run of plain text up to the next `%` with a single `write`. |
| `ft_format` | Reads the next argument with `va_arg` and calls the matching helper. |
| `ft_putchar` | Writes one character (`%c`). |
| `ft_putstr` | Writes a string, or `(null)` for `NULL` (`%s`). |
| `ft_putn` | Prints an unsigned number in any base from a digit string (`%u`, `%x`, `%X`). |
| `ft_putnbr_signed` | Prints a `-` if needed, then the number in base 10 (`%d`, `%i`). |
| `ft_putptr` | Prints `0x` and the address in hexadecimal, or `(nil)` for `NULL` (`%p`). |

### Notes

- `%p` with `NULL` prints `(nil)` (Linux/glibc behavior).
- Arguments that do not match their specifier cause undefined behavior, as with the real `printf`.

## Algorithm and data structure

- **One pass over the format string.** `ft_printf` reads each character once, left to right. Variadic arguments can only be read in order (one `va_arg` per conversion), so a single ordered pass is the natural fit, and the cost grows linearly with the format length.
- **Text in runs.** `ft_literal` writes everything up to the next `%` with one `write`, which means fewer system calls than character by character, and it needs no buffer (buffer management is forbidden by the subject).
- **Dispatch in `ft_format`.** Each specifier maps to one helper, so adding a conversion means adding one branch.
- **`va_list` passed by pointer.** A `va_list` passed by value leaves the caller's copy indeterminate after `va_arg`. Passing `va_list *` makes every helper advance the same argument position.
- **Numbers use a fixed 64-byte `char` array on the stack.** `ft_putn` takes `num % base` (the least significant digit first), looks the digit up in a digit string, and fills the array from the end towards the start. It then prints it with one `write`. The digit string (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`) is the only thing that changes between `%u`, `%x`, `%X`, `%d`/`%i` and `%p`, so one function serves all of them.
- **Why 64 bytes.** An `unsigned long long` has at most 64 bits, so even base 2 needs at most 64 digits. Base 10 needs at most 20 and base 16 at most 16.
- **Why no `malloc`.** A fixed array cannot fail to allocate or leak, so there is no allocation error path.
- **`INT_MIN`.** `-INT_MIN` overflows an `int` (undefined behavior), so `ft_putnbr_signed` widens to `long long` before negating.
- **Pointers.** `ft_putptr` converts through `uintptr_t`, an integer type able to hold a pointer value.
- **Errors.** Every `write` result is checked and `-1` is passed up to `ft_printf`.

## Instructions

```
make            # build libftprintf.a
make clean      # remove object files
make fclean     # remove object files and the library
make re         # rebuild everything
```

Use it in your own program:

```c
#include "ft_printf.h"

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
