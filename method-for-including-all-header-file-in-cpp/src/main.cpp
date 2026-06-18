#include<bits/stdc++.h>
using namespace std;

int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    cout << pow(2,3)<< endl;
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "Time to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}