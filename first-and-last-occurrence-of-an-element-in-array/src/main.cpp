#include <iostream>

using namespace std;
#include <bits/stdc++.h> 
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
   int low =0,high= n-1;
   while(high>=low){
       int mid =(low +high)/2;
       if(arr[mid]>=k)
       high= mid-1;
       if(arr[mid]<k)
       low = mid+1;
   }
   int a= low;
   low =0,high=n-1;
   // last idx
      while(high>=low){
       int mid =(low +high)/2;
       if(arr[mid]<=k)
       low= mid+1;
       if(arr[mid]>k)
       high = mid-1;
   }
   int b=high;
   if(arr[a]!=k || arr[b]!=k)
   return {-1,-1};
   return {a,b};

}

int main(int argc, char** argv){
    cout << "Hello world" << endl;
}