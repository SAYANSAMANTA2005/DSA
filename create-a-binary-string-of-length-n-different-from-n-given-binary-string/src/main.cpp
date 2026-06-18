#include <bits/stdc++.h>
// logic is not mine
using namespace std;
#define ll long long
#define MOD 1000000007
int main() {
	// your code goes here
	ll t,n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    vector<string> arr(n);
	    for(ll i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    string res="";
	    for(ll i=0;i<n;i++) {
	        if(arr[i][i]=='0') {
	            res=res+"1";
	        } else {
	            res=res+"0";
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}