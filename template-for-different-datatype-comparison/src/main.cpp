#include <iostream>
#include<ctime>
 #include<cstring>
  using namespace std ;
  
  template<typename T, typename U>
  auto maximum(T a, U b)-> decltype((a < b) ? b : a) 
  {
    return  (a>b) ? a: b;
}
  
 int main() {
    clock_t start_time=clock();
   
   cout <<  maximum(1,2.353)<< endl;
   
    clock_t end_time=clock();
    
double long timespend=((double long )(end_time-start_time))/
CLOCKS_PER_SEC*1e6;
    std:: cout<<"\ntime to run the code:"<<( timespend)<<"microsecond"<<std::endl;
    return 0;
}