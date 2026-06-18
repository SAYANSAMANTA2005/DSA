#include <stdio.h>
#include <stdlib.h>


struct node{
int data;
struct node*next;

};
void traverselinklist(struct node*ptr){
while (ptr!=NULL){
printf("%d\n",ptr->data);
ptr=ptr->next;
 }
}

insertlinklistatfirst(struct node **head){//double** because we are storing the adress of head pointer
struct node *p;
 p=(struct node *)malloc(sizeof(struct node));
 p->data=-2089;
 p->next=*head;//*head beacuse we are connecting p->next with adress of head pointer so that we can traverse from p to other nodes

traverselinklist(p);
}


int main() {
struct node *head;
struct node *second;
struct node *third;
struct node *fourth;

  // struct node *temp;
  
  head=(struct node *)malloc(sizeof(struct node));
 
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));

fourth=(struct node *)malloc(sizeof(struct node));


  head->next=second ;
   
  second->next=third;
  
  third->next=fourth;
  
 fourth->next=NULL;
 
 head->data=1;
  
 second->data=2;
 
 third->data=4;
 
 fourth->data=8;
 traverselinklist(head);//sending the pointer/adress that is head
 
 
 insertlinklistatfirst(&head);//sending adress of head pointer
 
 
 
 
 
    return 0;
}