#include<bits/stdc++.h>
using namespace std;

int size=4;
    
    
    stack<int>st;
    
    
    int arr[4][4]={
      {0,0,1,1},
      {0,0,1,1},
      {0,0,0,0},
      {0,0,1,1},
    
    };
    
void function_a_knows_b(int a ,int b){

if(
arr[a][b]==1){//remember in iteration b should came first

st.push(b);

return ;
}
if(arr[b][a]==1){//poping a


st.push(a);

return ;
  }

}

void celebrityfind(){

    
    for(int j=0;j<size;j++){
    
    st.push(j);
    cout << "your top element of stack is : " << "";
      cout  << st.top()<<endl;
    }
    
    while(st.size()>1){
    int a=st.top();st.pop();
    int b=st.top();st.pop();
    cout << "a is"<<a << endl;
    cout << "b is"<<b<< endl;
    
    function_a_knows_b(a,b);
    
    cout << "candidate after function_a_knows_b is : " << "";
      cout  << st.top()<<endl;
      
   
    }
    
    
    }
    
    
    
    
    
int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    celebrityfind();
    
    clock_t end_time=clock();
  double timespend=  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\n\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}