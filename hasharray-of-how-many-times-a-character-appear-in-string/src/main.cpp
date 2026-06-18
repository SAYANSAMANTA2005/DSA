#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std ;



string arr="sayan samanta";


int arrsize(){
int ans;
return ans=sizeof(arr)/sizeof(arr[0]);}

int size=arr.size();

int  minimum (){
int MIN=INT_MAX;

for(int i=0;i<size;i++){
if(arr[i]!=' '){
 MIN=min((int)arr[i]-'a',MIN);}

 }
return MIN;
}

int  maximum (){
int MAX=INT_MIN;

for(int i=0;i<size;i++){
if(arr[i]!=' '){
 MAX=max((int)arr[i]-'a',MAX);}

 }
return MAX;
}



int main() {
//  int size=sizeof(arr)/sizeof(arr[0]);
int Min=minimum();

int Max=maximum ();
std::vector<int> hasharr(Max-Min+1,0);

for(int i=0;i<size;i++){

hasharr[(int)arr[i]-'a'-Min]++;
}

for(int i=0;i<=Max-Min;i++){

if(hasharr[i]!=0){
cout <<"key:"<<(char) (i+1+(int)('a')-1)<<" present:" <<hasharr[i]<<" times"<< endl;}

}









    return 0;
}