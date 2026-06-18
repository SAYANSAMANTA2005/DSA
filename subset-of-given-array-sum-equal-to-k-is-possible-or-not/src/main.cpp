#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));
    for (int i = 0; i < n; i++) {
        dp[i][0]=true;
    }
    for (int i = 0; i < n; i++) {
        for(int j=1;j<=k;j++){
                if( (j - arr[i]) >=0) 
            dp[i+1][j] = dp[i][j]||dp[i][j - arr[i]];
            //constructing till idx i which values of targetsum is possible to achive
           //the logic of prev line of code-
           // if till using all elements till indx i....it is not possible to make a 
           // current target sum ....then the only option for that target sum to be possible 
           //*****before i+1 th indx is till ith index targetsum - arr[i] is possible 
       
            else
            dp[i+1][j]=dp[i][j];
        }
    }
    return dp[n][k];
}