In C++, containers from the Standard Template Library (STL) can be divided based on whether they store elements in contiguous memory or in non-contiguous (or linked) memory. This distinction affects performance, particularly in terms of access speed, memory usage, and efficiency of insertions and deletions.

### **1. Containers with Contiguous Memory Access**

Containers with contiguous memory access store elements in a single block of memory. This enables:
- **Fast random access**: Accessing an element by index is fast (constant time, `O(1)`).
- **Better memory locality**: They perform better in terms of cache usage, which can improve performance.

#### **Examples of Contiguous Memory Containers**

1. **`std::vector`**:
   - **Structure**: Dynamic array.
   - **Access**: Fast random access with `O(1)` complexity.
   - **Insertion/Deletion**: Efficient at the end (`push_back` is amortized `O(1)`), but costly (`O(n)`) at the beginning or in the middle since elements need to be shifted.
   - **Use Case**: Ideal for when you frequently need to access elements by index and most additions are at the end.
   
   ```cpp
   std::vector<int> vec = {1, 2, 3, 4};
   vec.push_back(5); // Adds 5 at the end
   int second = vec[1]; // Accessing the second element directly
   ```

2. **`std::array`**:
   - **Structure**: Fixed-size array.
   - **Access**: Fast random access with `O(1)` complexity.
   - **Insertion/Deletion**: Not possible to change size after creation; only contents can be modified.
   - **Use Case**: Useful when you need a fixed-size array with the performance benefits of contiguous memory.

   ```cpp
   std::array<int, 3> arr = {1, 2, 3};
   int first = arr[0]; // Access the first element
   ```

3. **`std::deque`** (partially contiguous):
   - **Structure**: Double-ended queue with segmented memory.
   - **Access**: Provides `O(1)` access to the front and back; random access is slightly slower than `std::vector` due to segmented structure.
   - **Insertion/Deletion**: Efficient insertions and deletions at both ends.
   - **Use Case**: Suitable for scenarios where you need fast access and modifications at both ends.

   ```cpp
   std::deque<int> deq = {1, 2, 3, 4};
   deq.push_front(0); // Adds 0 to the front
   deq.push_back(5);  // Adds 5 to the end
   ```

### **2. Containers with Non-Contiguous Memory Access**

Non-contiguous memory containers store elements as separate nodes or blocks, linked together by pointers. This allows:
- **Efficient insertions and deletions** at arbitrary positions (`O(1)` complexity for linked lists).
- **Stable iterators**: Since memory blocks are allocated individually, the address of elements usually remains constant, unlike with a `vector`, which might reallocate its storage.

#### **Examples of Non-Contiguous Memory Containers**

1. **`std::list`**:
   - **Structure**: Doubly linked list.
   - **Access**: `O(n)` access time since random access is not supported; sequential access only.
   - **Insertion/Deletion**: Fast `O(1)` insertions and deletions anywhere in the list.
   - **Use Case**: Useful when frequent insertions and deletions are required, but direct access by index is not.

   ```cpp
   std::list<int> lst = {1, 2, 3, 4};
   lst.push_front(0); // Adds 0 to the front
   lst.push_back(5);  // Adds 5 to the end
   ```

2. **`std::forward_list`**:
   - **Structure**: Singly linked list.
   - **Access**: Only forward traversal is possible (`O(n)` complexity).
   - **Insertion/Deletion**: Fast `O(1)` insertions and deletions at the front; more lightweight than `std::list`.
   - **Use Case**: Suitable for simple linked lists where memory overhead must be minimized.

   ```cpp
   std::forward_list<int> fwd_lst = {1, 2, 3, 4};
   fwd_lst.push_front(0); // Adds 0 to the front
   ```

3. **`std::set` and `std::map`**:
   - **Structure**: Tree-based associative containers, typically implemented as red-black trees.
   - **Access**: `O(log n)` for searching, insertion, and deletion.
   - **Insertion/Deletion**: Maintains sorted order, so insertions and deletions follow tree rotation rules.
   - **Use Case**: Suitable for when you need ordered collections with unique elements (`set`) or key-value pairs (`map`), with efficient logarithmic access.

   ```cpp
   std::set<int> s = {3, 1, 4};
   s.insert(2); // Inserts 2 in sorted order
   ```

4. **`std::unordered_set` and `std::unordered_map`**:
   - **Structure**: Hash table.
   - **Access**: `O(1)` average complexity for search, insertion, and deletion.
   - **Insertion/Deletion**: Fast on average but requires a good hash function.
   - **Use Case**: Use these for fast access when order isn’t important.

   ```cpp
   std::unordered_map<std::string, int> ages;
   ages["Alice"] = 30; // O(1) insertion
   ```

### **Comparison of Contiguous vs. Non-Contiguous Containers**

| Feature               | Contiguous Containers        | Non-Contiguous Containers        |
|-----------------------|-----------------------------|----------------------------------|
| **Random Access**     | Fast (`O(1)`)               | Slow (`O(n)` or `O(log n)`)     |
| **Memory Locality**   | High (cache-friendly)       | Low (poor cache utilization)     |
| **Insertion/Deletion**| Slow in middle (`O(n)`)     | Fast (`O(1)` at specific points) |
| **Memory Overhead**   | Low                         | Higher due to pointers, tree nodes |
| **Use Case**          | Fast access by index, fewer insertions/deletions | Frequent insertions/deletions, stable pointers |

### **Example Demonstrating Contiguous and Non-Contiguous Containers**

Here’s an example that initializes different types of containers and performs some common operations.

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_map>

int main() {
    // Contiguous container: vector
    std::vector<int> vec = {1, 2, 3, 4};
    vec.push_back(5);
    std::cout << "Vector: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << "\n";

    // Non-contiguous container: list
    std::list<int> lst = {1, 2, 3, 4};
    lst.push_front(0);
    std::cout << "List: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << "\n";

    // Non-contiguous container: set (sorted, unique)
    std::set<int> s = {3, 1, 4, 1, 2}; // Duplicates are ignored
    s.insert(5);
    std::cout << "Set: ";
    for (int val : s) std::cout << val << " ";
    std::cout << "\n";

    // Non-contiguous container: unordered_map (hash map)
    std::unordered_map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    std::cout << "Unordered Map:\n";
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
```

### **Output**
```
Vector: 1 2 3 4 5 
List: 0 1 2 3 4 
Set: 1 2 3 4 5 
Unordered Map:
Alice: 30
Bob: 25
```

### **Summary**

- **Contiguous Containers** like `std::vector` and `std::array` are ideal for when you need efficient memory use and fast random access.
- **Non-Contiguous Containers** like `std::list`, `std::set`, and `std::unordered_map` excel in scenarios where frequent insertions and deletions are required or when the data is large and scattered across memory. 

Choosing the right container depends on the specific performance characteristics and access patterns you need for your application.