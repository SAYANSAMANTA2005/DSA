#include<bits/stdc++.h>
using namespace std;





int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    vector<int>v;
    
   for(int i=0;i<pow(2,5);i++){ v.push_back(1);
    cout<<"size/no of element in array"<<v.size()<<endl;
    cout<<"capacity/ space allocated  in vector"<<v.capacity()<<endl;}
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "Time to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}