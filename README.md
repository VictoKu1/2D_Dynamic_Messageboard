# 2D Dynamic Message Board

A C++ implementation of a dynamic two-dimensional message board system that allows posting and reading messages in both horizontal and vertical directions.

## Task

Write a class to manage a two-dimensional message board according to the specifications in Part A.

In Part B, you must write a complete implementation. The implementation must pass all tests (60% of the grade):

```bash
make test
./test
```

Additionally, the code must successfully pass the readability test (20% of the grade):

```bash
make tidy
```

And the memory test (20% of the grade):

```bash
make valgrind
```

Furthermore, you must write a **main program** that demonstrates your solution. The content of the program is your choice - be creative. The program will not be automatically tested but only during presentation.

When you reach a state where both commands run without errors, you can check your grade using the command:

```bash
bash grade
```

## Solution

This project implements a dynamic 2D message board using C++ with the following key components:

### Core Architecture

The solution consists of three main files:
- **`Board.hpp`** - Header file defining the Board class interface
- **`Board.cpp`** - Implementation of the Board class methods
- **`Direction.hpp`** - Enumeration defining message directions (Horizontal/Vertical)

### Data Structure

The board uses a **sparse matrix representation** implemented as a nested `std::map`:
```cpp
std::map<int, std::map<int, char>> *board;
```

This approach efficiently handles:
- **Dynamic sizing**: The board automatically expands as needed
- **Memory efficiency**: Only occupied positions consume memory
- **Flexible positioning**: Messages can be placed at any coordinates

### Key Features

1. **Message Posting** (`post` method):
   - Supports both horizontal and vertical message placement
   - Automatically expands board boundaries
   - Overwrites existing content at overlapping positions
   - Handles edge cases and invalid directions

2. **Message Reading** (`read` method):
   - Reads messages of specified length in either direction
   - Returns underscore (`_`) for empty positions
   - Validates direction parameters

3. **Character Access** (`charAt` method):
   - Returns character at specific coordinates
   - Returns underscore for uninitialized positions

4. **Board Display** (`show` method):
   - Prints the current board state
   - Uses iterators for efficient traversal

### Main Program Features

The `Main.cpp` provides an interactive demonstration with:
- **Manual input**: Users can type messages directly
- **File input**: Read messages from text files
- **File output**: Save board state to files
- **Dynamic board expansion**: Automatically resizes as needed
- **Interactive menu**: User-friendly command interface

### Technical Implementation Details

- **Memory Management**: Proper destructor implementation with dynamic allocation
- **Boundary Tracking**: Maintains `maxRw` and `maxCn` for efficient board sizing
- **Error Handling**: Throws exceptions for invalid directions
- **Type Safety**: Uses appropriate data types and const correctness
- **Namespace Organization**: Code organized under `ariel` namespace

The solution successfully balances functionality, performance, and memory efficiency while providing a robust foundation for a dynamic message board system.

