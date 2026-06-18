#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m; // n = number of nodes, m = number of edges

    vector<int> visited_arr(n + 1, 0);
    // adjacency list to store the graph
    vector<vector<int>> adj(n + 1); // Initialize with size n+1 to hold nodes 1 to n

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph
    }

    queue<int> q;
    vector<int> bfs;
    int starting_node;
    cin >> starting_node;

    // Start BFS
    q.push(starting_node);
    visited_arr[starting_node] = 1; // Mark the starting node as visited

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (int next : adj[node]) {
            if (visited_arr[next] == 0) {
                // Unvisited neighbor
                q.push(next);
                visited_arr[next] = 1; // Mark as visited
            }
        }
    }

    // Output BFS result
    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}