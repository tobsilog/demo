//SUm of Odd

#include <stdio.h>

int oddSum(int *, int);

int main(){
    int size;
    printf("Enter how many values: ");
    scanf("%d", &size);
    int arr[size];
    int x;
    for(x = 0; x < size; x++){
        printf("Enter the element %d: ", x + 1);
        scanf("%d", &arr[x]);
    }
    int sum = oddSum(arr, size);
    
    printf("List {");
    
    int y;
    for(y = 0; y < size; y++){
        if(y < size - 1){
            printf("%d, ", arr[y]);
        } else {
            printf("%d", arr[y]);
        }
    }
    printf("}");
    
    printf("\nThe sum of odd is %d.", sum);

    return 0;
}

int oddSum(int *arr, int size){
    int x;
    int sum = 0;
    for(x = 0; x <= size; x++){
        if(arr[x] % 2 != 0){
            sum += arr[x];
        }
    }
    return sum;
}