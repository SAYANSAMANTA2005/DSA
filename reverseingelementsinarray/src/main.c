




    #include <stdio.h>

void fun(int arr[], int *n) {
 
    int a=0;
    printf("solution is :");
    int i=0;int j=*n-1;
    while ( i<j){
    int temp=arr[i] ;
    arr[i]=arr[j];
     arr[j]=temp;
     
     i++;
    j--;
    
        }
    
    
    return ;
    }

int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        fun(arr, &n);

    printf("Our array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    

    return 0;
}