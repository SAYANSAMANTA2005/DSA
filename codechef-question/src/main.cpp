#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;cin>>t;
while (t--){
    int n;cin>>n;
    vector<int>arr(n);
    vector<int>rev_sm_arr(n);
    vector<int>poss_sol_find_arr(n);
    for (int i=0;i<n;i++){
        cin >>arr[i];//taking input
    }
    int sum=arr[n-1];
    poss_sol_find_arr[n-1] =arr[n-1];
    for(int i=n-2;i>=0;i--){
       poss_sol_find_arr[i]= max(2*arr[i],arr[i]+poss_sol_find_arr[i+1]);
        sum +=arr[i];
    }
    if(poss_sol_find_arr[0]==sum)
    cout<<poss_sol_find_arr[0]+arr[n-1]<<endl;
    else
    std::cout << poss_sol_find_arr[0] << std::endl;
}
}
