### Conditionally remove elements from a vector
To efficiently remove all elements from a `std::vector<std::string>` that don’t contain a specific substring (in this case, a colon `":"`), you can use the `std::erase` and `std::remove_if` combination with a lambda function to filter elements.

Here's a sample code snippet:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> vec = {"apple:fruit", "banana", "carrot:vegetable", "date", "eggplant:vegetable"};

    // Use erase-remove idiom with a lambda to filter out elements that do not contain ":"
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                             [](const std::string& str) { return str.find(':') == std::string::npos; }),
              vec.end());

    // Print the modified vector
    for (const auto& str : vec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation

- `std::remove_if` moves all elements that **do not** contain `":"` to the end of the vector, returning an iterator to the new logical end of the vector.
- `vec.erase()` then removes the unwanted elements from the vector.

### Efficiency Consideration

This method is efficient because it minimizes reallocations by using `std::remove_if` and then resizing the vector only once with `erase`. This combination has a linear time complexity, making it optimal for filtering elements in place.