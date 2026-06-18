#include <iostream>

using namespace std;

int trap(vector<int>& height) {
        int n= height.size();
        vector<int>maxl(n),maxr(n);
        stack<int>sl,sr;
        maxl[0]=height[0];sl.push(height[0]);
        maxr[n-1]=height[n-1];sr.push(height[n-1]);
        for(int i=0;i<n;i++){
            maxl[i]=sl.top();
            if(height[i]<=sl.top())
            continue;
            else 
            sl.push(height[i]);

        }
        for(int i=n-1;i>=0;i--){
            maxr[i]=sr.top();
            if(height[i]>sr.top())
            sr.push(height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int h = min(maxl[i],maxr[i]);
            if(h>=height[i])
            h = h -height[i];
            else
            h =0;
            ans +=h*1;
        }
        return ans;
        
    }

int main(int argc, char** argv){
    cout << "Hello world" << endl;
}