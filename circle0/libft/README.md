# libft

A C utility library that reimplements ~45 standard libc functions from scratch, plus a set of linked-list helpers. Used as a dependency in nearly every subsequent 42 project.

## Functions

**Character checks** — `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`  
**Character conversion** — `ft_toupper`, `ft_tolower`  
**String** — `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`  
**Memory** — `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`  
**Conversion** — `ft_atoi`, `ft_itoa`  
**Output** — `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`  
**Linked list (bonus)** — `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Build

```sh
make        # builds libft.a
make bonus  # adds linked-list functions to libft.a
make clean
make fclean
make re
```

## Output

`libft.a` — static library, link with `-lft -L.`
