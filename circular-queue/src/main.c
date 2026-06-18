#include<stdio.h>
#include<stdlib.h>

struct circular_queue{

int size;
int f;
int r;
int*arr;

};


 void printfuction(struct circular_queue*s);


int isfull(struct circular_queue *s){
 if((s->r+1)%s->size==s->f){return 1;
    }
  else{return 0;}
 }

int isempty (struct circular_queue *s){
if(s->f==s->r){return 1;//it is true that queue is empty 
 }
  else{return 0;}//it is false that  queue is empty 
  }


void  enqueue(struct circular_queue *s,int data){
if(isfull(s)==1){
  printf(" circular queue is overflowed/ stack is full");
 return ;}

else{
s->r=(s->r+1)%(s->size);
s->arr[s->r]=data;

   
   printf("\nnew curcular queue after enqueueing  :\n");
   printfuction(s);
   
   return ;
  }
 }


void dequeue(struct circular_queue*s){
if(isempty(s)==1){
printf("circular queue is underflow/stack is empty");
 }

else{
   s->f=(s->f+1)%s->size;
   printf("\ndequeued element is %d\n",s->arr[s->f]);
   }
}


void showqueuebottom(struct circular_queue*s){
if(isempty(s)==1){
printf(" circular queue is underflow/stack is empty");
 }
  else {printf("%d\n",s->arr[s->r]);}
}
void showqueuetop (struct circular_queue*s){
if(isempty(s)==1){
printf("circular queue is underflow/stack is empty");
 }
  else{ printf("%d\n",s->arr[(s->f+1)%s->size]);}
}



 void printfuction(struct circular_queue*s){
 if(isempty(s)){
 printf("circular queue is underflowed/ stack is empty");}
 else{ 
 
 
for(int i=(s->f+1)%s->size;i!=(s->r+1)%s->size;i=(i+1)%s->size){

printf("%d ",s->arr[i]);
   }
   
  // printf("%d ",s->arr[(s->r)%s->size]);
  
  }}
 
 
 
 
 
int main(){

struct circular_queue*s= (struct circular_queue*)malloc(sizeof(struct circular_queue));
if(!s){

printf("memory allocation failed");
return 1;}
s->size=5;//size increase by 1,beacuse f is also taking as ofone array element 
s->f=s->r=0;
s->arr=(int*)malloc(s->size*sizeof(int));
if(!s->arr){

printf("memory allocation failed");
free(s);
return 1;}
enqueue(s,80);//time complexity 0(1)


enqueue(s,9);


enqueue(s,110);


enqueue(s,140);
printf("\noriginal circular queue :\n");

printfuction(s);//time complexity 0(1)

printf("\ntop element/1st element of circular queue is:");

showqueuetop(s);//time complexity 0(1)

printf("\nbottom most element/last element of circular queue is:");
showqueuebottom(s);//time complexity 0(1)

dequeue(s);//time complexity 0(1)

printf("\nnew circular queue after dequeueing  :\n");
printfuction(s);//time complexity 0(1)

dequeue(s);//time complexity 0(1)

printf("\nnew circular queue after dequeueing  :\n");
printfuction(s);//time complexity 0(1)


enqueue(s,190);


free(s->arr);
free(s);

return 0;



}