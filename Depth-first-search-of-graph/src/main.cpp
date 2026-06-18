#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Visit all the adjacent nodes
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // Create an adjacency list for the graph
    vector<vector<int>> adjList(vertices);

    // Read the edges of the graph
    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Create a visited array to track visited nodes
    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited);
        }
    }

    return 0;
}