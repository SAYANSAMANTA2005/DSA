#include<stdio.h>
int main (){
int n; int m; int k; int l;

printf("enter the num of rows :");
scanf("%d",&n);
printf("enter num of column for 1st matrix and number of rows for 2nd matrix:");

scanf("%d",&m);

printf("enter num of column for 2nd matrix ");
scanf("%d",&k);

int var1[n][m];
printf("elements of 1nd matrix\n:");
for(int i=0;i<n;i++){ 
for(int j=0;j<m;j++){
printf("[");
printf("%d %d",i,j );
printf("]");
printf("th term is:");
scanf("%d",& var1[i][j]);
}}
int var2[m][k]; 
printf("elements of 2nd matrix\n:");
for(int i=0;i<m;i++){ 
for(int j=0;j<k;j++){
printf("[");
printf("%d %d",i,j );
printf("]");
printf("th term is:");
scanf("%d",& var2[i][j]);
}}
int var[n][k]; int sum;
printf("elements of mitilpication of two matrix\n:");
for(int i=0;i<n;i++){ 
for(int j=0;j<k;j++){
 sum=0;
 for(l=0;l<m;l++){
sum=sum +var1[i][l]*var2[l][j];
}
var[i][j]=sum;
printf(" %d",var[i][j]);
}
printf("\n");}

return 0;
}