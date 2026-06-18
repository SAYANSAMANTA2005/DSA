#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std ;

int arr[]={1,4,3,1,4,3,5,7,7,7};




int main() {
   int size=sizeof(arr)/sizeof(arr[0]);
   unordered_map<int,int>m;
   
   for(int i=0;i<size;i++){
   m[arr[i]]++;

}



for(auto it=m.begin();it!=m.end();it++){

cout <<"key :"<< it->first<<" is present :"<<it->second<<" times in array"<< endl;}

    return 0;
}