#include <iostream>
#include<ctime>
//#include<string>
using namespace std ;
int main() {
    clock_t start_time=clock();
    //using namespace std ;
    
        
        int x='a';//explicit type change method 
        cout<< x<<endl;
       char y='a';//implicit type change method 
        cout<<( int)y<<endl;////implicit type change method 
    
     
     
    clock_t end_time=clock();

double long timespend=((double long )(end_time-start_time))/
CLOCKS_PER_SEC*1e6;
     cout<<"time to run the code:"<<( timespend)<<"microsecond"<<std::endl;
    return 0;
}