# 42 Common Core

This repository contains my projects from the [42](https://42.fr) Common Core curriculum — a peer-to-peer, project-based software engineering programme.

> **For reference only. Please do not copy.**

---

## Curriculum overview

The Common Core is split into circles (ranks). Each circle unlocks the next after the projects inside are validated.

| Circle | Projects | Topics |
|--------|----------|--------|
| 0 | [libft](#circle-0--libft) | C standard library reimplementation |
| 1 | [ft_printf](#circle-1--ft_printf), [get_next_line](#circle-1--get_next_line) | Variadic functions, file I/O |
| 2 | [pipex](#circle-2--pipex), [push_swap](#circle-2--push_swap), [so_long](#circle-2--so_long) | Process/pipe, sorting algorithms, 2D graphics |
| 3 | [minishell](#circle-3--minishell), [philosophers](#circle-3--philosophers) | Shell interpreter, concurrency/mutexes |
| 4 | [cub3d](#circle-4--cub3d), [cpp00–04](#circle-4--cpp00-04) | Raycasting engine, C++ OOP fundamentals |
| 5 | [cpp05–09](#circle-5--cpp05-09), [inception](#circle-5--inception), [webserv](#circle-5--webserv) | C++ advanced, Docker, HTTP server |

---

## Circle 0 — libft

A C utility library that reimplements ~45 standard functions (`string.h`, `ctype.h`, `stdlib.h`) plus linked-list helpers. Used as a dependency in nearly every subsequent project.

`circle0/libft/`

## Circle 1 — ft_printf

A reimplementation of `printf` supporting `%c %s %p %d %i %u %x %X %%`.

`circle1/ft_printf/`

## Circle 1 — get_next_line

A function that reads one line at a time from a file descriptor using a static buffer.

`circle1/get_next_line/`

## Circle 2 — pipex

Recreates the shell pipe operator: `./pipex file1 cmd1 cmd2 file2` behaves like `< file1 cmd1 | cmd2 > file2`. Bonus adds multiple pipes and here_doc support.

`circle2/pipex/`

## Circle 2 — push_swap

Sorts a stack of integers using only two stacks (a and b) and a limited set of operations. Includes a bonus `checker` program that validates a given sequence of moves.

`circle2/push_swap/`

## Circle 2 — so_long

A small 2D tile-based game built with MiniLibX. The player collects all items on a map and reaches the exit. Bonus adds animated sprites and enemy patrols.

`circle2/so_long/`

## Circle 3 — minishell

A Unix shell interpreter that supports pipes, redirections (`<`, `>`, `>>`, `<<`), environment variables, wildcards, and built-ins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.

`circle3/minishell/`

## Circle 3 — philosophers

The dining philosophers problem. Mandatory part uses POSIX threads and mutexes; bonus part uses processes and semaphores.

`circle3/philosophers/`

## Circle 4 — cub3d

A 3D first-person maze rendered with a raycasting engine (Wolf3D-style), built with MiniLibX. Parses a `.cub` configuration file for map layout and textures. Bonus adds animated door, minimap, and enemy sprites.

`circle4/cub3d/`

## Circle 4 — cpp00–04

Five C++ modules covering the fundamentals:

| Module | Topics |
|--------|--------|
| cpp00 | Namespaces, classes, member functions, I/O streams |
| cpp01 | Memory allocation, references, pointers to members, file streams |
| cpp02 | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form |
| cpp03 | Inheritance |
| cpp04 | Subtype polymorphism, abstract classes, interfaces |

`circle4/cpp00` – `circle4/cpp04`

## Circle 5 — cpp05–09

Four advanced C++ modules:

| Module | Topics |
|--------|--------|
| cpp05 | Exceptions, try/catch |
| cpp06 | C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`) |
| cpp07 | Templates |
| cpp08 | Templated containers, iterators, algorithms |
| cpp09 | STL — `map`, `stack`; Bitcoin exchange and RPN calculator |

`circle5/cpp05` – `circle5/cpp09`

## Circle 5 — inception

A Docker Compose infrastructure with three mandatory services (NGINX → WordPress → MariaDB) and five bonus services (Redis, FTP, Adminer, Portainer, static site), all running in separate containers behind TLS.

`circle5/inception/`

## Circle 5 — webserv

An HTTP/1.1 server written in C++98 using non-blocking I/O (`select`/`poll`). Supports GET, POST, DELETE, chunked encoding, CGI, file uploads, virtual hosts, and configurable routing via a config file.

`circle5/webserv/`

---

## How to build

Each project has a `Makefile`. Common targets:

```sh
make        # build
make bonus  # build with bonus features
make clean  # remove object files
make fclean # remove objects + binary
make re     # clean rebuild
```

Inception uses Docker:

```sh
cd circle5/inception
make        # docker-compose up
make down   # docker-compose down
```
