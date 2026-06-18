#include <bits/stdc++.h>
using namespace std;

int main() {
      // your code goes here
      int t;
      cin>>t;
      cin.ignore();
      while(t--){
          
          string concat_ab,concat_cs;
          int n;
          getline(cin,concat_ab);
         
        
          cin>>n;
          cin.ignore();
          cout<<concat_ab<<endl;
         
              for(int i=0;i<n;i++){
                  string c;cin>>c;
                  cin.ignore();
                  concat_cs.append(c);
              }
              
              //cout<<concat_cs<<endl;
              
          

          }
      }

