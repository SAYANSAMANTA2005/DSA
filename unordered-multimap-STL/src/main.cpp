#include<bits/stdc++.h>
using namespace std;



int main()
{
    cout << "Hello World!" << endl;
    
    
   //unordered map doesn't allow dulpicate key -value pair
   //ordering of keys are not available in
   //unordered map -insert,search,delete=O(1);
   //implement by hashing
   unordered_multimap<int,int>ms;//first-key
   //second-value
   //key must be unique in map
   //in multimap key may not be unique 
   //value may be duplicat
   
   ms.insert(make_pair(20,10));
   ms.insert(make_pair(20,60));
   ms.insert(make_pair(20,80));
   ms.insert(make_pair(20,50));
   
   ms.insert(make_pair(30,30));
   
   ms.insert(make_pair(40,20));
   ms.insert(make_pair(50,40));
 // ms[100]=60;//
   
    cout << ms.count(10) << endl;//
    //give no of key(10) present in map
   ms.insert(make_pair(20,100));
   
    for(auto it=ms.begin();it!=ms.end();it++){
    
    cout << ""<<it->first<<" "<<it->second<< endl;}
     ms.erase(20);//deletion of  key(10) value pair
    cout << "Hello World!" << endl;
    
        for(auto it=ms.begin();it!=ms.end();it++){
    
    cout << ""<<(*it).first<<" "<<(*it).second<< endl;}
    return 0;
}