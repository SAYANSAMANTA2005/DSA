#include <iostream>
#include<ctime>
 #include<cstring>
 
 
 class hero{
 private:
// in private you can access thing inside classs only
 //outside there is no access of private 
 std::string name;
 int health;
 public:
 char level;
 
 
 void printname(){
 std::cout << name << std:: endl;}
 
 void printhealth(){
 std::cout << health << std:: endl;}
 
 void printlevel(){
 std::cout << level << std:: endl;}
 
 int sethealth(int h){
 health =h;
 return health;}
 
 
 char setlevel(char l){
 level= l ;
 return level;}
  
 std::string setname(std::string  st){
 name = st ;
 return name;}
 
 int gethealth(){
 return health;}
 
 char getlevel(){
 return level;}
 
 
 };

int main() {
    clock_t start_time=clock();
    
    //creating objects 
     hero sayan;
     hero*cpp=new  hero;
     hero*c=new  hero;
     
   sayan.level='A';
   std::cout << sayan.getlevel()<< std::endl;
     sayan.sethealth(1);
     sayan.setlevel('B');
     sayan.setname("queen");
     sayan.printname();
     sayan.printhealth();
     sayan.printlevel();
     //using dereferencing operator 
      (*cpp).sethealth(5);
     (*cpp).setlevel('c');
     (*cpp).setname("king");
      (*cpp).printname();
      (*cpp).printhealth();
      (*cpp).printlevel();
     
     
     //using arrow operator 
        c->sethealth(10);
       c->setlevel('D');
        c->setname("queen card");
       c->printname();
       c->printhealth();
        c->printlevel();
     
    // std::cout << sayan.gethealth()<< std::endl;
    // std::cout << sayan.getlevel()<< std::endl;
        delete c;
       delete cpp;
       
    clock_t end_time=clock();

double long timespend=((double long )(end_time-start_time))/
CLOCKS_PER_SEC*1e6;
    std:: cout<<"time to run the code:"<<( timespend)<<"microsecond"<<std::endl;
    return 0;
}