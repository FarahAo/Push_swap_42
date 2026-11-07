*This activity has been created as part of the 42 curriculum by tkhaleel, fabo-ome.*

# Push_swap

## Description

**Push_swap** is a 42 C project that sorts a list of unique integers in ascending order using two stacks (`a` and `b`) and a restricted set of stack operations. Stack `a` initially contains the input values (the first value is at the top), and stack `b` starts empty. The program prints a sequence of operations to **standard output**; a checker can replay those operations to verify that `a` is sorted and `b` is empty.

This version implements three selectable sorting strategies and an adaptive strategy that chooses an algorithm based on the initial disorder of the input. Its goal is to produce **correct, reasonably short operation sequences**, not to sort by printing the final values.

### Supported operations

| Operation | Effect |
| --- | --- |
| `sa`, `sb` | Swap the top two elements of stack `a` or `b`. |
| `ss` | Swap the top two elements of both stacks. |
| `pa` | Push the top element of `b` onto `a`. |
| `pb` | Push the top element of `a` onto `b`. |
| `ra`, `rb` | Rotate a stack: move its top element to the bottom. |
| `rr` | Rotate both stacks. |
| `rra`, `rrb` | Reverse-rotate a stack: move its bottom element to the top. |
| `rrr` | Reverse-rotate both stacks. |

## Instructions

### Build

From the repository root, run:

```sh
make          # Build ./push_swap (and the local Libft and Printf libraries)
make clean    # Remove object files
make fclean   # Remove object files and binaries/libraries
make re       # Rebuild from scratch
```

The project uses `cc` with `-Wall -Wextra -Werror`. It expects the `Libft/` and `Printf/` directories used by the Makefile to be present.

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

### 1. Input preparation and index compression

The parser splits supplied arguments on spaces, checks numeric syntax and signed 32-bit bounds, and rejects duplicate values before building stack `a` as a singly linked list. Each stack tracks its head and size.

For the chunk and radix strategies, `assign_indexes()` gives each node its **rank among the input values**: the smallest value gets index `0`, the next gets `1`, and so on. This allows the algorithms to work with negative values and large numeric gaps while operating on indices from `0` to `n - 1`. The current rank-assignment implementation uses pairwise comparisons, so its preprocessing time is **O(n²)**; the operation-complexity figures below refer to emitted Push_swap instructions rather than this preprocessing CPU work.

### 2. Simple strategy — selection sort adaptation

**Selector:** `--simple`  
**Target operation complexity:** O(n²)

The algorithm repeatedly finds the smallest value remaining in stack `a`, rotates `a` in the shorter direction to bring that value to the top, and pushes it to `b`. Once only three elements remain in `a`, it sorts those with a dedicated three-element routine. Finally, it pushes the saved minimum values back from `b` to `a`, leaving the smallest on top.

The reason for selecting this method as the **simple baseline** is its straightforward logic and clear operation-count upper bound: up to O(n) stack rotations per extracted element over O(n) extractions, producing O(n²) operations. Tiny inputs use specialized cases where applicable.

### 3. Medium strategy — chunk-based sorting

**Selector:** `--medium`  
**Design target:** O(n√n) Push_swap operations

After assigning ranks, the algorithm chooses a chunk width approximately equal to `ceil(√n)`. It walks through `a`, pushes values that fall in a moving index window into `b`, and rotates `b` for lower-index values to help position them. It then repeatedly locates the largest index in `b`, rotates `b` in the shorter direction to bring that node to the top, and pushes it back to `a`.

Chunking is intended to process values in manageable ranges, reducing unnecessary work compared with repeatedly extracting minima directly from `a`. **Complexity caveat:** although O(n√n) is the project's medium-strategy target, the current implementation's repeated searches/rotations in `b` do not by themselves establish a rigorous O(n√n) worst-case operation bound; a worst-case bound of O(n²) is straightforward from the implementation. This should be analyzed or improved before claiming a proven O(n√n) bound.

### 4. Complex strategy — binary LSD radix sort

**Selector:** `--complex`  
**Push_swap operation complexity:** O(n log n)

This algorithm first assigns rank indices. Starting with the least-significant bit, it processes exactly `n` elements per bit position: values whose current bit is `0` are pushed from `a` to `b` (`pb`), while those whose bit is `1` are rotated within `a` (`ra`). It then pushes everything from `b` back into `a` (`pa`) and continues to the next bit. After all bits have been processed, stack `a` is sorted by rank, and therefore by original value.

There are O(log n) bit positions; each pass needs O(n) emitted operations, making this a predictable O(n log n) sorting strategy in the project's operation-count model. It trades some extra operations on small or nearly sorted inputs for predictable scaling on larger inputs.

### 5. Adaptive strategy — disorder-based selection

**Selector:** `--adaptive` (default)

The program calculates disorder **before performing any moves**. Disorder is the proportion of inverted pairs in the initial sequence: among all pairs `(i, j)` with `i < j`, count those for which `a[i] > a[j]`, then divide by the total number of pairs. A sorted input has disorder `0`; a reverse-sorted input has disorder `1`.

| Initial disorder | General strategy selected | Target operation class |
| --- | --- | --- |
| `0` | No moves needed | O(1) emitted operations |
| `0 < d < 0.2` | Selection sort | O(n²) |
| `0.2 ≤ d < 0.5` | Chunk sort | O(n√n) target; see caveat above |
| `d ≥ 0.5` | Binary radix sort | O(n log n) |

The current adaptive implementation also has **specialized handling for stacks of 2, 3, and 5 elements**, choosing dedicated routines for those sizes before applying the general disorder thresholds. This avoids unnecessary passes for very small inputs. The initial already-sorted check happens in the strategy selector for all strategies.

These thresholds follow the project specification. Their purpose is to use a simpler method when the input has little disorder and a more scalable method as disorder increases; they are not a guarantee that the chosen method produces the globally minimum number of moves for every input.

### Benchmark mode

The optional `--bench` mode reports the initial disorder percentage (two decimal places), selected strategy and advertised complexity class, total instruction count, and counts for each of the eleven stack operations. These metrics are printed to `stderr` **after sorting**. The operation stream remains on `stdout` for checker compatibility.

## Testing

The implementation was tested using all permutations of the integers `1` through `n` for every size `n = 2, 3, 4, 5, 6` — **872 cases per strategy**, or **3,488 small-input tests** across the four strategies — with all tests passing in the reported run. Additional individual random-input tests with 100 and 500 integers returned `OK` in the checker.

These correctness results do not establish performance on every input, memory safety, or compliance with the target complexity classes. Re-run the checker, performance measurements, invalid-input tests, and memory checks after changing any sorting or parsing code.

## Resources

- [42 Push_swap subject](en.subject.pdf) — the authoritative project requirements, allowed operations, strategy targets, benchmark format, and evaluation thresholds. (If the PDF is not committed to the repository, consult the copy provided by 42.)
- [GNU Make manual](https://www.gnu.org/software/make/manual/) — build targets and Makefile behavior.
- [tutorialspoint] (https://www.tutorialspoint.com/) — Understanding the choosen algorithms.
- [GeeksForGeeks](https://www.geeksforgeeks.org/) — fundamental data structures and algorithm analysis.


### Use of AI

AI tools (ChatGPT) were used as **learning and review assistance**, especially for reasoning about stack operations, checking the conditions in the three-element sorting routine, explaining how to pass operations and initial values correctly to a checker, and generating ideas/scripts for exhaustive small-input tests and random-input tests. AI also assisted in drafting and reviewing this README. The code and proposed fixes must be reviewed, tested, and understood by both contributors before submission.

## Contributors

- **tkhaleel** — contributions to parsing, stack operations/utilities, and chunk-based sorting, based on the supplied source-file authorship and revision records.
- **fabo-ome** — contributions to stack utilities, sorting/operation implementations, radix sorting, and sorting helpers, based on the supplied source-file authorship and revision records.

Both contributors are responsible for understanding and explaining the complete project. **Review and adjust the individual contribution details above to accurately reflect your team's actual work before submission.**
