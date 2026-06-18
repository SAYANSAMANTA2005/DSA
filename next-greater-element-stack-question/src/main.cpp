#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int>gr(n,-1);
	// Write your code here
	
	stack<int>st;
	for(int i=n-1;i>=0;i--){
		if(st.empty())
		gr[i]=-1;
		else{
                while (!st.empty() && arr[i] >= st.top()) {
                  st.pop();
                }
                if (!st.empty())
                  gr[i] = st.top();
               
                }
				 st.push(arr[i]);
        }
		return gr;
}

int main(int argc, char** argv){
    cout << "Hello world" << endl;
}