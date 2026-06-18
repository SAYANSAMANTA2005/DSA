#include <stdio.h>
#include <stdlib.h>


struct node{
int data;
struct node*next;

};
struct node*head;//global declared head
void traverselinklist(struct node*ptr){
//printf("%d\n",head->data);

while (ptr!=NULL){
printf("%d\n",ptr->data);
ptr=ptr->next;
 }
}




int main() {

struct node *second;
struct node *third;
struct node *fourth;
struct node *fifth;
struct node *sixth;
struct node *seventh;

  // struct node *temp;
  
  head=(struct node *)malloc(sizeof(struct node));
 
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));

fourth=(struct node *)malloc(sizeof(struct node));
fifth=(struct node *)malloc(sizeof(struct node));
 
sixth=(struct node *)malloc(sizeof(struct node));


seventh=(struct node *)malloc(sizeof(struct node));

  head->next=second;
   
  second->next=third;
  
  third->next=fourth;
  
  fourth->next=fifth;
  fifth->next=sixth;
   
  sixth->next=seventh;
  
  
  
  seventh->next=NULL;//circular link list
 
 head->data=1;
  
 second->data=2;
 
 third->data=4;
 
 fourth->data=8;
 fifth->data=16;
 sixth->data=32;
 seventh->data=64;
 printf("All the node's data of linklist:\n");
 traverselinklist(head);//sending the pointer/adress that is head
 
 printf("checking if we can deallocate all the nodes :\n");
 printf("writng all the memory deallocating nodes:\n");
 struct node* temp1=head;
 struct node* temp2=NULL;
 
 while(temp1 !=NULL){//freeing all node's momory//
 //memory deallocation
 
 temp2=temp1->next;
 
 printf("%d\n",temp1->data);
 free(temp1);
 temp1 =temp2;
 
 
 
 
 }
 
 
 return 0;
  
}