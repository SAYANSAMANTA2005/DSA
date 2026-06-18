#include<bits/stdc++.h>
using namespace std;





int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    array<int,4> a={1,2,3,4};
    
    for(int i=0; i<a.size();i++){
    
    cout <<"print by array method"<<a[i]<< endl;
    
    cout <<"print by at operator"<<a.at(i)<< endl;}
    cout <<"0 if array is not empty ,other wise 1: result is:"<<a.empty()<< endl;
    cout<<"front/first element:"<<a.front()<<endl;
    cout << "last/back element is:"<<a.back() << endl;
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "Time to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}