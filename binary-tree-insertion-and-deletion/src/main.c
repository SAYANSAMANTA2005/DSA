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

 int inorder(struct node*root){//data type of function can be taken any,it does not affect the result unless we have to return a spwctype of data type element
//index of array

if(root!=NULL){


inorder (root->left);
arr[i]=root->data;
printf("%d\n",root->data);
i++;
inorder(root->right);


    }
 }
 
struct node*insert(int num,struct node*root){
x=0;

struct node*previous=NULL;
while(root!=NULL){

previous= root;//1 time loop ,previous is the node before current root position 
if(num>root->data){root=root->right;}
if(num<root->data){root=root->left;}
if(num==root->data){
x=-1;
printf("\n%d num is previously present",root->data);
  }
struct node*new=createnode(num);
if(num<root->data){root ->left=createnode(num);}

 else{root->right=createnode(num);}

return root;


}
}
struct node*delete(int num,struct node*root){
x=0;

struct node*previous=NULL;
while(root->data!=num){

previous= root;//1 time loop ,previous is the node before current root position 
if(num>root->data){root=root->right;}
if(num<root->data){root=root->left;}
}


if(previous->data>root->data)
{
previous->left=NULL;
}

 else{
 previous->right=NULL;
 }

x=-1;

//if(root==NULL){
//printf("\n%d num is not previously present\n",num);}
free(root);
return root;


}

int main() {

 struct node*p= createnode( 50);
 struct node*p1= createnode( 40);
 
struct node*p2= createnode( 60);

struct node*p3= createnode( 20);
 struct node*p4= createnode( 45);
 
struct node*p5= createnode( 55);
//struct node*p6= createnode( 70);
//         50
 //      /   \
//      40     60
//      /\     /\
//     20 45  55  70

p->left=p1;
p1->left=p3;
p1->right=p4;
p->right=p2;
p2->left=p5;
//p2->right=p6;
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
 
struct node*z= insert(57,p);
 
 printf("inorder traversal:\n");
 inorder(p);
delete(55,p);
printf("inorder traversal:\n");
 inorder(p);
 //if(x==0){printf("\nnum is not present in binary tree ");}
    return 0;
    
}