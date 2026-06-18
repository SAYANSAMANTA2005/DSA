#include <bits/stdc++.h>
using namespace std;

#define loop(n,a) for(int i=a;i<n;i++)
#define loopvar(var,n,a) for(int var =a;var<n;var++)
#define input(a) for(auto &x:a) cin>>x;
#define display(x) cout<<x<<endl
#define input_of_vec(vec,end,start) loop(end,start) {cin>>vec[i];}
#define print_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cout<<a[i][j]<<' ';}cout<<endl;}
#define display_vec(vec,end,start) loop(end,start) {cout<<vec[i]<<" ";}
#define sorting(vec) sort(vec.begin(),vec.end())
#define nextline cout<<endl
#define int long long 
#define MOD 1000000007
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}
#define all(a) begin(a),end(a)
#define vi(a,size) vector<int>a(size)
#define vii vector<vector<int>>
#define faster_input_output ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int32_t main() {
	// your code goes here
  faster_input_output;
	int t;cin>>t;
	while(t--){
	    int n,m;cin>>n>>m;
	    string s,a;cin>>s>>a;
	    int curr = 0;
	    //display(s);
	    for(int j=0;j<n;j++){// j is index of string s
	    //display("before");
	    //cout<<j<<curr<<s[j]<<a[curr]<<endl;
	      if(s[j]!='?'){
	           //if(s[j] !=a[curr])
	           //j++;
	           if(s[j]==a[curr]){
	              // j++;
	               curr++;
	           }
	      }
	      else if(s[j]=='?'){// s[j] = '?'
	      // inserting diff alphabet than a[curr]
	          if(a[curr]=='a')
	          s[j] = 'b';
	          else
	          s[j] = 'a';
	         // j++;
	      }
	     // display("after");
	     // cout<<j<<curr<<s[j]<<a[curr]<<endl;
	        
	    }
	    //display(curr);
	    //display(m);
	  if(curr== m)
 display(-1);
	   else
	    display(s);
//	 nextline;
	 
	}
}