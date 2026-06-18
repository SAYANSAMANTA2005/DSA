#include <bits/stdc++.h> 
using namespace std;
int lcs(string &str1, string &str2){
    // Write your code here.
    int n=str1.size(),m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
      for (int j = 0; j < m; j++) {
          if(str1[i]==str2[j])
          dp[i+1][j+1]=1+dp[i][j];
         
          else dp[i+1][j+1]= max(dp[i][j+1],dp[i+1][j]);
      }
    }
     for(int i=0;i<=n;i++){
      for (int j = 0; j <= m; j++) {
          
          maxi =max(maxi,dp[i][j]);
      }
    }
    

    return maxi;

}
int longestPalindromeSubsequence(string s)

{
    string s1=s;
    reverse(s1.begin(),s1.end());
    // Write your code here.
    return lcs(s,s1);
}
int main(){
  
  string s;cin>>s;
  cout<<longestPalindromeSubsequence(s)<<endl;
  
}