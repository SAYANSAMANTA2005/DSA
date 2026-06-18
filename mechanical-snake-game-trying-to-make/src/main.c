#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 19
void sizeincrease_of_mech_snake(int *head_row,int *head_column,int  arr[n][n]);
//function prototype 

void move_function(int arr[n][n], int *new_head_row, int *new_head_column, int *head_row, int *head_column);
//function prototype 

int count_total_no_of_zerosqare(int arr[n][n]){
 int count =0;
for (int i=0;i<n;i++){
   for(int j=0;j<n;j++){
  if( arr[i][j]==0){
  count++;}
   }
   
  }
return count;


}

int count_total_no_of_fivesqare(int arr[n][n]){
 int count5 =0;
for (int i=0;i<n;i++){
   for(int j=0;j<n;j++){
  if( arr[i][j]==5){
  count5++;}
   }
   
  }
return count5;


}

void function(int i,int j,int  arr[n][n]){
if(arr[i][j]!=0||i<0||i>=n||j<0||j>=n||count_total_no_of_zerosqare(arr)<1){
 return ; 
 } 
 
 if(count_total_no_of_zerosqare(arr)==1){ 
 for (int i=0;i<n;i++){
  for(int j=0;j<n;j++){ 
  if(arr[i][j]!=2&& arr[i][j]!=1&&arr[i][j]!=5){ 
  printf("%d, %d \n",i,j);
    arr[i][j]=1;  
    break; } } } }
   if(count_total_no_of_zerosqare(arr)>1){ 
     arr[i][j]=2;}
   
    function(i+1,j  ,arr); 
    function(i-1,j  ,arr); 
    function(i  ,j+1,arr); 
    function(i  ,j-1,arr); 
    
    return;}

  
 void printfuction(  int arr[n][n]){
 
 srand(time(NULL));
int row_number1  = rand() % n;
int column_number2 = rand() % n;
 if(count_total_no_of_fivesqare(arr)==0){
 arr[row_number1][column_number2]=5;
    }//food for mechanical snake 
    
 for (int i=0;i<n;i++){
   for(int j=0;j<n;j++){
   printf("%d ",arr[i][j]);
   }
   printf("\n");
  }
  
  
  return;
  
  }
  
  
  void move_function(int arr[n][n],int*new_head_row,int *new_head_column,int*head_row,int*head_column){
  

     if(arr[*new_head_row][*new_head_column]==5){
     printf("\nsayan\n");
     sizeincrease_of_mech_snake(new_head_row, new_head_column, arr);
     
     }
     arr[*new_head_row][*new_head_column]=2;
   
   if(arr[*head_row][*head_column]!=5){
     
  function(*head_row,*head_column,arr);
  }
  
  
  for (int i=0;i<n;i++){
   for(int j=0;j<n;j++){
  if( arr[i][j]==2){
  printf("%d %d \n",i,j);
   arr[i][j]=0;}
   }
  }
  *head_row=*new_head_row;
*head_column=*new_head_column;

 printfuction(arr);
 
  
 
  return;
  }
  
 void nexthead(int*new_head_row,int*new_head_column,int *head_row,int *head_column){
 
  
 char decision;
 
 printf("for go down press 'd';move up row press 'u' ; move left press'l'move right press'r':\n('d'/'u'/'l'/'r');\n");

scanf("%c",& decision);

if( decision!='d' && decision!='u'&& decision!='l'&& decision!='r'){
//printf("invalid move ");
//scanf("%c",& decision);
return ;
  }
  else{
 if( decision=='d'){
*new_head_row =*head_row+1;}
else if( decision=='u') {
 *new_head_row=*head_row-1;}
else  if(decision=='r'){
 *new_head_column=*head_column+1;}
else   {
 *new_head_column=*head_column-1;}
 }
 
 return;
 
  }
  void sizeincrease_of_mech_snake(int *head_row, int *head_column, int arr[n][n]) {
    if (arr[*head_row][*head_column] != 0 || *head_row < 0 || *head_row >= n || *head_column < 0 || *head_column >= n || count_total_no_of_zerosqare(arr) < 1) {
        return;
    }

    if (count_total_no_of_zerosqare(arr) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != 2 && arr[i][j] != 1 && arr[i][j] != 5) {
                    printf("%d, %d \n", i, j);
                    arr[i][j] = 7;  // Assuming 7 represents the new body segment
                    break;
                }
            }
        }
    }
    if (count_total_no_of_zerosqare(arr) > 1) {
        arr[*head_row][*head_column] = 2;
    }

    function(*head_row + 1, *head_column, arr);
    function(*head_row - 1, *head_column, arr);
    function(*head_row, *head_column + 1, arr);
    function(*head_row, *head_column - 1, arr);

    return;
}
  
  
  
  
  
  
  
  //return;
  //}
  
  
int main(){
//srand(time(NULL));
//int row_number1  = rand() % n;
//int column_number2 = rand() % n;

int arr[n][n]=//1 represent snake is not present at that square 
{
    {1, 0, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
printfuction(arr);
//representating head or tail of mechanical snake
//0 represent mechanical snake's body




int head_row;
int head_column;
int new_head_row;
int new_head_column;
int row_decision;
int column_decision;
printf("enter the row of head of snake\n");
scanf("%d",&head_row);
printf("enter the column of head of snake\n");
scanf("%d",&head_column);

//arr[new_head_row][new_head_column]=2;


for(int k=0;k<1000;k++){


nexthead(&new_head_row,&new_head_column,&head_row,&head_column);

move_function(arr,&new_head_row,&new_head_column,&head_row,&head_column);
//moving snake 1 iteration

  }


return 0;

}