#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;cin>>t;
while(t--){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];//taking input
    }
    int 1_substring_no,0_substring_no;
    //calculate no of dubstring of 1 & 0   {}
    //next part
    1_substring_no--;
    if((arr[n-1]||arr[0])!=1)
    0_substring_no--;
    //Bob's fliping of element in array  
    
    //condition for winning 
    int poss_ans = 0_substring_no- 1_substring_no;
    int ans;
    if(poss_ans<=0){
        ans =0;
        
    }
    //printing output 
    std::cout << ans << std::endl;
}
}
