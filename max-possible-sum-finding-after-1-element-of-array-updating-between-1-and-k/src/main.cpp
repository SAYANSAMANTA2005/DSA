#include <bits/stdc++.h>
using namespace std;

int current_inc;
int inc=INT_MIN;
int main() {
    int t;
    cout << "enter no of testcase" << endl;
    cin>>t;
    while(t--) {

        int n,k;
        cout << "enter vec size and max possi element of vec " << endl;
        cin>>n>>k;
        int sum=0;
        vector<int>arr(n);
        for(int i=0; i<n; i++) { //taking arr input

            cout << "enter all n  array element" << endl;
            cin>>arr[i];
        }

        // your code goes here
        for(int i=0; i+1<n; i++ ) {
            sum+=abs(arr[i+1]-arr[i]);
        }

        for(int i=0; i+3<=n; i++) {

            int a=arr[i+1]-arr[i];
            int b=arr[i+2]-arr[i+1];
            if(a*b<0) {
                if((abs(k-arr[i])+
                        abs(arr[i+2]-k))>
                        abs(a)+abs(b)) {

                    arr[i+1]=k;


                }
                if((abs(1-arr[i])+
                        abs(arr[i+2]-1))>
                        ( abs(arr[i+1]-arr[i])+
                          abs(arr[i+2]-arr[i+1]))) {

                    arr[i+1]=1;
                }

                current_inc=

                    (abs(arr[i+1]-arr[i])+
                     abs(arr[i+2]-arr[i+1]))-(abs(a)+abs(b));
                inc=max(current_inc,abs(inc));

            }
        }
        int  i=0;
        int a=arr[i+1]-arr[i];
        if(abs(k-arr[i+1])>
                abs(a)) {

            arr[i]=k;
        }
        if(abs(1-arr[i+1])>
                abs(arr[i+1]-arr[i])) {


            arr[i]=1;
        }
        current_inc=

            (abs(arr[i+1]-arr[i])
             -abs(a));
        inc=max(current_inc,abs(inc));

        i=n-2;
        a=arr[i+1]-arr[i];

        if(abs(k-arr[i+1])>
                abs(a)) {

            arr[i+1]=k;
        }

        if(abs(1-arr[i+1])>
                abs(arr[i+1]-arr[i])) {

            arr[i+1]=1;
        }
        current_inc=

            (abs(arr[i+1]-arr[i])
             -abs(a));
        inc=max(current_inc,abs(inc));

        cout << "max possible sum after 1 element updation: "<<
             sum+inc << endl;

    }

}