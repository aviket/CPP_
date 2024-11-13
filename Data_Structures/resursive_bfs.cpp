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


void recursiveBFS(std::queue<char>& queue, std::set<char>& visited) {
    if (queue.empty()) return;

    char node = queue.front();   // Get the front node of the queue
    queue.pop();                 // Remove it from the queue
    std::cout << node << " ";    // Process the node (e.g., print it)

    // Enqueue all unvisited neighbors
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            queue.push(neighbor);
            visited.insert(neighbor); // Mark neighbor as visited
        }
    }

    // Recur with the updated queue
    recursiveBFS(queue, visited);
}

void startRecursiveBFS(char startNode) {
    std::queue<char> queue;
    std::set<char> visited;

    queue.push(startNode);       // Enqueue the starting node
    visited.insert(startNode);    // Mark as visited

    recursiveBFS(queue, visited);
}

int main() {
    std::cout << "Recursive BFS starting from A: ";
    startRecursiveBFS('A');
    std::cout << std::endl;
    return 0;
}


