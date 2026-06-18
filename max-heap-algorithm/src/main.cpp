#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std ;

vector<int>arr={0,1,2,3,8,9,2,7,6,657,352,252,353,50,99,15};


int n=arr.size();


void swap(int*a,int*b){
int temp=*a;
*a=*b;
*b=temp;


}

void make_maxheap(int root){

if(root>=n|| root<=0){return;}
int leftchild=2*root;
int rightchild=2*root+1;

while(root>=1&&leftchild<n&&(arr[leftchild]>arr[root])){

swap(&arr[leftchild],&arr[root]);

make_maxheap(leftchild);
make_maxheap(rightchild);
}

while(root>=1&&rightchild<n&&(arr[rightchild]>arr[root])){


swap(&arr[rightchild],&arr[root]);

make_maxheap(leftchild);
make_maxheap(rightchild);
}

}

int main() {
   make_maxheap(1);
     

cout << arr[0]<< endl;
   for(int i=1;i<n;i++){
   
   
   cout << "i is:"<<i<< ":arr: "<<arr[i] << endl;}
    return 0;
}