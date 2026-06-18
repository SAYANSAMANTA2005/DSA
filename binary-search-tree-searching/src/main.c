#include <stdio.h>
#include <stdlib.h>
int x;
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
 
void search(int num,struct node*root){
x=0;
if(root!=NULL){
if(num>root->data){search(num,root->right);}
if(num<root->data){search(num,root->left);}
if(num==root->data){
x=-1;
printf("\nnum have been found");}


}}

int main() {

 struct node*p= createnode( 50);
 struct node*p1= createnode( 40);
 
struct node*p2= createnode( 60);

struct node*p3= createnode( 20);
 struct node*p4= createnode( 45);
 
struct node*p5= createnode( 55);
struct node*p6= createnode( 70);
//       50
 //      /\
//      40     60
//      /\     /\
//     20 45  55  65

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
 
 search(57,p);
 if(x==0){printf("\nnum is not present in binary tree ");}
    return 0;
    
}