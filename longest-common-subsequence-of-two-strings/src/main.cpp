#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n= text1.size(),m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j])
                dp[i+1][j+1] = 1 + dp[i][j];
                /// if t1[i]==t2[j] after idx i lcs = 1+(max lcs after idx i-1 )
                else
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                // else option1 -u delete t1[i] and search max lcs till i-1 th idx of t1 & jth idx of t2
                //option2 - delete t2[j] and search max lcs till j-1 th index of t2 & ith idx of t1
            }
        }
        return dp[n][m];
        }

int main(int argc, char** argv){
string s1,s2;cin>>s1>>s2;
cout<<longestCommonSubsequence(s1,s2)<<endl; 
   
}