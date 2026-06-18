# include<stdio.h>
int main(){

int arr[]={5,4,3,2,1};
int n=5;int count=0;int min;
for(int i=0;i<n-1;i++){
min=i;
for(int j=i;j<n;j++){
if(arr[j]<arr[min]){

 min=j;}
int count=j+1;
}
int temp=arr[min];
arr[min]=arr[i];
arr[i]=temp;

}

for(int i=0;i<n;i++){
printf("%d ",arr[i]);}
return 0;

}