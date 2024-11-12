To create a C++ `vector` containing 20 random integers, you can follow these steps. This approach uses the C++ Standard Library's `<vector>`, `<algorithm>`, and `<random>` to generate and fill the vector with random values.

Here's a code example:

```cpp
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    // Step 1: Create an empty vector of integers
    std::vector<int> randomNumbers(20);

    // Step 2: Set up a random number generator
    std::random_device rd;                             // Obtain a random seed
    std::mt19937 gen(rd());                            // Use the Mersenne Twister engine
    std::uniform_int_distribution<int> dist(1, 100);   // Define a range [1, 100]

    // Step 3: Fill the vector with random integers
    std::generate(randomNumbers.begin(), randomNumbers.end(), [&]() { return dist(gen); });

    // Step 4: Print the random numbers (optional)
    for (int num : randomNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation
1. **Initialize the vector**: `std::vector<int> randomNumbers(20);` reserves space for 20 integers.
2. **Set up random number generator**: The `std::random_device` provides a seed for the random number generator. We use the `std::mt19937` engine and a uniform distribution between 1 and 100.
3. **Generate random numbers**: The `std::generate` algorithm fills the vector with values produced by `dist(gen)`.
4. **Display the vector**: Optional loop to print out the random numbers for verification. 

This code will create a vector filled with 20 random integers between 1 and 100.