# 🔄 push_swap - Sorting Algorithm Challenge

<div align="center">

![42 School Badge](https://img.shields.io/badge/42-push__swap-blue)
![Language](https://img.shields.io/badge/language-C-orange)
![Grade](https://img.shields.io/badge/grade-84%2F100-yellow)
![Algorithm](https://img.shields.io/badge/algorithm-sorting-yellow)

</div>

## 📋 About The Project

**push_swap** is an algorithmic project from the 42 school curriculum where you must sort a stack of random integers using a **limited set of operations**, with the goal of using the **minimum number of moves** possible.

This is not just about sorting—it's about:
- Algorithmic optimization
- Understanding complexity (Big O notation)
- Problem-solving under constraints
- Choosing the right algorithm for the job

## 🎯 Project Purpose

The purpose of push_swap is to:
- Sort a stack of integers efficiently
- Work with only two stacks (stack A and stack B)
- Use only specific allowed operations
- Minimize the number of operations needed
- Learn about different sorting algorithms and their complexities
- Understand when to use which algorithm based on input size

## 📝 What I Learned

Through this project, I gained deep understanding of:

### Algorithmic Concepts
- **Sorting Algorithms**: Insertion sort, quick sort, radix sort, merge sort concepts
- **Algorithm Optimization**: Choosing and adapting algorithms for constraints
- **Complexity Analysis**: Understanding O(n), O(n log n), O(n²)
- **Stack Operations**: Working with stack data structures
- **Edge Cases**: Handling small sets (3, 5 numbers) vs large sets (100, 500)

### Problem-Solving Strategies
- **Divide and Conquer**: Breaking problems into smaller pieces
- **Chunking**: Dividing data into manageable groups
- **Cost Calculation**: Finding the cheapest move at each step
- **Optimization**: Reducing operation count through smart choices

### Implementation Skills
- **Doubly Linked Lists**: Efficient stack implementation
- **Indexing**: Pre-processing data for faster sorting
- **Median Finding**: Partitioning based on median values
- **Move Optimization**: Combining operations when possible

## 🎮 Allowed Operations

You have two stacks: **Stack A** (contains all numbers initially) and **Stack B** (empty).

### Swap Operations
- `sa`: Swap first 2 elements of stack A
- `sb`: Swap first 2 elements of stack B
- `ss`: Execute `sa` and `sb` simultaneously

### Push Operations
- `pa`: Push top element from B to A
- `pb`: Push top element from A to B

### Rotate Operations (shift up)
- `ra`: Rotate stack A (first element becomes last)
- `rb`: Rotate stack B
- `rr`: Execute `ra` and `rb` simultaneously

### Reverse Rotate Operations (shift down)
- `rra`: Reverse rotate stack A (last element becomes first)
- `rrb`: Reverse rotate stack B
- `rrr`: Execute `rra` and `rrb` simultaneously

## 🎯 Grading Criteria

Your grade depends on efficiency:

| Test Size | Maximum Operations | Points |
|-----------|-------------------|---------|
| 3 numbers | ≤ 3 operations | Required |
| 5 numbers | ≤ 12 operations | Required |
| 100 numbers | < 700 operations | 5 points |
| 100 numbers | < 900 operations | 4 points |
| 100 numbers | < 1100 operations | 3 points |
| 100 numbers | < 1300 operations | 2 points |
| 100 numbers | < 1500 operations | 1 point |
| 500 numbers | < 5500 operations | 5 points |
| 500 numbers | < 7000 operations | 4 points |
| 500 numbers | < 8500 operations | 3 points |
| 500 numbers | < 10000 operations | 2 points |
| 500 numbers | < 11500 operations | 1 point |

**Minimum to pass: 80/100**

## 🚀 How to Use

### Compilation

```bash
git clone https://github.com/Motaz9999/Push_swap.git
cd Push_swap
make
```

This creates the `push_swap` executable.

### Make Commands

```bash
make        # Compile push_swap
make bonus  # Compile checker (if implemented)
make clean  # Remove object files
make fclean # Remove object files and executables
make re     # Recompile everything
```

### Running the Program

```bash
# Basic usage
./push_swap 3 2 1 5 4

# Using variables
ARG="4 67 3 87 23"; ./push_swap $ARG

# Test with random numbers
ARG=$(seq 1 100 | shuf); ./push_swap $ARG

# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### Output

The program outputs the sequence of operations needed to sort:

```bash
$ ./push_swap 3 2 1
sa
rra

$ ./push_swap 5 4 3 2 1
pb
pb
sa
pa
pa
```

## 🧪 Testing

### Using the Checker (Bonus)

The checker verifies if the operations actually sort the stack:

```bash
# Successful sort
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK

# Failed sort
$ echo "sa\npb\nrrr" | ./checker 3 2 1
KO
```

### Automated Testing

```bash
# Test with 3 numbers (all combinations)
for i in {1..6}; do
    ARG=$(seq 1 3 | shuf); 
    ./push_swap $ARG | wc -l;
done

# Test with 5 numbers (average 100 times)
for i in {1..100}; do
    ARG=$(seq 1 5 | shuf); 
    ./push_swap $ARG | wc -l;
done | awk '{s+=$1} END {print s/NR}'

# Test with 100 numbers
for i in {1..100}; do
    ARG=$(seq 1 100 | shuf); 
    ./push_swap $ARG | wc -l;
done | sort -n

# Test with 500 numbers
for i in {1..100}; do
    ARG=$(seq 1 500 | shuf); 
    ./push_swap $ARG | wc -l;
done | sort -n
```

### Recommended Testers

- [SimonCROS/push_swap_tester](https://github.com/SimonCROS/push_swap_tester)
- [gemartin99/Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester)

### Visualizers

Visualize the sorting process:
- [push_swap_visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer)
- [push-swap-gui (Python)](https://pypi.org/project/push-swap-gui/)

```bash
# Using push_swap_visualizer
python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
```

## 🧠 Algorithm Strategies

### For 3 Numbers
Simple hardcoded solution:
- Check all 6 possible permutations
- Maximum 2 operations needed

```
Example: [3, 2, 1]
sa  -> [2, 3, 1]
rra -> [1, 2, 3]
```

### For 5 Numbers
Push smallest 2 to B, sort 3 in A, push back:
- Push the 2 smallest numbers to B
- Sort remaining 3 in A
- Push back from B in correct position
- Maximum 12 operations

### For 100-500 Numbers

Popular algorithms include:

#### 1. **Chunk/Butterfly Algorithm**
- Divide numbers into chunks (e.g., 5 chunks for 100 numbers)
- Push chunks to B in sorted chunks
- Push back to A using cheapest move

#### 2. **Turk Algorithm** (My Implementation)
- Index all numbers (assign position ranks)
- Find median and push smaller half to B
- Use cost calculation for optimal moves
- Rotate to minimize operations

#### 3. **Radix Sort Adapted**
- Convert to binary representation
- Sort by each bit position
- Very efficient but uses many operations

#### 4. **Quick Sort Inspired**
- Use pivots to partition
- Recursively sort partitions
- Adapted for stack operations

## 🔧 My Implementation

### Data Structure

I used a **doubly linked list** to represent the stacks:

```c
typedef struct s_stack
{
    int             value;
    int             index;
    int             pos;
    int             target_pos;
    int             cost_a;
    int             cost_b;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;
```

### Algorithm Overview

1. **Preprocessing**
   - Index all numbers (smallest = 0, largest = n-1)
   - This allows working with positions instead of values

2. **Initial Push to B**
   - Push all except 3 to stack B
   - Use median/chunk strategy to keep B semi-sorted

3. **Sort Remaining 3 in A**
   - Use simple 3-number sort

4. **Calculate Costs**
   - For each element in B, calculate cost to move it to correct position in A
   - Cost = rotations in A + rotations in B

5. **Execute Cheapest Move**
   - Find element with lowest cost
   - Execute the move
   - Repeat until B is empty

6. **Final Rotation**
   - Rotate A to put smallest number on top

## 📊 Performance

My implementation achieves:

- **3 numbers**: ≤ 2 operations
- **5 numbers**: ≤ 10 operations (avg: 7)
- **100 numbers**: ~900 operations (avg)
- **500 numbers**: ~7500 operations (avg)

**Grade: 84/100** ⭐

## 💡 Key Insights

### 1. Indexing is Powerful
Instead of sorting values, sort indices. This simplifies comparisons.

```c
// Before: compare values
if (node->value < median_value)
    
// After: compare indices  
if (node->index < median_index)
```

### 2. Cost Calculation Optimization

```c
// Calculate combined cost for simultaneous operations
if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
    combined_cost = max(abs(cost_a), abs(cost_b));
else
    combined_cost = abs(cost_a) + abs(cost_b);
```

### 3. Special Cases First
Handle 3 and 5 numbers separately before general algorithm:
- They have known optimal solutions
- Saves operations compared to general algorithm

### 4. Minimize Operations
Look for opportunities to combine:
- Use `rr` instead of separate `ra` and `rb`
- Use `rrr` instead of separate `rra` and `rrb`

## ⚠️ Common Pitfalls

1. **Not Handling Edge Cases**
   - Already sorted
   - Reverse sorted
   - Duplicates (should error)
   - Non-numeric input
   - Numbers outside int range

2. **Memory Leaks**
   - Always free the linked list
   - Free on error paths too

3. **Wrong Cost Calculation**
   - Forgetting that rotation can go both ways
   - Not minimizing when rotations are in same direction

4. **Inefficient for Small Sets**
   - Using general algorithm for 3-5 numbers
   - Not special-casing these

## 🎓 What This Project Teaches

- **Algorithm Selection**: Choosing the right tool for the job
- **Optimization**: Making code not just work, but work *well*
- **Complexity**: Understanding Big O in practice
- **Data Structures**: Practical use of linked lists and stacks
- **Testing**: Importance of comprehensive testing with edge cases
- **Visualization**: Understanding your algorithm visually

## 📚 Resources

- [Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Push Swap Tutorial (Medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Big O Notation](https://www.bigocheatsheet.com/)
- [Visualize Algorithms](https://visualgo.net/en/sorting)

## 👤 Author

**Motaz**
- GitHub: [@Motaz9999](https://github.com/Motaz9999)
- Intra: @moodeh

---

<div align="center">

**⭐ Sorting is easy. Sorting efficiently is an art.**

Made at 42 School

</div>
