#include <stdio.h>
#include <stdlib.h>


struct stack{
int data;
struct stack*left;
struct stack*right;

};
void traversestackleft(struct stack*ptr){
while (ptr!=NULL){
printf("%d ",ptr->data);
ptr=ptr->left;
    }
    
    
}
 void traversestackright(struct stack*ptr){
while (ptr!=NULL){
printf("\n%d \n",ptr->data);
ptr=ptr->right;
    }
    
}
 int isstackempty(struct stack*head){
 
 if(head==NULL){
   
    return 1;//yes true
   } 
     
     else{return 0;//no false
            } 
     }


   int isstackfull (struct stack*head){
   struct stack*p;
   p=(struct stack*)malloc(sizeof(struct stack));
   if(p==NULL){return 1;}//yes true 
   
   else {
   
   free(p);
   return 0;}//no false
   
   }
 
void pushleft(struct stack**head,int data){//double** because we are storing the adress of head pointer
if (isstackfull(*head)==1){
printf("stack is overflowed/full");}

else{
struct stack*p;
 p=(struct stack*)malloc(sizeof(struct stack));//allocating dunammemory for new node
 p->data=data;
 p->left=*head;//*head beacuse we are connecting p->next with adress of head pointer so that we can traverse from p to other nodes
*head=p;
   }
}

void pushright(struct stack**head,int data){//double** because we are storing the adress of head pointer
if (isstackfull(*head)==1){
printf("stack is overflowed/full");}

else{
struct stack*p;
 p=(struct stack*)malloc(sizeof(struct stack));//allocating dunammemory for new node
 p->data=data;
 p->right=*head;//*head beacuse we are connecting p->next with adress of head pointer so that we can traverse from p to other nodes
*head=p;
   }
}







int main() {
struct stack*head=NULL;

//  head=(struct stack*)malloc(sizeof(struct stack));
 pushleft(&head,70);//sending adress of head pointer
 
 pushleft(&head,80) ;//sending adress of head pointer
   
   
 //pushright(&head,90);//sending adress of head pointer
 
// pushright(&head,100);
 pushleft(&head,110);
 //pushright(&head,120);
 pushleft(&head,130);

 //pushright(&head,140);

 printf("original stack was:\n\n\n");
 
 traversestackleft(head);
   
 
 traversestackright(head);
    return 0;
}