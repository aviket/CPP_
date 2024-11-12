Here's a demonstration of the C++ set algorithms—`set_union`, `set_intersection`, `set_difference`, and `set_symmetric_difference`. These algorithms require sorted input ranges and work on sorted sequences to produce various set operations.

### Example Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    // Define two sorted sets
    std::vector<int> setA = {1, 2, 3, 4, 5};
    std::vector<int> setB = {4, 5, 6, 7, 8};

    // Containers to store results of each set operation
    std::vector<int> union_result;
    std::vector<int> intersection_result;
    std::vector<int> difference_result;
    std::vector<int> symmetric_difference_result;

    // Set Union: Combine elements from both sets without duplicates
    std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   std::back_inserter(union_result));
    std::cout << "Union: ";
    for (int num : union_result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Set Intersection: Find elements common to both sets
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                          std::back_inserter(intersection_result));
    std::cout << "Intersection: ";
    for (int num : intersection_result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Set Difference: Find elements in setA but not in setB
    std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                        std::back_inserter(difference_result));
    std::cout << "Difference (A - B): ";
    for (int num : difference_result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Set Symmetric Difference: Find elements that are in either setA or setB, but not in both
    std::set_symmetric_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                                  std::back_inserter(symmetric_difference_result));
    std::cout << "Symmetric Difference: ";
    for (int num : symmetric_difference_result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation of Output
Given `setA = {1, 2, 3, 4, 5}` and `setB = {4, 5, 6, 7, 8}`, here’s what each set operation would output:

1. **Union**: Combines all elements from both sets, removing duplicates.  
   Output: `1 2 3 4 5 6 7 8`

2. **Intersection**: Contains only the elements present in both sets.  
   Output: `4 5`

3. **Difference (A - B)**: Contains elements in `setA` but not in `setB`.  
   Output: `1 2 3`

4. **Symmetric Difference**: Contains elements present in either `setA` or `setB` but not in both.  
   Output: `1 2 3 6 7 8`

### Notes
- **Sorted Inputs**: `setA` and `setB` must be sorted for these algorithms to work correctly.
- **Output Containers**: `std::back_inserter` is used to insert the results dynamically at the end of each result vector.
