# push_swap

Sorts a stack of integers using only two stacks (a and b) and a fixed instruction set. The goal is to sort with the fewest possible operations.

## Operations

| Instruction | Effect |
|-------------|--------|
| `sa` / `sb` / `ss` | swap top two elements of stack a / b / both |
| `pa` / `pb` | push top of b to a / top of a to b |
| `ra` / `rb` / `rr` | rotate stack a / b / both upward |
| `rra` / `rrb` / `rrr` | reverse rotate stack a / b / both |

## Build

```sh
make          # builds ./push_swap
make bonus    # builds ./checker
make clean
make fclean
make re
```

## Usage

```sh
# Generate sorted instruction list
./push_swap 3 2 1 5 4

# Validate a solution with checker (bonus)
./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
# prints OK or KO
```

## Algorithm

Numbers are ranked to reduce the problem to sorting indices. Small inputs (≤3, ≤5) use hard-coded optimal sequences. Larger inputs use a radix / digit-group approach that processes the stack in passes, keeping the operation count within the 42 project limits (500 ops for 100 numbers, 5000 for 500).
