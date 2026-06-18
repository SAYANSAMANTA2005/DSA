#include<stdio.h>

int fibonacci(int n,int dynamic_programming[]){//function ar argument a array ar size na likhlao hobe

dynamic_programming[0]=0;

dynamic_programming[1]=1;

 
 
for(int i=2;i<=n;i++){
dynamic_programming[i]=dynamic_programming[i-1]+dynamic_programming[i-2];}

return dynamic_programming[n];
}


int main(){

int n;
scanf("%d",&n);
int dynamic_programming [n+1];

for(int j=0;j<n+1;j++){dynamic_programming[j]=-1;}
//fibonacci(n,dynamic_programming);
printf("%d",fibonacci(n,dynamic_programming));//in array automatically it send it's adress so we don't need to use & in array while passing through function 


return 0;
}