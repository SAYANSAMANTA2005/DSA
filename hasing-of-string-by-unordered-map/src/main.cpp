#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std ;

string arr="hello my name is sayan samanta";




int main() {
   //int size=sizeof(arr)/sizeof(arr[0]);
   unordered_map<char,int>m;
   
   for(int i=0;i<arr.size();i++){
   if(arr[i]!=' '){
   m[(int)(arr[i]-'a')]++;}

}


for(auto it=m.begin();it!=m.end();it++){


cout <<"key :"<< (char)(it->first+'a')<<" is present :"<<it->second<<" times in array"<< endl;}

    return 0;
}