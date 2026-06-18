//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        
        queue<pair<int,int>>q;
        size_t row = mat.size();
        size_t col = mat[0].size();
        vector<vector<int>>vec(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==2)
                q.push({i,j});
            
            }
        }
        //if(q.empty()  && cnt1!=0)
       // return -1;
        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if(x+1<row && mat[x+1][y]==1){
                mat[x+1][y]=2;
                q.push({x+1,y});
                vec[x+1][y]= vec[x][y]+1;
            }
            if(x-1>=0 && mat[x-1][y]==1){
                q.push({x-1,y});
                 mat[x-1][y]=2;
                 vec[x-1][y]= vec[x][y]+1;
            }
            if(y+1<col && mat[x][y+1]==1){
                q.push({x,y+1});
                 mat[x][y+1]=2;
                 vec[x][y+1]= vec[x][y]+1;
            }
             if(y-1>=0 && mat[x][y-1]==1){
                q.push({x,y-1});
                 mat[x][y-1]=2;
                 vec[x][y-1]= vec[x][y]+1;
            }
            
        }
        int maxi=INT_MIN;
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1)
                return -1;
                maxi = max(maxi,vec[i][j]);
            }
        }
        return maxi;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}