# pipex

Recreates the shell pipe mechanism in C. The program opens two files and connects two commands through a pipe, mirroring the shell construct `< file1 cmd1 | cmd2 > file2`.

## Usage

```sh
./pipex file1 cmd1 cmd2 file2
# equivalent to: < file1 cmd1 | cmd2 > file2

# bonus — multiple pipes
./pipex file1 cmd1 cmd2 cmd3 file2

# bonus — here_doc
./pipex here_doc LIMITER cmd1 cmd2 file2
# equivalent to: cmd1 << LIMITER | cmd2 >> file2
```

## Build

```sh
make          # builds ./pipex
make bonus    # builds ./pipex_bonus
make clean
make fclean
make re
```

## How it works

1. Opens `file1` for reading and `file2` for writing
2. Creates a pipe and forks a child process
3. Child runs `cmd1` with stdin from `file1` and stdout into the pipe
4. Parent runs `cmd2` with stdin from the pipe and stdout to `file2`
5. Bonus uses multiple forks chained through pipes

## Dependencies

Links against `libft` (bundled in `libft/`).
