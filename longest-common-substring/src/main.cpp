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
         
          else dp[i+1][j+1]=0;
      }
    }
     for(int i=0;i<=n;i++){
      for (int j = 0; j <= m; j++) {
          
          maxi =max(maxi,dp[i][j]);
      }
    }
    

    return maxi;

}

int main(int argc, char** argv){
string s1,s2;cin>>s1>>s2;
    cout << lcs(s1,s2) << endl;
}