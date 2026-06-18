
#include<bits/stdc++.h>

using namespace std ;

bool should_i_swap(pair<int,string>a, pair<int,string> b){

if(a.first>b.first)return true ;//decreasing order

else if(a.second.size()>b.second.size()) return true;//decreasing order

 else return false;

}



int main() {

    vector<pair<int,string>>v={{1,"sayan"},{5,"s"},{9,"super"},{9,"ayan"},{1,"conperitor"},{1,"zero"}};
    
    
    sort(v.begin(),v.end(),should_i_swap);//
    //sorting of vector in cpp using stl
    
    //method for printing vector element method 1
    cout<<"method 1 for printing vector element "<<endl;
   for( auto num: v){
   
   cout << " " << num.first<<" "<<num.second<< endl;}
   
    
    cout<<"method 2 for printing vector element "<<endl;
   for( auto it=v.begin();it!=v.end();it++){
   
   cout << " " << (*it).first<<" "<<(*it).second << endl;}
   
   cout<<"method 3 for printing vector element "<<endl;
   for(int i=0;i<v.size();i++){
   
   cout << " " << v[i].first<<" "<<v[i].second<< endl;}
   
   
   
   
   
   
    return 0;
}