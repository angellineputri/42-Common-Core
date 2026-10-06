# get_next_line

A C function that reads one line at a time from a file descriptor. Each call returns the next line (including the newline character), or `NULL` on EOF or error.

## Signature

```c
char *get_next_line(int fd);
```

## Features

- Works with any file descriptor (file, stdin, pipe)
- Configurable buffer size via `-D BUFFER_SIZE=n` at compile time (default 42)
- Bonus: handles multiple file descriptors simultaneously

## Files

| File | Description |
|------|-------------|
| `get_next_line.c` | main function |
| `get_next_line_utils.c` | helper functions |
| `get_next_line_bonus.c` | multi-fd variant |
| `get_next_line_bonus.h` | bonus header |

## Build

No Makefile — compile directly into your project:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```
