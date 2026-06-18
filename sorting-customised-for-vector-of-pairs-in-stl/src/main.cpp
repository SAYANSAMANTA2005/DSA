
#include<bits/stdc++.h>

using namespace std ;

bool should_i_swap(pair<int,int>a, pair<int,int> b){

if(a.first>b.first)return true ;//decreasing order

else if(a.second>b.second) return true;//decreasing order

 else return false;

}



int main() {

    vector<pair<int,int>>v={{1,4},{5,7},{9,10},{9,-10},{1,-6},{1,0}};
    
    
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