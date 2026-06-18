#include<bits/stdc++.h>
using namespace std;

const int size=20;
    
    
    int noofelement1=0,noofelement2=0,noofelement3=0;
    stack<int>st1;
    stack<int>st2;
    stack<int>st3;
    
   // stack<int>storage;
    array<int,size>arr={-1};
   
   int top1=-1;
   int end1=-1;
   int top2=end1+1;
   int end2=top2 +noofelement2;
   int top3=end2+1;
   int end3=top3 +noofelement3;
    
    void push_stack1(){
    
    top1++;
    noofelement1++;
    end1++;
   // end1=top1+noofelement1-1;
    
   cout <<"after end1++ end1 is :" <<end1 << endl;
    arr[end1]=st1.top();
   cout << "after st1.top() end1 is:"<<end1 << endl;
    st1.pop();
    
    }
    void pop_stack1(){
    
    arr[end1]=-1;
    //top1--;
    noofelement1--;
    end1--;
    //cout << "poped element is:"<<st1.top()<< endl;
    st1.pop();
    
    }
    
    void push_stack2(){
    
    top2=end1+1;
    noofelement2++;
    end2=top2+noofelement2-1;
    cout <<"after end2++ :" <<end2 << endl;
    arr[end2]=st2.top();
    st2.pop();
    
    }
    
    void pop_stack2(){
    
    arr[end2]=-1;
        end2--;
    top2=end1+1;
   noofelement2--;
  //  end2--;
    
    
    cout <<"Is st2 empty? :" <<st2.empty()<< endl;
    //cout <<st2.top()<< endl;
    st2.pop();
    
    }
     
    void push_stack3(){
    
    top3=end2+1;
    noofelement3++;
    end3=top3+noofelement3-1;
    cout <<"after end2++ :" <<end3 << endl;
    arr[end3]=st3.top();
    st3.pop();
    
    }
    
    void pop_stack3(){
    
    arr[end3]=-1;
        end3--;
    top3=end2+1;
   noofelement3--;
  //  end2--;
    
    
    cout <<"Is st2 empty? :" <<st3.empty()<< endl;
    //cout <<st2.top()<< endl;
    st3.pop();
    
    }
    
    
    
int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    st1.push(1);push_stack1();
    st1.push(2);push_stack1();
    st1.push(3);push_stack1();
    st1.push(10);push_stack1();
    st1.push(20);push_stack1();
    st1.push(30);push_stack1();
    st1.pop();pop_stack1();//st1.top()=5
    st2.push(4);push_stack2();
    st2.push(5);push_stack2();
    st2.push(6);push_stack2();
    //st2.top()=6;
     st2.pop();pop_stack2();
    st3.push(4);push_stack3();
    st3.push(5);push_stack3();
    st3.push(6);push_stack3();
    
    
    
    for(int i=0;i<size;i++){
    cout << arr[i]<<" "<< endl;
    }
    
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\n\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}