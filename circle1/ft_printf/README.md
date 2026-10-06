# ft_printf

A reimplementation of the C standard `printf` function as a static library.

## Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | single character |
| `%s` | string |
| `%p` | pointer address (hex) |
| `%d` / `%i` | signed decimal integer |
| `%u` | unsigned decimal integer |
| `%x` | unsigned hex (lowercase) |
| `%X` | unsigned hex (uppercase) |
| `%%` | literal `%` |

## Build

```sh
make        # builds libftprintf.a
make clean
make fclean
make re
```

## Output

`libftprintf.a` — link with `-lftprintf -L.`

## Usage

```c
#include "ft_printf.h"

ft_printf("Hello %s, you are %d years old\n", name, age);
```
