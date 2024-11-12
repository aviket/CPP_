### count_if
To count all negative elements in a `std::vector<int>`, you can use the `std::count_if` algorithm with a lambda function that checks if each element is negative.

Here’s an example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, -2, 3, -4, 5, -6, 7, -8};

    // Use count_if with a lambda to count negative elements
    int negative_count = std::count_if(vec.begin(), vec.end(),
                                       [](int x) { return x < 0; });

    std::cout << "Number of negative elements: " << negative_count << std::endl;

    return 0;
}
```

### Explanation

- `std::count_if` iterates through each element in the vector and applies the lambda `[](int x) { return x < 0; }`, which checks if each element is negative.
- `negative_count` will store the number of elements that satisfy the condition.

This approach is both simple and efficient, with a linear time complexity, \( O(n) \), where \( n \) is the size of the vector.