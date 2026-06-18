
#include <stdio.h>
#include<stdbool.h>

int arr[1000000]={1};


int com=0;
int prim=0;

int isPrime(int n,int num) {

//if n is prime then O(num/n) time complexity 
    //if n is notprime then O(1) time complexity 
    
    if (n <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
   
        if (arr[n] == 0) {//O(1) time complexity 
         com++;
            return 0; 
            // If the number is divisible by any number other than 1 and itself, it's not prime
        }
        else{
        prim++;
    for (int i = 2; i*n  <= num; i++) {//O(num/n) time complexity 
    //only prime n can enter in this 
    
   if(arr[i*n]!=0){ arr[i*n]=0;
     // printf("%d not prime\n",i*n);
     
      
     }}}
    return 1; // If the number passes all the conditions, it's prime
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for(int i=2;i<num;i++){//O(num)
    arr[i]=1;}

    if(num<=100000000){
    for(int i=2;i<num;i++){//O(num) time complexity 
    
    
    isPrime(i,num);
    //if I is prime then O(num/i) time complexity 
    //if i is notprime then O(1) time complexity 
    
       // printf("%d is a prime number.\n", i);
    } }
    else{
    printf("increase arr size ");}
    
    for(int j=2;j<num;j++){
     if(arr[j]==1){
    printf("%d->prime num \n",j);}
    }
    
    printf("total prime no below or equal to %d is\n:%d",num,prim);
    printf("\ntotal composite no below or equal to %d is\n:%d",num,com);

    return 0;
}
    