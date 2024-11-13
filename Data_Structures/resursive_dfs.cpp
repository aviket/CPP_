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



void recursiveDFS(char node, std::set<char>& visited) {
    visited.insert(node);  // Mark the node as visited
    std::cout << node << " ";  // Process the node (e.g., print it)

    // Recur for all unvisited neighbors
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            recursiveDFS(neighbor, visited);
        }
    }
}

void startRecursiveDFS(char startNode) {
    std::set<char> visited;
    recursiveDFS(startNode, visited);
}

int main() {
    std::cout << "Recursive DFS starting from A: ";
    startRecursiveDFS('A');
    std::cout << std::endl;
    return 0;
}


