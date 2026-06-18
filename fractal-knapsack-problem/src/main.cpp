
#include<bits/stdc++.h>

using namespace std ;

bool should_i_swap(pair<int,int>a, pair<int,int> b){
double v1=a.first/a.second ;
double v2=b.first/b.second ;

if(v1>v2)return true ;//decreasing order accordingly to ratio




 else return false;

}



int main() {

    vector<pair<int,int>>v={{21,7},{24,4},{12,6},{40,5},{30,6}};
    
    
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
   
   cout << "value: " << v[i].first<<"; weight: "<<v[i].second<<"; value/weight:"<<v[i].first/v[i].second<< endl;}
   
   int maxweight=20;
   if(maxweight>=v[0].second){
   int profit=v[0].first;
   int weight =v[0].second;
   for(int i=1;i<v.size();i++){
   
   if(weight+v[i].second<=maxweight){
   
   profit+=v[i].first;
   weight +=v[i].second;
   cout << " "<<profit<<" "<< weight<< endl;
     }
    if(weight+v[i].second>maxweight&& weight<maxweight){
   
   profit+=(v[i].first/v[i].second)*(maxweight-weight);
   weight =maxweight;
   cout << " "<<profit<<" "<< weight<< endl;
     }
     
     
     
   }
   cout << "profit is:"<<profit << endl;
   }
   
    return 0;
}