#include <iostream>

using namespace std;
bool ispeak(vector<int>&arr,int idx){
    if(arr[idx]>arr[idx-1] && arr[idx]>arr[idx+1])
    return true;
    return false;
}
int findPeakElement(vector<int> &arr) {
    // Write your code here
    int n= arr.size();
    if(n==1)
    return 0;
    if(arr[0]>arr[1])
    return 0;
    if(arr[n-1]>arr[n-2])
    return n-1;
    int low=1,high=n-2;
    while(high>=low){
        int mid =(low +high)/2;
        if(ispeak(arr,mid))// mid is a peak
        return mid;// arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]
        else if(arr[mid]>arr[mid-1])// currently u r in increaing part 
        low = mid+1;
        else if(arr[mid]>arr[mid+1])// currently u r in decreasing part
        high = mid-1;
        else// for arr[mid-1]> arr[mid] && arr[mid+1]>arr[mid]
        // mid is actually a valley
         low =mid+1;

    }
    return -1;/// this line never executed

}

int main(int argc, char** argv){
    cout << "Hello world" << endl;
}