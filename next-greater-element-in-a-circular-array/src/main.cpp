

#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElementII(vector<int>& a) {
    // Write your code here.
    int n=a.size();
    vector<int>gr(2*n,-1),grr(n);
    stack<int>st;
    for(int i=2*n -1;i>=0;i--){
        if(!st.empty())
        int c =st.top();
        while (!st.empty() && a[i] >= st.top()) {
        st.pop();
        }
        if (!st.empty())
        gr[i] = st.top();
        st.push(a[i%n]);
    }
        for (int i = 0; i < n; i++) {
        
        grr[i]=gr[i];
        }
    
    return grr;
}

int main(int argc, char** argv){
    cout << "Hello world" << endl;
}