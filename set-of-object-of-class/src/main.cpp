#include<bits/stdc++.h>
using namespace std;


class person {
public:

int age;
string name;

bool operator<(const person&other)const{
return age<other.age;
 }
 
};



int main()
{
    cout << "Hello World!" << endl;
    
    
    set<person>s;//set of custom data type of person
    
    person p1,p2,p3;//setting person data type 's  element 
    
    p1.age=18;p1.name="sayan";
    p3.age=28;p3.name="ayan";
    p2.age=38;p2.name="sam";
    
    //seting all information about p1,p2,p3
    
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    
    
    
    for(auto it=s.begin();it!=s.end();it++){
    
    cout << ""<<(*it).age<<" "<<(*it).name << endl;}
    
    for(auto it=s.begin();it!=s.end();it++){
    
    cout << ""<<it->age<<" "<<it->name << endl;}
    
    return 0;
}