include <bits/stdc++.h>
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
          int n,d,l;cin>>n>>d>>l;
          vector<pair<int,int>>tree(n-1);
          int check =-1;
          if(n!=2){
             // if(n-1 >=l)
              int dmax = n-l+1;
              int dmin,k = ceil((double)(n-l-1)/(double)l);
              if((n-1)%l==1)
              dmin = 2*(k) -1;
              else
              dmin = 2*(k) +1;
              
              if(n-1>=l && dmin<= d && d<=dmax)
              check =0;
         ///    
       //   display(dmax);
        //  display(dmin);
          //
          }
          else {
              if(l==2 && d ==1)
              check=0;
          }
        
          if(check ==-1)
          display(-1);
          else{
              loop(n,1){
                  // n-1 times loop runs
                  if(i>=1 && i<= l)
                  cout<< 1<<" "<<i+1<<endl;
                  else
                  cout<< i<<" "<<i+1<<endl;
              }
       //nextline;
          }
      
      }
}
