#include<bits/stdc++.h>
using namespace std;





int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    int n=9;
   // array<int,6>arr={6,10,5,2,9,7};
    stack<int>st;
    vector<int>arr(n,-1);
    vector<int>ans={8,6,4,7,4,9,10,8,12};
    //ans[n]={8,6,4,7,4,9,10,8,12};
    //int n=23;
   for(int i=0;i<n;i++){ 
     
     if(st.empty()){
      st.push(i);}
     
     
     else{
    while(!st.empty() &&ans[st.top()]>ans[i]){
      arr[st.top()]=ans[i];
     st.pop();
        }
        if(!st.empty()){
        arr[i]=arr[st.top()];
        }
        st.push(i);
      }
     }
     cout << "\n ans array is:\n" << endl;
    for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";}
    
    cout << "\n previous array is:\n" << endl;
    
    for(int i=0;i<ans.size();i++){
    cout<<ans[i] <<" ";}
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}