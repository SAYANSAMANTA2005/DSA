#include <stdio.h>
#include <stdlib.h>

int arr[100];
int i=0;//globally declaration of this is essential because in this way what we storing
//in inorder function is passed to main function 
//I is declared globally for changing i value during recursive call 
struct node{
int data;
struct node*left;
struct node*right;
};

struct node* createnode(int data){
struct node*p;
p=(struct node*)malloc(sizeof(struct node));
p->data=data;
p->left=NULL;
p->right=NULL;

return p;//adress of new node
 }

 void inorder(struct node*root){
//index of array

if(root!=NULL){


inorder (root->left);
arr[i]=root->data;
printf("%d\n",root->data);
i++;
inorder(root->right);


    }
    

 }
 


int main() {

 struct node*p= createnode( 1);
 struct node*p1= createnode( 2);
 
struct node*p2= createnode( 3);

struct node*p3= createnode( 4);
 struct node*p4= createnode( 5);
 
struct node*p5= createnode( 6);
struct node*p6= createnode( 7);

p->left=p1;
p1->left=p3;
p1->right=p4;
p->right=p2;
p2->left=p5;
p2->right=p6;
 //sending the pointer/adress that is head
 
 printf("inorder traversal:\n");
 inorder(p);
 int y=0;
 for(int j=0;j+1<6;j++){
 
 if(arr[j]<arr[j+1]){
  y=-1;
 //printf("binary tree is  binary search tree");
   }
   else{y=-2;
   printf("binary tree is  not binary search tree");
   break;}
 }
 if(y==-1){printf("binary tree is  binary search tree");}
 
 
 printf("\ninorder traversal of binary tree is:\n ");
 
 for(int i=0;i<=6;i++){
 printf("%d ",arr[i]);}
    return 0;
    
}