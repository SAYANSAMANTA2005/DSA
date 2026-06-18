
#include<bits//stdc++.h>
using namespace std;



int main() {

    int n;cin>>n;
    int N=n;
    int pow2=0,pow5=0;
    while(n >0){
    pow2+= n/2;
    n/=2;
     }
     while(N >0){
    pow5+= N/5;
    N/=5;
     }
     cout << min(pow2,pow5) << endl;
     
    return 0;
}