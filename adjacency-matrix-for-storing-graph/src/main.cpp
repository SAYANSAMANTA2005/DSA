#include <iostream>
using namespace std;

int main() {
    int n,m;cin>>n>>m;// n= nodes num, m = edge num
    
    // adjacency matrix to store graph
    int adj[n+1][m+1];//space O(n*m)
    for(int i=0;i<m;i++){// time complexity O(n)
    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    adj[u][v]=1;
    }
    
    return 0;
}