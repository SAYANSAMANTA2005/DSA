#include <iostream>

using namespace std;

int main() {
    clock_t start_time=clock();
    
    cout<< "hello world" << endl;
     
    
     int x;
     cout<< "enter the number:";
     cin>>x;
    cout<<x << endl;
    cout<< "half of :"<<x<<"=" ;
     float y=(float)x;//type casting
    cout<< y/2<< endl;
   
    char ch;
    cout<< "enter the character:";
     cin>>ch;
    cout<< ch << endl;
    cout<< "asci value of :"<<ch<<"=" ;
     int b=(int )ch;//type casting
    cout<< b<< endl;
   
   char ch2;
    cout<< "enter the character:";
     cin>>ch2;
    cout<< ch2 << endl;
    cout<< "method 2 for asci value of :"<<ch2<<"=" ;
     //type casting
    cout<< (int)ch2<< endl;
   
    
    
    clock_t end_time=clock();

double timespend=((double)(end_time-start_time))/
CLOCKS_PER_SEC*1000000;
     cout<<"time to run the code:"<< float(timespend)<<"microsecond"<<endl;
    return 0;
}