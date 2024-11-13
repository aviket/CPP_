#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

std::unordered_map<char, std::vector<char>> graph = {
    {'A', {'B', 'C'}},
    {'B', {'A', 'D', 'E'}},
    {'C', {'A', 'F'}},
    {'D', {'B'}},
    {'E', {'B', 'F'}},
    {'F', {'C', 'E'}}
};

void iterativeBFS(char startNode) {
    std::set<char> visited;      // Set to keep track of visited nodes
    std::queue<char> queue;      // Queue for BFS

    queue.push(startNode);       // Enqueue the starting node
    visited.insert(startNode);    // Mark as visited

    while (!queue.empty()) {
        char node = queue.front();  // Get the front node of the queue
        queue.pop();                // Remove it from the queue

        std::cout << node << " ";   // Process the node (e.g., print it)

        // Enqueue all unvisited neighbors
        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push(neighbor);
                visited.insert(neighbor); // Mark neighbor as visited
            }
        }
    }
}

int main() {
    std::cout << "Iterative BFS starting from A: ";
    iterativeBFS('A');
    std::cout << std::endl;
    return 0;
}
