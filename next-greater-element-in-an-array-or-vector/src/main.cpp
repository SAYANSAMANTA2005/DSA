#include<bits/stdc++.h>
using namespace std;





int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    int n=6;
    array<int,6>arr={6,10,5,2,9,7};
    
    vector<int>ans(n,-1);
    //int n=23;
   for(int i=0;i<n;i++){ 
     for(int j=i+1;j<n;j++){
     if(arr[i]<arr[j]){
     ans[i]=arr[j];
     break;}}}
     
    for(int i=0;i<ans.size();i++){
    cout<<ans.at(i)<<endl;}
    
    
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "Time to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}