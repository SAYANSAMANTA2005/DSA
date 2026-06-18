#include <iostream>
#include<ctime>
//#include<string>
using shortcut_t=std::string ;//giving std::string data type name to shortcut_t
using integer= int ;
namespace first{

integer num=21;
shortcut_t name=" goat samanta";
}//:: is called scope operator
namespace second{
integer num=10;

shortcut_t  name=" sayan samanta";
}//:: is called scope operator

int main() {
    clock_t start_time=clock();
    using std::cout;
    //using std ::string;
    using std::endl;
        
        
        
    first:: name="apple";//modifying variable "name" inside first namespace 
    second::name="ballon";//modifying variable "name" inside second namespace 
     cout<< first::name<<endl;
     
     cout<< second::name<<endl;
     
     cout<< first::num<<endl;
     
     cout<< second::num<<endl;
     
     
    clock_t end_time=clock();

double long timespend=((double long )(end_time-start_time))/
CLOCKS_PER_SEC*1e6;
     cout<<"time to run the code:"<<( timespend)<<"microsecond"<<std::endl;
    return 0;
}