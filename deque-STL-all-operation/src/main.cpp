#include<bits/stdc++.h>
using namespace std;



    
    
int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    deque<int>dq;
    for(int i=0;i<10;i++){
    dq.push_front(10*i);
    
    }
    
    dq.pop_back();
    dq.push_back(23);
    
    while(!dq.empty()){
    cout <<"dq.front():"<< dq.front() << endl;
   // cout << "dq.back():"<<dq.back() << endl;
    dq.pop_front();
    }
    
    
    
   
    
    clock_t end_time=clock();
    double timespend =  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\n\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}