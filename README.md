# Push_Swap

This project is a sorting algorithm created as part of the 42 School curriculum. The goal is to sort a stack of integers, given as arguments, using the fewest possible "swap" operations, with the help of two stacks (stack A and stack B).

Stack A is initialized with the numbers provided as arguments. Stack B is initially empty and serves as a working space.

## Allowed Operations

The sort must be performed using only the following operations:

- `sa` (swap a): Swaps the first 2 elements at the top of stack a.
- `sb` (swap b): Swaps the first 2 elements at the top of stack b.
- `ss`: `sa` and `sb` at the same time.
- `pa` (push a): Takes the first element at the top of b and puts it on a.
- `pb` (push b): Takes the first element at the top of a and puts it on b.
- `ra` (rotate a): Shifts up all elements of stack a by one position (the first element becomes the last).
- `rb` (rotate b): Shifts up all elements of stack b by one position (the first element becomes the last).
- `rr`: `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shifts down all elements of stack a by one position (the last element becomes the first).
- `rrb` (reverse rotate b): Shifts down all elements of stack b by one position (the last element becomes the first).
- `rrr`: `rra` and `rrb` at the same time.

## Algorithm

The algorithm used in this project is designed to be efficient and optimized to reduce the number of instructions. It is inspired by the "Turkish" algorithm (cf. https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

**Error Handling:** The program first checks if the arguments are valid (only numbers, no duplicates, no integer overflow).

**Sort for 3 numbers:** If stack A contains only 3 numbers, a specific sort (`sort_three`) is applied to sort them in a minimum number of moves.

### Main Algorithm (for N > 3):

Two elements are first pushed from A to B to initialize stack B.

As long as there are more than 3 elements in A, the program enters an optimization loop:

**Cost Analysis:** For each element in A, the algorithm calculates its "target" in B and the "cost" in operations (`ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) to bring this element and its target to the top of their respective stacks.

**Best Move:** The element with the lowest cost (`is_good_one`) is identified.

**Execution:** The calculated rotations are performed, and the element is pushed from A to B (`pb`).

Once A is reduced to 3 elements, `sort_three` is applied to A.

**Return to A:** The elements are then moved back from B to A. The algorithm identifies the correct target in A for each element in B and performs the necessary rotations before "pushing" (`pa`).

**Finalization:** Stack A is finally rotated (`rra`) until the smallest number is at the top, ensuring it is perfectly sorted.

## Compilation and Usage

To compile, use the provided `Makefile`:

```bash
make
````

### Running the program:

The program can take numbers as arguments in two ways:

1. As multiple arguments:

````bash
./push_swap 2 1 3 6 5 8
````

2. As a single string (numbers separated by spaces):

````bash
./push_swap "2 1 3 6 5 8"
````

The program will output the list of operations to perform to standard output.
