# Push_swap

A sorting algorithm project that sorts integers using two stacks and a limited set of operations, with the goal of minimizing the number of operations performed.

## 📖 Overview

Push_swap is a 42 school project that implements an efficient sorting algorithm using only two stacks (A and B) and a specific set of stack operations. The program reads a list of integers and outputs the optimal sequence of operations needed to sort them in ascending order.

## 🎯 Algorithm Implementation

This implementation uses a **hybrid sorting approach**:

### Small Numbers (2-5 elements)
- **2-3 elements**: Hardcoded optimizations using simple swap and rotate operations
- **4-5 elements**: Extract smallest element(s) to stack B, sort remaining 3 in stack A, then push back

### Large Numbers (6+ elements)
- **Radix Sort with Index Normalization**
  - Each number is assigned an index based on its relative position (0 to n-1)
  - Sorts by processing each bit position from LSB to MSB
  - Elements with bit 0 go to stack B, bit 1 stays in stack A
  - After processing all elements, push everything back from B to A
  - Repeat for each bit position until sorted

**Key Features:**
- Index-based sorting eliminates the need to work with actual values
- Efficient bit manipulation for decision making
- Optimal for large datasets
- Predictable operation counts

## 🛠️ Project Structure

```
Push_swap/
├── includes/
│   └── push_swap.h           # Header with structures and function prototypes
├── src/
│   ├── main.c                # Entry point and argument parsing
│   ├── radixsort.c           # Radix sort implementation
│   ├── sortstack.c           # Small number sorting (2-5) and sort dispatcher
│   ├── normalization.c       # Index assignment for radix sort
│   ├── vald_input.c          # Input validation and parsing
│   ├── error_handle.c        # Error handling
│   ├── stack_utils.c         # Stack basic operations (create, push, free, add)
│   ├── stack_utils2.c        # Additional utilities (is_empty, pop)
│   ├── ops_a.c               # Stack A operations (pa, sa, ra, rra)
│   ├── ops_b.c               # Stack B operations (pb, sb, rb, rrb)
│   └── ops_both.c            # Combined operations (rr, rrr)
├── libft/                    # Custom C library
├── Makefile                  # Build configuration
└── checker_linux             # Checker program for validation
```

## 🔧 Installation

### Prerequisites
- GCC compiler
- Make
- Linux/Unix environment

### Build

```bash
# Clone the repository
git clone https://github.com/Motaz9999/Push_swap.git
cd Push_swap

# Compile the project
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

## 💻 Usage

### Basic Usage

```bash
# Sort a list of integers
./push_swap 3 2 1 0

# With negative numbers
./push_swap 5 -2 8 0 -9

# Single argument with space-separated numbers
./push_swap "4 67 3 87 23"
```

### Output
The program outputs the sequence of operations:
```bash
./push_swap 3 2 1
sa
rra
```

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |
| `ra` | Rotate A up (first → last) |
| `rb` | Rotate B up (first → last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (last → first) |
| `rrb` | Reverse rotate B (last → first) |
| `rrr` | `rra` and `rrb` simultaneously |

## ✅ Input Validation

The program validates all input and handles:
- **Non-numeric arguments** → Error
- **Duplicate numbers** → Error
- **Integer overflow** (> INT_MAX or < INT_MIN) → Error
- **Empty arguments** → Error
- **Single argument with multiple numbers** → Splits and validates

```bash
# These will output "Error"
./push_swap 1 2 3 3          # Duplicate
./push_swap 1 abc 3          # Non-numeric
./push_swap 2147483648       # Overflow
./push_swap ""               # Empty
```

## 🧪 Testing

### Test with Checker

```bash
# Generate random numbers and test
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
# Output: OK (if sorted correctly) or KO (if not)

# Test with 100 random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

# Count operations for 100 numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Performance Testing Script

```bash
#!/bin/bash
# test_push_swap.sh

echo "Testing 100 numbers - 100 iterations"
total=0
for i in {1..100}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    COUNT=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    total=$((total + COUNT))
    echo "Test $i: $RESULT - Operations: $COUNT"
done
echo "Average: $((total / 100)) operations"

echo -e "\nTesting 500 numbers - 20 iterations"
total=0
for i in {1..20}; do
    ARG=$(seq 1 500 | shuf | tr '\n' ' ')
    COUNT=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    total=$((total + COUNT))
    echo "Test $i: $RESULT - Operations: $COUNT"
done
echo "Average: $((total / 20)) operations"
```

## 📊 Performance Requirements

| Input Size | Excellent | Good | Average |
|------------|-----------|------|---------|
| 3 numbers  | ≤ 3 ops   | - | - |
| 5 numbers  | ≤ 12 ops  | - | - |
| 100 numbers| < 700 ops | < 900 ops | < 1100 ops |
| 500 numbers| < 5500 ops| < 7000 ops| < 8500 ops |

*Radix sort typically performs well within these limits*

## 🔍 Algorithm Details

### Radix Sort Process

1. **Initialization Phase** (`normalization.c`)
   - Assign each element an index (0 to n-1)
   - Index represents relative position in sorted order
   - Example: [42, -5, 100, 0] → [-5:0, 0:1, 42:2, 100:3]

2. **Bit Calculation** (`radixsort.c`)
   - Calculate number of bits needed: `ceil(log2(size))`
   - Example: 100 elements need 7 bits

3. **Sorting by Bits**
   - For each bit position (0 to max_bits):
     - If bit is 0: push to stack B (`pb`)
     - If bit is 1: rotate in stack A (`ra`)
   - After processing all elements, push everything back from B to A (`pa`)
   - Repeat for next bit position

4. **Result**
   - After processing all bits, stack A is sorted in ascending order

### Small Number Optimization

**For 2-3 elements:** Direct comparison and swap
- Maximum 3 operations needed

**For 4-5 elements:**
- Find smallest element(s)
- Push to stack B
- Sort remaining 3 elements in stack A
- Push back from stack B
- Maximum ~10-12 operations

## 📝 Key Implementation Details

### Data Structure
```c
typedef struct s_node
{
    int             value;   // Actual integer value
    int             index;   // Normalized index for radix sort
    struct s_node   *next;   // Pointer to next node
} t_node;
```

### Memory Management
- All dynamically allocated memory is properly freed
- Error handling frees stack before exit
- No memory leaks

### Edge Cases Handled
- Empty input
- Single element (already sorted)
- Already sorted input (no operations)
- Negative numbers
- Mixed positive and negative numbers

## 👤 Author

**Motaz** (moodeh)
- GitHub: [@Motaz9999](https://github.com/Motaz9999)
- 42 Intra: moodeh

## 📚 Learning Outcomes

- Algorithm complexity analysis (time & space)
- Bit manipulation techniques
- Stack data structure implementation
- Memory management in C
- Input validation and error handling
- Code optimization strategies

---

**Note:** This is a 42 school project. If you're a student, use this as reference for understanding concepts, not for copying code.