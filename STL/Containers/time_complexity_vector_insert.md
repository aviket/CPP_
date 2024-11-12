`std::vector` in C++ is a dynamic array that handles elements in contiguous memory. Here's a code snippet that will demonstrate the time complexity of insertion at different positions in a `std::vector<int>` with values from `1` to `10`.

For each operation:
1. Inserting at the front is \(O(n)\) because all elements have to shift one position to the right.
2. Inserting between the start and end is also \(O(n)\) as elements after the insertion point need to be shifted.
3. Inserting at the end is \(O(1)\) on average, though resizing when capacity is exceeded can make it \(O(n)\) occasionally.

Here's the code to measure time complexity:

```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // Initialize vector with 10,000 elements
    std::vector<int> vec(100000, 0);

    // Measure time for inserting at the front
    auto start = std::chrono::high_resolution_clock::now();
    vec.insert(vec.begin(), 0);  // Insert at the front
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Inserting at the front took: " << duration.count() << " seconds\n";

    // Reset vector with 10,000 elements for the next test
    vec = std::vector<int>(100000, 0);

    // Measure time for inserting in the middle
    start = std::chrono::high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size() / 2, 50);  // Insert in the middle
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Inserting in the middle took: " << duration.count() << " seconds\n";

    // Reset vector with 10,000 elements for the next test
    vec = std::vector<int>(100000, 0);

    // Measure time for inserting at the end
    start = std::chrono::high_resolution_clock::now();
    vec.push_back(20);  // Insert at the end
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Inserting at the end took: " << duration.count() << " seconds\n";

    return 0;
}

```

### Explanation

1. **Inserting at the Front (`vec.insert(vec.begin(), 0);`)**:
   - This operation shifts all existing elements one position to the right.
   - The time complexity is \(O(n)\).

2. **Inserting in the Middle (`vec.insert(vec.begin() + vec.size() / 2, 50);`)**:
   - This requires shifting half of the elements to the right.
   - The time complexity is \(O(n)\).

3. **Inserting at the End (`vec.push_back(20);`)**:
   - On average, this has a constant time complexity \(O(1)\) since `push_back` simply adds the element to the end.
   - If resizing occurs (when the capacity is exceeded), it can take \(O(n)\) time.

