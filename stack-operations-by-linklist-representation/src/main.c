#include <stdio.h>
#include <stdlib.h>


struct stack{
int data;
struct stack*next;

};
void traversestack(struct stack*ptr){
while (ptr!=NULL){
printf("%d ",ptr->data);
ptr=ptr->next;
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
 
void push(struct stack**head,int data){//double** because we are storing the adress of head pointer
if (isstackfull(*head)==1){
printf("stack is overflowed/full");}

else{
struct stack*p;
 p=(struct stack*)malloc(sizeof(struct stack));//allocating dunammemory for new node
 p->data=data;
 p->next=*head;//*head beacuse we are connecting p->next with adress of head pointer so that we can traverse from p to other nodes
*head=p;
   }
}



int  pop(struct stack**head){

        if(isstackempty(*head)==1){
        printf("stack is empty/underflow");
   
         return -1; }
        
        else{

        struct stack*temp = *head;
       * head = (*head)->next;
        int x=temp->data;
        free(temp);
        
        
        return x;
          }

}

int main() {
struct stack*head=NULL;

//  head=(struct stack*)malloc(sizeof(struct stack));
 push(&head,70);//sending adress of head pointer
 
 push(&head,80) ;//sending adress of head pointer
   
   
 push(&head,90);//sending adress of head pointer
 
 push(&head,100);
 push(&head,110);
 push(&head,120);
 push(&head,130);

 push(&head,140);

 printf("original stack was:\n\n\n");
 
 traversestack(head);
   
 int y= pop(&head);//sending adress of head pointer
 if(y!=-1){//works if stack has no -1 valued element
 printf("\n \n\npoped element is \n:%d ",y);
 printf("\nnew stack is:\n\n\n");
 traversestack(head);}
    return 0;
}