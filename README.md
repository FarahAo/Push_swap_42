*This activity has been created as part of the 42 curriculum by tkhaleel, fabo-ome.*

# Push_swap

## Description

**Push_swap** is a 42 C project that sorts a list of unique integers in ascending order using two stacks (`a` and `b`) and a restricted set of stack operations. Stack `a` initially contains the input values (the first value is at the top), and stack `b` starts empty. The program prints a sequence of operations to **standard output**; a checker can replay those operations to verify that `a` is sorted and `b` is empty.

This version implements three selectable sorting strategies and an adaptive strategy that chooses an algorithm based on the initial disorder of the input. Its goal is to produce **correct, reasonably short operation sequences**, not to sort by printing the final values.

## Supported operations

| Operation    | Effect                                                      |
| ------------ | ----------------------------------------------------------- |
| `sa`, `sb`   | Swap the top two elements of stack `a` or `b`.              |
| `ss`         | Swap the top two elements of both stacks.                   |
| `pa`         | Push the top element of `b` onto `a`.                       |
| `pb`         | Push the top element of `a` onto `b`.                       |
| `ra`, `rb`   | Rotate a stack: move its top element to the bottom.         |
| `rr`         | Rotate both stacks.                                         |
| `rra`, `rrb` | Reverse-rotate a stack: move its bottom element to the top. |
| `rrr`        | Reverse-rotate both stacks.                                 |

## Instructions

### Build

From the repository root, run:

```sh
make          # Build ./push_swap (and the local Printf library)
make clean    # Remove object files
make fclean   # Remove object files and libraries
make re       # Rebuild from scratch
```

The project uses `cc` with `-Wall -Wextra -Werror`. It expects the `Printf/` directory used by the Makefile to be present.

### Run

```sh
./push_swap 3 2 1

./push_swap "3 2 1"

./push_swap "3 2" "1"

./push_swap --simple 5 4 3 2 1

./push_swap --medium 5 4 3 2 1

./push_swap --complex 5 4 3 2 1

./push_swap --adaptive 5 4 3 2 1

./push_swap --bench --adaptive 5 4 3 2 1
```

`--adaptive` is the default strategy. The other strategy flags force the corresponding sorting method. `--bench` adds statistics on **standard error** (`stderr`), keeping the operations on standard output (`stdout`) so they can still be piped to a checker.

For valid input that is already sorted, no operations are printed. With no arguments, the program exits silently. Invalid values (including duplicates, non-integers, and values outside the signed 32-bit integer range) cause `Error\n` to be written to `stderr`.

### Verify with a checker

Use a checker available on your machine; for example, if the repository has `checker/checker_os`:

```sh
ARG="4 67 3 87 23"

./push_swap $ARG | ./checker/checker_os $ARG
```

The checker should print `OK` when the instruction sequence sorts the **same original input**. Always pass the numbers to both `push_swap` and the checker; running the checker without the original numbers does not test the intended stack.

Check the number of printed operations:

```sh
ARG=$(shuf -i 1-10000 -n 100)

./push_swap $ARG | wc -l

ARG=$(shuf -i 1-10000 -n 500)

./push_swap $ARG | wc -l
```

To save benchmark statistics separately:

```sh
ARG="4 67 3 87 23"

./push_swap --bench $ARG 2> bench.txt | ./checker/checker_os $ARG

cat bench.txt
```

## Algorithms and design decisions

### 1. Simple strategy — selection sort adaptation
Selector: --simple

The algorithm repeatedly finds the smallest value remaining in stack a, rotates a in the shorter direction to bring that value to the top, and pushes it to b. Once only three elements remain in a, it sorts those with a dedicated three-element routine. Finally, it pushes the saved minimum values back from b to a, leaving the smallest on top.

The reason for selecting this method as the simple baseline is its straightforward logic and predictable behavior. Tiny inputs use specialized cases where applicable.

**Complexity:** The algorithm repeatedly searches through the remaining elements to find the minimum. The search sizes decrease from approximately `n` to `n-1`, `n-2`, and so on. Therefore, the total number of comparisons is bounded by

`n + (n-1) + ... + 1 = n(n+1)/2`

which gives **O(n²)**. The rotations and stack operations do not change this overall quadratic bound.

### 2. Medium strategy — chunk-based sorting

**Selector:** `--medium`

After assigning ranks, the algorithm chooses a chunk width approximately equal to `ceil(√n)`. It walks through `a`, pushes values that fall in a moving index window into `b`, and rotates `b` for lower-index values to help position them. It then repeatedly locates the largest index in `b`, rotates `b` in the shorter direction to bring that node to the top, and pushes it back to `a`.

Chunking is intended to process values in manageable ranges, reducing unnecessary work compared with repeatedly extracting minima directly from `a`.

**Complexity:** The algorithm divides the input into approximately `√n` chunks. Each element is processed while scanning the stacks and is moved or rotated according to its position within the current chunk. As the input size increases, the number of operations grows with the number of elements and the number of chunks. With a chunk width of approximately `√n`, the operation count therefore grows approximately as **O(n√n)**.

This provides a more scalable growth in the number of operations as the input size increases.

### 3. Complex strategy — binary radix sort

**Selector:** `--complex`

This algorithm first assigns rank indices. Starting with the least-significant bit, it processes the elements according to the current bit: values whose bit is `0` are pushed from `a` to `b` (`pb`), while those whose bit is `1` are rotated within `a` (`ra`). It then pushes everything from `b` back into `a` (`pa`) and continues to the next bit.

After all bits have been processed, stack `a` is sorted by rank, and therefore by original value. This strategy provides predictable behavior as the input size increases.

**Complexity:** Each element is processed once for every binary digit of its rank. An input of `n` elements requires approximately

`ceil(log₂ n)`

bits. Each bit pass processes all `n` elements and moves the elements between the stacks. Therefore, the total work is approximately

`n × ceil(log₂ n)`

giving **O(n log n)**.

### 4. Adaptive strategy — disorder-based selection

**Selector:** `--adaptive` (default)

The program calculates disorder **before performing any moves**. Disorder is the proportion of inverted pairs in the initial sequence: among all pairs `(i, j)` with `i < j`, count those for which `a[i] > a[j]`, then divide by the total number of pairs. A sorted input has disorder `0`; a reverse-sorted input has disorder `1`.

| Initial disorder | General strategy selected |
| ---------------- | ------------------------- |
| `0`              | No moves needed            |
| `0 < d < 0.2`    | Selection sort             |
| `0.2 ≤ d < 0.5`  | Chunk sort                 |
| `d ≥ 0.5`        | Binary radix sort          |

The current adaptive implementation also has **specialized handling for stacks of 2, 3, and 5 elements**, choosing dedicated routines for those sizes before applying the general disorder thresholds. This avoids unnecessary passes for very small inputs. The initial already-sorted check happens in the strategy selector for all strategies.

These thresholds follow the project specification. Their purpose is to use a simpler method when the input has little disorder and a more scalable method as disorder increases; they are not a guarantee that the chosen method produces the globally minimum number of moves for every input.

### Benchmark mode

The optional `--bench` mode reports the initial disorder percentage (two decimal places), selected strategy, total instruction count, and counts for each of the eleven stack operations. These metrics are printed to `stderr` **after sorting**. The operation stream remains on `stdout` for checker compatibility.

## Testing

The implementation was tested using all permutations of the integers `1` through `n` for every size `n = 2, 3, 4, 5, 6` — **872 cases per strategy**, or **3,488 small-input tests** across the four strategies — with all tests passing in the reported run. Additional individual random-input tests with 100 and 500 integers returned `OK` in the checker.

These correctness results do not establish performance on every input, memory safety, or compliance with any particular complexity target. Re-run the checker, performance measurements, invalid-input tests, and memory checks after changing any sorting or parsing code.

## Resources

- 42 Push_swap subject — the authoritative project requirements, allowed operations, strategy targets, benchmark format, and evaluation thresholds.
- [GNU Make manual](https://www.gnu.org/software/make/manual/) — build targets and Makefile behavior.
- [TutorialsPoint](https://www.tutorialspoint.com/) — understanding the chosen algorithms.
- [GeeksForGeeks](https://www.geeksforgeeks.org/) — fundamental data structures and algorithm analysis.

### Use of AI

AI tools (ChatGPT) were used as **learning and review assistance**, especially for reasoning about stack operations, checking the conditions in the three-element sorting routine, explaining how to pass operations and initial values correctly to a checker, and generating ideas/scripts for exhaustive small-input tests and random-input tests. AI also assisted in drafting and reviewing this README. The code and proposed fixes must be reviewed, tested, and understood by both contributors before submission.

## Contributors

- **tkhaleel** — contributions to parsing, stack operations/utilities, and chunk-based sorting.
- **fabo-ome** — contributions to stack utilities, sorting/operation implementations, radix sorting, and sorting helpers.
- **Both** - Testing, handle memory leaks and edge cases. 
