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
  //parameterised constrictor
  hero (int health,char level,std::string name){
  
  this->health=health ;
  this->level=level;
  this->name=name;
  //std::cout << this <<std:: endl;
  std::cout << "constructor called" <<std:: endl;}
 
 
 
 // default constructor(non -parameterised constricter)
    hero() {//when you write any type of constructor you have to declare the default constructor by yourself 
        health = 0;
        level = 'Z';
        //std::cout << this << std::endl;
        std::cout << "Default constructor called" << std::endl;
    }
    
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
     hero sayan(10,'a',"queen");
     
   std::cout << sayan.getlevel()<< std::endl;
     
     sayan.printname();
     sayan.printhealth();
     sayan.printlevel();
     std::cout << &sayan<< std::endl;
     
   hero s(sayan);//
   //copy constructor 
     s.printname();
     s.printhealth();
     s.printlevel();
     std::cout << &s<< std::endl;
     
    clock_t end_time=clock();

double long timespend=((double long )(end_time-start_time))/
CLOCKS_PER_SEC*1e6;
    std:: cout<<"time to run the code:"<<( timespend)<<"microsecond"<<std::endl;
    return 0;
}