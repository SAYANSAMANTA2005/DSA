
#include<stdio.h>
#include<time.h>

#define end 8
int mid;
int arr[end]={0};//globally declare val for storing info about each leaf node
 
 int val_of_node[end];
 
int min(int a,int b){
if(a>b){return b;
    }
  else{return a;
  }
}

int build_node(int l,int h,int index_of_node,int val_of_node[]){

if(l==h){
val_of_node=arr[l];
return val_of_node;}//base case for leaf node

else{
mid=(l+h)/2;
build_node(l,mid,2*index_of_node+1,val_of_node);//left tree segment 
//recursive call for next children exploration 
build_node(mid+1,h,2*index_of_node+2,val_of_node);//right tree segment 

 val_of_node[index_of_node]= min(val_of_node[2*index_of_node+1],val_of_node[2*index_of_node+2]);// storing the nodes value (otherthan leaf nodes) from children nodes information 
 printf("%d, %d node val is:%d\n",l,h,val_of_node[index_of_node]);
 return val_of_node[index_of_node];
 
  
  }

}

int main(){
   clock_t start_time=clock();
// int val[end][end]={{0}};
 
 arr[0]=0;
 arr[1]=1;
 arr[2]=2;
 arr[3]=3;
 arr[4]=4;
 arr[5]=5;
 arr[6]=6;
 arr[7]=7;
 //fixing leaf node values
 

int l=0, h=7,index_of_node=1;

int ans=build_node(l,h,index_of_node,val_of_node);
printf("min no of array between array index %d and %dis\n:%d",l,h,ans);
clock_t end_time=clock();

double time=((double)(end_time-start_time))/
CLOCKS_PER_SEC*1000000;

printf("\ntime taken to run the code is\n%lf microsecond",time);
return 0;

}