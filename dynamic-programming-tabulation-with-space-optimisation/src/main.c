#include<stdio.h>

int fibonacci(int n){//function ar argument a array ar size na likhlao hobe

int previous_1=0;
int previous_2=1;


 int current ;
 
for(int i=2;i<=n;i++){


 current =previous_1+previous_2;
previous_1=previous_2;
previous_2=current ;
}

return current ;
}


int main(){

int n;
scanf("%d",&n);
int dynamic_programming [n+1];

for(int j=0;j<n+1;j++){dynamic_programming[j]=-1;}
//fibonacci(n,dynamic_programming);
printf("%d",fibonacci(n));//in array automatically it send it's adress so we don't need to use & in array while passing through function 


return 0;
}