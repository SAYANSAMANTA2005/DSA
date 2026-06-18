#include <bits/stdc++.h>

using namespace std;
bool isValid(string s) {
        stack<char>st;
        bool flag =true;
        for(char ch:s){
            if(ch=='('||ch=='{'||ch=='[')
            st.push(ch);
            if(ch==')'){
                if(st.empty())
                flag=false;
                else{
             char c = st.top();
             st.pop();
             if(c!='(')
             flag=false;
                }

            }
             if(ch=='}'){
                if(st.empty())
                flag=false;
                else{
             char c = st.top();
             st.pop();
             if(c!='{')
             flag=false;
                }

            }
             if(ch==']'){
                if(st.empty())
                flag=false;
                else{
             char c = st.top();
             st.pop();
             if(c!='[')
             flag=false;
                }

            }



        }
        if(!st.empty())
        flag=false;
        return flag;
    }
int main(int argc, char** argv){
string s;cin>>s;
    cout << isValid(s)<< endl;
}