In a `std::vector`, `begin` and `end` refer to iterators that point to the start and one-past-the-end of the vector's **currently used elements**, not its total capacity.

Here's how `begin` and `end` behave as elements are added or removed:

1. **Adding Elements**:
   - `begin` always points to the first element (index 0), regardless of the capacity.
   - `end` changes to reflect the new one-past-the-last position of the vector after each addition.
   - The vector may allocate more capacity if the number of elements exceeds the current capacity (e.g., if it reaches 20 and more elements are added), which may invalidate existing iterators.

2. **Removing Elements**:
   - If elements are removed from the back (e.g., with `pop_back`), `end` will adjust to reflect the new one-past-the-last element, but `begin` remains unchanged unless the vector becomes empty.
   - If elements are removed from the front or middle (e.g., with `erase`), `begin` remains the same, but `end` will move if the total number of elements decreases.
   - Removing elements in ways that involve reallocation (e.g., removing many elements to fit a smaller capacity) can also invalidate iterators.

### Example Code
Here’s a code snippet to demonstrate these changes:

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    v.reserve(20); // Reserve capacity of 20

    // Initial begin and end after reserve
    std::cout << "Initial begin: " << &*v.begin() << ", end: " << &*v.end() << '\n';

    // Adding elements
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
        std::cout << "After adding " << i << " -> begin: " << &*v.begin() 
                  << ", end: " << &*v.end() << '\n';
    }

    // Removing elements
    v.pop_back();
    std::cout << "After pop_back -> begin: " << &*v.begin() 
              << ", end: " << &*v.end() << '\n';

    v.erase(v.begin());  // Remove the first element
    std::cout << "After erasing first element -> begin: " << &*v.begin() 
              << ", end: " << &*v.end() << '\n';

    return 0;
}
```

### Explanation of Output
- **After each `push_back`**: `begin` remains the same (pointing to the start), while `end` shifts as the vector grows.
- **After `pop_back`**: `end` moves back one position, as the last element is removed.
- **After `erase`**: `begin` points to the new first element, while `end` updates accordingly.

The addresses printed for `begin` and `end` allow you to track how they change as elements are added or removed.