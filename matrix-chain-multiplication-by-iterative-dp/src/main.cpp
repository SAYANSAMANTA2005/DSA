#include <bits/stdc++.h> 
using namespace std;

int matrixMultiplication(int arr, int N)
{
    int n =N;
   
    int dp[N][N];
    for (int i = 0; i < n; i++) {
        dp[i][i]=0;
    }
    for (int length = 2; length < n; length++) {
      for (int i=1; i+length <= n; i++) {
          int j= i+length-1;
          dp[i][j]=INT_MAX;
      for(int k=i;k<j;k++){
          int addcost= arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
          dp[i][j] =min(dp[i][j],addcost);
      }
      }
    }
    return dp[1][N-1];
}
