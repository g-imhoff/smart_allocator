# Smart Allocator

Smart Allocator is a project designed to deepen the understanding of dynamic memory allocation concepts. This project demonstrates efficient memory management techniques by automatically freeing memory, handling heap fragmentation, and merging adjacent free memory blocks.

## Features

- **Automatic Memory Management**: Automatically frees memory when the pointer goes out of scope.
- **Heap Fragmentation Handling**: Efficiently allocates memory in the free segments of the heap.
- **Memory Merging**: Automatically merges contiguous free memory blocks to optimize memory usage.

## Getting Started

### Prerequisites

Ensure you have the following installed:
- [Git](https://git-scm.com/)
- [Make](https://www.gnu.org/software/make/)
- A C++ compiler (e.g., g++)

### Installation

Clone the repository:
```bash
git clone git@github.com:g-imhoff/smart_allocator.git
```

Navigate to the project directory:

```bash
cd smart_allocator
```

### Running Tests
To compile and run the tests:

```bash
make run 
```
You can modify the test cases by editing test_unit.cpp.

## Usage
To use the Smart Allocator, include the header and create an instance of smart_allocator:

```cpp
#include "smart_allocator.h"

// Allocate memory for a specific type
smart_allocator<type> ptr(size);
```
