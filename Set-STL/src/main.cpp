
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    
    set<int,greater<int>>s;
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    
    for(auto it=s.begin();it!=s.end();it++){
    
    
    cout << ""<<*it << endl;}
        cout << "Hello World!" << endl;
    
    set<int>s2;
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);
    s2.insert(50);
    s2.insert(50);
    for(auto it=s2.begin();it!=s2.end();it++){
    
    
    cout << ""<<*it << endl;}
    
    
    cout << "Hello World!" << endl;
  
    s2.erase(50);
    for(auto it=s2.begin();it!=s2.end();it++){
    
    
    cout << ""<<*it << endl;}
    
    
    
    return 0;
}