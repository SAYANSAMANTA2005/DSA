#include<bits/stdc++.h>
using namespace std;

int size=10;
    
    
    stack<int>st;
   // stack<int>storage;
    vector<int>vec(size);
   
    void make_density_gradient_stack(){
    
    for(int i=0;i<size;i++){
     if(i==0)continue;
    while(!st.empty() &&vec[i]>st.top()){
    //storage.push(st.top());
    st.pop();}
    st.push(vec[i]);
    
    
       }
    }
    
    
int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    for(int i=0;i<size;i++){//decreasing vector to increasing stack
    //
    
    vec[i]=size-i;
    
    }
     
    st.push(vec[0]);
    
    make_density_gradient_stack();
    while(!st.empty()){
    cout << st.top()<< endl;
    st.pop();}
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\n\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}