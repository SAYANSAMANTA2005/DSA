#include <iostream>
#include<ctime>
#include<math.h>
#include<cmath>
using namespace std;

int main() {
    clock_t start_time=clock();
        
     
    
     int x=5,y=9;
     cout<<"square root of "<<x<<"is"<<sqrt(x)<<endl;
     cout<<"cube root of "<<x<<"is"<<cbrt(x)<<endl;
    cout<<"max of "<<x <<"and"<<y<<"is"<<max(x,y)<<endl;
     cout<<"min of "<<x<<"and"<<y<<"is"<<min(x,y)<<endl;
     
     
     
     cout<< "enter the number:"<<x<<endl;
    
    (x%2==0)?cout<< "even" << endl:cout<< "odd" << endl;
   //syntax-> condition ?if ture:if false
    cout<<x << endl;
    
   
    
   
    
    
    clock_t end_time=clock();

double timespend=((double)(end_time-start_time))/
CLOCKS_PER_SEC*1e6;
     cout<<"time to run the code:"<<double( timespend-2)<<"microsecond"<<endl;
    return 0;
}