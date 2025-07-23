/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Question: Graphs - Breadth First Search (BFS)
*/


#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// BFS function
void bfs(map<char, vector<char>>& graph, char start) {
    set<char> visited;             // To keep track of visited nodes
    queue<char> q;                 // Queue for BFS

    q.push(start);                 // Start from the given node

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        if (visited.find(current) == visited.end()) {
            cout << current << " ";        // Visit the node
            visited.insert(current);       // Mark as visited

            // Enqueue all unvisited neighbors
            for (char neighbor : graph[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                }
            }
        }
    }
}

int main() {
    // Step 1: Define the graph (Adjacency List)
    map<char, vector<char>> graph;

    graph['A'] = { 'B', 'C', 'D' };
    graph['B'] = { 'A', 'D', 'E' };
    graph['C'] = { 'A', 'D' };
    graph['D'] = { 'A', 'B', 'C', 'E' };
    graph['E'] = { 'B', 'D' };

    // Test 1: Run BFS from vertex A
    cout << "BFS traversal starting from A: ";
    bfs(graph, 'A');

    //Test 2:Run BFS from from vertex D
    cout << "\nBFS traversal starting from D: ";
    bfs(graph, 'D');

    return 0;
}