//The breaker

#include <stdio.h>

int missingnumber(int *arr, int max, int size);

int main(){
    
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    int x;
    int max = 0;
    for(x = 0; x < size; x++){
        printf("Enter element: ");
        scanf("%d", &arr[x]);
        if(arr[x] > max){
        max = arr[x];
        }
    }
    int missing = missingnumber(arr, max, size);
    
    printf("The missing number is: %d", missing);
}

int missingnumber(int *arr, int max, int size){
    int x, y, missing;
    int check[max + 1];
    for(x = 0; x < size; x++){
        check[arr[x]] = 1;
    }
    for(y = 0; y < max + 1;y++){
        if(check[y] == 0){
           missing = y; 
        }
    }
    return missing;
}