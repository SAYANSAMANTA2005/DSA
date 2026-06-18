#include<bits/stdc++.h>
using namespace std;



int main()
{
    cout << "Hello World!" << endl;
    
    
    multiset<int>ms;
    
    ms.insert(50);
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
           
           
           
    for(auto it=ms.begin();it!=ms.end();it++){
    
    cout << ""<<(*it)<< endl;}
    ms.erase(10);
    cout << "Hello World!" << endl;
    
        for(auto it=ms.begin();it!=ms.end();it++){
    
    cout << ""<<(*it)<< endl;}
    
    
    return 0;
}