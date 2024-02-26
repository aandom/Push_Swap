# Push_Swap

## Description
Push_Swap is a project aimed at sorting a stack of integers using only a limited set of operations by using two stacks only. The goal is to efficiently sort the integers in ascending order by manipulating two stacks, namely Stack A and Stack B, using the following allowed operations:
- **Push (pa/pb)**: Take the top element from one stack and move it to the top of the other stack.
- **Rotate (ra/rb)**: Shift all elements of a stack by one position. For example, rotating Stack A means moving its top element to the bottom.
- **Reverse Rotate (rra/rrb)**: Shift all elements of a stack in the opposite direction by one position. For example, reverse rotating Stack A means moving its bottom element to the top.
- **Swap (sa/sb)**: Swap the top two elements of a stack.
- **Double Rotate (rr)**: Rotate both stacks simultaneously (ra and rb).
- **Double Reverse Rotate (rrr)**: Reverse rotate both stacks simultaneously (rra and rrb).
- **Double Swap (ss)**: Perform a swap operation on both stacks simultaneously (sa and sb).

These operations provide a limited set of actions to sort the given integers effectively.

## Algorithm
The algorithm I used to solve this project is looks like:

1. **Median-based Partitioning (Splitting Stack A)**:
    - **a)** Find the median of the given list of integers in Stack A.
    - **b)** Push all numbers greater than the median to Stack B.
    - **c)** Repeat steps **a** and **b** until only three elements are left in Stack A.
    - **d)** now sort the the three element left in Stack A.

2. **Selection Sort (Pushing Back elements from stack B to Stack A)**:
    - **a)** From Stack B, calculate the total number of moves needed for each element to be pushed back to the right position in Stack A.
      which is the total number of moves needed for the element to be on the top of stack B to be ready for push (cost of B) and the total number of moves needed to put that element on it's the right position on stack A (cost of A). 
    - **b)** then Perform the operationthat has the smallest/cheapest number of moves.
    - **c)** Repeat steps **a** and **b** until all elements in Stack B are pushed back to Stack A.

3. **Adjustment (Fixing Stack A)**:
    - At this stage, the elements in Stack A are partially sorted, but the minimum value may not be on the top of the stack.
    - Find the minimum value in Stack A and adjust its position by rotating or reverse rotating until it becomes the top/head of the stack.

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/aandom/Push_Swap.git
    ```
2. Navigate to the project directory:
    ```bash
    cd Push_Swap
    ```
3. Compile the program:
    ```bash
    make
    ```

## Usage
To use Push_Swap, follow the following steps:
1. Provide a list of integers as arguments:
    ```bash
    ./push_swap [list of integers]
    ```
2. The program will output a series of instructions to sort the integers.

Example:
```bash
./push_swap 5 3 8 1 2
