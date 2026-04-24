*This project has been created as part of the 42 curriculum by echarmai.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.

The goal is to sort a list of integers using two stacks (A and B) and a limited set of operations, while generating the smallest possible number of instructions.

At the start:
- Stack **A** contains a list of integers.
- Stack **B** is empty.

The program must output a sequence of operations that sorts stack A in ascending order.

Allowed operations:

- `sa` / `sb` — swap the first two elements of stack A or B
- `ss` — `sa` and `sb` at the same time
- `pa` — push the first element of B to A
- `pb` — push the first element of A to B
- `ra` / `rb` — rotate stack A or B (first element becomes last)
- `rr` — `ra` and `rb` at the same time
- `rra` / `rrb` — reverse rotate stack A or B (last element becomes first)
- `rrr` — `rra` and `rrb` at the same time

The challenge is not only to sort the numbers, but to do so efficiently with as few moves as possible.

---

## Algorithm Overview

This implementation includes:

- Hardcoded optimal sorting for:
  - 2 numbers
  - 3 numbers
  - 4 numbers
  - 5 numbers
- A stack-based strategy using:
  - Position tracking
  - Smart rotations (`ra` vs `rra`) based on element position
- A larger-scale sorting strategy for bigger inputs

The program minimizes unnecessary rotations by calculating whether it is faster to rotate forward or backward.

---

### Compilation
make

### Execution
./push_swap 4 3 2 1
