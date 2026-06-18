 #include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std ;




int arr[]={1,5,7,8,10,5,1,5,5,5,360000,7,7,8};

int arrsize(){
int ans;
return ans=sizeof(arr)/sizeof(arr[0]);}

int size=arrsize();

int  minimum (){
int MIN=INT_MAX;
for(int i=0;i<size;i++){
 MIN=min(arr[i],MIN);

 }
return MIN;
}

int  maximum (){
int MAX=INT_MIN;
for(int i=0;i<size;i++){
 MAX=max(arr[i],MAX);

 }
return MAX;
}



int main() {
//  int size=sizeof(arr)/sizeof(arr[0]);
int Min=minimum();

int Max=maximum ();
std::vector<int> hasharr(Max-Min+1,0);

for(int i=0;i<size;i++){

hasharr[arr[i]-Min]++;
}

for(int i=0;i<=Max-Min;i++){

if(hasharr[i]!=0){
cout <<"key:"<< i+1<<" present:" <<hasharr[i]<<" times"<< endl;}

}







    return 0;
}