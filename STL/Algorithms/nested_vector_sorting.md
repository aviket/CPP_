To create and populate a `std::vector<std::vector<int>>` with random integers, and then sort it based on the first element of each inner vector, you can follow this approach. This example demonstrates how to fill a 2D vector with random integers, then sort it using a custom comparator.

Here's the code:

```cpp
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    // Define dimensions for the 2D vector
    const int outerSize = 5;  // Number of inner vectors
    const int innerSize = 3;  // Number of elements in each inner vector

    // Create a 2D vector (vector of vectors)
    std::vector<std::vector<int>> vec(outerSize, std::vector<int>(innerSize));

    // Set up a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    // Populate the 2D vector with random integers
    for (auto& innerVec : vec) {
        for (auto& elem : innerVec) {
            elem = dist(gen);  // Fill each element with a random integer
        }
    }

    // Display the unsorted vector
    std::cout << "Unsorted vector:\n";
    for (const auto& innerVec : vec) {
        for (int elem : innerVec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // Sort the 2D vector based on the first element of each inner vector
    std::sort(vec.begin(), vec.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    // Display the sorted vector
    std::cout << "\nSorted vector:\n";
    for (const auto& innerVec : vec) {
        for (int elem : innerVec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

### Explanation
1. **Define the dimensions**: `outerSize` represents the number of inner vectors, and `innerSize` is the number of integers in each inner vector.
2. **Initialize the 2D vector**: `std::vector<std::vector<int>> vec(outerSize, std::vector<int>(innerSize));` creates a 2D vector with `outerSize` rows and `innerSize` columns.
3. **Generate random numbers**: The inner loop fills each integer in the 2D vector with a random integer between 1 and 100.
4. **Sort using the first element**: The `std::sort` function uses a lambda function as a comparator to sort the outer vector based on the first element of each inner vector.
5. **Display results**: Print both the unsorted and sorted 2D vectors for verification.

This code will create a 2D vector of random integers and then sort it by the first element of each inner vector.