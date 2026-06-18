#include<bits/stdc++.h>
using namespace std;



    
    
int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    queue<int>q;
    for(int i=0;i<10;i++){
    q.push(10*i);
    
    }
    
    
    cout << q.back() << endl;
    
    while(!q.empty()){
    cout << q.front() << endl;
    q.pop();
    }
    
    
    
   
    
    clock_t end_time=clock();
    double timespend =  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\n\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}