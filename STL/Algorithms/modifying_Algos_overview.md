Modifying algorithms in the C++ Standard Template Library (STL) are used to change the contents of containers. They offer a variety of operations such as copying, replacing, removing elements, filling values, and shuffling. Here’s a rundown of the main modifying algorithms and examples for each:

### 1. `std::copy`
Copies elements from one range to another.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest(5);

    std::copy(src.begin(), src.end(), dest.begin());
    for (int i : dest) std::cout << i << " "; // Output: 1 2 3 4 5
    return 0;
}
```

### 2. `std::copy_if`
Copies elements that satisfy a specific condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest;

    std::copy_if(src.begin(), src.end(), std::back_inserter(dest), [](int x) { return x % 2 == 0; });
    for (int i : dest) std::cout << i << " "; // Output: 2 4
    return 0;
}
```

### 3. `std::copy_n`
Copies a fixed number of elements.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest(3);

    std::copy_n(src.begin(), 3, dest.begin());
    for (int i : dest) std::cout << i << " "; // Output: 1 2 3
    return 0;
}
```

### 4. `std::fill`
Fills the range with a specified value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec(5);
    std::fill(vec.begin(), vec.end(), 10);
    for (int i : vec) std::cout << i << " "; // Output: 10 10 10 10 10
    return 0;
}
```

### 5. `std::fill_n`
Fills the first `n` elements of a range with a specified value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec(5);
    std::fill_n(vec.begin(), 3, 7);
    for (int i : vec) std::cout << i << " "; // Output: 7 7 7 0 0
    return 0;
}
```

### 6. `std::replace`
Replaces all instances of a specified value with another value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4};
    std::replace(vec.begin(), vec.end(), 2, 10);
    for (int i : vec) std::cout << i << " "; // Output: 1 10 3 10 4
    return 0;
}
```

### 7. `std::replace_if`
Replaces values that satisfy a specified condition with another value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::replace_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }, 0);
    for (int i : vec) std::cout << i << " "; // Output: 1 0 3 0 5
    return 0;
}
```

### 8. `std::remove`
Removes elements equal to a specified value (shifts elements and returns a new logical end).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4};
    vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());
    for (int i : vec) std::cout << i << " "; // Output: 1 3 4
    return 0;
}
```

### 9. `std::remove_if`
Removes elements based on a condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());
    for (int i : vec) std::cout << i << " "; // Output: 1 3 5
    return 0;
}
```

### 10. `std::transform`
Applies a function to each element and stores the result.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> src = {1, 2, 3};
    std::vector<int> dest(src.size());

    std::transform(src.begin(), src.end(), dest.begin(), [](int x) { return x * 2; });
    for (int i : dest) std::cout << i << " "; // Output: 2 4 6
    return 0;
}
```

### 11. `std::swap_ranges`
Swaps elements between two ranges.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};

    std::swap_ranges(a.begin(), a.end(), b.begin());
    for (int i : a) std::cout << i << " "; // Output: 4 5 6
    std::cout << "\n";
    for (int i : b) std::cout << i << " "; // Output: 1 2 3
    return 0;
}
```

### 12. `std::reverse`
Reverses the order of elements in a range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::reverse(vec.begin(), vec.end());
    for (int i : vec) std::cout << i << " "; // Output: 5 4 3 2 1
    return 0;
}
```

### 13. `std::rotate`
Rotates elements, moving the start of the range to a new position.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::rotate(vec.begin(), vec.begin() + 2, vec.end());
    for (int i : vec) std::cout << i << " "; // Output: 3 4 5 1 2
    return 0;
}
```

### 14. `std::shuffle`
Randomly shuffles elements in a range (C++11 and later).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    for (int i : vec) std::cout << i << " ";
    return 0;
}
```

### 15. `std::unique`
Removes consecutive duplicate elements (requires sorting first for general duplicates).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    for (int i : vec) std::cout << i << " "; // Output: 1 2 3 4 5
    return 0;
}
```

### Summary of Usage

These algorithms provide tools for:
- **Copying** elements with `copy`, `copy_if`, and `copy_n`.
- **Filling** values with `fill` and `fill_n`.
- **Replacing** elements using `replace` and `replace_if`.
- **Removing** elements via `remove`, `remove_if`, and `unique`.
- **Transforming** and **modifying** elements with `transform`, `reverse`, `rotate`, `shuffle`, and `swap_ranges`.

Each algorithm is optimized for use with standard containers, making them efficient for a wide range of data manipulation tasks in C++.