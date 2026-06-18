#include <iostream>
#include <vector> // Include this header for vector
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges
    
    // Adjacency list to store graph
    vector<vector<int>> adj(n + 1); // Use a 2D vector
    
    for (int i = 0; i < m; i++) { // time complexity O(m)
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return 0;
}