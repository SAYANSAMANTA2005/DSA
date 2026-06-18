#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int  fib(int n) {
    if (n==1||n==0) return n;


    return fib(n-1)+fib(n-2);

}
int main() {
   clock_t start=clock();
    int t;
    cout << "enter no of testcase:" << endl;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout << "n th fibonacci:"<<fib(n) << endl;
    }
    clock_t end=clock();
    
    cout << "time to run code in CPU :"<<
    (double)static_cast<double>(end-start)/
    CLOCKS_PER_SEC*1e6<<"microsecond" 
    << endl;

    return 0;
}