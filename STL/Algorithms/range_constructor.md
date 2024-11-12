The statement `vector<int> b(a.begin(), a.end());` creates a new vector `b` and initializes it with a copy of the elements in an existing vector `a`.

Here's a step-by-step explanation of how it works:

1. **Range Constructor**: `std::vector` has a range constructor that takes two iterators as arguments. This constructor creates a new vector by copying elements from the specified range `[first, last)` (in this case, `a.begin()` to `a.end()`).

2. **Iterators as Parameters**:
   - `a.begin()` is an iterator pointing to the first element of vector `a`.
   - `a.end()` is an iterator pointing just past the last element of vector `a`.
   - Together, `a.begin()` and `a.end()` represent the entire range of `a`.

3. **Copying Elements**:
   - When `b` is constructed, the range constructor copies each element in `a` to `b` in the same order.
   - This operation is an O(n) operation, where n is the number of elements in `a`.

4. **New Vector `b`**:
   - `b` is now a separate vector with the same values as `a`.
   - Changes made to `b` will not affect `a`, and vice versa, because `b` is an independent copy.

### Example Code

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b(a.begin(), a.end());  // Creates a copy of 'a' in 'b'

    // Display elements of b
    for (int i : b) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Output:
```
1 2 3 4 5
```

### Key Points
- This line of code (`vector<int> b(a.begin(), a.end());`) is a concise and efficient way to duplicate the contents of an existing vector.
- It’s a common idiom for copying a container or part of it.
- You can use this pattern with other STL containers that support iterators (e.g., copying from a `std::set` to a `std::vector`).