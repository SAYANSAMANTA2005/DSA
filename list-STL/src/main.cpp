
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    
    list<int>l;
    l.push_back(30);
    l.push_back(50);
        l.push_back(70);
    l.push_back(90);
    l.push_front(20);
    cout << "list is:" << endl;
    for(auto it=l.begin();it!=l.end();it++){//iterator for printing all values of list
    //it.end() points the next element of last element
    //it begin() points t first element of list
    cout << "" <<*it<< endl;
    }
    cout << "list end here:" << endl;
    cout << "" <<l.back()<< endl;
     
    cout << "" <<l.front()<< endl;
    cout << "" <<l.size()<< endl;
    
    l.pop_back();
    cout << "" <<l.size()<< endl;
    l.pop_front();
   cout << "" <<l.size()<< endl;
    
    cout << "" <<l.front()<< endl;
    
    l.pop_front();
    
    cout << "" <<l.empty()<< endl;
    
    
    return 0;
}