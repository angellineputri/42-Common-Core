# cpp09 — STL in Practice

Applies STL containers (`std::map`, `std::stack`, `std::deque`) to real algorithmic problems.

## Exercises

| Exercise | Description |
|----------|-------------|
| ex00 | `BitcoinExchange` — reads a price database CSV and evaluates a wallet at historical BTC prices using `std::map` |
| ex01 | `RPN` — evaluates a Reverse Polish Notation expression using `std::stack` |
| ex02 | `PmergeMe` — sorts a sequence using the Ford-Johnson merge-insert algorithm with both `std::deque` and `std::vector`, comparing times |

## Build

```sh
cd exNN && make
```

## Run

```sh
# ex00 — Bitcoin exchange
./btc input.txt

# ex01 — RPN calculator
./RPN "3 4 + 2 * 7 /"

# ex02 — merge-insert sort
./PmergeMe 3 5 9 7 4
```
