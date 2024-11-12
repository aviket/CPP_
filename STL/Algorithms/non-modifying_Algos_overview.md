Non-modifying algorithms in the C++ Standard Template Library (STL) are used to examine or query elements in a container without altering the container’s contents. These algorithms include searching, counting, finding, and checking conditions. Here’s a list of commonly used non-modifying algorithms, along with explanations and code examples:

---

### 1. `std::for_each`
Applies a function to each element in the range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << " "; });
    // Output: 1 2 3 4 5
    return 0;
}
```

---

### 2. `std::find`
Finds the first occurrence of a specified value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = std::find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) std::cout << "Found: " << *it;  // Output: Found: 3
    return 0;
}
```

---

### 3. `std::find_if`
Finds the first element that satisfies a specified condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x > 3; });
    if (it != vec.end()) std::cout << "First element > 3: " << *it;  // Output: First element > 3: 4
    return 0;
}
```

---

### 4. `std::find_if_not`
Finds the first element that does **not** satisfy a specified condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = std::find_if_not(vec.begin(), vec.end(), [](int x) { return x < 4; });
    if (it != vec.end()) std::cout << "First element >= 4: " << *it;  // Output: First element >= 4: 4
    return 0;
}
```

---

### 5. `std::all_of`
Checks if all elements satisfy a specified condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    bool result = std::all_of(vec.begin(), vec.end(), [](int x) { return x > 0; });
    std::cout << std::boolalpha << "All positive: " << result;  // Output: All positive: true
    return 0;
}
```

---

### 6. `std::any_of`
Checks if **any** element satisfies a specified condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {-1, 2, -3, 4, 5};
    bool result = std::any_of(vec.begin(), vec.end(), [](int x) { return x > 0; });
    std::cout << std::boolalpha << "Any positive: " << result;  // Output: Any positive: true
    return 0;
}
```

---

### 7. `std::none_of`
Checks if **no** elements satisfy a specified condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {-1, -2, -3, -4, -5};
    bool result = std::none_of(vec.begin(), vec.end(), [](int x) { return x > 0; });
    std::cout << std::boolalpha << "No positives: " << result;  // Output: No positives: true
    return 0;
}
```

---

### 8. `std::count`
Counts the occurrences of a specified value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 2};
    int count = std::count(vec.begin(), vec.end(), 2);
    std::cout << "Count of 2: " << count;  // Output: Count of 2: 3
    return 0;
}
```

---

### 9. `std::count_if`
Counts the elements that satisfy a specified condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int count = std::count_if(vec.begin(), vec.end(), [](int x) { return x > 3; });
    std::cout << "Count > 3: " << count;  // Output: Count > 3: 2
    return 0;
}
```

---

### 10. `std::mismatch`
Finds the first position where two ranges differ.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 0, 4};
    auto result = std::mismatch(vec1.begin(), vec1.end(), vec2.begin());
    if (result.first != vec1.end()) {
        std::cout << "Mismatch at index " << (result.first - vec1.begin()) << "\n";
        // Output: Mismatch at index 2
    }
    return 0;
}
```

---

### 11. `std::equal`
Checks if two ranges are equal.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 3, 4};
    bool result = std::equal(vec1.begin(), vec1.end(), vec2.begin());
    std::cout << std::boolalpha << "Vectors equal: " << result;  // Output: Vectors equal: true
    return 0;
}
```

---

### 12. `std::search`
Searches for a subsequence within a range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> subseq = {3, 4};

    auto it = std::search(vec.begin(), vec.end(), subseq.begin(), subseq.end());
    if (it != vec.end()) std::cout << "Subsequence found at index: " << (it - vec.begin());
    // Output: Subsequence found at index: 2
    return 0;
}
```

---

### 13. `std::find_end`
Finds the last occurrence of a subsequence in a range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 3, 4, 5};
    std::vector<int> subseq = {3, 4};

    auto it = std::find_end(vec.begin(), vec.end(), subseq.begin(), subseq.end());
    if (it != vec.end()) std::cout << "Last subsequence starts at index: " << (it - vec.begin());
    // Output: Last subsequence starts at index: 4
    return 0;
}
```

---

### 14. `std::adjacent_find`
Finds the first pair of adjacent equal elements.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 5};
    auto it = std::adjacent_find(vec.begin(), vec.end());
    if (it != vec.end()) std::cout << "First adjacent pair: " << *it;
    // Output: First adjacent pair: 2
    return 0;
}
```

---

### 15. `std::lexicographical_compare`
Compares two ranges lexicographically.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {1, 2, 4};
    bool result = std::lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    std::cout << std::boolalpha << "vec1 < vec2: " << result;  // Output: vec1 < vec2: true
    return 0;
}
```

---

### Summary

Non-modifying algorithms allow querying without changing container contents, which is useful in situations where the integrity of the data must remain unchanged during operations. The examples above demonstrate each algorithm’s functionality.