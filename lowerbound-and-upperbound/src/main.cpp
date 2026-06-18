#include <iostream>

using namespace std;
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	//return min idx where arr[idx]>=x
	int ans=n;
	int low =0,high=n-1;
	while(high>=low){
		int mid = (low +high)/2;
                if (arr[mid] >= x) {
                  high = mid - 1;
				  ans =min(ans,mid);
                }
                if(arr[mid]<x)
		low =mid+1;
	}
	return ans;
	// returned low .... because initially arr[low]<x
	//while loop will break when arr[low]>=x
}

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	// return smallest idx where arr[idx]>x
	int low =0,high=n-1;
	while(low<=high){
		int mid = (low +high)/2;
		if(arr[mid]<=x)
		low =mid+1;
		if(arr[mid]>x)
		high=mid-1;
	}
	// since initially arr[low]<=x ...
	//while loop will terminate when arr[low]>x
	return low; 

}

int main(int argc, char** argv){
    cout << "Hello world" << endl;
}