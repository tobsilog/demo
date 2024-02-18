//Reverse Trap

#include <stdio.h>
#include <stdlib.h>

int *reverse(int *arr, int size);

int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size + 1];
    int x;
    
    for(x = 0; x < size; x++){
        printf("Enter element %d: ", x + 1);
        scanf("%d", &arr[x]);
    }

    int *array = reverse(arr, size);
    
    int y;
     printf("Original array: [");
    for(y = 0; y < size; y++){
        if(y < size - 1){
            printf("%d, ", arr[y]);
        } else {
            printf("%d", arr[y]);
        }
    }
    printf("]\n");
    
    int k;
    printf("Reverse array: [");
    for(k = 0; *(array + k) != 0; k++){
         if(k < size - 1){
            printf("%d, ", *(array + k));
        } else {
            printf("%d", *(array + k));
        }
    }
    printf("]");
    
    free(array);

    return 0;
    
}

int *reverse(int *arr, int size){
    int *newa = (int *)malloc( (size + 1)* 4);
    int x, y;
    for(x = size - 1, y = 0; y < size; x--, y++){
             newa[x] = arr[y];
    }
    *(newa + (size + 1)) = 0;
    //printf("%d", *(newa + (size + 1)));
    return newa;
}