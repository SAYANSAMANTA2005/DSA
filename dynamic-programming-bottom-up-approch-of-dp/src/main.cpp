#include <iostream>
#include<bits/stdc++.h>
#define int unsigned long long
//10^20 max biggest num can be stored in unsigned long long
using namespace std;
vector<int>st(1e5,0);


signed main() {
    clock_t start=clock();


    int n;
    cout << "enter n :" << endl;
    cin>>n;
    st[0]=0;
    st[1]=1;
    for(int i=2; i<=n; i++) {
    //bottom-up approach of dynamic programming 

        st[i]=st[i-1]+st[i-2];
    }
    cout << "n th fibonacci:"<<st[n]<< endl;

    clock_t end=clock();

    cout << "time to run code in CPU :"<<
         (double)static_cast<double>(end-start)/
         CLOCKS_PER_SEC<<"second"
         << endl;

    return 0;
}