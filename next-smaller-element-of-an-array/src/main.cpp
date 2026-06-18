#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    vector<int>sr(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=st.top()){
            st.pop();
        }
        if(!st.empty())
        sr[i]=st.top();
        st.push(arr[i]);
    }
    return sr;
    
}

int main(int argc, char** argv){
    cout << "Hello world" << endl;
}