//Average of Even


#include <stdio.h>

int evenSum(int *, int );
float average(int *, int, int);

int main(){
    int size;
    int x;
    printf("Enter how many values: ");
    scanf("%d", &size);

    int arr[size];
    
    for(x = 0; x < size; x++){
        printf("Enter the element %d: ", x + 1);
        scanf("%d", &arr[x]);
    }

    int sum = evenSum(arr, size);
    float ave = average(arr, sum, size);
        
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
    printf("\nThe sum of even is %d.", sum);
    printf("\nThe average of even is %.2f.", ave);
    
}
int evenSum(int *arr, int size){
    int x;
    int sum = 0;
    for(x = 0; x < size; x++){
        if(arr[x] % 2 == 0){
            sum += arr[x];
        }
    }
    return sum;
}

int count(int *arr, int size){
    int count = 0, x;
    for(x = 0; x < size; x++){
        if(arr[x] % 2 == 0){
            count++;
        }
    }
    return count;
}

float average(int *arr, int sum, int size){
    int num = count(arr, size);
    float ave = (float )sum/(float)num;
    return ave;
}