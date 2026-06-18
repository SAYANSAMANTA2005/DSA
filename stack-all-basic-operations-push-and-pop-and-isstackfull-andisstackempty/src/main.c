#include<stdio.h>
#include<stdlib.h>

struct stack{

int size;
int top;
int*arr;

};
int isstackfull(struct stack *s){
 if(s->top>=s->size-1){return 1;
    }
  else{return 0;}
 }

int isstackempty (struct stack *s){
if(s->top==-1){return 1;//it is true that stack is empty 
 }
  else{return 0;}//it is false that stack is empty 
  }


void push(struct stack *s,int data){
if(isstackfull(s)==1){
printf("stack is overflowed/ stack is full");
return ;}

else{
s->top++;
s->arr[s->top]=data;
return ;
   }
 }


void pop(struct stack *s){
if(isstackempty(s)==1){
printf("stack is underflow/stack is empty");
 }

else{
   s->top--;
   
   }
}
showstacktop(struct stack*s){
  printf("%d",s->arr[s->top]);
}
 printfuction(struct stack *s){
 if(isstackfull(s)==1){
printf("stack is overflowed/ stack is full");}
else{ for(int i=0;i<=s->top;i++){

printf("%d ",s->arr[i]);
  }}}
 
 
 
 
 
int main(){

struct stack*s;
s->size=80;
s->top=-1;
s->arr=(int*)malloc(s->size*sizeof(int));
int data=80;
push(s,data);

push(s,90);

push(s,9);

showstacktop(s);
printfuction(s);
pop(s);
printf("\nnew stack after poping :\n");
printfuction(s);

return 0;



}