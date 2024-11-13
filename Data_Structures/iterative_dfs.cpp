#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>

std::unordered_map<char, std::vector<char>> graph = {
    {'A', {'B', 'C'}},
    {'B', {'A', 'D', 'E'}},
    {'C', {'A', 'F'}},
    {'D', {'B'}},
    {'E', {'B', 'F'}},
    {'F', {'C', 'E'}}
};


void iterativeDFS(char startNode) {
    std::set<char> visited;      // Set to keep track of visited nodes
    std::stack<char> stack;      // Stack for DFS

    stack.push(startNode);       // Push the starting node onto the stack

    while (!stack.empty()) {
        char node = stack.top(); // Get the node on top of the stack
        stack.pop();             // Remove it from the stack

        if (visited.find(node) == visited.end()) {
            visited.insert(node); // Mark the node as visited
            std::cout << node << " "; // Process the node (e.g., print it)

            // Add all unvisited neighbors to the stack
            // Reverse order to maintain the correct DFS order
            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    stack.push(*it);
                }
            }
        }
    }
}

int main() {
    std::cout << "Iterative DFS starting from A: ";
    iterativeDFS('A');
    std::cout << std::endl;
    return 0;
}
