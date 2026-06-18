#include <bits/stdc++.h>
using namespace std;
#define in long long
int main() {
      // your code goes here
      in t;cin>>t;
      while(t--){
          in a,b,count=0;
          cin>>a>>b;
          in diff =abs(a-b);
          int i=1;
          while(i<=sqrt(diff)){
              if((diff%i)==0){
                  if(diff/i !=i)
                  count+=2;
                  else
                  count++;
              }
              i++;
          }
          cout<<count<<endl;
        
      }

}