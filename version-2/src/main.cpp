#include<bits/stdc++.h>
using namespace std;

const int size=10;
    
    
    stack<int>st1;
    stack<int>st2;
   // stack<int>storage;
    array<int,size>arr={-1};
   
   int top1=-1;
   int top2=size;
    
    void push_stack1(){
    
    top1++;
  //  cout <<"before st1.top() :" <<arr[top1] << endl;
    arr[top1]=st1.top();
   cout << "after st1.top() :"<<arr[top1] << endl;
    st1.pop();
    
    }
    void pop_stack1(){
    
    arr[top1]=INT_MIN;
    top1--;
    
    cout << st1.top()<< endl;
    //st1.pop();
    
    }
    
    void push_stack2(){
    
    top2--;
    arr[top2]=st2.top();
    st2.pop();
    
    }
    
    void pop_stack2(){
    
    arr[top2]=INT_MIN;
    top2++;
    
    cout << st2.top()<< endl;
    //st1.pop();
    
    }
    
    
    
int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    st1.push(1);push_stack1();
    st1.push(2);push_stack1();
    st1.push(5);push_stack1();//st1.top()=5
    st2.push(3);push_stack2();
    st2.push(4);push_stack2();
    st2.push(6);push_stack2();//st2.top()=6;
    
    
    
    
    
    
    for(int i=0;i<size;i++){
    cout << arr[i]<<" "<< endl;
    }
    
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\n\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}