#include<stdio.h>
int main(){
int indstart=0; 
int indmid;
int indend=9;
int k=3;

 int arr[4]={1,1,1,2};//sorted array
  while((indend-indstart)>1){  
 
 indmid=(indstart+indend)/2;
 
    if(arr[indmid]>k){ indend=indmid;
 
 }
    else{indstart=indmid;}
 
 
 }//binary search algorithm 
    if(indend==indstart+1){
    if(k>arr[4]){
    printf(" ans is %d", arr[4]);
    }
 
    else if(2*k<(arr[indend]+arr[indstart])){
 
 
      printf("ans is %d",arr[indstart]);}
 
    else{ 
      printf("ans is %d",arr[indend]);
 }
}


return 0; 



}