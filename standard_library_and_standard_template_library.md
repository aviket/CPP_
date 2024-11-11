The **C++ Standard Library** and **C++ STL (Standard Template Library)** are both foundational components of modern C++ programming, but they refer to slightly different things.

### 1. **C++ Standard Library**
The C++ Standard Library is a collection of classes and functions defined by the ISO C++ standard, which is included with every compliant C++ compiler. It includes a wide range of tools to help developers with various tasks such as input/output, file handling, string manipulation, and more. 

The C++ Standard Library is broadly categorized into:
   - **Containers**: Classes like `std::vector`, `std::list`, and `std::map` that store collections of objects.
   - **Algorithms**: Functions like `std::sort`, `std::find`, and `std::accumulate` that operate on containers and other data.
   - **Iterators**: Objects that allow traversal of containers in a consistent manner.
   - **Input/Output (I/O)**: Streams like `std::cin`, `std::cout`, and file handling classes in `<fstream>`.
   - **Multithreading**: Tools for concurrency, such as `std::thread`, `std::mutex`, and `std::async`.
   - **Regular Expressions**: The `<regex>` library provides tools for pattern matching within text.
   - **Smart Pointers**: Classes like `std::unique_ptr` and `std::shared_ptr` for automatic memory management.
   - **Math and Numerics**: Libraries like `<cmath>`, `<random>`, and `<chrono>` for math functions, random numbers, and time operations.

### 2. **C++ STL (Standard Template Library)**
The **Standard Template Library (STL)** is a specific part of the C++ Standard Library. Originally developed as a separate library by Alexander Stepanov and others, it was later incorporated into the C++ Standard Library.

The STL is composed mainly of:
   - **Containers**: Classes such as `std::vector`, `std::list`, `std::deque`, and `std::map` that manage collections of data.
   - **Algorithms**: Generic functions for tasks such as sorting, searching, and modifying containers. Examples include `std::sort`, `std::binary_search`, and `std::transform`.
   - **Iterators**: Objects used to navigate through elements of containers. Iterators support a common interface for accessing elements in a container, allowing algorithms to work across different container types.

### Key Differences
- **Scope**: The C++ Standard Library encompasses more than just the STL. It includes features like I/O streams, multithreading, smart pointers, and more, which are outside the original scope of the STL.
- **STL as Part of the Standard Library**: The STL forms the backbone of the containers and algorithms in the C++ Standard Library but does not cover all of it. STL mainly refers to templates, while the C++ Standard Library includes more general utilities and functions.

### Examples

Here's an example of using both C++ Standard Library and STL features:

```cpp
#include <iostream>    // C++ Standard Library (for I/O)
#include <vector>      // C++ STL (container)
#include <algorithm>   // C++ STL (algorithm)
#include <numeric>     // C++ Standard Library (additional algorithms)

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using an STL algorithm (std::sort) to sort the numbers in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // Using C++ Standard Library's <numeric> library for std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // Outputting using C++ Standard Library I/O
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nSum: " << sum << std::endl;

    return 0;
}
```

In this code:
- `std::vector` and `std::sort` are part of the STL.
- `std::accumulate` and `std::cout` are parts of the broader C++ Standard Library.