
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    
    pair<string,int>p;
    p=make_pair("Rohit",30);
    cout << p.first<<p.second<< endl;
    p.first="sam";
    p.second=20;
    cout << p.first<<p.second<< endl;
    
    
    //for more than 2 element storing
     
    //pair<string,int>p2;
    pair<string,pair<int,int>>p2;
     p2=make_pair("Rohit",make_pair(24,30));
     cout <<p2.first<< p2.second.first<<p2.second.second<<endl;
     
     
         //for more than 2 element storing
     
     pair<string,pair<int,int>>p3;
    p3.first="sayan";
    p3.second.first=29;
    p3.second.second=15;
    cout << p3.first<<p3.second.first<<p3.second.second<< endl;
    
    //for 4 element to be in pair
    
    
    pair<pair<string,string>,pair<int,int>>p4;
    
    p4.first.first="pair";
    p4.first.second="four pair";
    p4.second.first=29;
    p4.second.second=15;
    cout << p4.first.first<<p4.first.second<<p4.second.first<<p4.second.second<< endl;
    
    
    
    return 0;
}