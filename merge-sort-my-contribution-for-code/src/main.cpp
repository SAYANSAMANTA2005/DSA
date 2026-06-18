#include<bits/stdc++.h>
using namespace std;

const int size=9;

int arr[size]={5,10,4,2,3,1,7,8,9};
   
   
   void swap(int*a,int*b){
   
   int temp=*a;
   *a=*b;
   *b=temp;
   }
   
//int size1=4;
//int size2=4;

//int arr1[4]={1,3,4,6};
//int arr2[4]={2,5,7,8};
//int ans[8];
void mergearray(int low,int mid,int high){//arr1[],int arr2[])//asending order merging 


int ptr1=0;int ptr2=0;
int i=low;
int size1=mid-low+1;
int size2=high-mid;
int arr1[size1];
int arr2[size2];
//int arr[size1+size2];

// Copy data to temporary arrays arr1[] and arr2[]
    for (int i = 0; i < size1; i++)
        arr1[i] = arr[low + i];
    for (int i = 0; i < size2; i++)
        arr2[i] = arr[mid + 1 + i];
        
while(i<(size1+size2)&&ptr1<size1 &&ptr2<size2){
  if(arr1[ptr1]>arr2[ptr2]){
 arr[i]=arr2[ptr2];
 ptr2++;
 i++;
  }
  else{
  arr[i]=arr1[ptr1];
  
   ptr1++;
   i++;}
 }
 // Copy remaining elements of arr1, if any
    while (ptr1 < size1) {
        arr[i++] = arr1[ptr1++];
    }

    // Copy remaining elements of arr2, if any
    while (ptr2 < size2) {
        arr[i++] = arr2[ptr2++];
    }
}
    
    
    
 void  devide(int low,int high){
 
 if(low==high){return;}//base case for recursion 
 int mid=(low+high)/2;
    
 
   devide(low, mid);
   devide(mid+1 ,high);
   //mergearray(arr1,arr2);
    mergearray(low,mid,high);
   
 }   
    
    
    
int main()
{   clock_t start_time =clock();
    cout << "Hello World!" << endl;
    
    
    
    devide(0,size-1);
    
    for(int i=0;i<size;i++){
    
    cout << arr[i] << " "<< endl;}
    
    clock_t end_time=clock();
    double timespend =  (double) (end_time-start_time)/CLOCKS_PER_SEC*1e6;
    cout << "\n\nTime to run the code "<<timespend <<"microsecond"<< endl;
    
    
    return 0;
}