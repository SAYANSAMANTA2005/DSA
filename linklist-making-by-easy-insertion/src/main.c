#include <stdio.h>
#include <stdlib.h>


struct stack{
int data;
struct node*next;

};
void traversestack(struct stack*ptr){
while (ptr!=NULL){
printf("%d\n",ptr->data);
ptr=ptr->next;
 }
}

insertstackatfirst(struct stack**head,int data){//double** because we are storing the adress of head pointer
struct stack*p;
 p=(struct stack*)malloc(sizeof(struct stack));//allocating dunammemory for new node
 p->data=data;
 p->next=*head;//*head beacuse we are connecting p->next with adress of head pointer so that we can traverse from p to other nodes
*head=p;

}


int main() {
struct stack*head;

  head=(struct stack*)malloc(sizeof(struct stack));
 head->next=NULL ;
  head->data=1;
  
 insertstackatfirst(&head,70);//sending adress of head pointer
 
 insertstackatfirst(&head,80) ;//sending adress of head pointer
   
   
 insertstackatfirst(&head,90);//sending adress of head pointer
 
 insertstackatfirst(&head,100);
 insertstackatfirst(&head,110);
 insertstackatfirst(&head,120);
insertstackatfirst(&head,130);

insertstackatfirst(&head,140);
 
 traversestack(head);
 
 
    return 0;
}