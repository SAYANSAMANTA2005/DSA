#include<bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &arr)
{
    // Write your code here.
      int n=arr.size();
        sort(arr.begin(),arr.end());
        //asending order 
        vector<int>lds(n,1),ans,hash(n);
        for(int i=0;i<n;i++){
          hash[i]=i;
            for(int j=0;j<i;j++){
              if (arr[i] % arr[j] == 0 && lds[j]+1>lds[i]) {
                lds[i] =lds[j] + 1;
              
                  hash[i] = j;
              }
            }
        }
        int maxi =INT_MIN;
        int idx;
        for(int i=0;i<n;i++){
            maxi = max(maxi,lds[i]);
            if(maxi==lds[i])
            idx=i;
        }
        ans.push_back(arr[idx]);
      while(hash[idx]!=idx){
          idx = hash[idx];
          ans.push_back(arr[idx]);
      }
       
        sort(ans.begin(),ans.end());
        //for (int i = 0; i < arr.size(); i++) {
         //   cout<<arr[i]<<" ";
       // }
       // cout<<endl;

        return ans;
        
}