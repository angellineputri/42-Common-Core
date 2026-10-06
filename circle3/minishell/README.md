# minishell

A Unix shell interpreter written in C. Parses and executes commands with pipes, redirections, environment variables, and built-in commands, closely following bash behaviour.

## Features

- Interactive prompt with GNU Readline (command history)
- Tokeniser → AST parser → executor pipeline
- Pipes (`|`) and parenthesised subshells
- Redirections: `<` `>` `>>` `<<` (here_doc)
- Environment variable expansion (`$VAR`, `$?`)
- Wildcard expansion (`*`)
- Signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`)

## Built-in commands

`echo` `cd` `pwd` `export` `unset` `env` `exit`

## Build

Requires `libreadline-dev`.

```sh
make
make clean
make fclean
make re
```

## Run

```sh
./minishell
```

## Project structure

| Directory | Contents |
|-----------|----------|
| `readline/` | input reading, signal handling, history |
| `tokenize/` | lexer, wildcard expansion |
| `syntax/` | syntax validation |
| `parsing/` | AST construction |
| `run/` | execution engine, pipes, redirections, built-ins |
| `exit_mini/` | memory cleanup and exit handling |
| `libft/` | bundled libft dependency |
