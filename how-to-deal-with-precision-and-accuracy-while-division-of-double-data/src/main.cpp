#include <bits/stdc++.h>
using namespace std;
#define loop(n) for(int i=0;i<n;i++)
# define double long double
#define int double
int32_t main() {
      // your code goes here
int t;cin>>t;
while(t--){
    int n;cin>>n;
    vector<int>arr(n+1);
    double ans=0.00000000;
    loop(n){
        cin>>arr[i];
    }
    //ans =arr[1];
    sort(arr.begin(),arr.end());//alt methode of sorting 
    reverse(arr.begin(),arr.end());
    ans =arr[0];
    for(int i=1;i<n;i++){
    
        //cout<<"ans ->"<<ans<<endl;
        ans = (ans+arr[i])/2.0;
    
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
}